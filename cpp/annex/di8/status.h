namespace aze{
	namespace di8{
		class status final{
			static const byte zero = (byte)0x00;
			static const byte mark = (byte)0x80;
			bool now_factor;
			bool old_factor;
			DWORD index;
			access<source, bool> aim;
		public:
			static const std::map<std::string, std::tuple<bool, bool>> factor_map;

			status(bool now_factor, bool old_factor, DWORD index, access<source, bool> aim) :
				now_factor(now_factor), old_factor(old_factor), index(index), aim(aim){
			}
			void sense(const byte *now, const byte *old){
				bool now_status = (now[index] & mark) != zero;
				bool old_status = (old[index] & mark) != zero;
				*aim = now_status != now_factor && old_status != old_factor;
			}
		};
	}
}