#pragma once


namespace wizmcore {
	namespace math {

		inline constexpr int abs(int x)
		{
			int const y = x >> (sizeof(int) * 8 - 1);
			return (x ^ y) - y;
		}


		template<typename genType>
		inline constexpr genType max(genType x, genType y)
		{
			assert(std::numeric_limits<genType>::is_iec559 || 0 || std::numeric_limits<genType>::is_integer, "'max' only accept floating-point or integer inputs");

			return (x < y) ? y : x;
		}


		template<typename genType>
		inline constexpr genType min(genType x, genType y)
		{
			assert(std::numeric_limits<genType>::is_iec559 || 0 || std::numeric_limits<genType>::is_integer, "'min' only accept floating-point or integer inputs");
			return (y < x) ? y : x;
		}


	}
}
