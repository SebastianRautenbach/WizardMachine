#pragma once
#include "vec.h"

namespace wizmcore {
	namespace math {
		template<typename T>
		class quat {
		public:
			vec<T, 4> values;

		public:
			quat() default;

			quat(T x, T y, T z, T w) {
				values[0] = x;
				values[1] = y;
				values[2] = z;
				values[3] = w;
			}

			quat(vec<T, 4> const& v) 
				: values(v) { }



		};
	}
}
