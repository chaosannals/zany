#pragma once
namespace anx{
	namespace py{
		class object final{
			handle aim;
		public:
			object(const handle &aim) :
				aim(aim){
			}
			handle operator()(const handle &argument){
				return PyEval_CallObject(aim, argument);
			}
			handle operator()(const handle &argument, const handle &key){
				return PyEval_CallObjectWithKeywords(aim, argument, key);
			}
			handle get(const char *name){
				return PyObject_GetAttrString(aim, name);
			}
			void set(const char *name,const handle &value){
				PyObject_SetAttrString(aim, name, value);
			}
		};
	}
}