#pragma once
namespace anx{
	namespace py{
		class module final{
			handle aim;
			module(const handle &aim) :
				aim(aim){
			}
		public:
			static module import(const char *name){
				return PyImport_ImportModule(name);
			}
		};
	}
}