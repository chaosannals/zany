namespace aze{
	namespace di8{
		class keyboard{
			static const int amount = 0x100;
			static const int time = 0x04;
			static const std::map<std::string, DWORD> key_map;
			IDirectInputDevice8 *device;
			std::unique_ptr<byte[]> now_status;
			std::unique_ptr<byte[]> old_status;
			std::map<std::tuple<std::string, std::string>, access<source, status>> status_map;
			std::vector<access<source, status>> status_group;

			inline bool update();
		public:
			keyboard(IDirectInputDevice8 *device) :device(device),
				now_status(new byte[amount]), old_status(new byte[amount]){
				memset(now_status.get(), 0, sizeof(byte) * amount);
				memset(old_status.get(), 0, sizeof(byte) * amount);
			}
			~keyboard(){
				if (device)device->Release();
			}
			void sense();
			censor<source, bool> access_key(const char *description);
		};
	}
}