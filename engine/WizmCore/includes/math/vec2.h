#pragma once
#include "vec.h"


namespace wizmcore {
	namespace math {

		template<typename T>
		class vec<T, 2> {
		private:
			const static uint16_t length = 2;
		
		public:
			T x, y;

		public:
			
			constexpr vec() = default;
			
			vec<T, 2>(T _x) {
				x = y = _x;
			}
			vec<T, 2>(T _x, T _y) {
				x = _x;
				y = _y;
			}

			constexpr bool operator==(vec<T, 2> const& v) {
				return (v.x == x &&
					v.y == y);
			}


			constexpr bool operator!=(vec<T, 2> const& v) {
				return !(v.x == x && v.y == y					
					);
			}


			constexpr void operator+=(vec<T, 2> const& v) {
				this->x += v.x;
				this->y += v.y;				
			}

			constexpr void operator-=(vec<T, 2> const& v) {
				this->x -= v.x;
				this->y -= v.y;
			}

			constexpr void operator*=(vec<T, 2> const& v) {
				this->x *= v.x;
				this->y *= v.y;
			}


			constexpr void operator/=(vec<T, 2> const& v) {
				this->x /= v.x;
				this->y /= v.y;
			}


			constexpr T operator[](uint16_t i) {
				if (i>length) {/* ERROR*/ throw "cant do this shit"; }
				return (&x)[i];
			}

			constexpr vec<T, 2> operator+(vec<T, 2> const& v) {
				return vec<T, 2>(this->x + v.x, this->y + v.y);
			}

			constexpr vec<T, 2> operator-(vec<T, 2> const& v) {
				return vec<T, 2>(this->x - v.x, this->y - v.y);
			}

			constexpr vec<T, 2> operator/(vec<T, 2> const& v) {
				return vec<T, 2>(this->x / v.x, this->y / v.y);
			}

			constexpr vec<T, 2> operator*(vec<T, 2> const& v) {
				return vec<T, 2>(this->x * v.x, this->y * v.y);
			}


			constexpr vec<T, 2> operator*(T const s) {
				return vec<T, 2>(this->x * s, this->y * s);
			}

			constexpr vec<T, 2> operator/(T const s) {
				return vec<T, 2>(this->x / s, this->y / s);
			}
		};
	}
}
