#pragma once
namespace anx{
	namespace x{
		class allocator : public ID3DXAllocateHierarchy{
			std::string module;											//文件目录
			std::map<std::string, wnt::s_r<model>> models;			//模型

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
			static void load_xfile(//由于用到共享指针，所以必须定义为静态函数
				const wnt::s_r<allocator> &master,
				LPDIRECT3DDEVICE9 device,
				const char *file);
		};
	}
}