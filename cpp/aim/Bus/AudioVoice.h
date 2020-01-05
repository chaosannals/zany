#ifndef AIM_BUS_AUDIOVOICE_H
#define AIM_BUS_AUDIOVOICE_H
#include <dsound.h>
#include <Pointer.h>
namespace Aim{
	namespace Bus{
		class AudioVoice final{
			Pointer<IDirectSoundBuffer> voice;
		public:
			AudioVoice(IDirectSoundBuffer *voice) :
				voice(voice){}
			void Play(int count)const{
				voice->Play(0, 0, count);
			}
			void Stop()const{
				voice->Stop();
			}
			bool IsPlaying()const{
				DWORD status = 0;
				voice->GetStatus(&status);
				return status & DSBSTATUS_PLAYING;
			}
		};
	}
}
#endif
