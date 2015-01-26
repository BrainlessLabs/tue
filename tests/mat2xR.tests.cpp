//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/mat.hpp>
#include "test_case.hpp"

#include <tue/math.hpp>
#include <tue/unused.hpp>
#include <tue/vec.hpp>

namespace
{
	using namespace tue;

	constexpr auto f1 = 1.1f;
	constexpr auto f2 = 2.2f;

	constexpr auto d2 = 2.2;

	constexpr auto i1 = 111;

	constexpr auto u2 = 2U;

	constexpr fmat2x2 fm221 = {
		{ 1.1f, 1.2f },
		{ 2.1f, 2.2f },
	};

	constexpr fmat2x2 fm222 = {
		{ 2.2f, 2.4f },
		{ 4.2f, 4.4f },
	};

	constexpr dmat2x2 dm221 = {
		{ 1.1, 1.2 },
		{ 2.1, 2.2 },
	};

	constexpr dmat2x2 dm222 = {
		{ 2.2, 2.4 },
		{ 4.2, 4.4 },
	};

	constexpr mat2x2<int> im221 = {
		{ 111, 222 },
		{ 333, 444 },
	};

	constexpr mat2x2<int> im222 = {
		{ 2, 3 },
		{ 4, 5 },
	};

	constexpr mat2x2<unsigned int> um222 = {
		{ 2U, 3U },
		{ 4U, 5U },
	};

	TEST_CASE(default_constructor)
	{
		fmat2x2 m;
		unused(m);
	}

	TEST_CASE(scalar_constructor)
	{
		constexpr fmat2x2 m1(1.1f);
		test_assert(m1[0] == fvec2(1.1f, 0.0f));
		test_assert(m1[1] == fvec2(0.0f, 1.1f));

		constexpr fmat2x3 m2(2.2f);
		test_assert(m2[0] == fvec3(2.2f, 0.0f, 0.0f));
		test_assert(m2[1] == fvec3(0.0f, 2.2f, 0.0f));

		constexpr fmat2x4 m3(3.3f);
		test_assert(m3[0] == fvec4(3.3f, 0.0f, 0.0f, 0.0f));
		test_assert(m3[1] == fvec4(0.0f, 3.3f, 0.0f, 0.0f));
	}

	TEST_CASE(column_constructor)
	{
		constexpr fmat2x2 m = {
			{ 1.1f, 1.2f },
			{ 2.1f, 2.2f },
		};
		test_assert(m[0] == fvec2(1.1f, 1.2f));
		test_assert(m[1] == fvec2(2.1f, 2.2f));
	}

	TEST_CASE(extend_and_truncate_constructors)
	{
		// TODO
	}

	TEST_CASE(explicit_conversion_constructor)
	{
		constexpr fmat2x2 m(dm221);
		test_assert(m[0] == fvec2(dm221[0]));
		test_assert(m[1] == fvec2(dm221[1]));
	}

	TEST_CASE(implicit_conversion_operator)
	{
		CONST_OR_CONSTEXPR dmat2x2 m = fm221;
		test_assert(m[0] == dvec2(fm221[0]));
		test_assert(m[1] == dvec2(fm221[1]));
	}

	TEST_CASE(identity)
	{
		CONST_OR_CONSTEXPR auto m1 = fmat2x2::identity();
		CONST_OR_CONSTEXPR auto m2 = fmat2x3::identity();
		CONST_OR_CONSTEXPR auto m3 = fmat2x4::identity();
		test_assert(m1 == fmat2x2(1.0f));
		test_assert(m2 == fmat2x3(1.0f));
		test_assert(m3 == fmat2x4(1.0f));
	}

	TEST_CASE(zero)
	{
		CONST_OR_CONSTEXPR auto m1 = fmat2x2::zero();
		CONST_OR_CONSTEXPR auto m2 = fmat2x3::zero();
		CONST_OR_CONSTEXPR auto m3 = fmat2x4::zero();
		test_assert(m1 == fmat2x2(0.0f));
		test_assert(m2 == fmat2x3(0.0f));
		test_assert(m3 == fmat2x4(0.0f));
	}

