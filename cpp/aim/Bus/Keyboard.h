#ifndef AIM_BUS_KEYBOARD_H
#define AIM_BUS_KEYBOARD_H
#include "InputDevice.h"
namespace Aim{
	namespace Bus{
		struct DIKEYBOARDSTATE final{
			byte state[0x100];
			byte operator[](int index)const{
				return state[index];
			}
		};
		class Keyboard final : public InputDevice<DIKEYBOARDSTATE>{
		public:
			Keyboard(IDirectInputDevice8 *device) :
				InputDevice<DIKEYBOARDSTATE>(device){}
			static LPCDIDATAFORMAT GetFormat(){
				return &c_dfDIKeyboard;
			}
			inline bool PastDented(int index)const{
				return (PeekOld()[index] & mark) != 0;
			}
			inline bool IsDented(int index)const{
				return (PeekNow()[index] & mark) != 0;
			}
			inline bool IsPress(int index)const{
				return IsDented(index) && !PastDented(index);
			}
			inline bool IsLoose(int index)const{
				return !IsDented(index) && PastDented(index);
			}
		};
	}
}
#endif
