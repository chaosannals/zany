namespace aze{
	template<typename F> class runner;

	//���׼��function���ƣ���ֻռһ��ָ���С���ڴ棬���ڴ��ݣ�������Ӧ�ò���function
	template<typename R ,typename... AL> class runner<R(AL...)> final{
		//base interface class
		struct base_runner{
			virtual ~base_runner(){}
			virtual R run(AL...) = 0;
			virtual base_runner *clone()const = 0;
		};
		//core implement class
		template<typename T> struct core_runner final : public base_runner{
			core_runner(const T &i) :instance(i){}
			R run(AL... al)final{ return instance(std::forward<AL>(al)...); }
			core_runner *clone()const final{ return new core_runner(*this); }
		private:
			T instance;
		};
		//interface of instance;
		base_runner *aim;
	public:
		template<typename T> runner(const T &o) : aim(new core_runner<decltype(o)>(o)){}
		runner(const runner &r) :aim(r.aim->clone()){}
		~runner(){ delete aim; }
		R operator()(AL... al)const{ return aim->run(std::forward<AL>(al)...); }
		runner &operator=(const runner &r){
			if (r == *this)return *this;
			delete aim;
			aim = r.aim->clone();
			return *this;
		}
		friend bool operator==(const runner &l, const runner &r){ return l.aim == r.aim; }
		friend bool operator!=(const runner &l, const runner &r){ return l.aim != r.aim; }
		friend bool operator<(const runner &l, const runner &r){ return l.aim < r.aim; }
		friend bool operator>(const runner &l, const runner &r){ return l.aim > r.aim; }
		friend bool operator<=(const runner &l, const runner &r){ return l.aim <= r.aim; }
		friend bool operator>=(const runner &l, const runner &r){ return l.aim >= r.aim; }
	};
}