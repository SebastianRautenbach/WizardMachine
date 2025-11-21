#pragma once
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include <cmath>
#include <limits>
#include "mathcontext.h"
#include "func_exponential.h"




namespace wizmcore {
	namespace math {

		template<typename T>
		constexpr vec2<T> normalize(vec2<T> const& v) {
			return std::sqrt(v.x * v.x + v.y * v.y);
		}
		template<typename T>
		constexpr vec3<T> normalize(vec3<T> const& v) {
			return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		}
		template<typename T>
		constexpr vec4<T> normalize(vec4<T> const& v) {
			return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
		}


		template<length_t L, typename T, bool Aligned>
		struct compute_normalize
		{
			inline static vec2<T> call(vec2<T> const& v)
			{
				assert(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");
				return v * inversesqrt(dot(v, v));
			}
			inline static vec3<T> call(vec3<T> const& v)
			{
				assert(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");
				return v * inversesqrt(dot(v, v));
			}
			inline static vec4<T> call(vec4<T> const& v)
			{
				assert(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");
				return v * inversesqrt(dot(v, v));
			}
		};

		

		// dot
		template<typename T>
		inline constexpr T dot(T x, T y)
		{
			assert(std::numeric_limits<T>::is_iec559, "'dot' accepts only floating-point inputs");
			return x * y;
		}









		template<typename T>
		inline constexpr T radians(T degrees) {
			assert(std::numeric_limits<T>::is_iec559, "'radians' only accept floating-point input");
			return degrees * static_cast<T>(0.01745329251994329576923690768489);
		}

		

		template<typename genType>
		inline constexpr genType clamp(genType x, genType minVal, genType maxVal)
		{
			assert(std::numeric_limits<genType>::is_iec559 || 0 || std::numeric_limits<genType>::is_integer, "'clamp' only accept floating-point or integer inputs");
			return min(max(x, minVal), maxVal);
		}









		template<typename T>
		constexpr vec2<T> cross(vec2<T> const& x, const vec2<T> const& y) {
			assert(std::numeric_limits<T>::is_iec559, "'cross' accepts only floating-point inputs");

			return vec2<T>(
				x.y * y.z - y.y * x.z,
				x.z * y.x - y.z * x.x);
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
		constexpr vec4<T> cross(vec4<T> const& x, const vec4<T> const& y) {
			assert(std::numeric_limits<T>::is_iec559, "'cross' accepts only floating-point inputs");

			return vec4<T>(
				x.y * y.z - y.y * x.z,
				x.z * y.x - y.z * x.x,
				x.x * y.y - y.x * x.y,
				x.w * y.w - y.w * x.w
			);
		}








		template<typename T>
		constexpr T dot(vec2<T> const& x, const vec2<T> const& y) {
			return T((x.x * y.x) + (x.y * y.y));
		}
		template<typename T>
		constexpr T dot(vec3<T> const& x, const vec3<T> const& y) {
			return T((x.x * y.x) + (x.y * y.y) + (x.z * y.z));			
		}
		template<typename T>
		constexpr T dot(vec4<T> const& x, const vec4<T> const& y) {
			return T((x.x * y.x) + (x.y * y.y) + (x.z * y.z) + (x.w * y.w));
		}


	}
}