	TEST_CASE(column)
	{
		CONST_OR_CONSTEXPR fvec2 column0 = fm221.column(0);
		CONST_OR_CONSTEXPR fvec2 column1 = fm221.column(1);
		test_assert(column0 == fm221[0]);
		test_assert(column1 == fm221[1]);
	}

	TEST_CASE(set_column)
	{
		fmat2x2 m;
		m.set_column(0, fvec2(1.1f, 1.2f));
		m.set_column(1, fvec2(2.1f, 2.2f));
		test_assert(m[0] == fvec2(1.1f, 1.2f));
		test_assert(m[1] == fvec2(2.1f, 2.2f));
	}

	TEST_CASE(row)
	{
		CONST_OR_CONSTEXPR fvec2 row0 = fm221.row(0);
		CONST_OR_CONSTEXPR fvec2 row1 = fm221.row(1);
		test_assert(row0 == fvec2(fm221[0][0], fm221[1][0]));
		test_assert(row1 == fvec2(fm221[0][1], fm221[1][1]));
	}

	TEST_CASE(set_row)
	{
		fmat2x2 m;
		m.set_row(0, fvec2(1.1f, 2.1f));
		m.set_row(1, fvec2(1.2f, 2.2f));
		test_assert(m[0] == fvec2(1.1f, 1.2f));
		test_assert(m[1] == fvec2(2.1f, 2.2f));
	}

	TEST_CASE(subscript_operator)
	{
		constexpr fmat2x2 cem = {
			{ 1.1f, 1.2f },
			{ 2.1f, 2.2f },
		};
		CONST_OR_CONSTEXPR fvec2 cem0 = cem[0];
		CONST_OR_CONSTEXPR fvec2 cem1 = cem[1];
		test_assert(cem0 == fvec2(1.1f, 1.2f));
		test_assert(cem1 == fvec2(2.1f, 2.2f));

		fmat2x2 m = cem;
		fvec2& m0 = m[0];
		fvec2& m1 = m[1];
		test_assert(static_cast<void*>(&m0) == static_cast<void*>(&m));
		test_assert(&m1 == &m0 + 1);

		const fmat2x2& cm = m;
		const fvec2& cm0 = cm[0];
		const fvec2& cm1 = cm[1];
		test_assert(&cm0 == &m0);
		test_assert(&cm1 == &m1);
	}

	TEST_CASE(pre_increment_operator)
	{
		fmat2x2 m = fm221;
		test_assert(&(++m) == &m);
		test_assert(m == fm221 + 1);
	}

	TEST_CASE(pre_decrement_operator)
	{
		fmat2x2 m = fm221;
		test_assert(&(--m) == &m);
		test_assert(m == fm221 - 1);
	}

	TEST_CASE(post_increment_operator)
	{
		fmat2x2 m = fm221;
		test_assert(m++ == fm221);
		test_assert(m == fm221 + 1);
	}

	TEST_CASE(post_decrement_operator)
	{
		fmat2x2 m = fm221;
		test_assert(m-- == fm221);
		test_assert(m == fm221 - 1);
	}

	TEST_CASE(addition_assignment_operator)
	{
		fmat2x2 m1 = fm221;
		test_assert(&(m1 += u2) == &m1);
		test_assert(m1 == fm221 + u2);

		fmat2x2 m2 = fm221;
		test_assert(&(m2 += um222) == &m2);
		test_assert(m2 == fm221 + um222);
	}

	TEST_CASE(subtraction_assignment_operator)
	{
		fmat2x2 m1 = fm221;
		test_assert(&(m1 -= u2) == &m1);
		test_assert(m1 == fm221 - u2);

		fmat2x2 m2 = fm221;
		test_assert(&(m2 -= um222) == &m2);
		test_assert(m2 == fm221 - um222);
	}

	TEST_CASE(multiplication_assignment_operator)
	{
		fmat2x2 m1 = fm221;
		test_assert(&(m1 *= u2) == &m1);
		test_assert(m1 == fm221 * u2);

		// TODO
		//fmat2x2 m2 = fm221;
		//test_assert(&(m2 *= um222) == &m2);
		//test_assert(m2 == fm221 * um222);
	}

