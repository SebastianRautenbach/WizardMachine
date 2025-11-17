#pragma once
#include "quat.h"
#include ""

namespace core {
	namespace math {

		template<typename T>
		void normalie(quat<T>& q) {
			float l = q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z;
			float f = 1.f / sqrt(l);
			
			q.x = q.x * f;
			q.y = q.y * f;
			q.z = q.z * f;
			q.w = q.w * f;

		}

		to_rotation_matrix
	}
}