#include "../../graphics.h"

using namespace anx;
using namespace anx::x;

void particle::reset(void(*action)(attribute&)){
	for (auto itor = group.begin(); itor != group.end(); ++itor)
		action(*itor);
}

void particle::increase(void(*action)(attribute&)){
	attribute one;
	action(one);
	if (reserve.empty())
		group.push_back(one);
	else{
		auto index = reserve.begin();
		group.at(*index) = one;
		reserve.erase(index);
	}
}

void particle::decrement(index_type index){
	group.at(index).able = false;
	reserve.insert(index);
}

void particle::delimit(){
	for (auto itor = group.begin(); itor != group.end(); ++itor){
	}
}

void particle::update(float interval,
	IDirect3DDevice9 *device){
	if (group.empty())return;
	fore_update(device);
	device->SetTexture(0, texture);
	device->SetFVF(description::fvf);
	device->SetStreamSource(0, vertexs, 0, sizeof(description));
	if (offset >= length)
		offset = 0;
	description *pointer = nullptr;
	vertexs->Lock(offset * sizeof(description),
		batch * sizeof(description),
		reinterpret_cast<void**>(&pointer),
		offset ? D3DLOCK_NOOVERWRITE : D3DLOCK_DISCARD);
	DWORD number = 0;
	for (auto i = group.begin(); i != group.end(); ++i){
		if (i->able){
			pointer->position = i->position;
			pointer->color = i->color;
			++pointer;
			++number;
			if (number == batch){
				vertexs->Unlock();
				device->DrawPrimitive(
					D3DPT_POINTLIST,
					offset, batch);
				offset += batch;
				if (offset >= length)
					offset = 0;
				vertexs->Lock(offset * sizeof(description),
					batch * sizeof(description),
					reinterpret_cast<void**>(&pointer),
					offset ? D3DLOCK_NOOVERWRITE : D3DLOCK_DISCARD);
				DWORD number = 0;
			}
		}
	}
	vertexs->Unlock();
	if (number){
		device->DrawPrimitive(
			D3DPT_POINTLIST,
			offset, batch);
	}
	offset += batch;
	back_update(device);
}

void particle::fore_update(IDirect3DDevice9 *device){
	device->SetRenderState(D3DRS_LIGHTING, FALSE);
	device->SetRenderState(D3DRS_POINTSPRITEENABLE, TRUE);
	device->SetRenderState(D3DRS_POINTSCALEENABLE, TRUE);
	device->SetRenderState(D3DRS_POINTSIZE, wnt::reinterpret<DWORD>(size));
	device->SetRenderState(D3DRS_POINTSIZE_MIN, wnt::reinterpret<DWORD>(0.0f));

	device->SetRenderState(D3DRS_POINTSCALE_A, wnt::reinterpret<DWORD>(0.0f));
	device->SetRenderState(D3DRS_POINTSCALE_B, wnt::reinterpret<DWORD>(0.0f));
	device->SetRenderState(D3DRS_POINTSCALE_C, wnt::reinterpret<DWORD>(1.0f));

	device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);

	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

void particle::back_update(IDirect3DDevice9 *device){
	device->SetRenderState(D3DRS_LIGHTING, TRUE);
	device->SetRenderState(D3DRS_POINTSPRITEENABLE, FALSE);
	device->SetRenderState(D3DRS_POINTSCALEENABLE, FALSE);
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}