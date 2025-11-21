#pragma once
#include "vec2.h"
#include "func_common.h"

namespace wizmcore {
	namespace math {


		template<typename T>
		inline constexpr vec2<T> abs(vec2<T> const& x)
		{
			return vec2<T>(abs(x.x), abs(x.y));
		}

	

		template<typename T>
		inline constexpr vec2<T> equal(vec2<T> const& x, vec2<T> const& y, T epsilon)
		{
			return lessThanEqual(abs(x - y), vec2<T>(epsilon));
		}

		template<typename T>
		inline constexpr bool all(vec2<T> const& v)
		{
			bool Result = true;
			for (uint16_t i = 0; i < v.length(); ++i)
				Result = Result && v[i];
			return Result;
		}

		template<typename T>
		inline vec2<T> lessThanEqual(vec2<T> const& x, vec2<T> const& y)
		{
			vec2<T> Result(T(true));
			for (uint16_t i = 0; i < x.length(); ++i)
				Result[i] = x[i] <= y[i];
			return Result;
		}
	}
}

