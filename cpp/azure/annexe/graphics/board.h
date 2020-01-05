#pragma once
namespace anx{
	class board{
		DWORD format;
		wnt::c_r<ID3DXSprite> sprite;
		std::string text;
		RECT rect;
		D3DCOLOR color;
		board(DWORD format,
			ID3DXSprite *sprite,
			const char *text,
			const RECT &rect,
			const D3DCOLOR &color) :
			format(format),
			sprite(sprite),
			text(text),
			rect(rect),
			color(color){
		}
	public:
		static wnt::s_r<board> create(
			DWORD format,
			ID3DXSprite *sprite,
			const char *text,
			const RECT &rect,
			const D3DCOLOR &color);
		void draw(ID3DXFont *aim);
	};
}