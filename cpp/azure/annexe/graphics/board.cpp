#include "../graphics.h"

using namespace anx;
using namespace wnt;

s_r<board> board::create(
	DWORD format,
	ID3DXSprite *sprite,
	const char *text,
	const RECT &rect,
	const D3DCOLOR &color){
	return s_r<board>(
		new board(format,
		sprite, text,
		rect, color));
}

void board::draw(ID3DXFont *aim){
	aim->DrawTextA(
		sprite.get(),
		text.c_str(),
		-1, &rect,
		format, color);
}