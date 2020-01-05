namespace anx{
	class sysdevice final{
		wnt::c_r<IDirectInput8> origin;
		mouse mouse;
		keyboard keyboard;
	public:
		sysdevice(IDirectInput8 *origin,
			IDirectInputDevice8 *mouse,
			IDirectInputDevice8 *keyboard) :
			origin(origin),
			mouse(mouse),
			keyboard(keyboard){}
		const anx::mouse &peek_mouse()const{ return mouse; }
		const anx::keyboard &peek_keyboard()const{ return keyboard; }
		void update(){
			mouse.update();
			keyboard.update();
		}

		static wnt::u_r<sysdevice> access(HINSTANCE process, HWND window){
			IDirectInput8 *origin = nullptr;
			IDirectInputDevice8 *mouse = nullptr;
			IDirectInputDevice8 *keyboard = nullptr;
			if (SUCCEEDED(DirectInput8Create(process, DIRECTINPUT_VERSION,
				IID_IDirectInput8, reinterpret_cast<void**>(&origin), nullptr)) &&
				SUCCEEDED(origin->CreateDevice(GUID_SysKeyboard, &keyboard, nullptr)) &&
				SUCCEEDED(keyboard->SetDataFormat(&c_dfDIKeyboard)) &&
				SUCCEEDED(keyboard->SetCooperativeLevel(window, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)) &&
				SUCCEEDED(origin->CreateDevice(GUID_SysMouse, &mouse, nullptr)) &&
				SUCCEEDED(mouse->SetDataFormat(&c_dfDIMouse)) &&
				SUCCEEDED(mouse->SetCooperativeLevel(window, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
				return wnt::u_r<sysdevice>(new sysdevice(origin, mouse, keyboard));
			if (keyboard)keyboard->Release();
			if (mouse)mouse->Release();
			if (origin)origin->Release();
			throw std::exception("access sysdevice failed");
		}
	};
}