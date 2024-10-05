#include "pch.h"
#include "CppUnitTest.h"

#include <cmath>

#include "Component/Vector3.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestVector3
{
	TEST_CLASS(TestVector3)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Vector3 test_vector(1.0f, 2.0f, 3.0f);
			Assert::AreEqual(1.0f, test_vector.x);
			Assert::AreEqual(2.0f, test_vector.y);
			Assert::AreEqual(3.0f, test_vector.z);
		}

		TEST_METHOD(Mult)
		{
			Vector3 test_vector(1.0f, 2.0f, 3.0f);

			Vector3 test_mult_vector_a = 5 * test_vector;
			Assert::AreEqual(5.0f, test_mult_vector_a.x);
			Assert::AreEqual(10.0f, test_mult_vector_a.y);
			Assert::AreEqual(15.0f, test_mult_vector_a.z);

			Vector3 test_mult_vector_b = 0 * test_vector;
			Assert::AreEqual(0.0f, test_mult_vector_b.x);
			Assert::AreEqual(0.0f, test_mult_vector_b.y);
			Assert::AreEqual(0.0f, test_mult_vector_b.z);

			Vector3 test_mult_vector_c = -2 * test_vector;
			Assert::AreEqual(-2.0f, test_mult_vector_c.x);
			Assert::AreEqual(-4.0f, test_mult_vector_c.y);
			Assert::AreEqual(-6.0f, test_mult_vector_c.z);
		}

		TEST_METHOD(MultEqu)
		{
			Vector3 test_mult_vector_a(1.0f, 2.0f, 3.0f);
			test_mult_vector_a *= 5;
			Assert::AreEqual(5.0f, test_mult_vector_a.x);
			Assert::AreEqual(10.0f, test_mult_vector_a.y);
			Assert::AreEqual(15.0f, test_mult_vector_a.z);

			Vector3 test_mult_vector_b(1.0f, 2.0f, 3.0f);
			test_mult_vector_b *= 0;
			Assert::AreEqual(0.0f, test_mult_vector_b.x);
			Assert::AreEqual(0.0f, test_mult_vector_b.y);
			Assert::AreEqual(0.0f, test_mult_vector_b.z);

			Vector3 test_mult_vector_c(1.0f, 2.0f, 3.0f);
			test_mult_vector_c *= -2;
			Assert::AreEqual(-2.0f, test_mult_vector_c.x);
			Assert::AreEqual(-4.0f, test_mult_vector_c.y);
			Assert::AreEqual(-6.0f, test_mult_vector_c.z);
		}

		TEST_METHOD(Add)
		{
			Vector3 test_vector(1.0f, 2.0f, 3.0f);

			Vector3 test_add_vector_a(4.0f, 5.0f, 6.0f);
			test_add_vector_a = test_add_vector_a + test_vector;
			Assert::AreEqual(5.0f, test_add_vector_a.x);
			Assert::AreEqual(7.0f, test_add_vector_a.y);
			Assert::AreEqual(9.0f, test_add_vector_a.z);

			Vector3 test_add_vector_b(0.0f, 0.0f, 0.0f);
			test_add_vector_b = test_add_vector_b + test_vector;
			Assert::AreEqual(1.0f, test_add_vector_b.x);
			Assert::AreEqual(2.0f, test_add_vector_b.y);
			Assert::AreEqual(3.0f, test_add_vector_b.z);

			Vector3 test_add_vector_c(-1.0f, -2.0f, -3.0f);
			test_add_vector_c = test_add_vector_c + test_vector;
			Assert::AreEqual(0.0f, test_add_vector_c.x);
			Assert::AreEqual(0.0f, test_add_vector_c.y);
			Assert::AreEqual(0.0f, test_add_vector_c.z);
		}

		TEST_METHOD(AddEqu)
		{
			Vector3 test_vector(1.0f, 2.0f, 3.0f);

			Vector3 test_add_vector_a(4.0f, 5.0f, 6.0f);
			test_add_vector_a += test_vector;
			Assert::AreEqual(5.0f, test_add_vector_a.x);
			Assert::AreEqual(7.0f, test_add_vector_a.y);
			Assert::AreEqual(9.0f, test_add_vector_a.z);

			Vector3 test_add_vector_b(0.0f, 0.0f, 0.0f);
			test_add_vector_b += test_vector;
			Assert::AreEqual(1.0f, test_add_vector_b.x);
			Assert::AreEqual(2.0f, test_add_vector_b.y);
			Assert::AreEqual(3.0f, test_add_vector_b.z);

			Vector3 test_add_vector_c(-1.0f, -2.0f, -3.0f);
			test_add_vector_c += test_vector;
			Assert::AreEqual(0.0f, test_add_vector_c.x);
			Assert::AreEqual(0.0f, test_add_vector_c.y);
			Assert::AreEqual(0.0f, test_add_vector_c.z);
		}

		TEST_METHOD(Sub)
		{
			Vector3 test_vector(1.0f, 2.0f, 3.0f);

			Vector3 test_add_vector_a(4.0f, 5.0f, 6.0f);
			test_add_vector_a = test_add_vector_a - test_vector;
			Assert::AreEqual(3.0f, test_add_vector_a.x);
			Assert::AreEqual(3.0f, test_add_vector_a.y);
			Assert::AreEqual(3.0f, test_add_vector_a.z);

			Vector3 test_add_vector_b(0.0f, 0.0f, 0.0f);
			test_add_vector_b = test_add_vector_b - test_vector;
			Assert::AreEqual(-1.0f, test_add_vector_b.x);
			Assert::AreEqual(-2.0f, test_add_vector_b.y);
			Assert::AreEqual(-3.0f, test_add_vector_b.z);

			Vector3 test_add_vector_c(-1.0f, -2.0f, -3.0f);
			test_add_vector_c = test_add_vector_c - test_vector;
			Assert::AreEqual(-2.0f, test_add_vector_c.x);
			Assert::AreEqual(-4.0f, test_add_vector_c.y);
			Assert::AreEqual(-6.0f, test_add_vector_c.z);
		}

		TEST_METHOD(SubEqu)
		{
			Vector3 test_vector(1.0f, 2.0f, 3.0f);

			Vector3 test_add_vector_a(4.0f, 5.0f, 6.0f);
			test_add_vector_a -= test_vector;
			Assert::AreEqual(3.0f, test_add_vector_a.x);
			Assert::AreEqual(3.0f, test_add_vector_a.y);
			Assert::AreEqual(3.0f, test_add_vector_a.z);

			Vector3 test_add_vector_b(0.0f, 0.0f, 0.0f);
			test_add_vector_b -= test_vector;
			Assert::AreEqual(-1.0f, test_add_vector_b.x);
			Assert::AreEqual(-2.0f, test_add_vector_b.y);
			Assert::AreEqual(-3.0f, test_add_vector_b.z);

			Vector3 test_add_vector_c(-1.0f, -2.0f, -3.0f);
			test_add_vector_c -= test_vector;
			Assert::AreEqual(-2.0f, test_add_vector_c.x);
			Assert::AreEqual(-4.0f, test_add_vector_c.y);
			Assert::AreEqual(-6.0f, test_add_vector_c.z);
		}

		TEST_METHOD(Norm)
		{
			Vector3 test_vector_a(1.0f, 2.0f, 3.0f);
			Assert::AreEqual(sqrtf(14.0f), Vector3::norm(test_vector_a));

			Vector3 test_vector_b(0.0f, 0.0f, 0.0f);
			Assert::AreEqual(0.0f, Vector3::norm(test_vector_b));

			Vector3 test_vector_c(-4.0f, -5.0f, -6.0f);
			Assert::AreEqual(sqrtf(77.0f), Vector3::norm(test_vector_c));
		}

		TEST_METHOD(InvNorm)
		{
			Vector3 test_vector_a(1.0f, 2.0f, 3.0f);
			Assert::AreEqual(1.0f/sqrtf(14.0f), Vector3::inv_norm(test_vector_a));

			Vector3 test_vector_b(0.0f, 0.0f, 0.0f);
			Assert::AreEqual(0.0f, Vector3::inv_norm(test_vector_b));

			Vector3 test_vector_c(-4.0f, -5.0f, -6.0f);
			Assert::AreEqual(1.0f/sqrtf(77.0f), Vector3::inv_norm(test_vector_c));
		}

		TEST_METHOD(Normalize)
		{
			Vector3 test_vector_a(1.0f, 2.0f, 3.0f);
			test_vector_a = Vector3::normalize(test_vector_a);
			Assert::AreEqual(1.0f / sqrtf(14.0f), test_vector_a.x);
			Assert::AreEqual(2.0f / sqrtf(14.0f), test_vector_a.y);
			Assert::AreEqual(3.0f / sqrtf(14.0f), test_vector_a.z);

			Vector3 test_vector_b(0.0f, 0.0f, 0.0f);
			test_vector_b = Vector3::normalize(test_vector_b);
			Assert::AreEqual(0.0f, test_vector_b.x);
			Assert::AreEqual(0.0f, test_vector_b.y);
			Assert::AreEqual(0.0f, test_vector_b.z);

			Vector3 test_vector_c(-4.0f, -5.0f, -6.0f);
			test_vector_c = Vector3::normalize(test_vector_c);
			Assert::AreEqual(-4.0f * (1 / sqrtf(77.0f)), test_vector_c.x);
			Assert::AreEqual(-5.0f * (1 / sqrtf(77.0f)), test_vector_c.y);
			Assert::AreEqual(-6.0f * (1 / sqrtf(77.0f)), test_vector_c.z);
		}

		TEST_METHOD(Conv)
		{
			Vector3 test_vector(1.0f, 2.0f, 3.0f);

			Vector3 test_conv_vector_a(4.0f, 5.0f, 6.0f);
			test_conv_vector_a = Vector3::conv(test_vector, test_conv_vector_a);
			Assert::AreEqual(4.0f, test_conv_vector_a.x);
			Assert::AreEqual(10.0f, test_conv_vector_a.y);
			Assert::AreEqual(18.0f, test_conv_vector_a.z);

			Vector3 test_conv_vector_b(0.0f, 0.0f, 0.0f);
			test_conv_vector_b = Vector3::conv(test_vector, test_conv_vector_b);
			Assert::AreEqual(0.0f, test_conv_vector_b.x);
			Assert::AreEqual(0.0f, test_conv_vector_b.y);
			Assert::AreEqual(0.0f, test_conv_vector_b.z);

			Vector3 test_conv_vector_c(-1.0f, -2.0f, -3.0f);
			test_conv_vector_c = Vector3::conv(test_vector, test_conv_vector_c);
			Assert::AreEqual(-1.0f, test_conv_vector_c.x);
			Assert::AreEqual(-4.0f, test_conv_vector_c.y);
			Assert::AreEqual(-9.0f, test_conv_vector_c.z);
		}

		TEST_METHOD(Dot)
		{
			Vector3 test_vector(1.0f, 2.0f, 3.0f);

			Vector3 test_dot_vector_a(4.0f, 5.0f, 6.0f);
			Assert::AreEqual(32.0f, Vector3::dot(test_vector, test_dot_vector_a));

			Vector3 test_dot_vector_b(0.0f, 0.0f, 0.0f);
			Assert::AreEqual(0.0f, Vector3::dot(test_vector, test_dot_vector_b));

			Vector3 test_dot_vector_c(-1.0f, -2.0f, -3.0f);
			Assert::AreEqual(-14.0f, Vector3::dot(test_vector, test_dot_vector_c));
		}

		TEST_METHOD(Cross)
		{
			Vector3 test_vector(1.0f, 2.0f, 3.0f);

			Vector3 test_cross_vector_a(4.0f, 5.0f, 6.0f);
			test_cross_vector_a = Vector3::cross(test_vector, test_cross_vector_a);
			Assert::AreEqual(-3.0f, test_cross_vector_a.x);
			Assert::AreEqual(6.0f, test_cross_vector_a.y);
			Assert::AreEqual(-3.0f, test_cross_vector_a.z);

			Vector3 test_cross_vector_b(0.0f, 0.0f, 0.0f);
			test_cross_vector_b = Vector3::cross(test_vector, test_cross_vector_b);
			Assert::AreEqual(0.0f, test_cross_vector_b.x);
			Assert::AreEqual(0.0f, test_cross_vector_b.y);
			Assert::AreEqual(0.0f, test_cross_vector_b.z);

			Vector3 test_cross_vector_c(-1.0f, -2.0f, -3.0f);
			test_cross_vector_c = Vector3::cross(test_vector, test_cross_vector_c);
			Assert::AreEqual(0.0f, test_cross_vector_c.x);
			Assert::AreEqual(0.0f, test_cross_vector_c.y);
			Assert::AreEqual(0.0f, test_cross_vector_c.z);
		}
	};
}
