#pragma once
#include "quat.h"
#include "mat4.h"
#include "scalar_constants.h"

namespace wizmcore {
	namespace math {

		template<typename T>
		inline vec3<T> q_to_euler(quat<T> const& x)
		{
			return vec3<T>(pitch(x), yaw(x), roll(x));
		}


		template<typename T>
		inline T pitch(quat<T> const& q)
		{
			T const y = static_cast<T>(2) * (q.y * q.z + q.w * q.x);
			T const x = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;

			if (all(equal(vec2<T>(x, y), vec2<T>(0), epsilon<T>()))) //avoid atan2(0,0) - handle singularity - Matiis
				return static_cast<T>(static_cast<T>(2) * atan(q.x, q.w));

			return static_cast<T>(atan(y, x));
		}
























		template<typename T>
		void normalize(quat<T>& q) {
			float l = q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z;
			float f = 1.f / sqrt(l);
			q.x = q.x * f;
			q.y = q.y * f;
			q.z = q.z * f;
			q.w = q.w * f;
		}

		template<typename T>
		void from_angle_axis(float angle, const vec3<T>& axis, quat<T>& q) {
			T fHalfAngle = 0.5 * angle;
			T fSin = sin(fHalfAngle);
			q.w = cos(fHalfAngle);
			q.x = fSin * axis.x;
			q.y = fSin * axis.y;
			q.z = fSin * axis.z;
		}

		template<typename T>
		constexpr void from_rotation_matrix(quat<T>& q, const mat4<T>& r) {
			T trace = r[0][0] + r[1][1] + r[2][2];
			T root;

			if (trace > 0.0)
			{				
				root = sqrt(trace + 1.0f);
				q.w = 0.5f * root;
				root = 0.5f / root;
				q.x = (r[2][1] - r[1][2]) * root;
				q.y = (r[0][2] - r[2][0]) * root;
				q.z = (r[1][0] - r[0][1]) * root;
			}
			else
			{				
				static size_t next[3] = { 1, 2, 0 };
				size_t i = 0;
				if (r[1][1] > r[0][0])
					i = 1;
				if (r[2][2] > r[i][i])
					i = 2;
				size_t j = next[i];
				size_t k = next[j];

				root = sqrt(r[i][i] - r[j][j] - r[k][k] + T(1));
				T* apkQuat[3] = { &q.x, &q.y, &q.z };
				*apkQuat[i] = T(0.5) * root;
				root = T(0.5) / root;
				q.w = (r[k][j] - r[j][k]) * root;
				*apkQuat[j] = (r[j][i] + r[i][j]) * root;
				*apkQuat[k] = (r[k][i] + r[i][k]) * root;
			}
		}
		

		template<typename T>
		constexpr mat4<T> q_to_mat4(const quat<T>& q) {
			T fTx = T(2) * q.x;
			T fTy = T(2) * q.y;
			T fTz = T(2) * q.z;
			T fTwx = fTx * q.w;
			T fTwy = fTy * q.w;
			T fTwz = fTz * q.w;
			T fTxx = fTx * q.x;
			T fTxy = fTy * q.x;
			T fTxz = fTz * q.x;
			T fTyy = fTy * q.y;
			T fTyz = fTz * q.y;
			T fTzz = fTz * q.z;

			mat4<T> m_out(T(0));

			m_out[0][0] = T(1) - (fTyy + fTzz);
			m_out[0][1] = fTxy - fTwz;
			m_out[0][2] = fTxz + fTwy;

			m_out[1][0] = fTxy + fTwz;
			m_out[1][1] = T(1) - (fTxx + fTzz);
			m_out[1][2] = fTyz - fTwx;

			m_out[2][0] = fTxz - fTwy;
			m_out[2][1] = fTyz + fTwx;
			m_out[2][2] = T(1) - (fTxx + fTyy);
			
			return m_out;
		}
	}
}