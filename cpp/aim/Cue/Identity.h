#ifndef AIM_CUE_IDENTITY_H
#define AIM_CUE_IDENTITY_H
#include <cstddef>
#include <initializer_list>
namespace Aim{
	namespace Cue{
		template<size_t N> struct Identity final{
			char sign[N];
			Identity(std::initializer_list<char> list){
				auto pointer = list.begin;
				for (size_t i = 0; i != N; ++i)
					sign[i] = pointer != list.end ? *pointer++ : '\0';
			}
			friend bool operator==(const Identity &l, const Identity &r){
				for (size_t i = 0; i != N; ++i)
					if (l.sign[i] != r.sign[i])
						return false;
				return true;
			}
			friend bool operator!=(const Identify &l, const Identity &r){
				return !(l == r);
			}
		};
	}
}
#endif
