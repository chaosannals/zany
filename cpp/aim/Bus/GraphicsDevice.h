#ifndef AIM_BUS_GRAPHICSDEVICE_H
#define AIM_BUS_GRAPHICSDEVICE_H
#include <d3d11.h>
#include <vector>
#include <Pointer.h>
#include <Interface.h>
#include <Implement.h>
namespace Aim{
	namespace Bus{
		struct GRAPHICS_DEVICE_DESC{
			D3D_FEATURE_LEVEL Level;
			DXGI_SWAP_CHAIN_DESC SwapChainDesc;
			D3D11_VIEWPORT Viewport;
		};
		class GraphicsDevice final : public Implement<Interface>{
			Pointer<ID3D11Device> device;
			Pointer<ID3D11DeviceContext> context;
			Pointer<IDXGISwapChain> swapChain;
			Pointer<ID3D11RenderTargetView> renderTargetView;
			GraphicsDevice(ID3D11Device *device,
				ID3D11DeviceContext *context,
				IDXGISwapChain *swapChain,
				ID3D11RenderTargetView *renderTargetView):
				device(device),context(context),
				swapChain(swapChain),
				renderTargetView(renderTargetView){}
		public:
			static Pointer<GraphicsDevice> Initialize(
				IDXGIAdapter *adapter,
				const GRAPHICS_DEVICE_DESC &desc);
			void SetViewport(const D3D11_VIEWPORT &viewport);
		};
	}
}
#endif
