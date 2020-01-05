namespace aze{
	namespace di8{
		class mouse{
			static const int time = 0x04;
			IDirectInputDevice8 *device;
			std::unique_ptr<DIMOUSESTATE> now_status;
			std::unique_ptr<DIMOUSESTATE> old_status;
			access<source, float> x;
			access<source, float> y;
			access<source, float> z;
		public:
			mouse(IDirectInputDevice8 *device) :
				device(device),
				now_status(new DIMOUSESTATE),
				old_status(new DIMOUSESTATE),
				x(new data<float>(0.0f)),
				y(new data<float>(0.0f)),
				z(new data<float>(0.0f)){
			}
			~mouse(){
				if (device)device->Release();
			}
			void sense();
			censor<source, bool> access_button(const char *description);
			censor<source, float> access_arrow(const char *description);
		};
	}
}