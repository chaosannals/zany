namespace aze{
	template<template<typename> class T, typename I> class annexe;
	template<typename I> struct course;
	template<typename I> struct source;
	template<template<typename> class T, typename I> class access;
	template<template<typename> class T, typename I> class censor;

	//附加于接口或数据上供access所用的接口
	template<template<typename> class T, typename I> class annexe{
		friend class access<T, I>;
		virtual int count()const = 0;
		virtual bool examine()const = 0;
		virtual void appoint(access<T, I> *pointer)const = 0;
		virtual void dismiss(access<T, I> *pointer)const = 0;
	public:
		virtual ~annexe(){}
	};

	//附加的目标是接口
	template<typename I> struct course : public annexe<course, I>, public I{
		I *access(){ return this; }
	};

	//附加的目标是数据
	template<typename I> struct source : public annexe<source, I>{
		source(const I &i) :instance(i){}
		I *access(){ return &instance; }
	private:
		I instance;
	};

	//用于访问的智能指针
	template<template<typename> class T, typename I> class access final{
		T<I> *aim;
	public:
		access(T<I> *pointer) :aim(pointer){ aim->appoint(this); }
		access(const access &r) :aim(r.aim){ aim->appoint(this); }
		~access(){ aim->dismiss(this); }
		I *operator->()const{ return aim->access(); }
		I &operator*()const{ return *aim->access(); }
		access &operator=(const access &r){
			if (*this == r)return *this;
			aim->dismiss(this);
			aim = r.aim;
			aim->appoint(this);
			return *this;
		}
		int count()const{ return aim->count(); }
		bool examine()const{ return aim->examine(); }

		friend bool operator==(const access &l, const access &r){ return l.aim == r.aim; }
		friend bool operator!=(const access &l, const access &r){ return l.aim != r.aim; }
		friend bool operator<(const access &l, const access &r){ return l.aim < r.aim; }
		friend bool operator<=(const access &l, const access &r){ return l.aim <= r.aim; }
		friend bool operator>(const access &l, const access &r){ return l.aim > r.aim; }
		friend bool operator>=(const access &l, const access &r){ return l.aim >= r.aim; }
	};

	//仅起到读作用的智能指针
	template<template<typename> class T, typename I> class censor final{
		access<T, I> aim;
	public:
		censor(const access<T, I> &pointer) :aim(pointer){}
		const I *operator->()const{ return aim.operator->(); }
		const I &operator*()const{ return *aim; }
		int count()const{ return aim->count(); }
		bool examine()const{ return aim->examine(); }

		friend bool operator==(const censor &l, const censor &r){ return l.aim == r.aim; }
		friend bool operator!=(const censor &l, const censor &r){ return l.aim != r.aim; }
		friend bool operator<(const censor &l, const censor &r){ return l.aim < r.aim; }
		friend bool operator<=(const censor &l, const censor &r){ return l.aim <= r.aim; }
		friend bool operator>(const censor &l, const censor &r){ return l.aim > r.aim; }
		friend bool operator>=(const censor &l, const censor &r){ return l.aim >= r.aim; }
	};
}