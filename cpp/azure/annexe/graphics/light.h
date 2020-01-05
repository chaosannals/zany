#pragma once
namespace anx{
	class light : public D3DLIGHT9{
		light(const D3DLIGHT9 &base) :
			D3DLIGHT9(base){}
	public:
		static wnt::s_r<light> create(const D3DLIGHT9 &base){
			return wnt::s_r<light>(new light(base));
		}
	};
}