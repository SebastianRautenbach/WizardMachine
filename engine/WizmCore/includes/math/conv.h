#pragma once
#include <cmath>

#include "vec4.h"
#include "vec3.h"
#include "mat4.h"

static constexpr float PI = 3.14159265358979323846f;

namespace wizm
{
    namespace math
    {
        template <typename T>
        inline vec4<T> v3tov4(const vec3<T>& v)
        {
            return vec4<T>(v[0], v[1], v[2], T{1});
        }
        
        inline float radians(float d)
        {
            return d * PI / 180.f;
        }
        
        inline float degrees(float r)
        {
            return r * 180.f / PI;
        }
        
        inline float asin(float d)
        {
            return std::asin(d);
        }
        
        inline float cos(float d)
        {
            return std::cos(d);
        }
        
        inline float sin(float d)
        {
            return std::sin(d);
        }
        
        inline float acos(float d)
        {
            return std::acos(d);
        }
        
        inline vec3<float> cross(vec3<float> const& v1, vec3<float> const& v2)
        {
            return {
                v1[1] * v2[2] - v1[2] * v2[1],
                v1[2] * v2[0] - v1[0] * v2[2],
                v1[0] * v2[1] - v1[1] * v2[0]
            };
        }
        
        inline float dot(vec3<float> const& v1, vec3<float> const& v2)
        {
            return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
        }
        
        inline vec3<float> normalize(vec3<float> const& v)
        {
            float length = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
            return {v[0] / length, v[1] / length, v[2] / length};
        }
    }
}