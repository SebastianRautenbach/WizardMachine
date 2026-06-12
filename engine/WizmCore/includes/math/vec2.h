#pragma once
#include <cassert>

namespace wizm
{
    namespace math
    {
    
        template<typename T>
        struct vec2
        {
            T data[2];
            
            
            //////////////////////////////////////////////////////////////////////
            ///                        CONSTRUCTORS
            //////////////////////////////////////////////////////////////////////
            
            constexpr vec2()
                : data{ T(0), T(0) }
            {
            }

            constexpr explicit vec2(T x)
                : data{ x, x }
            {
            }
            
            constexpr vec2(T x, T y)
                : data{ x, y }
            {
            }
            
            constexpr vec2(const vec2& v);
            
            //////////////////////////////////////////////////////////////////////
            ///                      OPERATOR OVERLOADS
            //////////////////////////////////////////////////////////////////////
            
            vec2<T>& operator=(vec2<T> const& v2)
            {
                if (this != &v2)
                {
                    for (int i = 0; i < 2; ++i)
                    {
                        data[i] = v2.data[i];
                    }
                }
                return *this;
            }
            
            vec2& operator+=(const vec2& v2)
            {
                for (int i = 0; i < 2; ++i)
                    data[i] += v2.data[i];
                return *this;
            }
            
            vec2& operator-=(const vec2& v2)
            {
                for (int i = 0; i < 2; ++i)
                    data[i] -= v2.data[i];
                return *this;
            }
            
            vec2& operator*=(const vec2& v2)
            {
                for (int i = 0; i < 2; ++i)
                    data[i] *= v2.data[i];
                return *this;
            }
            
            vec2& operator/=(const vec2& v2)
            {
                for (int i = 0; i < 2; ++i)
                    data[i] /= v2.data[i];
                return *this;
            }
            
            vec2 operator*(T scalar) const
            {
                return {
                    data[0] * scalar,
                    data[1] * scalar
                };
            }
            
            vec2 operator/(T scalar) const
            {
                return {
                    data[0] / scalar,
                    data[1] / scalar
                };
            }
            
            vec2& operator*=(T scalar)
            {
                data[0] *= scalar;
                data[1] *= scalar;
                return *this;
            }

            vec2& operator/=(T scalar)
            {
                data[0] /= scalar;
                data[1] /= scalar;
                return *this;
            }
            
            vec2 operator-() const
            {
                return {
                    -data[0],
                    -data[1]
                };
            }
            
            bool operator==(const vec2& v2) const
            {
                return data[0] == v2.data[0]
                    && data[1] == v2.data[1];
            }
            
            bool operator!=(const vec2& v2) const
            {
                return !(*this == v2);
            }
            
            vec2 operator+(vec2 const& v2) const
            {
                vec2 result;
                
                for (int i = 0; i < 2; i++)
                    result.data[i] = data[i] + v2.data[i];
                
                return result;
            }
            
            vec2 operator-(vec2 const& v2) const
            {
                vec2 result;
                
                for (int i = 0; i < 2; i++)
                    result.data[i] = data[i] - v2.data[i];
                
                return result;
            }
            
            vec2 operator*(vec2 const& v2) const
            {
                vec2 result;
                
                for (int i = 0; i < 2; i++)
                    result.data[i] = data[i] * v2.data[i];
                
                return result;
            }
        
            vec2 operator/(vec2 const& v2) const
            {
                vec2 result;
                
                for (int i = 0; i < 2; i++)
                    result.data[i] = data[i] / v2.data[i];
                
                return result;
            }
        
            T& operator[](size_t index)
            {
                assert(index < 2);
                return data[index];
            }

            const T& operator[](size_t index) const
            {
                assert(index < 2);
                return data[index];
            }
        };

        template <typename T>
        constexpr vec2<T>::vec2(const vec2& v)
        {
            this->data[0] = v.data[0];
            this->data[1] = v.data[1];
        }
    }    
}