#ifndef AIM_STRUCTURE_H
#define AIM_STRUCTURE_H
#include "Interface.h"
#include "Implement.h"
namespace Aim{
	template<typename S> struct Structure : public Implement<Interface>{
		operator S()const{
			return value;
		}
		Structure &operator=(S value){
			this->value = value;
			return this;
		}
	private:
		S value;
	};
}
#endif
