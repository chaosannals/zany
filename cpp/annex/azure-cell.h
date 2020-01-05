namespace aze{
	template<template<typename> class T, typename I, typename... IL> struct cell;
	template<typename I, typename... IL> struct card;
	template<typename I, typename... IL> struct placard;

	template<template<typename> class T, typename I, typename... IL> struct cell : public T<I>, public cell<T, IL...>{
		void appoint(aze::access<T, I> *pointer)const final{
			++*amount;
			group.insert(pointer);
		}
		void dismiss(aze::access<T, I> *pointer)const final{
			group.erase(pointer);
			if (--*amount == 0)delete this;
		}
		cell(){}
		cell(const I &i, const IL&... il) :T<I>(i), cell<T, IL...>(il...){}
		access<T, I> consign(T<I> *successor){
			access<T, I> reserve(this);
			for (auto itor = group.begin(); itor != group.end(); ++itor)
				if (*itor != &reserve)**itor = successor;
			return reserve;
		}
	private:
		std::set<access<T, I>*> group;
	};
	template<template<typename> class T, typename I> struct cell<T, I> : public T<I>{
		void appoint(aze::access<T, I> *pointer)const final{
			++*amount;
			group.insert(pointer);
		}
		void dismiss(aze::access<T, I> *pointer)const final{
			group.erase(pointer);
			if (--*amount == 0)delete this;
		}
		cell() :amount(new int(0)){}
		cell(const I &i) :T<I>(i), amount(new int(0)){}
		~cell(){ delete amount; }
		access<T, I> consign(T<I> *successor){
			access<T, I> reserve(this);
			for (auto itor = group.begin(); itor != group.end(); ++itor)
				if (*itor != &reserve)**itor = successor;
			return reserve;
		}
	protected:
		int *const amount;
	private:
		std::set<access<T, I>*> group;
	};

	template<typename I, typename... IL> struct card : public cell<source, I, IL...>{
		int count()const final{ return *amount; }
		bool examine()const override{ return true; }
		card(const I &i, const IL&... il) :cell<aze::source, I, IL...>(i, il...){}
	};

	template<typename I, typename... IL> struct placard : public cell<course, I, IL...>{
		int count()const final{ return *amount; }
	};
}