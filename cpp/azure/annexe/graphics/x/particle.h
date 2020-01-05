#pragma once
namespace anx{
	namespace x{
		class particle{
		public:
			struct attribute;
			using index_type = std::vector<attribute>::size_type;
			struct description{
				static const DWORD  fvf = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_PSIZE;
				D3DXVECTOR3 position;
				D3DXCOLOR color;
				float size;
			};
			struct attribute{
				bool able;
				float age;
				float life;
				D3DXVECTOR3 position;
				D3DXVECTOR3 velocity;
				D3DXVECTOR3 acceleration;
				D3DXCOLOR color;
				D3DXCOLOR fade;
			};
		private:
			float rate;
			float size;
			DWORD length;
			DWORD offset;
			DWORD batch;
			IDirect3DTexture9 *texture;
			IDirect3DVertexBuffer9 *vertexs;
			D3DXVECTOR3 origin;
			std::vector<attribute> group;
			std::set<index_type> reserve;
			particle(){

			}
			void decrement(index_type index);
			static void random(
				D3DXVECTOR3 &out,
				D3DXVECTOR3 &min,
				D3DXVECTOR3 &max);
		public:
			static wnt::s_r<particle> create(
				IDirect3DDevice9 *device,
				const char *texture);
			~particle(){}
			void reset(void(*action)(attribute&));
			void increase(void(*action)(attribute&));
			void delimit();
			void update(float interval,
				IDirect3DDevice9 *device);
			virtual void fore_update(IDirect3DDevice9 *device);
			virtual void back_update(IDirect3DDevice9 *device);
		};
	}
}