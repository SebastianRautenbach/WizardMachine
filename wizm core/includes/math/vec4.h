#pragma once

namespace core {

	namespace math {
		template<typename T>
		class vec4 {
		public:
			T x, y, z, w;

		public:

			vec4() : x(0), y(0), z(0), w(0) {}
			vec4(T v) : x(v), y(v), z(v), w(v) {}
			vec4(T v1, T v2, T v3, T v4) : x(v1), y(v2), z(v3), w(v4) {}

			vec4& operator=(const vec4& v) {
				x = v.x;
				y = v.y;
				z = v.z;
				w = v.w;
				return *this;
			}


			vec4& operator*=(const vec4& v) {
				x *= v.x;
				y *= v.y;
				z *= v.z;
				w *= v.w;
				return *this;
			}

			vec4 operator-() {
				return vec4(-x, -y, -z, -w);
			}

			vec4& operator/=(const vec4& v) {
				x /= v.x;
				y /= v.y;
				z /= v.z;
				w /= v.w;
				return *this;
			}
			vec4& operator+=(const vec4& v) {
				x += v.x;
				y += v.y;
				z += v.z;
				w += v.w;
				return *this;
			}
			vec4& operator-=(const vec4& v) {
				x -= v.x;
				y -= v.y;
				z -= v.z;
				w -= v.w;
				return *this;
			}
			vec4 operator+(const vec4& v) {
				return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
			}
			vec4 operator-(const vec4& v) {
				return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
			}
			vec4 operator/(const vec4& v) {
				return vec4(x / v.x, y / v.y, z / v.z, w / v.w);
			}
			vec4 operator*(const vec4& v) {
				return vec4(x * v.x, y * v.y, z * v.z, w * v.w);
			}

		};
	}
}