#include "entirety.h"

namespace{
	MSG msg{ nullptr, WM_NULL, 0, 0, 0, { 0, 0 } };
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, PSTR, int visibility)try{
	auto environment = anx::aze::environment::create(instance, visibility);
	if (!environment)throw wnt::mistake("create environment failed");
	while (msg.message != WM_QUIT){
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		environment->execute();
	}
	return static_cast<int>(msg.wParam);
}
catch (const std::exception &e){
	MessageBoxA(nullptr, e.what(), "error", MB_ICONERROR);
	return 1;
}