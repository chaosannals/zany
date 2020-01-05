#pragma once

#include <dinput.h>
#include <xaudio2.h>
#include <awntk.h>

namespace anx{
	class speaker;

	template<typename S> class device;
	class mouse;
	class keyboard;
	class sysdevice;
	struct DIKEYBOARDSTATE final{
		byte state[0x100];
		byte operator[](int index)const{
			return state[index];
		}
	};
}
//�����豸
#include "utensil/device.h"
#include "utensil/mouse.h"
#include "utensil/keyboard.h"
#include "utensil/sysdevice.h"
//��Ч
#include "utensil/speaker.h"
