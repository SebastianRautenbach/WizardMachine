#pragma once
#include <cmath>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"




namespace wizmcore {
	namespace math {


		using std::cos;

		template<typename T>
		inline vec2<T> cos(vec2<T> const& v)
		{
			return vec2<T>(cos(v.x), cos(v.y));
		}
		template<typename T>
		inline vec3<T> cos(vec3<T> const& v)
		{
			return vec3<T>(cos(v.x), cos(v.y), cos(v.z));
		}
		template<typename T>
		inline vec4<T> cos(vec4<T> const& v)
		{
			return vec4<T>(cos(v.x), cos(v.y), cos(v.z), cos(v.w));
		}

		
		using std::sin;


		template<typename T>
		inline vec2<T> sin(vec2<T> const& v)
		{
			return vec2<T>(sin(v.x), sin(v.y));
		}
		template<typename T>
		inline vec3<T> sin(vec3<T> const& v)
		{
			return vec3<T>(sin(v.x), sin(v.y), sin(v.z));
		}
		template<typename T>
		inline vec4<T> sin(vec4<T> const& v)
		{
			return vec4<T>(sin(v.x), sin(v.y), sin(v.z), sin(v.w));
		}
		

	}
}


