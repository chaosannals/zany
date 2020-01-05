#ifndef AIM_CUE_WAVE_H
#define AIM_CUE_WAVE_H
#include <Pointer.h>
#include <Interface.h>
#include <Implement.h>
#include "RIFF.h"
namespace Aim{
	namespace Cue{
		struct WAVEFormat{
			uint16_t Format;//�����ʽ
			uint16_t Channel;//������Ŀ
			struct{
				uint32_t Rate;//����Ƶ��
				uint32_t Span;//ÿ���ֽ���
				uint16_t Align;//���ݶ���
				uint16_t Bits;//����bits��
			}Sample;
		};
		struct WAVEFormatHeader : public RIFFChunkHeader, public WAVEFormat{};
		struct WAVEHeader : public RIFFHeader{
			WAVEFormatHeader Info;
		};

		class WAVEChunk : RIFFChunkHeader{
			uint8_t *data;
		public:
			WAVEChunk(RIFF4CC sign, uint32_t size, uint8_t *data) :
				RIFFChunkHeader(sign, size), data(data){}
			~WAVEChunk(){
				if (data)delete[] data;
			}
			bool Is(RIFF4CC sign)const{ return Sign == sign; }
			uint32_t Count()const{ return Size; }
			uint8_t *Access()const{ return data; }
			const uint8_t *Peek()const{ return data; }
		};

		class WAVE final : public Implement<Interface>{
			WAVEFormat format;
			WAVEChunk data;
			WAVEChunk fact;
			WAVE(const WAVEFormat &format,
				uint32_t dataSize, uint8_t *dataBuffer,
				uint32_t factSize, uint8_t *factBuffer) :
				format(format),
				data(RIFF4CC({ 'D', 'A', 'T', 'A' }), dataSize, dataBuffer),
				fact(RIFF4CC({ 'F', 'A', 'C', 'T' }), factSize, factBuffer){}
		public:
			static Pointer<WAVE> LoadFormFile(const char *path);
			const WAVEFormat &PeekFormat()const{
				return format;
			}
			const WAVEChunk &PeekData()const{
				return data;
			}
			const WAVEChunk &PeekFact()const{
				return fact;
			}
		};
	}
}
#endif
