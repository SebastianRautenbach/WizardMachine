#pragma once
#include "vec2.h"
#include <limits>
#include <cstddef>
#include <cassert>
#include <cstdint>


namespace wizmcore {
	namespace math {

		template<typename T>
		class mat2 {
		private:
			typedef vec2<T> col_type;
			typedef uint16_t length_type;
			static constexpr length_type length() { return 3; }

		public:
			col_type value[2];

		public:

			constexpr mat2() = default;

			mat2(mat2<T> const& m)
				: value{ col_type(m[0]), col_type(m[1]) }
			{
			}

			mat2(
				T const& x0, T const& y0,
				T const& x1, T const& y1)
				: value{
					col_type(x0, y0),
					col_type(x1, y1)}
			{
			}

			mat2(T s)
				: value{ col_type(s, 0), col_type(0, s)}
			{
			}

			mat2(
				col_type const& v0,
				col_type const& v1)
				: value{ col_type(v0), col_type(v1)}
			{
			}

			template<
				typename X1, typename Y1,
				typename X2, typename Y2>
			constexpr mat2(
				X1 const& x1, Y1 const& y1,
				X2 const& x2, Y2 const& y2)
				: value{ col_type(x1, y1), col_type(x2, y2)}
			{
			}


			template<typename U>
			constexpr mat2<T>& operator=(mat2<U> const& m)
			{
				this->value[0] = m[0];
				this->value[1] = m[1];
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

			constexpr mat2 operator-() const {
				return mat2<T>(
					-value[0], -value[1]
				);
			}

			constexpr mat2 operator+(const mat2& m) {

			}
			constexpr mat2 operator-(const mat2& m) {

			}


			constexpr mat2 operator*(T scaler) {

			}
			constexpr mat2 operator/(T scaler) {

			}


			constexpr col_type operator*(col_type const& v) const {

			}
			constexpr mat2 operator*(mat2 const& m) const {

			}

		};




	};
}