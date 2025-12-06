#pragma once
#include <vec.h>
#include <mat.h>
#include <cmath>
#include <generic_vec_func.h>

namespace wizmcore {
	namespace math {

		template<typename T>
		mat<T, 4, 4> translate(mat<T, 4, 4> const& m, vec<T, 4> const& v) {
			mat<T, 4, 4> Result(m);
			Result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3]; 
			return Result;
		}

		template<typename T>
		mat<T, 4, 4> scale(mat<T, 4, 4> const& m, vec<T, 4> const& v) {
			mat<T, 4, 4> Result;
			Result[0] = m[0] * v[0];
			Result[1] = m[1] * v[1];
			Result[2] = m[2] * v[2];
			Result[3] = m[3];
			return Result;
		}


		template<typename T>
		inline mat<T, 4, 4> ortho(T left, T right, T bottom, T top, T zNear, T zFar) {
			mat<T, 4, 4> Result(1);
			Result[0][0] = static_cast<T>(2) / (right - left);
			Result[1][1] = static_cast<T>(2) / (top - bottom);
			Result[2][2] = -static_cast<T>(2) / (zFar - zNear);
			Result[3][0] = -(right + left) / (right - left);
			Result[3][1] = -(top + bottom) / (top - bottom);
			Result[3][2] = -(zFar + zNear) / (zFar - zNear);
			return Result;
		}


		template<typename T>
		inline mat<T,4, 4> perspective(T fovy, T aspect, T zNear, T zFar)
		{
			assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

			T const tanHalfFovy = std::tan(fovy / static_cast<T>(2));

			mat<T, 4, 4> Result(static_cast<T>(0));
			Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
			Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
			Result[2][2] = -(zFar + zNear) / (zFar - zNear);
			Result[2][3] = -static_cast<T>(1);
			Result[3][2] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
			return Result;
		}

		template<typename T>
		inline mat<T, 4, 4> lookAt(vec<T, 3> const& eye, vec<T, 3> const& center, vec<T, 3> const& up)
		{
			vec<T, 3>  const f(normalize(center - eye));
			vec<T, 3>  const s(normalize(cross(f, up)));
			vec<T, 3>  const u(cross(s, f));

			mat<T, 4, 4> Result(1);
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

		template<typename T>
		inline mat<T, 4, 4> transform() {
			mat<4, 4, T, Q> Result(m);
			Result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
			return Result;
		}
	}
}
