//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../mat.hpp"
#include "../math.hpp"
#include "../quat.hpp"
#include "../vec.hpp"

// The Tuesday C++ math and template library.
namespace tue
{
  // Non-member math functions.
  namespace math
  {
    template<typename T>
    inline mat<T, 3, 2> translation_mat(
        const T& x, const T& y) noexcept
    {
      return {
        { 1, 0 },
        { 0, 1 },
        { x, y },
      };
    }

    template<typename T>
    inline mat<T, 3, 2> translation_mat(
        const vec2<T>& xy) noexcept
    {
      return translation_mat(xy.x(), xy.y());
    }

    template<typename T>
    inline mat<T, 4, 3> translation_mat(
        const T& x, const T& y, const T& z) noexcept
    {
      return {
        { 1, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 1 },
        { x, y, z },
      };
    }

    template<typename T>
    inline mat<T, 4, 3> translation_mat(
        const vec3<T>& xyz) noexcept
    {
      return translation_mat(xyz.x(), xyz.y(), xyz.z());
    }

    template<typename T>
    inline auto rotation_mat(const T& radians) noexcept
    {
      using U = decltype(math::sin(radians));
      U s, c;
      math::sincos(radians, s, c);
      return mat<U, 2, 2>{
        { c, s },
        { -s, c },
      };
    }

    template<typename T>
    inline auto rotation_mat(
        const T& axis_x,
        const T& axis_y,
        const T& axis_z,
        const T& radians) noexcept
    {
      using U = decltype(math::sin(radians));
      const U x = static_cast<U>(axis_x);
      const U y = static_cast<U>(axis_y);
      const U z = static_cast<U>(axis_z);

      U s, c;
      math::sincos(radians, s, c);
      const U omc = 1 - c;

      const U xx = x * x;
      const U xy = x * y;
      const U xz = x * z;
      const U xs = x * s;
      const U yy = y * y;
      const U yz = y * z;
      const U ys = y * s;
      const U zz = z * z;
      const U zs = z * s;
      const U xxomc = xx * omc;
      const U xyomc = xy * omc;
      const U xzomc = xz * omc;
      const U yyomc = yy * omc;
      const U yzomc = yz * omc;
      const U zzomc = zz * omc;

      return mat<U, 3, 3>{
        { xxomc + c, xyomc + zs, xzomc - ys },
        { xyomc - zs, yyomc + c, yzomc + xs },
        { xzomc + ys, yzomc - xs, zzomc + c },
      };
    }

    template<typename T>
    inline auto rotation_mat(
        const vec3<T>& axis,
        const T& radians) noexcept
    {
      return rotation_mat(axis.x(), axis.y(), axis.z(), radians);
    }

    template<typename T>
    inline mat<T, 3, 3> rotation_mat(const quat<T>& q) noexcept
    {
      const T x = q.x();
      const T y = q.y();
      const T z = q.z();
      const T w = q.w();
      const T xx2 = x * x * 2;
      const T xy2 = x * y * 2;
      const T xz2 = x * z * 2;
      const T xw2 = x * w * 2;
      const T yy2 = y * y * 2;
      const T yz2 = y * z * 2;
      const T yw2 = y * w * 2;
      const T zz2 = z * z * 2;
      const T zw2 = z * w * 2;
      return {
        { 1 - yy2 - zz2, xy2 - zw2, xz2 + yw2 },
        { xy2 + zw2, 1 - xx2 - zz2, yz2 - xw2 },
        { xz2 - yw2, yz2 + xw2, 1 - xx2 - yy2 },
      };
    }

    template<typename T>
    inline mat<T, 2, 2> scale_mat(
        const T& x, const T& y) noexcept
    {
      return {
        { x, 0 },
        { 0, y },
      };
    }

    template<typename T>
    inline mat<T, 2, 2> scale_mat(
        const vec2<T>& xy) noexcept
    {
      return scale_mat(xy.x(), xy.y());
    }

    template<typename T>
    inline mat<T, 3, 3> scale_mat(
        const T& x, const T& y, const T& z) noexcept
    {
      return {
        { x, 0, 0 },
        { 0, y, 0 },
        { 0, 0, z },
      };
    }

    template<typename T>
    inline mat<T, 3, 3> scale_mat(
        const vec3<T>& xyz) noexcept
    {
      return scale_mat(xyz.x(), xyz.y(), xyz.z());
    }

    template<typename T>
    inline mat<T, 3, 2> camera_mat(
        const vec2<T>& translation,
        const T& rotation,
        const vec2<T>& scale = vec2<T>(T(1))) noexcept
    {
      return scale_mat(1 / scale)
          * rotation_mat(-rotation)
          * translation_mat(-translation);
    }

    template<typename T>
    inline mat<T, 4, 3> camera_mat(
        const vec3<T>& translation,
        const quat<T>& rotation,
        const vec3<T>& scale = vec3<T>(T(1))) noexcept
    {
      return scale_mat(1 / scale)
          * rotation_mat(math::conjugate(rotation))
          * translation_mat(-translation);
    }

    template<typename T>
    inline auto perspective_mat(
        const T& fovy,
        const T& aspect,
        const T& near,
        const T& far)
    {
      using U = decltype(math::sin(fovy));
      U s, c;
      math::sincos(fovy/2, s, c);
      const U f = c / s;
      const U nmf = static_cast<U>(near - far);

      return mat<U, 4, 4>{
        { f / aspect, 0,             0,  0 },
        { 0,          f,             0,  0 },
        { 0, 0,     (near + far) / nmf, -1 },
        { 0, 0, (2 * near * far) / nmf,  0 },
      };
    }
  }
}