namespace aze{
	struct raw_senser;

	access<course, raw_senser> access_raw_senser(const char *description);

	struct raw_senser{
		virtual ~raw_senser(){}
		virtual void sense() = 0;
		virtual censor<source, bool> access_bool(const char *description) = 0;
		virtual censor<source, float> access_float(const char *description) = 0;
	};
}