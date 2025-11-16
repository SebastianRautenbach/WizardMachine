#pragma once

namespace core {

	namespace math {
		template<typename T>
		class vec2 {
		public:
			T x, y;

		public:

			vec2() : x(0), y(0) {}
			vec2(T v) : x(v), y(v) {}
			vec2(T v1, T v2) : x(v1), y(v2) {}

			vec2& operator=(const vec2& v) {
				x = v.x;
				y = v.y;
				return *this;
			}
			vec2& operator*=(const vec2& v) {
				x *= v.x;
				y *= v.y;
				return *this;
			}
			vec2& operator/=(const vec2& v) {
				x /= v.x;
				y /= v.y;
				return *this;
			}
			vec2& operator+=(const vec2& v) {
				x += v.x;
				y += v.y;
				return *this;
			}
			vec2& operator-=(const vec2& v) {
				x -= v.x;
				y -= v.y;
				return *this;
			}
			vec2 operator+(const vec2& v) {
				return vec2(x + v.x, y + v.y);
			}
			vec2 operator-(const vec2& v) {
				return vec2(x - v.x, y - v.y);
			}
			vec2 operator/(const vec2& v) {
				return vec2(x / v.x, y / v.y);
			}
			vec2 operator*(const vec2& v) {
				return vec2(x * v.x, y * v.y);
			}

		};
	}
}