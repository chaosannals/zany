#include "../../graphics.h"

using namespace anx;
using namespace anx::x;

namespace {
	const int MAX_TEXTURE = 8;

	void refresh(LPDIRECT3DDEVICE9 device, LPD3DXFRAME pointer, LPD3DXMATRIX buffer){
		for (container *data = static_cast<container*>(pointer->pMeshContainer);
			data != nullptr; data = static_cast<container*>(data->pNextMeshContainer)){
			//更新带动画的模型
			if (data->pSkinInfo != nullptr){
				DWORD number = data->pSkinInfo->GetNumBones();
				for (DWORD i = 0; i != number; ++i)
					D3DXMatrixMultiply(&buffer[i],
					data->pSkinInfo->GetBoneOffsetMatrix(i), data->bones[i]);
				void *target, *source;
				data->MeshData.pMesh->LockVertexBuffer(D3DLOCK_READONLY, &source);
				data->mesh->LockVertexBuffer(0, &target);
				data->pSkinInfo->UpdateSkinnedMesh(buffer, nullptr, source, target);
				data->mesh->UnlockVertexBuffer();
				data->MeshData.pMesh->UnlockVertexBuffer();
			}
			//逐个渲染网格容器里的子网格
			for (DWORD i = 0, j = 0; i != data->NumMaterials; ++i){
				device->SetMaterial(&data->pMaterials[i].MatD3D);
				if (j != MAX_TEXTURE && data->textures[i])
					device->SetTexture(j++, data->textures[i]);
				data->mesh->DrawSubset(i);
			}
		}
		//递归框架树里的兄弟框架或子框架
		if (pointer->pFrameSibling != nullptr)
			refresh(device, pointer->pFrameSibling, buffer);
		if (pointer->pFrameFirstChild != nullptr)
			refresh(device, pointer->pFrameFirstChild, buffer);
	}
}


wnt::s_r<model> model::create(
	const wnt::s_r<allocator> &master,
	LPD3DXFRAME root,
	LPD3DXANIMATIONCONTROLLER controller){
	DWORD size = frame::setup(root);
	wnt::u_r<D3DXMATRIX[]>buffer(new D3DXMATRIX[size]);
	return wnt::s_r<model>(
		new model(size,
		buffer.release(),
		root, controller,
		master));
}

void model::render(float time, LPDIRECT3DDEVICE9 device){
	frame::change(frame);
	refresh(device, frame, buffer.pointer.get());
}