	TEST_CASE(division_assignment_operator)
	{
		fmat2x2 m1 = fm221;
		test_assert(&(m1 /= u2) == &m1);
		test_assert(m1 == fm221 / u2);

		fmat2x2 m2 = fm221;
		test_assert(&(m2 /= um222) == &m2);
		test_assert(m2 == fm221 / um222);
	}

	TEST_CASE(modulo_assignment_operator)
	{
		mat2x2<int> m1 = im221;
		test_assert(&(m1 %= u2) == &m1);
		test_assert(m1 == im221 % u2);

		mat2x2<int> m2 = im221;
		test_assert(&(m2 %= um222) == &m2);
		test_assert(m2 == im221 % um222);
	}

	TEST_CASE(bitwise_and_assignment_operator)
	{
		mat2x2<int> m1 = im221;
		test_assert(&(m1 &= u2) == &m1);
		test_assert(m1 == (im221 & u2));

		mat2x2<int> m2 = im221;
		test_assert(&(m2 &= um222) == &m2);
		test_assert(m2 == (im221 & um222));
	}

	TEST_CASE(bitwise_or_assignment_operator)
	{
		mat2x2<int> m1 = im221;
		test_assert(&(m1 |= u2) == &m1);
		test_assert(m1 == (im221 | u2));

		mat2x2<int> m2 = im221;
		test_assert(&(m2 |= um222) == &m2);
		test_assert(m2 == (im221 | um222));
	}

	TEST_CASE(bitwise_xor_assignment_operator)
	{
		mat2x2<int> m1 = im221;
		test_assert(&(m1 ^= u2) == &m1);
		test_assert(m1 == (im221 ^ u2));

		mat2x2<int> m2 = im221;
		test_assert(&(m2 ^= um222) == &m2);
		test_assert(m2 == (im221 ^ um222));
	}

	TEST_CASE(bitwise_shift_left_assignment_operator)
	{
		mat2x2<int> m1 = im221;
		test_assert(&(m1 <<= u2) == &m1);
		test_assert(m1 == (im221 << u2));

		mat2x2<int> m2 = im221;
		test_assert(&(m2 <<= um222) == &m2);
		test_assert(m2 == (im221 << um222));
	}

	TEST_CASE(bitwise_shift_right_assignment_operator)
	{
		mat2x2<int> m1 = im221;
		test_assert(&(m1 >>= u2) == &m1);
		test_assert(m1 == (im221 >> u2));

		mat2x2<int> m2 = im221;
		test_assert(&(m2 >>= um222) == &m2);
		test_assert(m2 == (im221 >> um222));
	}

	TEST_CASE(unary_plus_operator)
	{
		CONST_OR_CONSTEXPR auto m = +fm221;
		test_assert(m[0] == +fm221[0]);
		test_assert(m[1] == +fm221[1]);
	}

	TEST_CASE(unary_minus_operator)
	{
		CONST_OR_CONSTEXPR auto m = -fm221;
		test_assert(m[0] == -fm221[0]);
		test_assert(m[1] == -fm221[1]);
	}

	TEST_CASE(bitwise_not_operator)
	{
		CONST_OR_CONSTEXPR auto m = ~im221;
		test_assert(m[0] == ~im221[0]);
		test_assert(m[1] == ~im221[1]);
	}

	TEST_CASE(addition_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = f1 + dm222;
		test_assert(m1[0] == f1 + dm222[0]);
		test_assert(m1[1] == f1 + dm222[1]);

		CONST_OR_CONSTEXPR auto m2 = fm221 + d2;
		test_assert(m2[0] == fm221[0] + d2);
		test_assert(m2[1] == fm221[1] + d2);

		CONST_OR_CONSTEXPR auto m3 = fm221 + dm222;
		test_assert(m3[0] == fm221[0] + dm222[0]);
		test_assert(m3[1] == fm221[1] + dm222[1]);
	}

