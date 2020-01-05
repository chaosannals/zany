#include "..\entirety.h"

using namespace aze;
using namespace std;

void di8::mouse::sense(){
	now_status.swap(old_status);
	for (int i = 0; i != time && device->GetDeviceState(sizeof(DIMOUSESTATE), now_status.get()); ++i)
		device->Acquire();
	*x += now_status->lX;
	*y += now_status->lY;
	*z += now_status->lZ;
}