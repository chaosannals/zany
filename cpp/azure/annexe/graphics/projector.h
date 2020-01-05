#pragma once
namespace anx{
	class projector{
		wnt::c_r<IDirect3D9> origin;
		wnt::c_r<IDirect3DDevice9> device;
		wnt::c_r<ID3DXFont> font;
		wnt::s_r<x::allocator> allocator;
		std::vector<wnt::s_r<image>> scene;
		std::vector<wnt::s_r<board>> boards;

		projector(IDirect3D9 *origin,
			IDirect3DDevice9 *device,
			ID3DXFont *font, const char *directory) :
			origin(origin), device(device), font(font),
			allocator(new x::allocator(directory)){
		}
	public:
		~projector(){}
		static wnt::u_r<projector> create(
			D3DPRESENT_PARAMETERS &parameters,
			const D3DVIEWPORT9 &viewport,
			const D3DXMATRIX &projection,
			const D3DXFONT_DESC &font,
			const char *directory);
		void refresh(float time, camera &shot);
		void load_xfile(const char *file);
		void appoint(const wnt::s_r<image> &one);
		void dismiss(const wnt::s_r<image> &one);
		void appoint(const wnt::s_r<board> &one);
		void dismiss(const wnt::s_r<board> &one);
	};
}