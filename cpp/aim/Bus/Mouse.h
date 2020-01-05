#ifndef AIM_BUS_MOUSE_H
#define AIM_BUS_MOUSE_H
#include "InputDevice.h"
namespace Aim{
	namespace Bus{
		class Mouse final : public InputDevice<DIMOUSESTATE>{
			LONG x, y, z;
		public:
			Mouse(IDirectInputDevice8 *device) :
				InputDevice<DIMOUSESTATE>(device),
				x(0), y(0), z(0){}
			static LPCDIDATAFORMAT GetFormat(){
				return &c_dfDIMouse;
			}
			bool PastDented(int index)const{
				return (PeekOld().rgbButtons[index] & mark) != 0;
			}
			bool IsDented(int index)const{
				return (PeekNow().rgbButtons[index] & mark) != 0;
			}
			bool IsPress(int index)const{
				return IsDented(index) && !PastDented(index);
			}
			bool is_loose(int index)const{
				return !IsDented(index) && PastDented(index);
			}
			float PeekX()const{ return static_cast<float>(x); }
			float PeekY()const{ return static_cast<float>(y); }
			float PeekZ()const{ return static_cast<float>(z); }
			float PeekLostX()const{ return static_cast<float>(PeekNow().lX); }
			float PeekLostY()const{ return static_cast<float>(PeekNow().lY); }
			float PeekLostZ()const{ return static_cast<float>(PeekNow().lZ); }
			void Update()final{
				InputDevice<DIMOUSESTATE>::Update();
				x += PeekNow().lX;
				y += PeekNow().lY;
				z += PeekNow().lZ;
			}
		};
	}
}
#endif
