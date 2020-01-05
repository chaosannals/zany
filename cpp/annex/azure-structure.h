namespace aze{
	template<typename T> struct xyz;
	template<typename T> struct rgba;

	template<typename T> struct xyz{
		T x, y, z;
		xyz(const T &x, const T &y, const T &z) :x(x), y(y), z(z){}
		friend xyz operator+(const xyz &l, const xyz &r){ return xyz(l.x + r.x, l.y + r.y, l.z + r.z); }
		friend xyz operator-(const xyz &l, const xyz &r){ return xyz(l.x - r.x, l.y - r.y, l.z - r.z); }
		friend xyz operator*(const T &factor, const xyz &r){ return xyz(factor * r.x, factor * r.y, factor * r.z); }
		friend xyz operator*(const xyz &l, const T &factor){ return factor * l; }
	};

	template<typename T> struct rgba{
		T r, g, b, a;
		rgba(const T &r, const T &g, const T &b, const T &a) :r(r), g(g), b(b), a(a){}
		friend rgba operator+(const rgba &l, const rgba &r){ return rgba(l.r + r.r, l.g + r.g, l.b + r.b, l.a + r.a); }
		friend rgba operator-(const rgba &l, const rgba &r){ return rgba(l.r - r.r, l.g - r.g, l.b - r.b, l.a - r.a); }
		friend rgba operator*(const T &factor, const rgba &r){ return rgba(factor * r.r, factor * r.g, factor * r.b, factor * r.a); }
		friend rgba operator*(const rgba &l, const T &factor){ return factor * l; }
	};
}