#include "entirety.h"

using namespace anx;
using namespace wnt;
using namespace wnt::di8;
namespace{
	const TCHAR wndclass_name[] = TEXT("azure wndclass name");
	const TCHAR window_title[] = TEXT("annex:azure");

	LRESULT CALLBACK process(
		HWND window,
		UINT message,
		WPARAM wparam,
		LPARAM lparam){
		LRESULT result = 0;
		switch (message){
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_CLOSE:
			DestroyWindow(window);
			break;
		default:
			result = DefWindowProc(window, message, wparam, lparam);
			break;
		}
		return result;
	}

	u_r<projector> create_projector(HWND window){
		D3DPRESENT_PARAMETERS parameters{
			800, 600, D3DFMT_A2R10G10B10, 1,
			D3DMULTISAMPLE_8_SAMPLES, 0,
			D3DSWAPEFFECT_DISCARD, window, TRUE,
			TRUE, D3DFMT_D24S8,
			0, D3DPRESENT_RATE_DEFAULT,
			D3DPRESENT_INTERVAL_IMMEDIATE
		};
		D3DVIEWPORT9 viewport{
			0, 0, 800, 600, 0, 1
		};
		D3DXMATRIX projection;
		D3DXMatrixPerspectiveFovLH(
			&projection,
			D3DX_PI * 0.2f,
			1440.0f / 900.0f,
			1.0f, 10000.0f);
		D3DXFONT_DESC font{
			25,15,500,D3DX_DEFAULT,
			FALSE,DEFAULT_CHARSET,
			0, 0, 0, L"Times New Roman"
		};
		return anx::projector::create(
			parameters,
			viewport,
			projection,
			font,
			"original");
	}
}

u_r<aze::environment> aze::environment::create(
	HINSTANCE instance, int visibility){
	auto type = wnd_cls::derive({
		sizeof(WNDCLASSEX), 0, process,
		0, 0, instance,
		LoadIcon(nullptr, IDI_APPLICATION),
		LoadCursor(nullptr, IDC_ARROW),
		static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH)),
		nullptr, wndclass_name,
		LoadIcon(nullptr, IDI_WINLOGO)
	});
	HWND window = type.create({
		{ WS_OVERLAPPEDWINDOW, 0 },
		0, 0, 800, 600,
		TEXT("azure"),
		nullptr, nullptr, instance, nullptr });
	if (!IsWindow(window))
		throw mistake("create window failed");
	ShowWindow(window, visibility);
	UpdateWindow(window);

	auto device = dev_fty::create(instance);
	auto keyboard = device.create<kbd_dev>(window, GUID_SysKeyboard, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	auto mouse = device.create<mus_dev>(window, GUID_SysMouse, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	auto screen = create_projector(window);
	auto worker = preface::create();
	UnregisterClass(wndclass_name, instance);
	return u_r<environment>(
		new environment(
		type, window,
		worker.release(),
		device,
		keyboard.release(),
		mouse.release(),
		screen.release()));
}

void aze::environment::execute()try{
	keyboard->update();
	mouse->update();
	if (worker->advance(
		clock.elapse<float>(),
		*keyboard,
		*mouse,
		*screen))return;
	adjust(worker->submit());
}
catch (const mistake &e){
	log.log(e.what(), wnt::endl,
		e.why(), wnt::endl);
}

void aze::environment::adjust(std::string description){
	std::stringstream stream(description);
}