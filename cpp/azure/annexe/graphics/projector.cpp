#include "../graphics.h"

using namespace anx;
using namespace wnt;

u_r<projector> projector::create(
	D3DPRESENT_PARAMETERS &parameters,
	const D3DVIEWPORT9 &viewport,
	const D3DXMATRIX &projection,
	const D3DXFONT_DESC &font,
	const char *directory){
	c_r<IDirect3D9> origin(Direct3DCreate9(D3D_SDK_VERSION));
	if (origin.empty())return nullptr;
	D3DCAPS9 caps;
	origin->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
	DWORD vertexprocessing = (
		(caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		? D3DCREATE_HARDWARE_VERTEXPROCESSING
		: D3DCREATE_SOFTWARE_VERTEXPROCESSING);
	c_r<IDirect3DDevice9> device;
	c_r<ID3DXFont> writter;
	if (SUCCEEDED(origin->CreateDevice(
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
		parameters.hDeviceWindow, vertexprocessing,
		&parameters, device.access())) &&
		SUCCEEDED(D3DXCreateFontIndirect(
		device.get(), &font, writter.access()))){
		device->SetViewport(&viewport);
		device->SetRenderState(D3DRS_LIGHTING, TRUE);
		device->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
		device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
		device->SetRenderState(D3DRS_ZENABLE, TRUE);
		device->SetTransform(D3DTS_PROJECTION, &projection);
		return u_r<projector>(
			new projector(
			origin.release(),
			device.release(),
			writter.release(),
			directory));
	}
	return nullptr;
}

void projector::refresh(float time, camera &shot){
	device->SetTransform(D3DTS_VIEW, shot.peek());
	device->Clear(0, nullptr,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		0xccffff, 1.0f, 0);
	device->BeginScene();
	for (auto itor = scene.begin(); itor != scene.end(); ++itor)
		(*itor)->refresh(time, device.get());
	for (auto itor = boards.begin(); itor != boards.end(); ++itor)
		(*itor)->draw(font.get());
	device->EndScene();
	device->Present(nullptr, nullptr, nullptr, nullptr);
}

void projector::load_xfile(const char *file){
	x::allocator::load_xfile(
		allocator,
		device.get(),
		file);
}

void projector::appoint(const s_r<image> &one){
	one->apply(*allocator);
	scene.push_back(one);
}

void projector::dismiss(const s_r<image> &one){
	for (auto itor = scene.begin(); itor != scene.end(); ++itor){
		if (one == *itor){
			*itor = scene.back();
			scene.pop_back();
			break;
		}
	}
}

void projector::appoint(const s_r<board> &one){
	boards.push_back(one);
}

void projector::dismiss(const s_r<board> &one){
	for (auto itor = boards.begin(); itor != boards.end(); ++itor){
		if (one == *itor){
			*itor = boards.back();
			boards.pop_back();
			break;
		}
	}
}