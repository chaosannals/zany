#include <COMMistake.h>
#include "GraphicsDevice.h"
namespace{
#ifdef _DEBUG
	const UINT DeviceFlag = D3D11_CREATE_DEVICE_DEBUG;
#else
	const UINT DeviceFlag = 0;
#endif
	struct FEATURE{
		UINT Number;
		const D3D_FEATURE_LEVEL *Buffer;
	};
	FEATURE ParseFeature(D3D_FEATURE_LEVEL level){
		static const D3D_FEATURE_LEVEL levels[] = {
			D3D_FEATURE_LEVEL_11_1,
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0,
			D3D_FEATURE_LEVEL_9_3,
			D3D_FEATURE_LEVEL_9_2,
			D3D_FEATURE_LEVEL_9_1
		};
		UINT number = sizeof(levels) / sizeof(D3D_FEATURE_LEVEL);
		const D3D_FEATURE_LEVEL *buffer = levels;
		while (*buffer != level){
			++buffer;
			--number;
		}
		return{ number, buffer };
	}
}

Aim::Pointer<Aim::Bus::GraphicsDevice> Aim::Bus::GraphicsDevice::Initialize(
	IDXGIAdapter *adapter, const Aim::Bus::GRAPHICS_DEVICE_DESC &desc){
	D3D_FEATURE_LEVEL level = desc.Level;
	FEATURE feature = ParseFeature(level);
	Pointer<ID3D11Device> device;
	Pointer<ID3D11DeviceContext> context;
	Pointer<IDXGISwapChain> swapChain;
	Pointer<ID3D11RenderTargetView> renderTargetView;
	Pointer<ID3D11Texture2D> backBuffer;
	COMMistake::Check(D3D11CreateDeviceAndSwapChain(
		adapter, D3D_DRIVER_TYPE_HARDWARE, nullptr, DeviceFlag,
		feature.Buffer, feature.Number, D3D11_SDK_VERSION, &desc.SwapChainDesc,
		swapChain.Access(), device.Access(), &level, context.Access()));
	COMMistake::Check(swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
		reinterpret_cast<void**>(backBuffer.Access())));
	COMMistake::Check(device->CreateRenderTargetView(
		backBuffer.Get(), nullptr, renderTargetView.Access()));
	context->OMSetRenderTargets(1, renderTargetView.Access(), nullptr);
	context->RSSetViewports(1, &desc.Viewport);
	return new GraphicsDevice(device.Release(), context.Release(),
		swapChain.Release(), renderTargetView.Release());
}

void Aim::Bus::GraphicsDevice::SetViewport(const D3D11_VIEWPORT &viewport){
	context->RSSetViewports(1, &viewport);
}
