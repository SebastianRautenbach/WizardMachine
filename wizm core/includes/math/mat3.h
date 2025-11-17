#pragma once
#include "vec3.h"
#include <limits>
#include <cstddef>
#include <cassert>
#include <cstdint>


namespace core {
	namespace math {

		template<typename T>
		class mat3 {
		private:
			typedef vec3<T> col_type;
			typedef uint16_t length_type;
			static constexpr length_type length() { return 3; }

		public:
			col_type value[3];

		public:

			constexpr mat3() = default;

			mat3(mat3<T> const& m)
				: value{ col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3]) }
			{
			}

			mat3(
				T const& x0, T const& y0, T const& z0,
				T const& x1, T const& y1, T const& z1,
				T const& x2, T const& y2, T const& z2)
				: value{
					col_type(x0, y0, z0),
					col_type(x1, y1, z1),
					col_type(x2, y2, z2)}
			{
			}

			mat3(T s)
				: value{ col_type(s, 0, 0), col_type(0, s, 0), col_type(0, 0, s) }
			{
			}

			mat3(
				col_type const& v0,
				col_type const& v1,
				col_type const& v2)
				: value{ col_type(v0), col_type(v1), col_type(v2)}
			{
			}

			template<
				typename X1, typename Y1, typename Z1,
				typename X2, typename Y2, typename Z2,
				typename X3, typename Y3, typename Z3>
			constexpr mat3(
				X1 const& x1, Y1 const& y1, Z1 const& z1,
				X2 const& x2, Y2 const& y2, Z2 const& z2,
				X3 const& x3, Y3 const& y3, Z3 const& z3)
				: value{ col_type(x1, y1, z1), col_type(x2, y2, z2), col_type(x3, y3, z3)}
			{
			}


			template<typename U>
			constexpr mat3<T>& operator=(mat3<U> const& m)
			{
				this->value[0] = m[0];
				this->value[1] = m[1];
				this->value[2] = m[2];				
				return *this;
			}


			constexpr col_type& operator[](length_type i) noexcept {
				assert(i < this->length());
				return this->value[i];
			}
			constexpr col_type const& operator[](length_type i) const noexcept {
				assert(i < this->length());
				return this->value[i];
			}

			constexpr mat3 operator-() const {
				return mat3(
					-value[0], -value[1], -value[2]
				);
			}

			constexpr mat3 operator+(const mat3& m) {

			}
			constexpr mat3 operator-(const mat3& m) {

			}


			constexpr mat3 operator*(T scaler) {

			}
			constexpr mat3 operator/(T scaler) {

			}


			constexpr col_type operator*(col_type const& v) const {

			}
			constexpr mat3 operator*(mat3 const& m) const {

			}

		};




	};
}