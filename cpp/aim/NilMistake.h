#ifndef AIM_NILMISTAKE_H
#define AIM_NILMISTAKE_H
#include <string>
#include "Mistake.h"
namespace Aim{
	class NilMistake final : public Mistake{
		std::string report;
		NilMistake(const char *text) :
			Mistake("nil"), report(text){
		}
	public:
		template<typename T> static T Deny(
			T aim, T nil, const char *text = "deny"){
			if (aim == nil)throw NilMistake(text);
			return aim;
		}
		template<typename T> static T Aver(
			T aim, const char *text = "aver"){
			if (aim == nullptr)throw(NilMistake(text));
			return aim;
		}
	};
}
#endif
