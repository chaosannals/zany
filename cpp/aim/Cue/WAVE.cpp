#include <memory>
#include <fstream>
#include <Finality.h>
#include <Mistake.h>
#include "WAVE.h"
namespace{
	bool Indentify(const Aim::Cue::WAVEHeader &header){
		return header.Identity == Aim::Cue::RIFF4CC({ 'R', 'I', 'F', 'F' })
			&& header.Type == Aim::Cue::RIFF4CC({ 'W', 'A', 'V', 'E' })
			&& header.Info.Sign == Aim::Cue::RIFF4CC({ 'f', 'm', 't', ' ' });
	}
	std::unique_ptr<uint8_t[]> Load(Aim::Cue::RIFFChunkHeader &chunk, std::fstream &file){
		std::unique_ptr<uint8_t[]> data(new uint8_t[chunk.Size]);
		file.read(reinterpret_cast<char*>(data.get()), chunk.Size);
		return data;
	}
}

Aim::Pointer<Aim::Cue::WAVE> Aim::Cue::WAVE::LoadFormFile(const char *path){
	std::fstream file;
	file.open(path, std::ios::in | std::ios::binary);
	if (!file.is_open())throw Mistake("Open file failed");
	Finality finality([&file](){ file.close(); });
	WAVEHeader header;
	file.read(reinterpret_cast<char*>(&header), sizeof(WAVEHeader));
	if (!Indentify(header))throw Mistake("Is not WAVE file");
	file.seekg(header.Info.Size - sizeof(WAVEFormat), std::ios::cur);
	uint32_t dataSize = 0, factSize = 0;
	std::unique_ptr<uint8_t[]> dataBuffer, factBuffer;
	while (!file.eof()){
		RIFFChunkHeader chunk;
		file.read(reinterpret_cast<char*>(&chunk), sizeof(RIFFChunkHeader));
		if (chunk.Sign == RIFF4CC({ 'D', 'A', 'T', 'A' }) ||
			chunk.Sign == RIFF4CC({ 'd', 'a', 't', 'a' })){
			dataSize = chunk.Size;
			dataBuffer = Load(chunk, file);
		}
		else if (chunk.Sign == RIFF4CC({ 'F', 'A', 'C', 'T' }) ||
			chunk.Sign == RIFF4CC({ 'f', 'a', 'c', 't' })){
			factSize = chunk.Size;
			factBuffer = Load(chunk, file);
		}
		else break;
	}
	return new WAVE(header.Info,
		dataSize, dataBuffer.release(),
		factSize, factBuffer.release());
}