	TEST_CASE(subtraction_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = f1 - dm222;
		test_assert(m1[0] == f1 - dm222[0]);
		test_assert(m1[1] == f1 - dm222[1]);

		CONST_OR_CONSTEXPR auto m2 = fm221 - d2;
		test_assert(m2[0] == fm221[0] - d2);
		test_assert(m2[1] == fm221[1] - d2);

		CONST_OR_CONSTEXPR auto m3 = fm221 - dm222;
		test_assert(m3[0] == fm221[0] - dm222[0]);
		test_assert(m3[1] == fm221[1] - dm222[1]);
	}

	TEST_CASE(multiplication_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = f1 * dm222;
		test_assert(m1[0] == f1 * dm222[0]);
		test_assert(m1[1] == f1 * dm222[1]);

		CONST_OR_CONSTEXPR auto m3 = fm221 * d2;
		test_assert(m3[0] == fm221[0] * d2);
		test_assert(m3[1] == fm221[1] * d2);
	}

	TEST_CASE(division_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = f1 / dm222;
		test_assert(m1[0] == f1 / dm222[0]);
		test_assert(m1[1] == f1 / dm222[1]);

		CONST_OR_CONSTEXPR auto m2 = fm221 / d2;
		test_assert(m2[0] == fm221[0] / d2);
		test_assert(m2[1] == fm221[1] / d2);

		CONST_OR_CONSTEXPR auto m3 = fm221 / dm222;
		test_assert(m3[0] == fm221[0] / dm222[0]);
		test_assert(m3[1] == fm221[1] / dm222[1]);
	}

	TEST_CASE(modulo_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 % um222;
		test_assert(m1[0] == i1 % um222[0]);
		test_assert(m1[1] == i1 % um222[1]);

		CONST_OR_CONSTEXPR auto m2 = im221 % u2;
		test_assert(m2[0] == im221[0] % u2);
		test_assert(m2[1] == im221[1] % u2);

		CONST_OR_CONSTEXPR auto m3 = im221 % um222;
		test_assert(m3[0] == im221[0] % um222[0]);
		test_assert(m3[1] == im221[1] % um222[1]);
	}

	TEST_CASE(bitwise_and_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 & um222;
		test_assert(m1[0] == (i1 & um222[0]));
		test_assert(m1[1] == (i1 & um222[1]));

		CONST_OR_CONSTEXPR auto m2 = im221 & u2;
		test_assert(m2[0] == (im221[0] & u2));
		test_assert(m2[1] == (im221[1] & u2));

		CONST_OR_CONSTEXPR auto m3 = im221 & um222;
		test_assert(m3[0] == (im221[0] & um222[0]));
		test_assert(m3[1] == (im221[1] & um222[1]));
	}

	TEST_CASE(bitwise_or_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 | um222;
		test_assert(m1[0] == (i1 | um222[0]));
		test_assert(m1[1] == (i1 | um222[1]));

		CONST_OR_CONSTEXPR auto m2 = im221 | u2;
		test_assert(m2[0] == (im221[0] | u2));
		test_assert(m2[1] == (im221[1] | u2));

		CONST_OR_CONSTEXPR auto m3 = im221 | um222;
		test_assert(m3[0] == (im221[0] | um222[0]));
		test_assert(m3[1] == (im221[1] | um222[1]));
	}

	TEST_CASE(bitwise_xor_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 ^ um222;
		test_assert(m1[0] == (i1 ^ um222[0]));
		test_assert(m1[1] == (i1 ^ um222[1]));

		CONST_OR_CONSTEXPR auto m2 = im221 ^ u2;
		test_assert(m2[0] == (im221[0] ^ u2));
		test_assert(m2[1] == (im221[1] ^ u2));

		CONST_OR_CONSTEXPR auto m3 = im221 ^ um222;
		test_assert(m3[0] == (im221[0] ^ um222[0]));
		test_assert(m3[1] == (im221[1] ^ um222[1]));
	}

	TEST_CASE(bitwise_shift_left_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 << um222;
		test_assert(m1[0] == (i1 << um222[0]));
		test_assert(m1[1] == (i1 << um222[1]));

		CONST_OR_CONSTEXPR auto m2 = im221 << u2;
		test_assert(m2[0] == (im221[0] << u2));
		test_assert(m2[1] == (im221[1] << u2));

		CONST_OR_CONSTEXPR auto m3 = im221 << um222;
		test_assert(m3[0] == (im221[0] << um222[0]));
		test_assert(m3[1] == (im221[1] << um222[1]));
	}

