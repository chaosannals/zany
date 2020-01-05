#ifndef AIM_FUN_TALENT_H
#define AIM_FUN_TALENT_H
#include <Caller.h>
namespace Aim {
	namespace Fun {
		class Talent final {
			float value;
			Caller<void(float&,float)> alter;
		public:
			Talent(float value) :
				value(value),
				alter([](auto a, auto b) {a = b; }) {}
			Talent &operator=(float value) {
				alter(this->value, value);
			}
		};
	}
}
#endif
