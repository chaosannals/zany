#ifndef AIM_BUS_INPUTBUS_H
#define AIM_BUS_INPUTBUS_H
#include <vector>
#include <memory>
#include <dinput.h>
#include <Pointer.h>
#include <COMMistake.h>
namespace Aim{
	namespace Bus{
		class InputBus final{
			Pointer<IDirectInput8> bus;
			InputBus(IDirectInput8 *bus) :bus(bus){}
		public:
			static InputBus Initialize(HINSTANCE instance);
			std::vector<DIDEVICEINSTANCE> Match(DWORD type, DWORD flag);
			template<typename T> Pointer<T> Connect(
				HWND window, GUID id, DWORD level){
				Pointer<IDirectInputDevice8> result;
				HRESULT sign = bus->CreateDevice(id, result.Access(), nullptr);
				if (FAILED(sign))throw COMMistake(sign, "create device failed");
				sign = result->SetDataFormat(T::GetFormat());
				if (FAILED(sign))throw COMMistake(sign, "set data format failed");
				sign = result->SetCooperativeLevel(window, level);
				if (FAILED(sign))throw COMMistake(sign, "set cooperative level failed");
				return new T(result.Release());
			}
		};
	}
}
#endif
