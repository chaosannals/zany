#ifndef AIM_ALLOCATION_H
#define AIM_ALLOCATION_H
#include <cstddef>
namespace Aim{
	template<typename T, typename... TL> class Allocation;
	template<> class Allocation<void> final{
		char *allocation;
		Allocation(char *allocation) :allocation(allocation){}
		char *AccessRow()const{ return allocation - sizeof(std::size_t); }
		std::size_t *AccessCounter()const{
			return reinterpret_cast<std::size_t*>(AccessRow());
		}
	public:
		friend Allocation<void> Allocate(std::size_t size){
			return ++new(new char[size + sizeof(std::size_t)])std::size_t(size);
		}
		~Allocation(){ if (allocation)delete[] AccessRow(); }
		void *Access()const{ return allocation; }
		std::size_t Count()const{ return *AccessCounter(); }
	};
	template<typename T> class Allocation<T> final{
		Allocation<void> allocation;
	public:
		template<typename... AL> Allocation(AL... al) :
			allocation(Allocate(sizeof(T)) + sizeof(std::size_t)){
			new(++new(allocation.Access()) T(std::forward(al)...)) std::size_t(0);
		}
		T *Access(){ return reinterpret_cast<T*>(allocation.Access()); }
	};
	template<typename T> class Allocation<T[]> final{
		Allocation<void> allocation;
	public:

	};
}
#endif