	TEST_CASE(bitwise_shift_right_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 >> um222;
		test_assert(m1[0] == (i1 >> um222[0]));
		test_assert(m1[1] == (i1 >> um222[1]));

		CONST_OR_CONSTEXPR auto m2 = im221 >> u2;
		test_assert(m2[0] == (im221[0] >> u2));
		test_assert(m2[1] == (im221[1] >> u2));

		CONST_OR_CONSTEXPR auto m3 = im221 >> um222;
		test_assert(m3[0] == (im221[0] >> um222[0]));
		test_assert(m3[1] == (im221[1] >> um222[1]));
	}

	TEST_CASE(equality_operator)
	{
		constexpr fmat2x2 m1 = {
			fvec2(1.0f),
			fvec2(2.0f),
		};
		constexpr ivec2 iv0(0);
		constexpr ivec2 iv1(1);
		constexpr ivec2 iv2(2);
		constexpr mat2x2<int> m2(iv1, iv2);
		constexpr mat2x2<int> m3(iv0, iv2);
		constexpr mat2x2<int> m4(iv1, iv0);
		CONST_OR_CONSTEXPR bool result1 = (m1 == m2);
		CONST_OR_CONSTEXPR bool result2 = (m1 == m3);
		CONST_OR_CONSTEXPR bool result3 = (m1 == m4);
		test_assert(result1 == true);
		test_assert(result2 == false);
		test_assert(result3 == false);
	}

	TEST_CASE(inequality_operator)
	{
		constexpr fmat2x2 m1 = {
			fvec2(1.0f),
			fvec2(2.0f),
		};
		constexpr ivec2 iv0(0);
		constexpr ivec2 iv1(1);
		constexpr ivec2 iv2(2);
		constexpr mat2x2<int> m2(iv1, iv2);
		constexpr mat2x2<int> m3(iv0, iv2);
		constexpr mat2x2<int> m4(iv1, iv0);
		CONST_OR_CONSTEXPR bool result1 = (m1 != m2);
		CONST_OR_CONSTEXPR bool result2 = (m1 != m3);
		CONST_OR_CONSTEXPR bool result3 = (m1 != m4);
		test_assert(result1 == false);
		test_assert(result2 == true);
		test_assert(result3 == true);
	}

	TEST_CASE(sin)
	{
		const auto fsin = math::sin(fm221);
		test_assert(fsin[0] == math::sin(fm221[0]));
		test_assert(fsin[1] == math::sin(fm221[1]));

		const auto isin = math::sin(im221);
		test_assert(isin[0] == math::sin(im221[0]));
		test_assert(isin[1] == math::sin(im221[1]));
	}

	TEST_CASE(cos)
	{
		const auto fcos = math::cos(fm221);
		test_assert(fcos[0] == math::cos(fm221[0]));
		test_assert(fcos[1] == math::cos(fm221[1]));

		const auto icos = math::cos(im221);
		test_assert(icos[0] == math::cos(im221[0]));
		test_assert(icos[1] == math::cos(im221[1]));
	}

	TEST_CASE(sincos)
	{
		fmat2x2 fsin, fcos;
		math::sincos(fm221, fsin, fcos);
		test_assert(fsin == math::sin(fm221));
		test_assert(fcos == math::cos(fm221));

		dmat2x2 isin, icos;
		math::sincos(im221, isin, icos);
		test_assert(isin == math::sin(im221));
		test_assert(icos == math::cos(im221));
	}

