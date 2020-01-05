#ifndef AIM_IMPLEMENT_H
#define AIM_IMPLEMENT_H
#include "Counter.h"
namespace Aim{
	template<typename I, typename... IL> class Implement :public I, public IL...{
		Counter counter;
	public:
		void Attach()const final{
			const_cast<Counter&>(counter).Increase();
		}
		void Detach()const final{
			const_cast<Counter&>(counter).Decrease();
			if (counter.Count() == 0)delete this;
		}
	};
}
#endif
