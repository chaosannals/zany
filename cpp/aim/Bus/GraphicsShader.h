#ifndef AIM_BUS_GRAPHICSSHADER_H
#define AIM_BUS_GRAPHICSSHADER_H
#include <d3d11.h>
#include <Pointer.h>
namespace Aim{
	namespace Bus{
		struct COMPILE_DESC{
			const D3D_SHADER_MACRO *Macros;
		};
		class GraphicsShader final{
			Pointer<ID3DBlob> code;
		public:
			static GraphicsShader Compile(const void *data);
			static GraphicsShader CompileFormFile(
				const char *path, const COMPILE_DESC &desc);
		};
	}
}
#endif
