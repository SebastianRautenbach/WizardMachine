#pragma once
#include "vec.h"

namespace wizmcore {
	namespace math {
		template<typename T>
		class qua {
		public:
			vec<T, 4> values;

		public:
			quat() = default;

			qua(T x, T y, T z, T w) {
				values[0] = x;
				values[1] = y;
				values[2] = z;
				values[3] = w;
			}

			qua(vec<T, 4> const& v) 
				: values(v) { }

			qua operator+(qua const& q) const
			{
				return qua(values + q.values);
			}
			
			qua operator-(qua const& q) const
			{
				return qua(values - q.values);
			}
			
			qua operator*(qua const& q) const
			{
				return qua(
						values[3] * q.values[0] + values[0] * q.values[3] + values[1] * q.values[2] - values[2] * q.values[1],
						values[3] * q.values[1] + values[1] * q.values[3] + values[2] * q.values[0] - values[0] * q.values[2],
						values[3] * q.values[2] + values[2] * q.values[3] + values[0] * q.values[1] - values[1] * q.values[0], 
						values[3] * q.values[3] - values[0] * q.values[0] - values[1] * q.values[1] - values[2] * q.values[2]
					);
			}
			
			qua operator*(float s) const
			{
				return qua(
					values *= s	
				);
			}
			
		};
	}
}
