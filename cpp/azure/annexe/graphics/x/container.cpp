#include "../../graphics.h"

using namespace anx;

namespace{
	DWORD *clone_indices(LPD3DXMESH mesh, const DWORD *indices){
		DWORD number = mesh->GetNumFaces() * 3;
		DWORD *result = new DWORD[number];
		std::memcpy(result, indices, sizeof(DWORD)* number);
		return result;
	}

	D3DXMATERIAL *default_materials(){
		D3DXMATERIAL *result = new D3DXMATERIAL[1];
		ZeroMemory(&result[0].MatD3D, sizeof(D3DMATERIAL9));
		result[0].MatD3D.Diffuse.a = 0.5f;
		result[0].MatD3D.Diffuse.r = 0.5f;
		result[0].MatD3D.Diffuse.g = 0.5f;
		result[0].MatD3D.Diffuse.b = 0.5f;
		result[0].MatD3D.Specular = result[0].MatD3D.Diffuse;
		return result;
	}

	D3DXMATERIAL *clone_materials(DWORD number, CONST D3DXMATERIAL *material){
		if (number < 1)return default_materials();
		D3DXMATERIAL *result = new D3DXMATERIAL[number];
		for (DWORD i = 0; i != number; ++i)
			result[i] = material[i];
		return result;
	}

	LPDIRECT3DTEXTURE9 *default_textures(){
		auto result = new LPDIRECT3DTEXTURE9[1];
		result[0] = nullptr;
		return result;
	}

	LPDIRECT3DTEXTURE9 *create_textures(
		DWORD number,
		CONST D3DXMATERIAL *material,
		IDirect3DDevice9 *device,
		std::string path){
		if (number < 1)return default_textures();
		auto result = new LPDIRECT3DTEXTURE9[number];
		for (DWORD i = 0; i != number; ++i){
			if (material[i].pTextureFilename != nullptr){
				path += material[i].pTextureFilename;
				D3DXCreateTextureFromFileA(device, path.c_str(), &result[i]);
			}
			else result[i] = nullptr;
		}
		return result;
	}
}

const D3DXMESHCONTAINER x::container::null{ nullptr, { D3DXMESHTYPE_MESH }, nullptr, nullptr, 0, 0, nullptr };

x::container *x::container::create(
	LPCSTR name,
	CONST D3DXMESHDATA *mesh,
	CONST D3DXMATERIAL *materials,
	DWORD material_number,
	CONST DWORD *indices,
	LPD3DXSKININFO skin,
	const std::string &directory){
	if (mesh == nullptr
		|| mesh->Type != D3DXMESHTYPE_MESH
		|| mesh->pMesh == nullptr)
		throw std::exception("does not deal");
	auto result = new x::container;
	result->Name = wnt::clone(name);
	result->MeshData.Type = D3DXMESHTYPE_MESH;
	result->pAdjacency = clone_indices(mesh->pMesh, indices);
	wnt::c_r<IDirect3DDevice9> device;
	D3DVERTEXELEMENT9 element[MAX_FVF_DECL_SIZE];
	if (SUCCEEDED(mesh->pMesh->GetDevice(device.access()))
		&& SUCCEEDED(mesh->pMesh->GetDeclaration(element))){
		if (skin != nullptr){
			//只有在模型是有骨骼的情况下保留一个网格副本
			mesh->pMesh->CloneMesh(D3DXMESH_MANAGED, element, device.get(), &result->MeshData.pMesh);
			result->pSkinInfo = skin;
			skin->AddRef();
			//获取用于追踪 动画变换矩阵 的数组
			DWORD number = skin->GetNumBones();
			if (number != 0)result->bones = new D3DXMATRIX*[number];
		}
		else result->MeshData.pMesh = nullptr;
		mesh->pMesh->CloneMesh(D3DXMESH_MANAGED, element, device.get(), &result->mesh);
		result->NumMaterials = max(material_number, 1);
		result->pMaterials = clone_materials(result->NumMaterials, materials);
		result->textures = create_textures(result->NumMaterials, materials, device.get(), directory);
	}
	return result;
}