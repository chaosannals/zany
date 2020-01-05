#pragma once
namespace anx{
	namespace x{
		struct container : public D3DXMESHCONTAINER{							//模型容器
			static const D3DXMESHCONTAINER null;
			LPDIRECT3DTEXTURE9 *textures;										//贴图，用于储存贴图
			LPD3DXMESH mesh;													//网格，用于存储改变后的网格
			D3DXMATRIX **bones;													//骨骼定位，用于找到骨骼的转换矩阵
			container() :D3DXMESHCONTAINER(null),
				textures(nullptr), bones(nullptr){
				MeshData.Type = D3DXMESHTYPE_MESH;
				MeshData.pMesh = nullptr;
			}
			static container *create(
				LPCSTR name,
				CONST D3DXMESHDATA *mesh,
				CONST D3DXMATERIAL *materials,
				DWORD material_number,
				CONST DWORD *indices,
				LPD3DXSKININFO skin,
				const std::string &directory);
		};
	}
}