#pragma once
#include "vec.h"
#include "mat.h"
#include "quat.h"

namespace wizmcore {
	namespace math {
		
		typedef vec<float, 2> vec2;
		typedef vec<float, 3> vec3;
		typedef vec<float, 4> vec4;
		
		typedef mat<float, 2, 2> mat2;
		typedef mat<float, 3, 3> mat3;
		typedef mat<float, 4, 4> mat4;
		
		typedef qua<float> quat;
	}
}