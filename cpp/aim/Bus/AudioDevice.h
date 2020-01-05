#ifndef AIM_BUS_AUDIODEVICE_H
#define AIM_BUS_AUDIODEVICE_H
#include <dsound.h>
#include <Pointer.h>
#include "AudioVoice.h"
namespace Aim{
	namespace Bus{
		class AudioDevice final{
			Pointer<IDirectSound8> bus;
			AudioDevice(IDirectSound8 *bus) :bus(bus){}
		public:
			static AudioDevice Initialize(HWND window);
			AudioVoice LoadWAVFormFile(const char *path);
		};
	}
}
#endif
