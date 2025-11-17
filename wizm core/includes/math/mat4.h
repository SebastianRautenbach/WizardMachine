#pragma once
#include "vec4.h"
#include <limits>
#include <cstddef>
#include <cassert>
#include <cstdint>


namespace core {
	namespace math{
	
		template<typename T>
		class mat4 {
		private:
			typedef vec4<T> col_type;	
			typedef uint16_t length_type;
			static constexpr length_type length() { return 4; }

		public:
			col_type value[4];

		public:

			constexpr mat4() = default;

			mat4(mat4<T> const& m)
				: value{ col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3]) }
			{}

			mat4(
				T const& x0, T const& y0, T const& z0, T const& w0,
				T const& x1, T const& y1, T const& z1, T const& w1,
				T const& x2, T const& y2, T const& z2, T const& w2,
				T const& x3, T const& y3, T const& z3, T const& w3) 
				: value{
					col_type(x0, y0, z0, w0),
					col_type(x1, y1, z1, w1),
					col_type(x2, y2, z2, w2),
					col_type(x3, y3, z3, w3) }
			{
			}

			mat4(T s)
				: value{ col_type(s, 0, 0, 0), col_type(0, s, 0, 0), col_type(0, 0, s, 0), col_type(0, 0, 0, s) }
			{}

			mat4(
				col_type const& v0,
				col_type const& v1,
				col_type const& v2,
				col_type const& v3) 
				: value{ col_type(v0), col_type(v1), col_type(v2), col_type(v3) }
			{}

			template<
				typename X1, typename Y1, typename Z1, typename W1,
				typename X2, typename Y2, typename Z2, typename W2,
				typename X3, typename Y3, typename Z3, typename W3,
				typename X4, typename Y4, typename Z4, typename W4>
			constexpr mat4(
				X1 const& x1, Y1 const& y1, Z1 const& z1, W1 const& w1,
				X2 const& x2, Y2 const& y2, Z2 const& z2, W2 const& w2,
				X3 const& x3, Y3 const& y3, Z3 const& z3, W3 const& w3,
				X4 const& x4, Y4 const& y4, Z4 const& z4, W4 const& w4) 
				: value{ col_type(x1, y1, z1, w1), col_type(x2, y2, z2, w2), col_type(x3, y3, z3, w3), col_type(x4, y4, z4, w4) }
			{}

			
			template<typename U>
			constexpr mat4<T>& operator=(mat4<U> const& m)
			{				
				this->value[0] = m[0];
				this->value[1] = m[1];
				this->value[2] = m[2];
				this->value[3] = m[3];
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
			
			constexpr mat4 operator-() const {							
				return mat4(
					-value[0], -value[1], -value[2], -value[3]
				);
			}
			
			constexpr mat4 operator+(const mat4& m) {
			
			}
			constexpr mat4 operator-(const mat4& m) {
			
			}
			
			
			constexpr mat4 operator*(T scaler) {
			
			}
			constexpr mat4 operator/(T scaler) {
			
			}


			constexpr col_type operator*(col_type const& v) const {
			
			}
			constexpr mat4 operator*(mat4 const& m) const {
			
			}

		};	
		

		

	};
}