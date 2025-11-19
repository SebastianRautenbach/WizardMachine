#pragma once
#include <cassert>
#include <stdint.h>


namespace wizmcore {

	namespace math {
		template<typename T>
		class vec3 {
		public:
			T x, y, z;

		public:
			typedef uint16_t length_type;
			static constexpr length_type length() { return 3; }

		public:

			vec3() : x(0), y(0), z(0) {}
			vec3(T v) : x(v), y(v), z(v) {}
			vec3(T v1, T v2, T v3) : x(v1), y(v2), z(v3) {}

			constexpr vec3<T>& operator=(const vec3& v) {
				x = v.x;
				y = v.y;
				z = v.z;
				return *this;
			}
			constexpr vec3<T>& operator*=(const vec3& v) {
				x *= v.x;
				y *= v.y;
				z *= v.z;
				return *this;
			}
			constexpr vec3<T>& operator/=(const vec3& v) {
				x /= v.x;
				y /= v.y;
				z /= v.z;
				return *this;
			}
			constexpr vec3<T>& operator+=(const vec3<T>& v) {
				x += v.x;
				y += v.y;
				z += v.z;
				return *this;
			}
			constexpr vec3<T>& operator-=(const vec3<T>& v) {
				x -= v.x;
				y -= v.y;
				z -= v.z;
				return *this;
			}
			constexpr vec3<T> operator+(const vec3<T>& v) {
				return vec3<T>(x + v.x, y + v.y, z + v.z);
			}

			constexpr vec3<T> operator-() {
				return vec3<T>(
					-x,
					-y,
					-z);
			}

			constexpr vec3<T> operator-(const vec3<T>& v) const {
				return vec3<T>(
					x-v.x,
					y-v.y,
					z-v.z);
			}


			constexpr vec3<T> operator/(const vec3& v) {
				return vec3<T>(x / v.x, y / v.y, z / v.z);
			}
			constexpr vec3<T> operator*(const vec3<T>& v) {
				return vec3<T>(x * v.x, y * v.y, z * v.z);
			}
			constexpr vec3<T> operator*(const T s) {
				return vec3<T>(x * s, y * s, z * s);
			}

			constexpr T& operator[](length_type i) {
				assert(i >= 0 && i < this->length());
				return (&x)[i];
			}
			constexpr T const& operator[](length_type i) const {
				assert(i >= 0 && i < this->length());
				return (&x)[i];
			}
		};
	}

	
}