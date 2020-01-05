#include <fstream>
#include <cstdint>
#include <Finality.h>
#include <COMMistake.h>
#include <Cue/WAVE.h>
#include "AudioDevice.h"

Aim::Bus::AudioDevice Aim::Bus::AudioDevice::Initialize(HWND window){
	Pointer<IDirectSound8> bus;
	COMMistake::Check(DirectSoundCreate8(nullptr, bus.Access(), nullptr));
	COMMistake::Check(bus->SetCooperativeLevel(window,DSSCL_NORMAL));
	return bus.Release();
}

Aim::Bus::AudioVoice Aim::Bus::AudioDevice::LoadWAVFormFile(const char *path){
	auto wave = Aim::Cue::WAVE::LoadFormFile(path);
	auto info = wave->PeekFormat();
	WAVEFORMATEX format{
		info.Format,
		info.Channel,
		info.Sample.Rate,
		info.Sample.Span,
		info.Sample.Align,
		info.Sample.Bits,0
	};
	DSBUFFERDESC desc{
		sizeof(DSBUFFERDESC),
		DSBCAPS_CTRLVOLUME,
		wave->PeekData().Count(),
		0, &format, { 0, 0, 0 }
	};
	Pointer<IDirectSoundBuffer> result;
	void *data = nullptr;
	DWORD size = 0;
	COMMistake::Check(bus->CreateSoundBuffer(&desc, result.Access(), nullptr));
	COMMistake::Check(result->Lock(0, 0, &data, &size, nullptr, nullptr, DSBLOCK_ENTIREBUFFER));
	memcpy(data, wave->PeekData().Peek(), min(size, wave->PeekData().Count()));
	COMMistake::Check(result->Unlock(data, size, nullptr, 0));
	return result.Release();
}
