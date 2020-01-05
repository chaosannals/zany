namespace anx{
	template<typename S> class device{
		static const int turn = 0x4;
		IDirectInputDevice8 *aim;
		wnt::u_r<S> now;
		wnt::u_r<S> old;
	public:
		static const byte mark = (byte)0x80;
		static const byte zero = (byte)0x00;
		device(IDirectInputDevice8 *aim) :
			aim(aim), now(new S), old(new S){
			std::memset(now.get(), 0, sizeof(S));
			std::memset(old.get(), 0, sizeof(S));
		}
		virtual ~device(){
			if (aim)aim->Release();
		}
		const S &peek_now()const{ return *now.get(); }
		const S &peek_old()const{ return *old.get(); }
		virtual void update(){
			now.swap(old);
			for (int i = 0; i != turn
				&& FAILED(aim->GetDeviceState(sizeof(S), now.get()));
				++i)aim->Acquire();
		}
	};
}