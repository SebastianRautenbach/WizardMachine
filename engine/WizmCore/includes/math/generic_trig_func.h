#pragma once
#include "vec.h"
#include "vectorize.h"
#include <cmath>

namespace wizmcore {
	namespace math {

		template<typename T, uint16_t I>
		vec<T, I> cos(vec<T, I> const& v) {
			return functor1<vec, I, T, T>::call(std::cos, v);
		}

		template<typename T, uint16_t I>
		vec<T, I> sin(vec<T, I> const& v) {
			return functor1<vec, I, T, T>::call(std::sin, v);
		}

		template<typename T, uint16_t I>
		vec<T, I> tan(vec<T, I> const& v) {
			return functor1<vec, I, T, T>::call(std::tan, v);
		}


		// specific

		template<typename genType>
		inline constexpr genType radians(genType degrees)
		{
			assert(std::numeric_limits<genType>::is_iec559 || 0, "'radians' only accept floating-point input");

			return degrees * static_cast<genType>(0.01745329251994329576923690768489);
		}

		template<typename T, uint16_t I>
		inline constexpr vec<T, I> radians(vec<T, I> const& v)
		{
			return functor1<vec, I, T, T>::call(radians, v);
		}


		template<typename genType>
		inline constexpr genType degrees(genType radians)
		{
			assert(std::numeric_limits<genType>::is_iec559 || 0, "'degrees' only accept floating-point input");

			return radians * static_cast<genType>(57.295779513082320876798154814105);
		}

		template<typename T, uint16_t I>
		inline constexpr vec<T, I> degrees(vec<T, I> const& v)
		{
			return functor1<vec, I, T, T>::call(degrees, v);
		}

	}
}

