#ifndef AIM_BUS_INPUTDEVICE_H
#define AIM_BUS_INPUTDEVICE_H
#include <memory>
#include <dinput.h>
#include <Interface.h>
#include <Implement.h>
#include <Pointer.h>
namespace Aim{
	namespace Bus{
		template<typename S> class InputDevice : public Implement<Interface>{
			static const int outtime = 0x4;
			Pointer<IDirectInputDevice8> device;
			std::unique_ptr<S> now;
			std::unique_ptr<S> old;
		public:
			static const byte mark = (byte)0x80;
			static const byte zero = (byte)0x00;
			InputDevice(IDirectInputDevice8 *device) :
				device(device), now(new S), old(new S){
				std::memset(now.get(), 0, sizeof(S));
				std::memset(old.get(), 0, sizeof(S));
			}
			const S &PeekNow()const{ return *now.get(); }
			const S &PeekOld()const{ return *old.get(); }
			virtual void Update(){
				now.swap(old);
				for (int i = 0; i != outtime &&
					FAILED(device->GetDeviceState(sizeof(S), now.get()));
					++i)device->Acquire();
			}
		};
	}
}
#endif
