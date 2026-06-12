#pragma once
#include <cmath>

#include "conv.h"
#include "mat4.h"
#include "vec3.h"

namespace wizm
{
    namespace math
    {
        template<typename T>
        constexpr mat4<T> translate(mat4<T> const& model, vec3<T> const& t);
        
        template<typename T>
        constexpr mat4<T> rotate(mat4<T> const& model, T angle, vec3<T> const& axis);
        
        template<typename T>
        constexpr mat4<T> scale(mat4<T> const& model, vec3<T> const& s);
        
        mat4<float> perspective(const float fov, const float aspect, const float near, const float far);
        
        mat4<float> lookAt(vec3<float> const& position, vec3<float> const& center, vec3<float> const& up);
    }
}



template <typename T>
constexpr wizm::math::mat4<T> wizm::math::translate(mat4<T> const& model, vec3<T> const& t)
{
    wizm::math::mat4<T> m = model;

    m[0][3] += t[0];
    m[1][3] += t[1];
    m[2][3] += t[2];

    return m;
}

template <typename T>
constexpr wizm::math::mat4<T> wizm::math::rotate(mat4<T> const& model, T angle, vec3<T> const& axis)
{
    T c = std::cos(angle);
    T s = std::sin(angle);
    T t = T(1) - c;

    T len = std::sqrt(axis[0]*axis[0] + axis[1]*axis[1] + axis[2]*axis[2]);
    T x = axis[0] / len;
    T y = axis[1] / len;
    T z = axis[2] / len;
    
    mat4<T> r = mat4<T>::identity();

    r[0][0] = x*x*t + c;
    r[0][1] = x*y*t - z*s;
    r[0][2] = x*z*t + y*s;

    r[1][0] = y*x*t + z*s;
    r[1][1] = y*y*t + c;
    r[1][2] = y*z*t - x*s;

    r[2][0] = z*x*t - y*s;
    r[2][1] = z*y*t + x*s;
    r[2][2] = z*z*t + c;

    return model * r;
}

template <typename T>
constexpr wizm::math::mat4<T> wizm::math::scale(mat4<T> const& model, vec3<T> const& s)
{
    wizm::math::mat4<T> m = model;

    m[0][0] *= s[0];
    m[1][1] *= s[1];
    m[2][2] *= s[2];

    return m;
}

wizm::math::mat4<float> wizm::math::perspective(const float fov, const float aspect, const float near, const float far)
{
    float tanHalfFov = std::tan(fov / 2.f);

    mat4<float> m = mat4<float>(0.f);

    m[0][0] = 1.f / (aspect * tanHalfFov);
    m[1][1] = 1.f / tanHalfFov;
    m[2][2] = (far + near) / (near - far);
    m[2][3] = (2.f * far * near) / (near - far);
    m[3][2] = -1.f;

    return m;
}

wizm::math::mat4<float> wizm::math::lookAt(vec3<float> const& position, vec3<float> const& center,
    vec3<float> const& up)
{
    vec3<float> z = normalize(position - center);
    vec3<float> x = normalize(cross(up, z));
    vec3<float> y = cross(z, x);

    mat4<float> view = mat4<float>::identity();

    // Each basis vector occupies one row [row][col]:
    // row 0 = x axis, row 1 = y axis, row 2 = z axis
    view[0][0] = x[0];  view[0][1] = x[1];  view[0][2] = x[2];
    view[1][0] = y[0];  view[1][1] = y[1];  view[1][2] = y[2];
    view[2][0] = z[0];  view[2][1] = z[1];  view[2][2] = z[2];

    // Translation in the last column of each row
    view[0][3] = -dot(x, position);
    view[1][3] = -dot(y, position);
    view[2][3] = -dot(z, position);

    return view;
}