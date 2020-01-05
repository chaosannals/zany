#include "../../graphics.h"

using namespace anx;

const D3DXFRAME x::frame::null{ nullptr, {}, nullptr, nullptr, nullptr };

void x::frame::change(LPD3DXFRAME pointer, LPD3DXMATRIX space){
	frame *aim = static_cast<frame*>(pointer);
	if (space != nullptr)
		D3DXMatrixMultiply(&aim->matrix,
		&aim->TransformationMatrix, space);
	else
		aim->matrix = aim->TransformationMatrix;
	if (aim->pFrameSibling != nullptr)
		change(aim->pFrameSibling, space);
	if (aim->pFrameFirstChild != nullptr)
		change(aim->pFrameFirstChild, &aim->matrix);
}

DWORD x::frame::setup(LPD3DXFRAME root, LPD3DXFRAME pointer){
	DWORD result = 0;
	container *data = static_cast<container*>(pointer->pMeshContainer);
	if (data != nullptr && data->pSkinInfo != nullptr){
		DWORD number = data->pSkinInfo->GetNumBones();
		result = max(result, number);
		for (DWORD i = 0; i != number; ++i){
			frame *temp = static_cast<frame*>(D3DXFrameFind(
				root, data->pSkinInfo->GetBoneName(i)));
			if (temp != nullptr)
				data->bones[i] = &temp->matrix;
		}
	}
	if (pointer->pFrameSibling != nullptr)
		result = max(result, setup(root, pointer->pFrameSibling));
	if (pointer->pFrameFirstChild != nullptr)
		result = max(result, setup(root, pointer->pFrameFirstChild));
	return result;
}