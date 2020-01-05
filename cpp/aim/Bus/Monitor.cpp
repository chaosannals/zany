#include <COMMistake.h>
#include "Monitor.h"

std::vector<DXGI_MODE_DESC> Aim::Bus::Monitor::EnumerateMode(DXGI_FORMAT format){
	UINT number = 0;
	COMMistake::Check(monitor->GetDisplayModeList(format, 0, &number, nullptr));
	std::vector<DXGI_MODE_DESC> result(number);
	COMMistake::Check(monitor->GetDisplayModeList(format, 0, &number, result.data()));
	return result;
}
