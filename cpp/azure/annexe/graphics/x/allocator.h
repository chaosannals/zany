#pragma once
namespace anx{
	namespace x{
		class allocator : public ID3DXAllocateHierarchy{
			std::string module;											//�ļ�Ŀ¼
			std::map<std::string, wnt::s_r<model>> models;			//ģ��

			static wnt::s_r<model> setup(
				LPD3DXFRAME frame,
				LPD3DXANIMATIONCONTROLLER controller);
		public:
			allocator(const char *module) :module(module){}
			STDMETHOD(CreateFrame)(THIS_ LPCSTR name, LPD3DXFRAME *output)final;
			STDMETHOD(CreateMeshContainer)(THIS_ LPCSTR name,
				CONST D3DXMESHDATA *mesh, CONST D3DXMATERIAL *material,
				CONST D3DXEFFECTINSTANCE *effect, DWORD material_number,
				CONST DWORD *indices, LPD3DXSKININFO skin,
				LPD3DXMESHCONTAINER *output)final;
			STDMETHOD(DestroyFrame)(THIS_ LPD3DXFRAME pointer)final;
			STDMETHOD(DestroyMeshContainer)(THIS_ LPD3DXMESHCONTAINER pointer)final;
			wnt::s_r<model> find(const char *file);
			static void load_xfile(//�����õ�����ָ�룬���Ա��붨��Ϊ��̬����
				const wnt::s_r<allocator> &master,
				LPDIRECT3DDEVICE9 device,
				const char *file);
		};
	}
}