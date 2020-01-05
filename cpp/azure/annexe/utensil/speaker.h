namespace anx{
	class speaker final{
		IXAudio2 *origin;
		IXAudio2MasteringVoice *mastering;
	public:
		speaker(IXAudio2 *origin,
			IXAudio2MasteringVoice *mastering) :
			origin(origin), mastering(mastering){
		}
		~speaker(){
			if (mastering)mastering->DestroyVoice();
			if (origin)origin->Release();
		}
	};
}