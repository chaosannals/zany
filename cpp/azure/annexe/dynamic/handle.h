#pragma once
namespace anx{
	namespace py{
		class handle final{
			PyObject *pointer;
		public:
			handle(PyObject *pointer) :
				pointer(pointer){
			}
			handle(const handle &r) :
				pointer(r.pointer){
				Py_XINCREF(pointer);
			}
			virtual ~handle(){
				Py_XDECREF(pointer);
			}
			operator PyObject*()const{
				return pointer;
			}
		};
	}
}