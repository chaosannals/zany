namespace aze{
	class finality;

	class finality final{
		std::vector<runner<void()>> stack;
	public:
		~finality(){
			std::for_each(stack.rbegin(), stack.rend(),
				[](const runner<void()> &r){ r(); });
		}
		template<typename F> void push(const F &f){
			stack.push_back(f);
		}
		runner<void()> pop(){
			runner<void()> result = stack.back();
			stack.pop_back();
			return result;
		}
		void clear(){
			stack.clear();
		}
	};
}