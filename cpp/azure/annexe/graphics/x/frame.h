#pragma once
namespace anx{
	namespace x{
		struct frame :public D3DXFRAME{
			static const D3DXFRAME null;
			D3DXMATRIX matrix;
			frame() :D3DXFRAME(null){
				D3DXMatrixIdentity(&matrix);
			}
			static void change(LPD3DXFRAME pointer){ change(pointer, nullptr); }
			static DWORD setup(LPD3DXFRAME root){ return setup(root, root); }
		private:
			static void change(LPD3DXFRAME pointer, LPD3DXMATRIX space);
			static DWORD setup(LPD3DXFRAME root, LPD3DXFRAME pointer);
		};
	}
}