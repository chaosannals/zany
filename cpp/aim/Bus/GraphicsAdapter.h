#ifndef AIM_BUS_GRAPHICSADAPTER_H
#define AIM_BUS_GRAPHICSADAPTER_H
#include <d3d11.h>
#include <vector>
#include <Pointer.h>
#include "GraphicsDevice.h"
#include "Monitor.h"
namespace Aim{
	namespace Bus{
		class GraphicsAdapter final{
			Pointer<IDXGIAdapter> adapter;
			GraphicsAdapter(IDXGIAdapter *adapter) :adapter(adapter){}
		public:
			static std::vector<GraphicsAdapter> Enumerate();
			Pointer<GraphicsDevice> CreateDevice(const GRAPHICS_DEVICE_DESC &desc){
				return GraphicsDevice::Initialize(adapter.Get(), desc);
			}
			std::vector<Monitor> EnumerateMonitor();
		};
	}
}
#endif
