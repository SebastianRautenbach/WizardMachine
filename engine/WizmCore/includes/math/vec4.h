#pragma once
#include "vec.h"


namespace wizmcore {
	namespace math {

		template<typename T>
		class vec<T, 4> {

		private:
			const static uint16_t length = 3;

		public:
			T x, y, z, w;

		public:
			vec<T, 4>() = default;

			vec<T, 4>(T _x) {
				x = y = z = w = _x;
			}
			vec<T, 4>(T _x, T _y, T _z, T _w) {
				x = _x;
				y = _y;
				z = _z;
				w = _w;
			}

			constexpr bool operator==(vec<T, 4> const& v) {
				return (v.x == x &&
					v.y == y &&
					v.z == z && 
					v.w == w
					);
			}


			constexpr bool operator!=(vec<T, 4> const& v) {
				return !(v.x == x &&
					v.y == y &&
					v.z == z &&
					v.w == w
					);
			}


			constexpr void operator+=(vec<T, 4> const& v) {
				this->x += v.x;
				this->y += v.y;
				this->z += v.z;
				this->w += v.w;
			}

			constexpr void operator-=(vec<T, 4> const& v) {
				this->x -= v.x;
				this->y -= v.y;
				this->z -= v.z;
				this->w -= v.w;
			}

			constexpr void operator*=(vec<T, 4> const& v) {
				this->x *= v.x;
				this->y *= v.y;
				this->z *= v.z;
				this->w *= v.w;
			}


			constexpr void operator/=(vec<T, 4> const& v) {
				this->x /= v.x;
				this->y /= v.y;
				this->z /= v.z;
				this->w /= v.w;
			}

			constexpr vec<T, 4> operator+(vec<T, 4> const& v) {
				return vec<T, 4>(this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w);
			}

			constexpr vec<T, 4> operator-(vec<T, 4> const& v) {
				return vec<T, 4>(this->x - v.x, this->y - v.y, this->z - v.z, this->w - v.w );
			}

			constexpr vec<T, 4> operator/(vec<T, 4> const& v) {
				return vec<T, 4>(this->x / v.x, this->y / v.y, this->z / v.z, this->w / v.w);
			}

			
			constexpr vec<T, 4> operator*(vec<T, 4> const& v) const {
				return vec<T, 4>(this->x * v.x, this->y * v.y, this->z * v.z, this->w * v.w);
			}
			
			
			constexpr vec<T, 4> operator*(vec<T, 4> const& v) {
				return vec<T, 4>(this->x * v.x, this->y * v.y, this->z * v.z, this->w * v.w);
			}

			constexpr vec<T, 4> operator*(T s) const {
				return vec<T, 4>(this->x * s, this->y * s, this->z * s, this->w * s);
			}

			constexpr vec<T, 4> operator/(T const s) {
				return vec<T, 4>(this->x / s, this->y / s, this->z / s, this->w / s);
			}

			constexpr T& operator[](uint16_t i) {
				if (i > length) {/* ERROR*/ throw "cant do this shit"; }
				return (&x)[i];
			}

			constexpr T const& operator[](uint16_t i) const {
				if (i > length) {/* ERROR*/ throw "cant do this shit"; }
				return (&x)[i];
			}
		};
	}
}
