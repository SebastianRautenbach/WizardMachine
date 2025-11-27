#pragma once
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

namespace wizmcore {
	namespace math {		
		template<typename T>
		vec3<T> v4ToV3(const vec4<T>& v) {
			return vec3<T>(v.x, v.y, v.z);
		}
		
		template<typename T>
		vec2<T> v4ToV2(const vec4<T>& v) {
			return vec2<T>(v.x, v.y);
		}

		template<typename T>
		vec2<T> v3ToV2(const vec3<T>& v) {
			return vec2<T>(v.x, v.y);
		}


	}
}