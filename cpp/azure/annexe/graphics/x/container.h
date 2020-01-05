#pragma once
namespace anx{
	namespace x{
		struct container : public D3DXMESHCONTAINER{							//ģ������
			static const D3DXMESHCONTAINER null;
			LPDIRECT3DTEXTURE9 *textures;										//��ͼ�����ڴ�����ͼ
			LPD3DXMESH mesh;													//�������ڴ洢�ı�������
			D3DXMATRIX **bones;													//������λ�������ҵ�������ת������
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