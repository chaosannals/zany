#include "InputBus.h"

namespace{
	BOOL CALLBACK EnumDeviceProcess(LPCDIDEVICEINSTANCE instance, LPVOID group){
		auto target = reinterpret_cast<std::vector<DIDEVICEINSTANCE>*>(group);
		target->push_back(*instance);
		return DIENUM_CONTINUE;
	}
}

Aim::Bus::InputBus Aim::Bus::InputBus::Initialize(HINSTANCE instance){
	Pointer<IDirectInput8> bus;
	if (FAILED(DirectInput8Create(instance, DIRECTINPUT_VERSION,
		IID_IDirectInput8, reinterpret_cast<void**>(bus.Access()), nullptr)))
		throw Mistake("create dev_fty failed");
	return bus.Release();
}

std::vector<DIDEVICEINSTANCE> Aim::Bus::InputBus::Match(DWORD type, DWORD flag){
	std::vector<DIDEVICEINSTANCE> result;
	HRESULT sign = bus->EnumDevices(
		type, EnumDeviceProcess, &result, flag);
	if (FAILED(sign))throw COMMistake(sign, "fail to match");
	return result;
}
