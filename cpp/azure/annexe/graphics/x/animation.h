#pragma once
namespace anx{
	namespace x{
		class animation{
			UINT index;									//当前动画编号
			FLOAT speed;								//速度倍数
			FLOAT transition;							//转化速率
			wnt::c_r<ID3DXAnimationController> controller;
			animation(const wnt::c_r<ID3DXAnimationController> &controller) :
				index(0), speed(1.0f), transition(0.25f), controller(controller){
				act(index);
			}
		public:
			static wnt::u_r<animation> create(ID3DXAnimationController *pointer);
			void refresh(float time);
			void act(UINT i);
			void act(const char *name);
			UINT get_index(const std::string &name);
			void set_speed(float value){ speed = value; }
		};
	}
}