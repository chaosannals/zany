#ifndef AIM_BUS_MONITOR_H
#define AIM_BUS_MONITOR_H
#include <d3d11.h>
#include <vector>
#include <Pointer.h>
namespace Aim{
	namespace Bus{
		class Monitor final{
			Pointer<IDXGIOutput> monitor;
		public:
			Monitor(IDXGIOutput *monitor) :monitor(monitor){}
			std::vector<DXGI_MODE_DESC> EnumerateMode(DXGI_FORMAT format);
		};
	}
}
#endif
