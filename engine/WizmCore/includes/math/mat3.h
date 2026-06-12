#pragma once

#include <cassert>

#include "vec3.h"

namespace wizm
{
    namespace math
    {
        template<typename T>
        struct mat3
        {
            vec3<T> mat[3];

            //////////////////////////////////////////////////////////////////////
            ///                        CONSTRUCTORS
            //////////////////////////////////////////////////////////////////////

            constexpr mat3()
                : mat{
                    vec3<T>(0),
                    vec3<T>(0),
                    vec3<T>(0)
                }
            {
            }

            constexpr explicit mat3(T value)
                : mat{
                    vec3<T>(value),
                    vec3<T>(value),
                    vec3<T>(value)
                }
            {
            }

            constexpr mat3(
                const vec3<T>& x,
                const vec3<T>& y,
                const vec3<T>& z)
                : mat{ x, y, z}
            {
            }

            constexpr mat3(const mat3&) = default;
            constexpr mat3(mat3&&) = default;

            //////////////////////////////////////////////////////////////////////
            ///                      ASSIGNMENT
            //////////////////////////////////////////////////////////////////////

            constexpr mat3& operator=(const mat3&) = default;
            constexpr mat3& operator=(mat3&&) = default;

            //////////////////////////////////////////////////////////////////////
            ///                 MATRIX + MATRIX OPERATORS
            //////////////////////////////////////////////////////////////////////

            constexpr mat3 operator+(const mat3& rhs) const
            {
                mat3 result;

                for (int i = 0; i < 3; ++i)
                    result.mat[i] = mat[i] + rhs.mat[i];

                return result;
            }

            constexpr mat3& operator+=(const mat3& rhs)
            {
                for (int i = 0; i < 3; ++i)
                    mat[i] += rhs.mat[i];

                return *this;
            }

            constexpr mat3 operator-(const mat3& rhs) const
            {
                mat3 result;

                for (int i = 0; i < 3; ++i)
                    result.mat[i] = mat[i] - rhs.mat[i];

                return result;
            }

            constexpr mat3& operator-=(const mat3& rhs)
            {
                for (int i = 0; i < 3; ++i)
                    mat[i] -= rhs.mat[i];

                return *this;
            }

            //////////////////////////////////////////////////////////////////////
            ///                MATRIX * MATRIX
            //////////////////////////////////////////////////////////////////////

            constexpr mat3 operator*(const mat3& rhs) const
            {
                mat3 result;

                for (int i = 0; i < 3; ++i)
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; ++k)
                            result[i][j] += mat[i][k] * rhs.mat[k][j];

                return result;
            }

            constexpr mat3& operator*=(const mat3& rhs)
            {
                *this = *this * rhs;
                return *this;
            }

            //////////////////////////////////////////////////////////////////////
            ///                MATRIX * VECTOR
            //////////////////////////////////////////////////////////////////////

            constexpr vec3<T> operator*(const vec3<T>& v) const
            {
                return vec3<T>(
                    mat[0][0] * v[0] +
                    mat[0][1] * v[1] +
                    mat[0][2] * v[2],

                    mat[1][0] * v[0] +
                    mat[1][1] * v[1] +
                    mat[1][2] * v[2],

                    mat[2][0] * v[0] +
                    mat[2][1] * v[1] +
                    mat[2][2] * v[2]
                );
            }

            //////////////////////////////////////////////////////////////////////
            ///                MATRIX * SCALAR
            //////////////////////////////////////////////////////////////////////

            constexpr mat3 operator*(T scalar) const
            {
                mat3 result;

                for (int i = 0; i < 3; ++i)
                    result.mat[i] = mat[i] * scalar;

                return result;
            }

            constexpr mat3& operator*=(T scalar)
            {
                for (int i = 0; i < 3; ++i)
                    mat[i] *= scalar;

                return *this;
            }

            constexpr mat3 operator/(T scalar) const
            {
                mat3 result;

                for (int i = 0; i < 3; ++i)
                    result.mat[i] = mat[i] / scalar;

                return result;
            }

            constexpr mat3& operator/=(T scalar)
            {
                for (int i = 0; i < 3; ++i)
                    mat[i] /= scalar;

                return *this;
            }

            friend constexpr mat3 operator*(T scalar, const mat3& m)
            {
                return m * scalar;
            }

            //////////////////////////////////////////////////////////////////////
            ///                COMPARISON
            //////////////////////////////////////////////////////////////////////

            constexpr bool operator==(const mat3& rhs) const
            {
                for (int i = 0; i < 3; ++i)
                {
                    if (mat[i] != rhs.mat[i])
                        return false;
                }

                return true;
            }

            constexpr bool operator!=(const mat3& rhs) const
            {
                return !(*this == rhs);
            }

            //////////////////////////////////////////////////////////////////////
            ///                UNARY
            //////////////////////////////////////////////////////////////////////

            constexpr mat3 operator-() const
            {
                mat3 result;

                for (int i = 0; i < 3; ++i)
                    result.mat[i] = -mat[i];

                return result;
            }

            //////////////////////////////////////////////////////////////////////
            ///                ACCESS
            //////////////////////////////////////////////////////////////////////

            constexpr vec3<T>& operator[](size_t row)
            {
                assert(row < 3);
                return mat[row];
            }

            constexpr const vec3<T>& operator[](size_t row) const
            {
                assert(row < 3);
                return mat[row];
            }

            //////////////////////////////////////////////////////////////////////
            ///                UTILITIES
            //////////////////////////////////////////////////////////////////////

            static constexpr mat3 identity()
            {
                mat3 result;

                result[0][0] = 1;
                result[1][1] = 1;
                result[2][2] = 1;

                return result;
            }
        };
    }
}