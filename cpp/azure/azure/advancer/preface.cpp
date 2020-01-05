#include "../entirety.h"

using namespace anx;
using namespace anx::aze;
using namespace wnt;
using namespace wnt::di8;

u_r<preface> preface::create(){
	return u_r<preface>(new preface());
}

bool preface::advance(
	float time,
	const kbd_dev &keyboard,
	const mus_dev &mouse,
	projector &screen){
	static bool b = true;
	if (b){
		b = false;
		auto l = light::create({
			D3DLIGHT_DIRECTIONAL,
			{ 1.0f, 1.0f, 1.0f },
			{ 1.0f, 1.0f, 1.0f },
			{ 1.0f, 1.0f, 1.0f },
			{ 1.0f, 1.0f, 1.0f },
			{ -1.0f, -1.0f, 1.0f },
			1.0f, 1.0f,
			1.0f, 1.0f, 1.0f,
			1.0f, 1.0f
		});
		screen.load_xfile("tiny.x");
		tiny->appoint(l);
		tiny->place(0.0f, 0.0f, -100.0f);
		tiny->adjust(4.0f);
		tiny->yaw(3.14f);
		tiny2->appoint(l);
		screen.appoint(tiny2);
		tiny2->move(0.0f, 0.0f, 100.0f);
		tiny2->speed(4.0f);
		screen.appoint(tiny);
		auto text = board::create(
			DT_TOP | DT_LEFT,
			nullptr, "hello",
			{ 0, 0, 200, 200 },
			0xff000000);
		screen.appoint(text);
	}
	if (keyboard.is_loose(DIK_Q))
		MessageBox(0, 0, 0, 16);
	if (keyboard.is_dented(DIK_W))
		shot.walk(time * 100.0f);
	if (keyboard.is_dented(DIK_S))
		shot.walk(time * -100.0f);
	if (keyboard.is_press(DIK_X))
		log.log(wnt::clock, "A", wnt::endl);
	screen.refresh(time, shot);
	return true;
}

std::string preface::submit(){
	return "";
}