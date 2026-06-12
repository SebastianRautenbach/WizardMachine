#pragma once

#include <cassert>

#include "vec4.h"
//#include "vec3.h"
//#include "vec2.h"

namespace wizm
{
    namespace math
    {
        template<typename T>
        struct mat4
        {
            vec4<T> mat[4];

            //////////////////////////////////////////////////////////////////////
            ///                        CONSTRUCTORS
            //////////////////////////////////////////////////////////////////////

            constexpr mat4()
                : mat{
                    vec4<T>(0),
                    vec4<T>(0),
                    vec4<T>(0),
                    vec4<T>(0)
                }
            {
            }

            constexpr explicit mat4(T value)
                : mat{
                    vec4<T>(value),
                    vec4<T>(value),
                    vec4<T>(value),
                    vec4<T>(value)
                }
            {
            }

            constexpr mat4(
                const vec4<T>& x,
                const vec4<T>& y,
                const vec4<T>& z,
                const vec4<T>& w)
                : mat{ x, y, z, w }
            {
            }

            constexpr mat4(const mat4&) = default;
            constexpr mat4(mat4&&) = default;

            //////////////////////////////////////////////////////////////////////
            ///                      ASSIGNMENT
            //////////////////////////////////////////////////////////////////////

            constexpr mat4& operator=(const mat4&) = default;
            constexpr mat4& operator=(mat4&&) = default;

            //////////////////////////////////////////////////////////////////////
            ///                 MATRIX + MATRIX OPERATORS
            //////////////////////////////////////////////////////////////////////

            constexpr mat4 operator+(const mat4& rhs) const
            {
                mat4 result;

                for (int i = 0; i < 4; ++i)
                    result.mat[i] = mat[i] + rhs.mat[i];

                return result;
            }

            constexpr mat4& operator+=(const mat4& rhs)
            {
                for (int i = 0; i < 4; ++i)
                    mat[i] += rhs.mat[i];

                return *this;
            }

            constexpr mat4 operator-(const mat4& rhs) const
            {
                mat4 result;

                for (int i = 0; i < 4; ++i)
                    result.mat[i] = mat[i] - rhs.mat[i];

                return result;
            }

            constexpr mat4& operator-=(const mat4& rhs)
            {
                for (int i = 0; i < 4; ++i)
                    mat[i] -= rhs.mat[i];

                return *this;
            }

            //////////////////////////////////////////////////////////////////////
            ///                MATRIX * MATRIX
            //////////////////////////////////////////////////////////////////////

            constexpr mat4 operator*(const mat4& rhs) const
            {
                mat4 result;

                for (int i = 0; i < 4; ++i)
                    for (int j = 0; j < 4; ++j)
                        for (int k = 0; k < 4; ++k)
                            result[i][j] += mat[i][k] * rhs.mat[k][j];

                return result;
            }

            constexpr mat4& operator*=(const mat4& rhs)
            {
                *this = *this * rhs;
                return *this;
            }

            //////////////////////////////////////////////////////////////////////
            ///                MATRIX * VECTOR
            //////////////////////////////////////////////////////////////////////

            constexpr vec4<T> operator*(const vec4<T>& v) const
            {
                return vec4<T>(
                    mat[0][0] * v[0] +
                    mat[0][1] * v[1] +
                    mat[0][2] * v[2] +
                    mat[0][3] * v[3],

                    mat[1][0] * v[0] +
                    mat[1][1] * v[1] +
                    mat[1][2] * v[2] +
                    mat[1][3] * v[3],

                    mat[2][0] * v[0] +
                    mat[2][1] * v[1] +
                    mat[2][2] * v[2] +
                    mat[2][3] * v[3],

                    mat[3][0] * v[0] +
                    mat[3][1] * v[1] +
                    mat[3][2] * v[2] +
                    mat[3][3] * v[3]
                );
            }

            //////////////////////////////////////////////////////////////////////
            ///                MATRIX * SCALAR
            //////////////////////////////////////////////////////////////////////

            constexpr mat4 operator*(T scalar) const
            {
                mat4 result;

                for (int i = 0; i < 4; ++i)
                    result.mat[i] = mat[i] * scalar;

                return result;
            }

            constexpr mat4& operator*=(T scalar)
            {
                for (int i = 0; i < 4; ++i)
                    mat[i] *= scalar;

                return *this;
            }

            constexpr mat4 operator/(T scalar) const
            {
                mat4 result;

                for (int i = 0; i < 4; ++i)
                    result.mat[i] = mat[i] / scalar;

                return result;
            }

            constexpr mat4& operator/=(T scalar)
            {
                for (int i = 0; i < 4; ++i)
                    mat[i] /= scalar;

                return *this;
            }

            friend constexpr mat4 operator*(T scalar, const mat4& m)
            {
                return m * scalar;
            }

            //////////////////////////////////////////////////////////////////////
            ///                COMPARISON
            //////////////////////////////////////////////////////////////////////

            constexpr bool operator==(const mat4& rhs) const
            {
                for (int i = 0; i < 4; ++i)
                {
                    if (mat[i] != rhs.mat[i])
                        return false;
                }

                return true;
            }

            constexpr bool operator!=(const mat4& rhs) const
            {
                return !(*this == rhs);
            }

            //////////////////////////////////////////////////////////////////////
            ///                UNARY
            //////////////////////////////////////////////////////////////////////

            constexpr mat4 operator-() const
            {
                mat4 result;

                for (int i = 0; i < 4; ++i)
                    result.mat[i] = -mat[i];

                return result;
            }

            //////////////////////////////////////////////////////////////////////
            ///                ACCESS
            //////////////////////////////////////////////////////////////////////

            constexpr vec4<T>& operator[](size_t row)
            {
                assert(row < 4);
                return mat[row];
            }

            constexpr const vec4<T>& operator[](size_t row) const
            {
                assert(row < 4);
                return mat[row];
            }

            //////////////////////////////////////////////////////////////////////
            ///                UTILITIES
            //////////////////////////////////////////////////////////////////////

            static constexpr mat4 identity()
            {
                mat4 result;

                result[0][0] = 1;
                result[1][1] = 1;
                result[2][2] = 1;
                result[3][3] = 1;

                return result;
            }
        };
    }
}