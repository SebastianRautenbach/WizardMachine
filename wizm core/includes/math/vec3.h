#pragma once

namespace core {


	template<typename T>
	class vec3 {
	public:
		T x, y, z;

	public:

		vec3() : x(0), y(0), z(0) {}
		vec3(T v) : x(v), y(v), z(v) {}
		vec3(T v1, T v2, T v3) : x(v1), y(v2), z(v3) {}

		vec3& operator=(const vec3& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}
		vec3& operator*=(const vec3& v) {
			x *= v.x;
			y *= v.y;
			z *= v.z;
			return *this;
		}
		vec3& operator/=(const vec3& v) {
			x /= v.x;
			y /= v.y;
			z /= v.z;
			return *this;
		}
		vec3& operator+=(const vec3& v) {
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		vec3& operator-=(const vec3& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		vec3 operator+(const vec3& v) {
			return vec3(x + v.x, y + v.y, z + v.z);
		}
		vec3 operator-(const vec3& v) {
			return vec3(x - v.x, y - v.y, z - v.z);
		}
		vec3 operator/(const vec3& v) {
			return vec3(x / v.x, y / v.y, z / v.z);
		}
		vec3 operator*(const vec3& v) {
			return vec3(x * v.x, y * v.y, z * v.z);
		}

	};
}