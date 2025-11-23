#pragma once
#include <limits>


namespace wizmcore {
	namespace math {


		template<typename genType>
		inline constexpr genType epsilon()
		{
			assert(std::numeric_limits<genType>::is_iec559, "'epsilon' only accepts floating-point inputs");
			return std::numeric_limits<genType>::epsilon();
		}


	}
}