#pragma once
#include <cassert>

namespace wizmcore {
	namespace math {

		template<template<typename T, uint16_t L> class vec, uint16_t L, typename R, typename T>
		struct functor1 {};

		template<template<typename T, uint16_t L> class vec, typename R, typename T>
		struct functor1<vec, 1, R, T>
		{
			inline constexpr static vec<R, 1> call(R(*Func) (T x), vec<T, 1> const& v)
			{
				return vec<R, 1>(Func(v.x));
			}
		};
		template<template<typename T, uint16_t L> class vec, typename R, typename T>
		struct functor1<vec, 2, R, T>
		{
			inline constexpr static vec<R, 2> call(R(*Func) (T x), vec<T, 2> const& v)
			{
				return vec<R, 2>(Func(v.x));
			}
		};
		template<template<typename T, uint16_t L> class vec, typename R, typename T>
		struct functor1<vec, 3, R, T>
		{
			inline constexpr static vec<R, 3> call(R(*Func) (T x), vec<T, 3> const& v)
			{
				return vec<R, 3>(Func(v.x));
			}
		};
		template<template<typename T, uint16_t L> class vec, typename R, typename T>
		struct functor1<vec, 4, R, T>
		{
			inline constexpr static vec<R, 4> call(R(*Func) (T x), vec<T, 4> const& v)
			{
				return vec<R, 4>(Func(v.x));
			}
		};
	}
}