	TEST_CASE(pow)
	{
		const auto fpow1 = math::pow(fm221, f2);
		test_assert(fpow1[0] == math::pow(fm221[0], f2));
		test_assert(fpow1[1] == math::pow(fm221[1], f2));

		const auto ipow1 = math::pow(im221, f2);
		test_assert(ipow1[0] == math::pow(im221[0], f2));
		test_assert(ipow1[1] == math::pow(im221[1], f2));

		const auto fpow2 = math::pow(fm221, fm222);
		test_assert(fpow2[0] == math::pow(fm221[0], fm222[0]));
		test_assert(fpow2[1] == math::pow(fm221[1], fm222[1]));

		const auto ipow2 = math::pow(im221, fm222);
		test_assert(ipow2[0] == math::pow(im221[0], fm222[0]));
		test_assert(ipow2[1] == math::pow(im221[1], fm222[1]));
	}

	TEST_CASE(rcp)
	{
		const auto frcp = math::rcp(fm221);
		test_assert(frcp[0] == math::rcp(fm221[0]));
		test_assert(frcp[1] == math::rcp(fm221[1]));

		const auto ircp = math::rcp(im221);
		test_assert(ircp[0] == math::rcp(im221[0]));
		test_assert(ircp[1] == math::rcp(im221[1]));
	}

	TEST_CASE(sqrt)
	{
		const auto fsqrt = math::sqrt(fm221);
		test_assert(fsqrt[0] == math::sqrt(fm221[0]));
		test_assert(fsqrt[1] == math::sqrt(fm221[1]));

		const auto isqrt = math::sqrt(im221);
		test_assert(isqrt[0] == math::sqrt(im221[0]));
		test_assert(isqrt[1] == math::sqrt(im221[1]));
	}

	TEST_CASE(rsqrt)
	{
		const auto frsqrt = math::rsqrt(fm221);
		test_assert(frsqrt[0] == math::rsqrt(fm221[0]));
		test_assert(frsqrt[1] == math::rsqrt(fm221[1]));

		const auto irsqrt = math::rsqrt(im221);
		test_assert(irsqrt[0] == math::rsqrt(im221[0]));
		test_assert(irsqrt[1] == math::rsqrt(im221[1]));
	}

	TEST_CASE(min)
	{
		const auto fmin = math::min(fm221, fm222);
		test_assert(fmin[0] == math::min(fm221[0], fm222[0]));
		test_assert(fmin[1] == math::min(fm221[1], fm222[1]));

		const auto imin = math::min(im221, im222);
		test_assert(imin[0] == math::min(im221[0], im222[0]));
		test_assert(imin[1] == math::min(im221[1], im222[1]));
	}

	TEST_CASE(max)
	{
		const auto fmax = math::max(fm221, fm222);
		test_assert(fmax[0] == math::max(fm221[0], fm222[0]));
		test_assert(fmax[1] == math::max(fm221[1], fm222[1]));

		const auto imax = math::max(im221, im222);
		test_assert(imax[0] == math::max(im221[0], im222[0]));
		test_assert(imax[1] == math::max(im221[1], im222[1]));
	}

	TEST_CASE(abs)
	{
		const auto fabs = math::abs(fm222);
		test_assert(fabs[0] == math::abs(fm222[0]));
		test_assert(fabs[1] == math::abs(fm222[1]));

		const auto iabs = math::abs(im222);
		test_assert(iabs[0] == math::abs(im222[0]));
		test_assert(iabs[1] == math::abs(im222[1]));

		const auto uabs = math::abs(um222);
		test_assert(uabs[0] == math::abs(um222[0]));
		test_assert(uabs[1] == math::abs(um222[1]));
	}

	TEST_CASE(compmult)
	{
		CONST_OR_CONSTEXPR auto m = math::compmult(fm221, dm222);
		test_assert(m[0] == fm221[0] * dm222[0]);
		test_assert(m[1] == fm221[1] * dm222[1]);
	}

	TEST_CASE(transpose)
	{
		constexpr fmat4x2 m42 = {
			{ 1.1f, 1.2f },
			{ 2.1f, 2.2f },
			{ 3.1f, 3.2f },
			{ 4.1f, 4.2f },
		};

		CONST_OR_CONSTEXPR fmat2x4 m1 = math::transpose(m42);
		test_assert(m1[0] == m42.row(0));
		test_assert(m1[1] == m42.row(1));

		// TODO
		//constexpr fmat3x2 m32(m43);
		//constexpr fmat2x2 m22(m43);
	}
}