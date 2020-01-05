#include <COMMistake.h>
#include "GraphicsAdapter.h"

std::vector<Aim::Bus::GraphicsAdapter> Aim::Bus::GraphicsAdapter::Enumerate(){
	std::vector<GraphicsAdapter> result;
	Pointer<IDXGIFactory> factory;
	COMMistake::Check(CreateDXGIFactory(__uuidof(IDXGIFactory),
		reinterpret_cast<void**>(factory.Access())));
	IDXGIAdapter *adapter = nullptr;
	for (DWORD i = 0; factory->EnumAdapters(i, &adapter); ++i)
		result.push_back(adapter);
	return result;
}

std::vector<Aim::Bus::Monitor> Aim::Bus::GraphicsAdapter::EnumerateMonitor(){
	std::vector<Monitor> result;
	IDXGIOutput *monitor;
	for (UINT i = 0; adapter->EnumOutputs(i, &monitor) != DXGI_ERROR_NOT_FOUND; ++i)
		result.push_back(monitor);
	return result;
}
