#ifndef AIM_FINALITY_H
#define AIM_FINALITY_H
#include "Caller.h"
namespace Aim{
	class Finality final{
		Caller<void()> finality;
	public:
		Finality() :finality([](){}){}
		template<typename T> Finality(const T &finality) :
			finality(finality){
		}
		template<typename T> Finality &operator=(const Finality &r){
			finality = r.finality;
		}
		~Finality(){ finality(); }
	};
}
#endif
