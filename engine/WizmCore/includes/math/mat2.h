#pragma once

#include <cassert>

#include "vec2.h"

namespace wizm
{
    namespace math
    {
        template<typename T>
        struct mat2
        {
            vec2<T> mat[2];

            //////////////////////////////////////////////////////////////////////
            ///                        CONSTRUCTORS
            //////////////////////////////////////////////////////////////////////

            constexpr mat2()
                : mat{
                    vec2<T>(0),
                    vec2<T>(0)
                }
            {
            }

            constexpr explicit mat2(T value)
                : mat{
                    vec2<T>(value),
                    vec2<T>(value)
                }
            {
            }

            constexpr mat2(
                const vec2<T>& x,
                const vec2<T>& y)
                : mat{ x, y }
            {
            }

            constexpr mat2(const mat2&) = default;
            constexpr mat2(mat2&&) = default;

            //////////////////////////////////////////////////////////////////////
            ///                      ASSIGNMENT
            //////////////////////////////////////////////////////////////////////

            constexpr mat2& operator=(const mat2&) = default;
            constexpr mat2& operator=(mat2&&) = default;

            //////////////////////////////////////////////////////////////////////
            ///                 MATRIX + MATRIX OPERATORS
            //////////////////////////////////////////////////////////////////////

            constexpr mat2 operator+(const mat2& rhs) const
            {
                mat2 result;

                for (int i = 0; i < 2; ++i)
                    result.mat[i] = mat[i] + rhs.mat[i];

                return result;
            }

            constexpr mat2& operator+=(const mat2& rhs)
            {
                for (int i = 0; i < 2; ++i)
                    mat[i] += rhs.mat[i];

                return *this;
            }

            constexpr mat2 operator-(const mat2& rhs) const
            {
                mat2 result;

                for (int i = 0; i < 2; ++i)
                    result.mat[i] = mat[i] - rhs.mat[i];

                return result;
            }

            constexpr mat2& operator-=(const mat2& rhs)
            {
                for (int i = 0; i < 2; ++i)
                    mat[i] -= rhs.mat[i];

                return *this;
            }

            //////////////////////////////////////////////////////////////////////
            ///                MATRIX * MATRIX
            //////////////////////////////////////////////////////////////////////

            constexpr mat2 operator*(const mat2& rhs) const
            {
                mat2 result;

                for (int i = 0; i < 2; ++i)
                    for (int j = 0; j < 2; ++j)
                        for (int k = 0; k < 2; ++k)
                            result[i][j] += mat[i][k] * rhs.mat[k][j];

                return result;
            }

            constexpr mat2& operator*=(const mat2& rhs)
            {
                *this = *this * rhs;
                return *this;
            }

            //////////////////////////////////////////////////////////////////////
            ///                MATRIX * VECTOR
            //////////////////////////////////////////////////////////////////////

            constexpr vec2<T> operator*(const vec2<T>& v) const
            {
                return vec2<T>(
                    mat[0][0] * v[0] +
                    mat[0][1] * v[1],

                    mat[1][0] * v[0] +
                    mat[1][1] * v[1]
                );
            }

            //////////////////////////////////////////////////////////////////////
            ///                MATRIX * SCALAR
            //////////////////////////////////////////////////////////////////////

            constexpr mat2 operator*(T scalar) const
            {
                mat2 result;

                for (int i = 0; i < 2; ++i)
                    result.mat[i] = mat[i] * scalar;

                return result;
            }

            constexpr mat2& operator*=(T scalar)
            {
                for (int i = 0; i < 2; ++i)
                    mat[i] *= scalar;

                return *this;
            }

            constexpr mat2 operator/(T scalar) const
            {
                mat2 result;

                for (int i = 0; i < 2; ++i)
                    result.mat[i] = mat[i] / scalar;

                return result;
            }

            constexpr mat2& operator/=(T scalar)
            {
                for (int i = 0; i < 2; ++i)
                    mat[i] /= scalar;

                return *this;
            }

            friend constexpr mat2 operator*(T scalar, const mat2& m)
            {
                return m * scalar;
            }

            //////////////////////////////////////////////////////////////////////
            ///                COMPARISON
            //////////////////////////////////////////////////////////////////////

            constexpr bool operator==(const mat2& rhs) const
            {
                for (int i = 0; i < 2; ++i)
                {
                    if (mat[i] != rhs.mat[i])
                        return false;
                }

                return true;
            }

            constexpr bool operator!=(const mat2& rhs) const
            {
                return !(*this == rhs);
            }

            //////////////////////////////////////////////////////////////////////
            ///                UNARY
            //////////////////////////////////////////////////////////////////////

            constexpr mat2 operator-() const
            {
                mat2 result;

                for (int i = 0; i < 2; ++i)
                    result.mat[i] = -mat[i];

                return result;
            }

            //////////////////////////////////////////////////////////////////////
            ///                ACCESS
            //////////////////////////////////////////////////////////////////////

            constexpr vec2<T>& operator[](size_t row)
            {
                assert(row < 2);
                return mat[row];
            }

            constexpr const vec2<T>& operator[](size_t row) const
            {
                assert(row < 2);
                return mat[row];
            }

            //////////////////////////////////////////////////////////////////////
            ///                UTILITIES
            //////////////////////////////////////////////////////////////////////

            static constexpr mat2 identity()
            {
                mat2 result;

                result[0][0] = 1;
                result[1][1] = 1;

                return result;
            }
        };
    }
}