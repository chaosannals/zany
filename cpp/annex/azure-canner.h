namespace aze{
	template<typename I> class canner;

	template<typename I> class canner{
		struct content{
			int amount;
			I instance;
			template<typename... AL> content(AL... al) :amount(0), instance(std::forward<AL>(al)...){}
			int appoint(){ return ++amount; }
			int dismiss(){ return --amount; }
		}*aim;
	public:
		template<typename... AL> canner(AL... al) :aim(new content(std::forward<AL>(al)...)){ aim->appoint(); }
		canner(const cannner &r) :aim(r.aim){ aim->appoint(); }
		~canner(){ if (aim->dismiss() == 0)delete aim; }
		I *operator->()const{ return &aim->instance; }
		I &operator*()const{ return aim->instance; }
		canner &operator=(const canner &r){
			if (aim == r.aim)return *this;
			aim->dismiss();
			aim = r.aim;
			aim->appoint();
			return *this;
		}
		int count()const{ return aim->amount; }
	};
}