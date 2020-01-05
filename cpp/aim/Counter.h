#ifndef AIM_COUNTER_H
#define AIM_COUNTER_H
#include <cstddef>
namespace Aim{
	class Counter final{
		std::size_t counter;
	public:
		Counter(std::size_t counter = 0) :counter(counter){}
		std::size_t Count()const{ return counter; }
		void Increase(){ ++counter; }
		void Decrease(){ --counter; }
		void Increase(std::size_t value){ counter += value; }
		void Decrease(std::size_t value){ counter += value; }
	};
}
#endif
