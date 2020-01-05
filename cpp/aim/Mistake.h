#ifndef AIM_MISTAKE_H
#define AIM_MISTAKE_H
#include <exception>
namespace Aim{
	struct Mistake : public std::exception{
		Mistake() :exception(){}
		Mistake(const char *text) :
			exception(text){}
		virtual const char *why()const{
			return "unknown";
		}
	};
}
#endif
