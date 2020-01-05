#include "../../graphics.h"

using namespace anx;
using namespace wnt;

//创建Frame,分配D3DXFRAME内存空间
HRESULT x::allocator::CreateFrame(
	THIS_ LPCSTR name,
	LPD3DXFRAME *output)try{
	*output = new frame;
	(*output)->Name = wnt::clone(name);
	D3DXMatrixIdentity(&(*output)->TransformationMatrix);
	return S_OK;
}
catch (...){
	DestroyFrame(*output);
	*output = nullptr;
	return E_FAIL;
}
//创建MeshContainer,分配XCONTAINER内存空间
HRESULT x::allocator::CreateMeshContainer(
	THIS_ LPCSTR name,
	CONST D3DXMESHDATA *mesh,
	CONST D3DXMATERIAL *materials,
	CONST D3DXEFFECTINSTANCE *,
	DWORD number,
	CONST DWORD *indices,
	LPD3DXSKININFO skin,
	LPD3DXMESHCONTAINER *output)try{
	*output = container::create(
		name,mesh,
		materials,number,
		indices,skin,
		module + "\\texture\\");
	return S_OK;
}
catch (...){
	DestroyMeshContainer(*output);
	output = nullptr;
	return E_FAIL;
}
//回收Frame
HRESULT x::allocator::DestroyFrame(
	THIS_ LPD3DXFRAME pointer){
	if (pointer == nullptr)return S_OK;
	frame *aim = static_cast<frame*>(pointer);
	if (aim->Name != nullptr)delete[] aim->Name;
	delete aim;
	return S_OK;
}
//回收Container
HRESULT x::allocator::DestroyMeshContainer(
	THIS_ LPD3DXMESHCONTAINER pointer){
	if (pointer == nullptr)return S_OK;
	container *aim = static_cast<container*>(pointer);
	if (aim->Name != nullptr)delete[] aim->Name;
	if (aim->pMaterials != nullptr)delete[] aim->pMaterials;
	if (aim->pAdjacency != nullptr)delete[] aim->pAdjacency;
	if (aim->MeshData.pMesh != nullptr)aim->MeshData.pMesh->Release();
	//xframe附加项
	if (aim->mesh != nullptr)aim->mesh->Release();
	if (aim->textures != nullptr){
		for (DWORD i = 0; i != aim->NumMaterials; ++i)
			if (aim->textures[i] != nullptr)
				aim->textures[i]->Release();
		delete[] aim->textures;
	}
	if (aim->bones != nullptr)delete[] aim->bones;
	delete aim;
	return S_OK;
}

s_r<x::model> x::allocator::find(const char *file){
	auto itor = models.find(file);
	if (itor == models.end())return nullptr;
	return itor->second;
}

void x::allocator::load_xfile(
	const s_r<allocator> &master,
	LPDIRECT3DDEVICE9 device,
	const char *file){
	LPD3DXFRAME root = nullptr;
	LPD3DXANIMATIONCONTROLLER controller = nullptr;
	std::string path = master->module + "\\model\\" + file;
	if (SUCCEEDED(D3DXLoadMeshHierarchyFromXA(
		path.c_str(), D3DXMESH_MANAGED, device,
		master.get(), nullptr, &root, &controller))) try{
		auto result = model::create(master, root, controller);
		master->models.insert({ file, result });
	}
	catch (...){
		if (controller)controller->Release();
		if (root)master->DestroyFrame(root);
		throw;
	}
}