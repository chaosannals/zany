#pragma once
namespace anx{
	class image{
		bool visiable;
		wnt::s_r<x::model> model;
		wnt::u_r<x::animation> animation;
		std::string description;
		x::cube cube;
		std::vector<wnt::s_r<light>> lights;
		image(const char *description) :
			visiable(false),
			description(description){
		}
	public:
		static wnt::s_r<image> create(const char *description);
		~image(){}
		void hide(){ visiable = false; }
		void show(){ if (model)visiable = true; }
		void act(UINT i){ animation->act(i); }
		void act(const char *name){ animation->act(name); }
		void nod(float angle){ cube.nod(angle); }
		void yaw(float angle){ cube.yaw(angle); }
		void roll(float angle){ cube.roll(angle); }
		void adjust(float size){ cube.adjust(size); }
		void face(float x, float y, float z){ cube.face(x, y, z); }
		void move(float x, float y, float z){ cube.move(x, y, z); }
		void place(float x, float y, float z){ cube.place(x, y, z); }
		const char *describe()const { return description.c_str(); }
		void refresh(float time, LPDIRECT3DDEVICE9 device);
		void apply(x::allocator &allocator);
		void appoint(const wnt::s_r<light> light);
		void dismiss(const wnt::s_r<light> light);
		void speed(float s){ animation->set_speed(s); }
	};
}