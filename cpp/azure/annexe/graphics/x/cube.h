#pragma once
namespace anx{
	namespace x{
		class cube{
			bool changed;
		protected:
			wnt::u_r<D3DXMATRIX> raw;
			D3DXVECTOR3 top;
			D3DXVECTOR3 right;
			D3DXVECTOR3 front;
			D3DXVECTOR3 position;
			D3DXMATRIX size;
			static void correct(
				D3DXVECTOR3 &top,
				D3DXVECTOR3 &front,
				D3DXVECTOR3 &right);
			static void rotation(float angle,
				const D3DXVECTOR3 &axis,
				D3DXVECTOR3 &first,
				D3DXVECTOR3 &second);
			virtual void change()const;
		public:
			cube() :raw(new D3DXMATRIX),
				top(0.0f, 1.0f, 0.0f),
				right(1.0f, 0.0f, 0.0f),
				front(0.0f, 0.0f, 1.0f),
				position(0.0f, 0.0f, 0.0f){
				D3DXMatrixIdentity(raw.get());
				D3DXMatrixIdentity(&size);
			}
			virtual ~cube(){}
			const D3DXMATRIX *peek();
			void nod(float angle);
			void yaw(float angle);
			void roll(float angle);
			void walk(float value);
			void strafe(float value);
			void fly(float value);
			void adjust(float size);
			void adjust(float x, float y, float z);
			void face(float x, float y, float z);
			void move(float x, float y, float z);
			void place(float x, float y, float z);
		};
	}
}