namespace anx{
	class keyboard final : public device<DIKEYBOARDSTATE>{
	public:
		keyboard(IDirectInputDevice8 *aim) :
			device<DIKEYBOARDSTATE>(aim){}
		bool past_dented(int index)const{
			return (peek_old()[index] & mark) != 0;
		}
		bool is_dented(int index)const{
			return (peek_now()[index] & mark) != 0;
		}
		bool is_press(int index)const{
			return is_dented(index) && !past_dented(index);
		}
		bool is_loose(int index)const{
			return !is_dented(index) && past_dented(index);
		}
	};
}