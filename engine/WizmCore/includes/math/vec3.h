#pragma once
#include <cassert>

namespace wizm
{
    namespace math
    {
    
        template<typename T>
        struct vec3
        {
            T data[3];
            
            
            //////////////////////////////////////////////////////////////////////
            ///                        CONSTRUCTORS
            //////////////////////////////////////////////////////////////////////
            
            
            
            constexpr vec3()
            : data{ 0, 0, 0 }
            {
            }

            constexpr explicit vec3(T x)
            : data{ x, x, x }
            {
            }
            
            constexpr vec3(T x, T y, T z)
                : data{x, y, z}
            {
            }
            
            constexpr vec3(const vec3& v);
            
            //////////////////////////////////////////////////////////////////////
            ///                      OPERATOR OVERLOADS
            //////////////////////////////////////////////////////////////////////
            
            
            vec3<T>& operator=(vec3<T> const& v2)
            {
                if (this != &v2)
                {
                    for (int i = 0; i < 3; ++i)
                    {
                        data[i] = v2.data[i];
                    }
                }
                return *this;
            }
            
            vec3& operator+=(const vec3& v2)
            {
                for (int i = 0; i < 3; ++i)
                    data[i] += v2.data[i];
                return *this;
            }
            
            vec3& operator-=(const vec3& v2)
            {
                for (int i = 0; i < 3; ++i)
                    data[i] -= v2.data[i];
                return *this;
            }
            
            vec3& operator*=(const vec3& v2)
            {
                for (int i = 0; i < 3; ++i)
                    data[i] *= v2.data[i];
                return *this;
            }
            
            vec3& operator/=(const vec3& v2)
            {
                for (int i = 0; i < 3; ++i)
                    data[i] /= v2.data[i];
                return *this;
            }
            
            vec3<T> operator*(T scalar) const
            {
                return {
                    data[0] * scalar,
                    data[1] * scalar,
                    data[2] * scalar
                };
            }
            
            vec3 operator/(T scalar) const
            {
                return {
                    data[0] / scalar,
                    data[1] / scalar,
                    data[2] / scalar
                };
            }
            
            vec3& operator*=(T scalar)
            {
                data[0] *= scalar;
                data[1] *= scalar;
                data[2] *= scalar;
                return *this;
            }

            vec3& operator/=(T scalar)
            {
                data[0] /= scalar;
                data[1] /= scalar;
                data[2] /= scalar;
                return *this;
            }
            
            vec3 operator-() const
            {
                return {
                    -data[0],
                    -data[1],
                    -data[2],
                };
            }
            
            bool operator==(const vec3& v2) const
            {
                return data[0] == v2.data[0]
                    && data[1] == v2.data[1]
                    && data[2] == v2.data[2];
            }
            
            bool operator!=(const vec3& v2) const
            {
                return !(*this == v2);
            }
            
            vec3 operator+(vec3 const& v2 ) const
            {
                vec3 result;
                
                for (int i = 0; i < 3; i++)
                    result.data[i] = data[i] + v2.data[i];
                
                return result;
            }
            
            vec3 operator-(vec3 const& v2 ) const
            {
                vec3 result;
                
                for (int i = 0; i < 3; i++)
                    result.data[i] = data[i] - v2.data[i];
                
                return result;
            }
            
            vec3 operator*(vec3 const& v2 ) const
            {
                vec3 result;
                
                for (int i = 0; i < 3; i++)
                    result.data[i] = data[i] * v2.data[i];
                
                return result;
            }
        
            vec3 operator/(vec3 const& v2 ) const
            {
                vec3 result;
                
                for (int i = 0; i < 3; i++)
                    result.data[i] = data[i] / v2.data[i];
                
                return result;
            }
        
            T& operator[](size_t index)
            {
                assert(index < 3);
                return data[index];
            }

            const T& operator[](size_t index) const
            {
                assert(index < 3);
                return data[index];
            }
        };

        template <typename T>
        constexpr vec3<T>::vec3(const vec3& v)
        {
            this->data[0] = v.data[0];
            this->data[1] = v.data[1];
            this->data[2] = v.data[2];
        }
    }    
}


