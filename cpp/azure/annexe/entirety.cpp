#include "entirety.h"

namespace{
	std::set<anx::py::antetype*> engines;
}
void anx::py::attach(antetype *pointer){
	engines.insert(pointer);
	if (!Py_IsInitialized())
		Py_Initialize();
}

void anx::py::detach(antetype *pointer){
	engines.erase(pointer);
	if (engines.empty())
		Py_Finalize();
}

BOOL APIENTRY DllMain(
	HINSTANCE instance,
	DWORD reason,
	PVOID reserve){
	return TRUE;
}