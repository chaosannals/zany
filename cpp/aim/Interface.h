#ifndef AIM_INTERFACE_H
#define AIM_INTERFACE_H
namespace Aim{
	struct Interface{
		virtual ~Interface(){}
		virtual void Attach()const = 0;
		virtual void Detach()const = 0;
	};
#ifdef AIM_COUNTABLE_POINTER_ENABLE
	inline void Attach(const Interface *pointer){
		if (pointer)pointer->Attach();
	}
	inline void Detach(const Interface *pointer){
		if (pointer)pointer->Detach();
	}
#endif
}
#endif
