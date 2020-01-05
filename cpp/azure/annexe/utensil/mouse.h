namespace anx{
	class mouse final : public device<DIMOUSESTATE>{
		float x, y, z;
	public:
		mouse(IDirectInputDevice8 *aim) :
			device<DIMOUSESTATE>(aim),
			x(0.0f), y(0.0f), z(0.0f){}
		bool past_dented(int index)const{
			return (peek_old().rgbButtons[index] & mark) != 0;
		}
		bool is_dented(int index)const{
			return (peek_now().rgbButtons[index] & mark) != 0;
		}
		bool is_press(int index)const{
			return is_dented(index) && !past_dented(index);
		}
		bool is_loose(int index)const{
			return !is_dented(index) && past_dented(index);
		}
		float peek_x()const{ return x; }
		float peek_y()const{ return y; }
		float peek_z()const{ return z; }
		void update()final{
			device<DIMOUSESTATE>::update();
			const DIMOUSESTATE &state = peek_now();
			x += static_cast<float>(state.lX);
			y += static_cast<float>(state.lY);
			z += static_cast<float>(state.lZ);
		}
	};
}