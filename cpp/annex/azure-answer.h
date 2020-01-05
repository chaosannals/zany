namespace aze{
	struct career;
	template<bool able> class answer;

	access<course, career> create_career(const char *description);

	struct career{
		virtual ~career(){}
		virtual const char *peek()const = 0;
		virtual const char *peek(int line)const = 0;
		virtual int insert(const char *text) = 0;
	};

	template<bool able> class answer{
		access<course, career> aim;
	public:
		answer(const char *description) :aim(create_career(description)){}
		const char *peek()const{ return aim->peek(); }
		const char *peek(int line)const{ return aim->peek(line); }
		int insert(const char *text)const{ return aim->insert(text); }
	};
	template<> class answer<false> final{
		const char *peek()const{ return nullptr; }
		const char *peek(int)const{ return nullptr; }
		int insert(const char *text)const{ return -1; }
	};
}