#pragma once
namespace anx{
	namespace x{
		class model{
			struct bones{
				DWORD size;
				std::unique_ptr<D3DXMATRIX[]> pointer;
				bones(DWORD size, D3DXMATRIX *pointer) :
					size(size), pointer(pointer){}
			}buffer;
			LPD3DXFRAME frame;
			LPD3DXANIMATIONCONTROLLER controller;
			wnt::s_r<allocator> master;

			model(DWORD size, D3DXMATRIX *pointer,
				LPD3DXFRAME frame,
				LPD3DXANIMATIONCONTROLLER controller,
				const wnt::s_r<allocator> &master) :
				buffer(size, pointer), frame(frame),
				controller(controller), master(master){
			}
		public:
			~model(){
				if (controller)controller->Release();
				if (frame)master->DestroyFrame(frame);
			}
			static wnt::s_r<model> create(
				const wnt::s_r<allocator> &master,
				LPD3DXFRAME root, LPD3DXANIMATIONCONTROLLER controller);
			void render(float time, LPDIRECT3DDEVICE9 device);
			ID3DXAnimationController *peek_animation()const{ return controller; }
		};
	}
}