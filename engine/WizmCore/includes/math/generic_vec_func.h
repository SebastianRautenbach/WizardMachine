#pragma once
#include "vec.h"
#include "vectorize.h"
#include "generic_exp_func.h"
#include <limits>
#include <cmath>

namespace wizmcore {
	namespace math{

		template<typename V, typename T>
		struct compute_dot {};

		template<typename T>
		struct compute_dot<vec<T, 1>, T>
		{
			inline constexpr static T call(vec<T, 1> const& a, vec<T, 1> const& b)
			{
				return a.x * b.x;
			}
		};

		template<typename T>
		struct compute_dot<vec<T, 2>, T>
		{
			inline constexpr static T call(vec<T, 2> const& a, vec<T, 2> const& b)
			{
				vec<T, 2> tmp(a * b);
				return tmp.x + tmp.y;
			}
		};

		template<typename T>
		struct compute_dot<vec<T, 3>, T>
		{
			inline constexpr static T call(vec<T, 3> const& a, vec<T, 3> const& b)
			{
				vec<T, 3> tmp(a * b);
				return tmp.x + tmp.y + tmp.z;
			}
		};

		template<typename T>
		struct compute_dot<vec<T, 4>, T>
		{
			inline constexpr static T call(vec<T, 4> const& a, vec<T, 4> const& b)
			{
				vec<T, 4> tmp(a * b);
				return (tmp.x + tmp.y) + (tmp.z + tmp.w);
			}
		};

		template<typename T>
		inline constexpr T dot(T x, T y)
		{
			assert(std::numeric_limits<T>::is_iec559, "'dot' accepts only floating-point inputs");
			return x * y;
		}

		template<typename T, uint16_t I>
		inline constexpr T dot(vec<T, I> const& x, vec<T, I> const& y)
		{
			assert(std::numeric_limits<T>::is_iec559, "'dot' accepts only floating-point inputs");
			return compute_dot<vec<T, I>, T>::call(x, y);
		}

		template<typename T>
		struct compute_cross
		{
			inline constexpr static vec<T, 3> call(vec<T, 3> const& x, vec<T, 3> const& y)
			{
				assert(std::numeric_limits<T>::is_iec559, "'cross' accepts only floating-point inputs");

				return vec<T, 3>(
					x.y * y.z - y.y * x.z,
					x.z * y.x - y.z * x.x,
					x.x * y.y - y.x * x.y);
			}
		};

		template<typename T>
		inline  constexpr vec<T, 3> cross(vec<T, 3> const& x, vec<T, 3> const& y)
		{
			return compute_cross<T>::call(x, y);
		}

		template<typename T, uint16_t I>
		struct compute_normalize
		{
			inline static vec<T, I> call(vec<T, I> const& v)
			{
				assert(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");
				return v * inversesqrt(dot(v, v));
			}
		};
		
		template<typename T, uint16_t I>
		inline vec<T, I> normalize(vec<T, I> const& x)
		{
			assert(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");

			return compute_normalize<T, I>::call(x);
		}

		template<typename genType>
		inline genType length(genType x)
		{
			assert(std::numeric_limits<genType>::is_iec559, "'length' accepts only floating-point inputs");

			return abs(x);
		}

		template<typename T, uint16_t I>
		struct compute_length
		{
			inline static T call(vec<T, I> const& v)
			{
				return sqrt(dot(v, v));
			}
		};

		template<typename T, uint16_t I>
		inline T length(vec<T, I> const& v)
		{
			assert(std::numeric_limits<T>::is_iec559, "'length' accepts only floating-point inputs");

			return compute_length<T, I >::call(v);
		}

		template<typename T, uint16_t I>
		struct compute_distance {
			inline static T call(vec<T, I> const& p0, vec<T, I> const& p1)
			{
				return length(p1 - p0);
			}
		};

		// distance
		template<typename genType>
		inline genType distance(genType const& p0, genType const& p1)
		{
			assert(std::numeric_limits<genType>::is_iec559, "'distance' accepts only floating-point inputs");

			return length(p1 - p0);
		}

		template<typename T, uint16_t I>
		inline T distance(vec<T, I> const& p0, vec<T, I> const& p1)
		{
			return compute_distance<T, I >::call(p0, p1);
		}
	}

}
