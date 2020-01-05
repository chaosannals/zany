#ifndef AIM_POINTER_H
#define AIM_POINTER_H
namespace Aim{
	template<typename T> class Pointer final{
		T *pointer;
	public:
		Pointer(T *pointer = nullptr) :pointer(pointer){}
		Pointer(const Pointer &r) :pointer(r.pointer){
			Attach(pointer);
		}
		~Pointer(){ Detach(pointer); }
		T *operator->()const{ return pointer; }
		T &operator*()const{ return *pointer; }
		Pointer &operator=(const Pointer &r){
			if (r.pointer == pointer)return *this;
			Detach(pointer);
			pointer = r.pointer;
			Attach(pointer);
			return *this;
		}
		bool IsNull()const{ return pointer == nullptr; }
		T *Get()const{ return pointer; }
		T **Access(){ return &pointer; }
		T *Release(){
			T *result = pointer;
			pointer = nullptr;
			return result;
		}
	};
	template<typename T> inline Pointer<T> Appoint(T *pointer){
		Pointer<T> result(pointer);
		Attach(pointer);
		return result;
	}
#ifdef AIM_COM_POINTER_ENABLE
#include <Unknwn.h>
	inline void Attach(IUnknown *pointer){
		if(pointer)pointer->AddRef();
	}
	inline void Detach(IUnknown *pointer){
		if(pointer)pointer->Release();
	}
#endif
}
#endif
