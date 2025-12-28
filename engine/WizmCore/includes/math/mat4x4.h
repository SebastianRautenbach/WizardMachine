#pragma once
#include "mat.h"
#include "vec.h"

namespace wizmcore {
	namespace math {
	
		template<typename T>
		class mat<T, 4, 4> {
		
		public:
			 vec<T, 4> values[4];

		public:

			// constructors //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			mat<T, 4, 4>() = default;
			
			mat<T, 4, 4>(T s) {
				values[0] = vec<T, 4>(s);
				values[1] = vec<T, 4>(s);
				values[2] = vec<T, 4>(s);
				values[3] = vec<T, 4>(s);
			}

			mat<T, 4, 4>(
				vec<T, 4> v1,
				vec<T, 4> v2,
				vec<T, 4> v3,
				vec<T, 4> v4
			)
			{
				values[0] = v1;
				values[1] = v2;
				values[2] = v3;
				values[3] = v4;
			}

			// operator overloads ////////////////////////////////////////////////////////////////////////////////////////////////////////////



			constexpr mat<T, 4, 4> operator+(mat<T, 4, 4> const& m) {
				return mat<T, 4, 4>(
				this->values[0] + m.values[0],
				this->values[1] + m.values[1],
				this->values[2] + m.values[2],
				this->values[3] + m.values[3]
				);
			}
			constexpr mat<T, 4, 4> operator+(T s) {
				return mat<T, 4, 4>(
				this->values[0] + s,
				this->values[1] + s,
				this->values[2] + s,
				this->values[3] + s
					);
			}
			constexpr mat<T, 4, 4> operator-(mat<T, 4, 4> const& m) {
				return mat<T, 4, 4>(
				this->values[0] - m.values[0],
				this->values[1] - m.values[1],
				this->values[2] - m.values[2],
				this->values[3] - m.values[3]
					);
			}
			constexpr mat<T, 4, 4> operator-(T s) {
				return mat<T, 4, 4>(
				this->values[0] - s,
				this->values[1] - s,
				this->values[2] - s,
				this->values[3] - s
					);
			}
			constexpr mat<T, 4, 4> operator*(mat<T, 4, 4> const& m) {
				return mat<T, 4, 4>(
				this->values[0] * m.values[0],
				this->values[1] * m.values[1],
				this->values[2] * m.values[2],
				this->values[3] * m.values[3]
					);
			}
			constexpr mat<T, 4, 4> operator*(T s) {
				return mat<T, 4, 4>(
				this->values[0] * s,
				this->values[1] * s,
				this->values[2] * s,
				this->values[3] * s
					);
			}
			constexpr mat<T, 4, 4> operator/(mat<T, 4, 4> const& m) {
				return mat<T, 4, 4>(
				this->values[0] / m.values[0],
				this->values[1] / m.values[1],
				this->values[2] / m.values[2],
				this->values[3] / m.values[3]
					);
			}
			constexpr  mat<T, 4, 4> operator/(T s) {
				return mat<T, 4, 4>(
				this->values[0] / s,
				this->values[1] / s,
				this->values[2] / s,
				this->values[3] / s
					);
			}

			constexpr void operator+=(mat<T, 4, 4> const& m) {
				this->values[0] += m.values[0];
				this->values[1] += m.values[1];
				this->values[2] += m.values[2];
				this->values[3] += m.values[3];
			}

			constexpr void operator-=(mat<T, 4, 4> const& m) {
				this->values[0] -= m.values[0];
				this->values[1] -= m.values[1];
				this->values[2] -= m.values[2];
				this->values[3] -= m.values[3];
			}

			constexpr void operator*=(mat<T, 4, 4> const& m) {
				this->values[0] *= m.values[0];
				this->values[1] *= m.values[1];
				this->values[2] *= m.values[2];
				this->values[3] *= m.values[3];
			}

			constexpr void operator*=(T s) {
				this->values[0] *= s;
				this->values[1] *= s;
				this->values[2] *= s;
				this->values[3] *= s;
			}

			constexpr void operator/=(mat<T, 4, 4> const& m) {
				this->values[0] /= m.values[0];
				this->values[1] /= m.values[1];
				this->values[2] /= m.values[2];
				this->values[3] /= m.values[3];
			}

			constexpr void operator/=(T s) {
				this->values[0] /= s;
				this->values[1] /= s;
				this->values[2] /= s;
				this->values[3] /= s;
			}

			constexpr bool operator==(mat<T, 4, 4> const& m) {
				return (this->values[0] == m.values[0] &&
					this->values[1] == m.values[1] &&
					this->values[2] == m.values[2] &&
					this->values[3] == m.values[3]);
			}

			constexpr vec<T, 4>& operator[](uint16_t i) {
				return this->values[i];
			}

			constexpr vec<T, 4> const& operator[](uint16_t i) const {
				return this->values[i];
			}

		};
	}
}


