namespace STM{
	
template <class T>
	struct vec2_generic
	{
		T x = 0;
		T y = 0;
		inline vec2_generic() : x(0), y(0) {                                                      }
		inline vec2_generic(T _x, T _y) : x(_x), y(_y) {                                                      }
		inline vec2_generic(const vec2_generic& v) : x(v.x), y(v.y) {                                                      }
		inline T mag() { return sqrt(x * x + y * y); }
		inline T mag2() { return x * x + y * y; }
		inline vec2_generic  norm() { T r = 1 / mag(); return vec2_generic(x*r, y*r); }
		inline vec2_generic  perp() { return vec2_generic(-y, x); }
		inline T dot(const vec2_generic& rhs) { return this->x * rhs.x + this->y * rhs.y; }
		inline T cross(const vec2_generic& rhs) { return this->x * rhs.y - this->y * rhs.x; }
		inline vec2_generic  operator +  (const vec2_generic& rhs) const { return vec2_generic(this->x + rhs.x, this->y + rhs.y); }
		inline vec2_generic  operator -  (const vec2_generic& rhs) const { return vec2_generic(this->x - rhs.x, this->y - rhs.y); }
		inline vec2_generic  operator *  (const T& rhs)           const { return vec2_generic(this->x * rhs, this->y * rhs); }
		inline vec2_generic  operator /  (const T& rhs)           const { return vec2_generic(this->x / rhs, this->y / rhs); }
		inline vec2_generic& operator += (const vec2_generic& rhs) { this->x += rhs.x; this->y += rhs.y; return *this; }
		inline vec2_generic& operator -= (const vec2_generic& rhs) { this->x -= rhs.x; this->y -= rhs.y; return *this; }
		inline vec2_generic& operator *= (const T& rhs) { this->x *= rhs; this->y *= rhs; return *this; }
		inline vec2_generic& operator /= (const T& rhs) { this->x /= rhs; this->y /= rhs; return *this; }
		inline T& operator [] (std::size_t i) { return *((T*)this + i);	   /* <-- D'oh :( */ }
	};
	template<class T> inline vec2_generic<T> operator * (const float& lhs, const vec2_generic<T>& rhs) { return vec2_generic<T>(lhs * rhs.x, lhs * rhs.y); }
	template<class T> inline vec2_generic<T> operator * (const double& lhs, const vec2_generic<T>& rhs) { return vec2_generic<T>(lhs * rhs.x, lhs * rhs.y); }
	template<class T> inline vec2_generic<T> operator * (const int& lhs, const vec2_generic<T>& rhs) { return vec2_generic<T>(lhs * rhs.x, lhs * rhs.y); }
	template<class T> inline vec2_generic<T> operator / (const float& lhs, const vec2_generic<T>& rhs) { return vec2_generic<T>(lhs / rhs.x, lhs / rhs.y); }
	template<class T> inline vec2_generic<T> operator / (const double& lhs, const vec2_generic<T>& rhs) { return vec2_generic<T>(lhs / rhs.x, lhs / rhs.y); }
	template<class T> inline vec2_generic<T> operator / (const int& lhs, const vec2_generic<T>& rhs) { return vec2_generic<T>(lhs / rhs.x, lhs / rhs.y); }

	typedef vec2_generic<int> vi2d;
	typedef vec2_generic<float> vf2d;
	typedef vec2_generic<double> vd2d;
}
