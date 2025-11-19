#pragma once
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include <cmath>
#include <limits>

namespace wizmcore {
	namespace math {

		template<typename T>
		constexpr vec4<T> normalize(vec4<T> const& v) {
			return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
		}
		template<typename T>
		constexpr vec3<T> normalize(vec3<T> const& v) {
			return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		}
		template<typename T>
		constexpr vec2<T> normalize(vec2<T> const& v) {
			return std::sqrt(v.x * v.x + v.y * v.y);
		}

		template<typename T>
		inline constexpr T radians(T degrees) {
			assert(std::numeric_limits<T>::is_iec559, "'radians' only accept floating-point input");
			return degrees * static_cast<T>(0.01745329251994329576923690768489);
		}



		template<typename T>
		constexpr vec3<T> cross(vec3<T> const& x, const vec3<T> const& y) {
			assert(std::numeric_limits<T>::is_iec559, "'cross' accepts only floating-point inputs");

			return vec3<T>(
				x.y * y.z - y.y * x.z,
				x.z * y.x - y.z * x.x,
				x.x * y.y - y.x * x.y);
		}

		template<typename T>
		constexpr T dot(vec3<T> const& x, const vec3<T> const& y) {
			return T((x.x * y.x) + (x.y * y.y) + (x.z * y.z));			
		}

	}
}

