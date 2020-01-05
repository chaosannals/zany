#ifndef AIM_CUE_RIFF_H
#define AIM_CUE_RIFF_H
#include <cstdint>
namespace Aim{
	namespace Cue{
		struct RIFF4CC{
			char Sign[4];
			RIFF4CC() :RIFF4CC({ '\0', '\0', '\0', '\0' }){}
			RIFF4CC(const char(&sign)[4]){
				for (int i = 0; i != 4; ++i)
					Sign[i] = sign[i];
			}
			friend bool operator==(RIFF4CC l,RIFF4CC r){
				return *reinterpret_cast<uint32_t*>(l.Sign)
					== *reinterpret_cast<uint32_t*>(r.Sign);
			}
			friend bool operator!=(RIFF4CC l,RIFF4CC r){
				return !(l == r);
			}
		};

		struct RIFFHeader{
			RIFF4CC Identity;
			uint32_t Size;//管辖范围内余下字节数[即下一字节开始计起]
			RIFF4CC Type;
			RIFFHeader() :RIFFHeader(
				RIFF4CC({ 'R', 'I', 'F', 'F' }), 4,
				RIFF4CC({ 'N', 'U', 'L', 'L' })){}
			RIFFHeader(uint32_t size, RIFF4CC type) :RIFFHeader(
				RIFF4CC({ 'R', 'I', 'F', 'F' }), size, type){}
			RIFFHeader(RIFF4CC identity,
				uint32_t size, RIFF4CC type) :
				Identity(identity),
				Size(size), Type(type){}
		};

		struct RIFFChunkHeader{
			RIFF4CC Sign;
			uint32_t Size;//管辖范围内余下字节数[即下一字节开始计起]
			RIFFChunkHeader() :RIFFChunkHeader(
				RIFF4CC({ 'N', 'U', 'L', 'L' }), 0){}
			RIFFChunkHeader(RIFF4CC sign, uint32_t size) :
				Sign(sign), Size(size){}
		};

		struct RIFFListHeader : public RIFFHeader{
			RIFFListHeader() :RIFFListHeader(4,
				RIFF4CC({ 'N', 'U', 'L', 'L' })){}
			RIFFListHeader(uint32_t size, RIFF4CC type) :RIFFHeader(
				RIFF4CC({ 'L', 'I', 'S', 'T' }), size, type){}
		};
	}
}
#endif
