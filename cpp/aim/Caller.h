#ifndef AIM_CALLER_H
#define AIM_CALLER_H
#include <utility>
namespace Aim{
	template<typename T> class Caller;
	template<typename R, typename... AL> class Caller<R(AL...)> final{
		typedef R(*FunctionPointerType)(AL...);
		struct Callable{
			virtual ~Callable(){}
			virtual R Call(AL...) = 0;
			virtual Callable *Clone()const = 0;
		}*caller;
		template<typename T> class CoreCaller final : public Callable{
			T caller;
		public:
			CoreCaller(const T &caller) :caller(caller){}
			R Call(AL... al)final{
				return caller(std::forward<AL>(al)...);
			}
			Callable *Clone()const final{
				return new CoreCaller(caller);
			}
		};
		Caller(Callable *caller) :caller(caller){}
	public:
		template<typename T> Caller(const T &caller) :
			caller(new CoreCaller<T>(caller)){
		}
		Caller(const Caller &r) :caller(r.caller->Clone()){}
		~Caller(){ delete caller; }
		R operator()(AL... al)const{
			return caller->Call(std::forward<AL>(al)...);
		}
		Caller &operator=(const Caller &r){
			if (r.caller == *this)return *this;
			delete caller;
			caller = r.caller->Clone();
			return *this;
		}
		Caller Appoint(){
			return caller;
		}
	};
}
#endif
