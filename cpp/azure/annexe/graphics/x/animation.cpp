#include "../../graphics.h"

using namespace anx;
using namespace anx::x;

namespace {
	const DWORD track = 0;
}

wnt::u_r<animation> animation::create(ID3DXAnimationController *pointer){
	if (!pointer)throw std::exception("nullptr ID3DXAnimationController");
	wnt::c_r<ID3DXAnimationController> controller;
	if(FAILED(pointer->CloneAnimationController(
		pointer->GetMaxNumAnimationOutputs(),
		pointer->GetMaxNumAnimationSets(),
		pointer->GetMaxNumTracks(),
		pointer->GetMaxNumEvents(),
		controller.access())))
		throw std::exception("failed to clone ID3DXAnimationController");
	return wnt::u_r<animation>(new animation(controller));
}

void animation::act(UINT i){
	index = min(i, controller->GetNumAnimationSets());
	wnt::c_r<ID3DXAnimationSet> set;
	controller->GetAnimationSet(index, set.access());
	controller->SetTrackAnimationSet(track, set.get());
}

void animation::act(const char *name){
	index = get_index(name);
	act(index);
}

void animation::refresh(float interval){
	double time = controller->GetTime();
	controller->UnkeyAllTrackEvents(track);
	controller->SetTrackEnable(track, TRUE);
	controller->KeyTrackSpeed(track, speed,
		time, transition, D3DXTRANSITION_LINEAR);
	controller->KeyTrackWeight(track, 1.0f,
		time, transition, D3DXTRANSITION_LINEAR);
	controller->AdvanceTime(interval, nullptr);
}

UINT animation::get_index(const std::string &name){
	for (UINT i = 0; i != controller->GetNumAnimationSets(); ++i){
		wnt::c_r<ID3DXAnimationSet> set;
		if (FAILED(controller->GetAnimationSet(i, set.access())))
			continue;
		if (set->GetName() && name == set->GetName())
			return i;
	}
	return 0;
}