#pragma once
#include "vec.h"


namespace wizmcore {
	namespace math {

		template<typename T>
		class vec<T, 3> {

		private:
			const static uint16_t length = 3;


		public:
			T x, y, z;

		public:
			
			constexpr vec() = default;
			
			vec<T, 3>(T _x) {
				x = y = z = _x;
			}
			vec<T, 3>(T _x, T _y, T _z) {
				x = _x;
				y = _y;
				z = _z;
			}

			constexpr bool operator==(vec<T, 3> const& v) {
				return (v.x == x &&
						v.y == y &&
						v.z == z
					);
			}
			

			constexpr bool operator!=(vec<T, 3> const& v) {
				return !(v.x == x &&
					v.y == y &&
					v.z == z
					);
			}


			constexpr void operator+=(vec<T, 3> const& v) {
				this->x += v.x;
				this->y += v.y;
				this->z += v.z;
			}

			constexpr void operator-=(vec<T, 3> const& v) {
				this->x -= v.x;
				this->y -= v.y;
				this->z -= v.z;
			}

			constexpr void operator*=(vec<T, 3> const& v) {
				this->x *= v.x;
				this->y *= v.y;
				this->z *= v.z;
			}


			constexpr void operator/=(vec<T, 3> const& v) {
				this->x /= v.x;
				this->y /= v.y;
				this->z /= v.z;
			}


			constexpr vec<T, 3> operator+(vec<T, 3> const& v) {
				return vec<T, 3>(this->x + v.x, this->y + v.y, this->z + v.z);
			}
			constexpr vec<T, 3> operator+(vec<T, 3> const& v) const { 
				return vec<T, 3>(this->x + v.x, this->y + v.y, this->z + v.z);
			}

			constexpr vec<T, 3> operator-(vec<T, 3> const& v) {
				return vec<T, 3>(this->x - v.x, this->y - v.y, this->z - v.z);
			}
			constexpr vec<T, 3> operator-(vec<T, 3> const& v) const {
				return vec<T, 3>(this->x - v.x, this->y - v.y, this->z - v.z);
			}
			constexpr vec<T, 3> operator-() const {
				return vec<T, 3>(-this->x, -this->y, -this->z);
			}


			constexpr vec<T, 3> operator/(vec<T, 3> const& v) {
				return vec<T, 3>(this->x / v.x, this->y / v.y, this->z / v.z);
			}

			constexpr vec<T, 3> operator*(vec<T, 3> const& v) {
				return vec<T, 3>(this->x * v.x, this->y * v.y, this->z * v.z);
			}

			constexpr vec<T, 3> operator*(vec<T, 3> const& v) const {
				return vec<T, 3>(this->x * v.x, this->y * v.y, this->z * v.z);
			}

			constexpr vec<T, 3> operator*(T const s) {
				return vec<T, 3>(this->x * s, this->y * s, this->z * s);
			}

			constexpr vec<T, 3> operator*(T const s) const {
				return vec<T, 3>(this->x * s, this->y * s, this->z * s);
			}

			constexpr vec<T, 3> operator/(T const s) {
				return vec<T, 3>(this->x / s, this->y / s, this->z / s);
			}

			constexpr T operator[](uint16_t i) {
				if (i > length) {/* ERROR*/ throw "cant do this shit"; }
				return (&x)[i];
			}
		};
	}
}
