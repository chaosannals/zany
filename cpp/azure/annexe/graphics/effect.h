#pragma once
namespace anx{
	class effect{
		wnt::u_r<x::particle> core;
		effect(){}

	public:
		static wnt::s_r<effect> create();
	};
}