Header `<tue/vec.hpp>`
===============
This header provides the `vec` type, type aliases, and some related non-member
functions.

Types
-----
The `vec` type represents an N-dimensional vector with a given component type
and count. It is declared as follows:

    template<typename T, int N>
    class vec;

`T` is used to specify the component type. No restrictions are placed on this
type.

`N` is used to specify the component count. It must be an integer between 2 and
4 inclusive.

Type aliases
------------
    template<typename T>
    using vec2 = vec<T, 2>;
    
    template<typename T>
    using vec3 = vec<T, 3>;
    
    template<typename T>
    using vec4 = vec<T, 4>;
    
    using fvec2 = vec2<float>;
    using fvec3 = vec3<float>;
    using fvec4 = vec4<float>;
    using dvec2 = vec2<double>;
    using dvec3 = vec3<double>;
    using dvec4 = vec4<double>;
    using ivec2 = vec2<int>;
    using ivec3 = vec3<int>;
    using ivec4 = vec4<int>;
    using uvec2 = vec2<unsigned int>;
    using uvec3 = vec3<unsigned int>;
    using uvec4 = vec4<unsigned int>;
    using bvec2 = vec2<bool>;
    using bvec3 = vec3<bool>;
    using bvec4 = vec4<bool>;

Member types
------------
    using component_type = T;

Member constants
----------------
    static constexpr int component_count = N;

Member functions
----------------
- Object creation
    - [(constructor)](../functions/vec/constructor.md)
    - [`zero`](../functions/vec/zero.md)
    - [`x_axis`](../functions/vec/x_axis.md)
    - [`y_axis`](../functions/vec/y_axis.md)
    - [`z_axis`](../functions/vec/z_axis.md) (N >= 3)
    - [`w_axis`](../functions/vec/w_axis.md) (N >= 4)
- Accessors
    - [`x`](../functions/vec/x.md)
    - [`y`](../functions/vec/y.md)
    - [`z`](../functions/vec/z.md) (N >= 3)
    - [`w`](../functions/vec/w.md) (N >= 4)
    - [`r`](../functions/vec/r.md)
    - [`g`](../functions/vec/g.md)
    - [`b`](../functions/vec/b.md) (N >= 3)
    - [`a`](../functions/vec/a.md) (N >= 4)
    - [`xy`](../functions/vec/xy.md) (N > 2)
    - [`rg`](../functions/vec/rg.md) (N > 2)
    - [`xyz`](../functions/vec/xyz.md) (N > 3)
    - [`rgb`](../functions/vec/rgb.md) (N > 3)
    - [`data`](../functions/vec/data.md)
- Modifiers
    - [`set_x`](../functions/vec/set_x.md)
    - [`set_y`](../functions/vec/set_y.md)
    - [`set_z`](../functions/vec/set_z.md) (N >= 3)
    - [`set_w`](../functions/vec/set_w.md) (N >= 4)
    - [`set_r`](../functions/vec/set_r.md)
    - [`set_g`](../functions/vec/set_g.md)
    - [`set_b`](../functions/vec/set_b.md) (N >= 3)
    - [`set_a`](../functions/vec/set_a.md) (N >= 4)
    - [`set_xy`](../functions/vec/set_xy.md) (N > 2)
    - [`set_rg`](../functions/vec/set_rg.md) (N > 2)
    - [`set_xyz`](../functions/vec/set_xyz.md) (N > 3)
    - [`set_rgb`](../functions/vec/set_rgb.md) (N > 3)

Operators
---------
- [`+m`](../operators/vec/unary_plus.md)
- [`-m`](../operators/vec/unary_minus.md)
- [`~m`](../operators/vec/bitwise_not.md)
- [`++m`](../operators/vec/pre_increment.md)
- [`--m`](../operators/vec/pre_decrement.md)
- [`m++`](../operators/vec/post_increment.md)
- [`m--`](../operators/vec/post_decrement.md)
- [`lhs + rhs`](../operators/vec/addition.md)
- [`lhs - rhs`](../operators/vec/subtraction.md)
- [`lhs * rhs`](../operators/vec/multiplication.md)
- [`lhs / rhs`](../operators/vec/division.md)
- [`lhs % rhs`](../operators/vec/modulo.md)
- [`lhs & rhs`](../operators/vec/bitwise_and.md)
- [`lhs | rhs`](../operators/vec/bitwise_or.md)
- [`lhs ^ rhs`](../operators/vec/bitwise_xor.md)
- [`lhs << rhs`](../operators/vec/shift_left.md)
- [`lhs >> rhs`](../operators/vec/shift_right.md)
- [`m += other`](../operators/vec/addition_assignment.md)
- [`m -= other`](../operators/vec/subtraction_assignment.md)
- [`m *= other`](../operators/vec/multiplication_assignment.md)
- [`m /= other`](../operators/vec/division_assignment.md)
- [`m %= other`](../operators/vec/modulo_assignment.md)
- [`m &= other`](../operators/vec/bitwise_and_assignment.md)
- [`m |= other`](../operators/vec/bitwise_or_assignment.md)
- [`m ^= other`](../operators/vec/bitwise_xor_assignment.md)
- [`m <<= other`](../operators/vec/shift_left_assignment.md)
- [`m >>= other`](../operators/vec/shift_right_assignment.md)
- [`lhs == rhs`](../operators/vec/equal_to.md)
- [`lhs != rhs`](../operators/vec/not_equal_to.md)
- [`m[i]`](../operators/vec/subscript.md)

Non-member functions
--------------------
- [`tue::math`](../namespaces/tue/math.md)
    - [`sin`](../functions/math/sin.md)
    - [`cos`](../functions/math/cos.md)
    - [`sincos`](../functions/math/sincos.md)
    - [`exp`](../functions/math/exp.md)
    - [`log`](../functions/math/log.md)
    - [`pow`](../functions/math/pow.md)
    - [`recip`](../functions/math/recip.md)
    - [`sqrt`](../functions/math/sqrt.md)
    - [`rsqrt`](../functions/math/rsqrt.md)
    - [`min`](../functions/math/min.md)
    - [`max`](../functions/math/max.md)
    - [`abs`](../functions/math/abs.md)
    - [`dot`](../functions/math/dot.md)
    - [`cross`](../functions/math/cross.md)
    - [`length2`](../functions/math/length2.md)
    - [`length`](../functions/math/length.md)
    - [`normalize`](../functions/math/normalize.md)
    - [`comp_mult`](../functions/math/comp_mult.md)
    - [`select`](../functions/math/select.md)
    - [`less`](../functions/math/less.md)
    - [`less_equal`](../functions/math/less_equal.md)
    - [`greater`](../functions/math/greater.md)
    - [`greater_equal`](../functions/math/greater_equal.md)
    - [`equal`](../functions/math/equal.md)
    - [`not_equal`](../functions/math/not_equal.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.