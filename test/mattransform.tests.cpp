//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/mat.hpp>
#include <mon/test_case.hpp>

using namespace tue;

namespace
{
  TEST_CASE(translation_mat_2d)
  {
    const fmat3x2 m1 = math::translation_mat(1.1f, 2.2f);
    test_assert(m1[0] == fvec2(1.0f, 0.0f));
    test_assert(m1[1] == fvec2(0.0f, 1.0f));
    test_assert(m1[2] == fvec2(1.1f, 2.2f));

    const fmat3x2 m2 = math::translation_mat(fvec2(1.1f, 2.2f));
    test_assert(m2 == m1);
  }

  TEST_CASE(translation_mat_3d)
  {
    const fmat4x3 m1 = math::translation_mat(1.1f, 2.2f, 3.3f);
    test_assert(m1[0] == fvec3(1.0f, 0.0f, 0.0f));
    test_assert(m1[1] == fvec3(0.0f, 1.0f, 0.0f));
    test_assert(m1[2] == fvec3(0.0f, 0.0f, 1.0f));
    test_assert(m1[3] == fvec3(1.1f, 2.2f, 3.3f));

    const fmat4x3 m2 = math::translation_mat(fvec3(1.1f, 2.2f, 3.3f));
    test_assert(m2 == m1);
  }

  TEST_CASE(rotation_mat_2d)
  {
    const fmat2x2 m = math::rotation_mat(1.23f);
    test_assert(m[0] == fvec2( math::cos(1.23f), math::sin(1.23f)));
    test_assert(m[1] == fvec2(-math::sin(1.23f), math::cos(1.23f)));
  }

  TEST_CASE(rotation_mat_3d)
  {
    const float x = 1.1f;
    const float y = 2.2f;
    const float z = 3.3f;
    const float w = 4.4f;
    const float s = math::sin(w);
    const float c = math::cos(w);
    const fmat3x3 m1 = math::rotation_mat(x, y, z, w);
    test_assert(m1[0][0] == x*x*(1-c) + c);
    test_assert(m1[0][1] == y*x*(1-c) + z*s);
    test_assert(m1[0][2] == x*z*(1-c) - y*s);
    test_assert(m1[1][0] == x*y*(1-c) - z*s);
    test_assert(m1[1][1] == y*y*(1-c) + c);
    test_assert(m1[1][2] == y*z*(1-c) + x*s);
    test_assert(m1[2][0] == x*z*(1-c) + y*s);
    test_assert(m1[2][1] == y*z*(1-c) - x*s);
    test_assert(m1[2][2] == z*z*(1-c) + c);

    const fmat3x3 m2 = math::rotation_mat(fvec3(x, y, z), w);
    test_assert(m2 == m1);
  }

  TEST_CASE(rotation_mat_quat)
  {
    const float x = 1.1f;
    const float y = 2.2f;
    const float z = 3.3f;
    const float w = 4.4f;
    const fmat3x3 m = math::rotation_mat(fquat(x, y, z, w));
    test_assert(m[0][0] == 1 - 2*y*y -2*z*z);
    test_assert(m[0][1] == 2*x*y - 2*z*w);
    test_assert(m[0][2] == 2*x*z + 2*y*w);
    test_assert(m[1][0] == 2*x*y + 2*z*w);
    test_assert(m[1][1] == 1 - 2*x*x - 2*z*z);
    test_assert(m[1][2] == 2*y*z - 2*x*w);
    test_assert(m[2][0] == 2*x*z - 2*y*w);
    test_assert(m[2][1] == 2*y*z + 2*x*w);
    test_assert(m[2][2] == 1 - 2*x*x - 2*y*y);
  }

  TEST_CASE(scale_mat_2d)
  {
    const fmat2x2 m1 = math::scale_mat(1.1f, 2.2f);
    test_assert(m1[0] == fvec2(1.1f, 0.0f));
    test_assert(m1[1] == fvec2(0.0f, 2.2f));

    const fmat2x2 m2 = math::scale_mat(fvec2(1.1f, 2.2f));
    test_assert(m2 == m1);
  }

  TEST_CASE(scale_mat_3d)
  {
    const fmat3x3 m1 = math::scale_mat(1.1f, 2.2f, 3.3f);
    test_assert(m1[0] == fvec3(1.1f, 0.0f, 0.0f));
    test_assert(m1[1] == fvec3(0.0f, 2.2f, 0.0f));
    test_assert(m1[2] == fvec3(0.0f, 0.0f, 3.3f));

    const fmat3x3 m2 = math::scale_mat(fvec3(1.1f, 2.2f, 3.3f));
    test_assert(m2 == m1);
  }

  TEST_CASE(camera_mat_2d)
  {
    const fvec2 translation(1.1f, 2.2f);
    const float rotation = 3.3f;
    const fmat3x2 m1 = math::camera_mat(translation, rotation);
    test_assert(m1
        == math::rotation_mat(-rotation)
        * math::translation_mat(-translation));

    const fvec2 scale(4.4f, 5.5f);
    const fmat3x2 m2 = math::camera_mat(translation, rotation, scale);
    test_assert(m2
        == math::scale_mat(1 / scale)
        * math::rotation_mat(-rotation)
        * math::translation_mat(-translation));
  }

  TEST_CASE(camera_mat_3d)
  {
    const fvec3 translation(1.1f, 2.2f, 3.3f);
    const fquat rotation(4.4f, 5.5f, 6.6f, 7.7f);
    const fmat4x3 m1 = math::camera_mat(translation, rotation);
    test_assert(m1
        == math::rotation_mat(math::conjugate(rotation))
        * math::translation_mat(-translation));

    const fvec3 scale(8.8f, 9.9f, 10.11f);
    const fmat4x3 m2 = math::camera_mat(translation, rotation, scale);
    test_assert(m2
        == math::scale_mat(1 / scale)
        * math::rotation_mat(math::conjugate(rotation))
        * math::translation_mat(-translation));
  }

  TEST_CASE(perspective_mat)
  {
    const float fovy = 1.1f;
    const float aspect = 2.2f;
    const float near = 3.3f;
    const float far = 4.4f;
    const float f = math::cos(fovy/2) / math::sin(fovy/2);
    const fmat4x4 m = math::perspective_mat(fovy, aspect, near, far);
    test_assert(m[0][0] == f/aspect);
    test_assert(m[0][1] == 0.0f);
    test_assert(m[0][2] == 0.0f);
    test_assert(m[0][3] == 0.0f);
    test_assert(m[1][0] == 0.0f);
    test_assert(m[1][1] == f);
    test_assert(m[1][2] == 0.0f);
    test_assert(m[1][3] == 0.0f);
    test_assert(m[2][0] == 0.0f);
    test_assert(m[2][1] == 0.0f);
    test_assert(m[2][2] == (near+far) / (near-far));
    test_assert(m[2][3] == -1.0f);
    test_assert(m[3][0] == 0.0f);
    test_assert(m[3][1] == 0.0f);
    test_assert(m[3][2] == (2*near*far) / (near-far));
    test_assert(m[3][3] == 0.0f);
  }
}