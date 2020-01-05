namespace aze{
	namespace di8{
		class raw_senser final : public engine<aze::raw_senser>{
			IDirectInput8 *origin;
			keyboard keyboard;
			mouse mouse;
		public:
			raw_senser(IDirectInput8 *origin,
				IDirectInputDevice8 *keyboard,
				IDirectInputDevice8 *mouse) :
				origin(origin), keyboard(keyboard), mouse(mouse){
			}
			~raw_senser(){
				origin->Release();
			}
			bool examine()const final{ return true; }
			void sense()final;
			censor<source, bool> access_bool(const char *description)final;
			censor<source, float> access_float(const char *description)final;
		};
	}
}