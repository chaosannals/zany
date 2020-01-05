#include "../graphics.h"

using namespace anx;
using namespace wnt;

namespace{
	const int MAX_LIGHT = 8;
}

s_r<image> image::create(const char *description){
	return s_r<image>(new image(description));
}

void image::refresh(float time, LPDIRECT3DDEVICE9 device){
	if (!visiable)return;
	device->SetTransform(D3DTS_WORLD, cube.peek());
	for (DWORD index = 0; index != MAX_LIGHT; ++index){
		BOOL able = index < lights.size();
		if (able)device->SetLight(index, lights[index].get());
		device->LightEnable(index, able);
	}
	animation->refresh(time);
	model->render(time, device);
}

void image::apply(x::allocator &allocator){
	model = allocator.find(description.c_str());
	animation = x::animation::create(model->peek_animation());
	show();
}

void image::appoint(s_r<light> light){
	if (lights.size() < MAX_LIGHT)
		lights.push_back(light);
	else
		lights.back() = light;
}
void image::dismiss(s_r<light> light){
	for (auto itor = lights.begin(); itor != lights.end(); ++itor){
		if (*itor == light){
			*itor = lights.back();
			lights.pop_back();
			break;
		}
	}
}