#pragma once
#include <cmath>

namespace wizmcore {
	namespace math {
		template<typename genType>
		inline genType inversesqrt(genType x)
		{
			return static_cast<genType>(1) / sqrt(x);
		}
	}
}
