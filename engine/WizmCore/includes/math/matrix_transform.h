#pragma once
#include "mat4.h"
#include "vec3.h"
#include "func_geometric.h"

namespace wizmcore {
	namespace math {

		template<typename T>
		mat4<T> perspective(T fovy, T aspect, T zNear, T zFar) {
			assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));
			T const tanHalfFovy = tan(fovy / static_cast<T>(2));
			mat4<T> Result(static_cast<T>(0));
			Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
			Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
			Result[2][2] = -(zFar + zNear) / (zFar - zNear);
			Result[2][3] = -static_cast<T>(1);
			Result[3][2] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
			return Result;
		}

		template<typename T>
		inline constexpr mat4<T> translate(mat4<T> const& m, vec3<T> const& v)
		{
			mat4<T> Result(m);
			Result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
			return Result;
		}


		template<typename T>
		inline mat4<T> scale(mat4<T> const& m, vec3<T> const& v)
		{
			mat4<T> Result;
			Result[0] = m[0] * v[0];
			Result[1] = m[1] * v[1];
			Result[2] = m[2] * v[2];
			Result[3] = m[3];
			return Result;
		}
		
		
		// right hand
		template<typename T>
		mat4<T> lookAt(vec3<T> const& eye, vec3<T> const&  center, vec3<T> const& up) {
			auto x = (center - eye);
			
			vec3<T> const f(normalize(center - eye));
			vec3<T> const s(normalize(cross(f, up)));
			vec3<T> const u(cross(s, f));

			mat4<T> Result(1);
			Result[0][0] = s.x;
			Result[1][0] = s.y;
			Result[2][0] = s.z;
			Result[0][1] = u.x;
			Result[1][1] = u.y;
			Result[2][1] = u.z;
			Result[0][2] = -f.x;
			Result[1][2] = -f.y;
			Result[2][2] = -f.z;
			Result[3][0] = -dot(s, eye);
			Result[3][1] = -dot(u, eye);
			Result[3][2] = dot(f, eye);
			return Result;
		}



	}
}
