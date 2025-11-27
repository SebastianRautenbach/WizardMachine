#pragma once
#include "vec3.h"
#include <cmath>
#include "func_trig.h"

namespace wizmcore {
	namespace math {
		
		
		template<typename T>
		class quat {
		
		public:
			T x, y, z, w;

		public:
			typedef uint16_t length_type;			
			static constexpr length_type length() { return 4; }

		public:
			constexpr T& operator[](length_type i) {
				assert(i >= 0 && i < this->length());
				return (&x)[i];
			}
			constexpr T const& operator[](length_type i) const {
				assert(i >= 0 && i < this->length());
				return (&x)[i];
			}
			constexpr quat<T>& operator=(quat<T> const& q) = default;
			template<typename U>
			constexpr quat<T>& operator=(quat<U> const& q) {
				this->w = static_cast<T>(q.w);
				this->x = static_cast<T>(q.x);
				this->y = static_cast<T>(q.y);
				this->z = static_cast<T>(q.z);
				return *this;
			}
			 
			constexpr quat<T> operator*(float f) const {
				return quat<T>(
					w * f,
					x * f,
					y * f,
					z * f
				);
			}

			constexpr quat<T> operator+(const quat<T>& q) const {
				return quat<T>(
					x + q.x,
					y + q.y,
					z + q.z,
					w + q.w
				);
			}
			constexpr quat<T> operator-(const quat<T>& q) const {
				return quat<T>(
					x - q.x,
					y - q.y,
					z - q.z,
					w - q.w
					);
			}

			constexpr quat<T> operator*(const quat<T>& q) const {
				return quat<T>(
					w * q.w - x * q.x - y * q.y - z * q.z,
					w * q.x + x * q.w + y * q.z - z * q.y,
					w * q.y + y * q.w + z * q.x - x * q.z,
					w * q.z + z * q.w + x * q.y - y * q.x
					);
			}
	

		public:
			constexpr quat() = default;
			
			constexpr quat(T v) 
				: x(v), y(v), z(v), w(v)
			{}

			constexpr quat(vec3<T> eulerAngle)
			{
			
				vec3<T> c = cos(eulerAngle * T(0.5));
				vec3<T> s = sin(eulerAngle * T(0.5));

				this->w = c.x * c.y * c.z + s.x * s.y * s.z;
				this->x = s.x * c.y * c.z - c.x * s.y * s.z;
				this->y = c.x * s.y * c.z + s.x * c.y * s.z;
				this->z = c.x * c.y * s.z - s.x * s.y * c.z;
			}

			constexpr quat(T v0, T v1, T v2, T v3) 
				: x(v0), y(v1), z(v2), w(v3)
			{}

			constexpr quat(const quat& q) {
				x = q.x;
				y = q.y;
				z = q.z;
				w = q.w;
			}
		};
	}
}