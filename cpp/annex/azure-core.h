namespace aze{
	template<template<typename> class T, typename I, typename... IL> struct core;
	template<typename I, typename... IL> struct data;
	template<typename I, typename... IL> struct engine;

	//����ͨ��new delete�����ü����ڴ洦��ʽ
	template<template<typename> class T, typename I, typename... IL> struct core : public T<I>, public core<T, IL...>{
		void appoint(aze::access<T, I> *pointer)const final{ ++*amount; }
		void dismiss(aze::access<T, I> *pointer)const final{ if (--*amount == 0)delete this; }
		core(){}
		core(const I &i, const IL&... il) :T<I>(i), core<T, IL...>(il...){}
	};
	template<template<typename> class T, typename I> struct core<T, I> : public T<I>{
		void appoint(aze::access<T, I> *pointer)const final{ ++*amount; }
		void dismiss(aze::access<T, I> *pointer)const final{ if (--*amount == 0)delete this; }
		~core(){ delete amount; }
	protected:
		int *const amount;
		core() :amount(new int(0)){}
		core(const I &i) :T<I>(i), amount(new int(0)){}
	};

	//���ڴ������ݵ�core
	template<typename I, typename... IL> struct data : public core<source, I, IL...>{
		int count()const final{ return *amount; }
		bool examine()const override{ return true; }
		data(const I &i, const IL&... il) :core<aze::source, I, IL...>(i, il...){}
	};

	//���ڴ���ӿڵ�core
	template<typename I, typename... IL> struct engine : public core<course, I, IL...>{
		int count()const final{ return *amount; }
	};
}