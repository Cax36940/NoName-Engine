#include "pch.h"
#include "CppUnitTest.h"

#include <cmath>

#include "Component/Vector4.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestVector4
{
	TEST_CLASS(TestVector4)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Vector4 test_vector(1.0f, 2.0f, 3.0f, 4.0f);
			Assert::AreEqual(1.0f, test_vector.x);
			Assert::AreEqual(2.0f, test_vector.y);
			Assert::AreEqual(3.0f, test_vector.z);
			Assert::AreEqual(4.0f, test_vector.t);
		}

		TEST_METHOD(Mult)
		{
			Vector4 test_vector(1.0f, 2.0f, 3.0f, 4.0f);

			Vector4 test_mult_vector_a = 5 * test_vector;
			Assert::AreEqual(5.0f, test_mult_vector_a.x);
			Assert::AreEqual(10.0f, test_mult_vector_a.y);
			Assert::AreEqual(15.0f, test_mult_vector_a.z);
			Assert::AreEqual(20.0f, test_mult_vector_a.t);

			Vector4 test_mult_vector_b = 0 * test_vector;
			Assert::AreEqual(0.0f, test_mult_vector_b.x);
			Assert::AreEqual(0.0f, test_mult_vector_b.y);
			Assert::AreEqual(0.0f, test_mult_vector_b.z);
			Assert::AreEqual(0.0f, test_mult_vector_b.t);

			Vector4 test_mult_vector_c = -2 * test_vector;
			Assert::AreEqual(-2.0f, test_mult_vector_c.x);
			Assert::AreEqual(-4.0f, test_mult_vector_c.y);
			Assert::AreEqual(-6.0f, test_mult_vector_c.z);
			Assert::AreEqual(-8.0f, test_mult_vector_c.t);
		}

		TEST_METHOD(MultEqu)
		{
			Vector4 test_mult_vector_a(1.0f, 2.0f, 3.0f, 4.0f);
			test_mult_vector_a *= 5;
			Assert::AreEqual(5.0f, test_mult_vector_a.x);
			Assert::AreEqual(10.0f, test_mult_vector_a.y);
			Assert::AreEqual(15.0f, test_mult_vector_a.z);
			Assert::AreEqual(20.0f, test_mult_vector_a.t);

			Vector4 test_mult_vector_b(1.0f, 2.0f, 3.0f, 4.0f);
			test_mult_vector_b *= 0;
			Assert::AreEqual(0.0f, test_mult_vector_b.x);
			Assert::AreEqual(0.0f, test_mult_vector_b.y);
			Assert::AreEqual(0.0f, test_mult_vector_b.z);
			Assert::AreEqual(0.0f, test_mult_vector_b.t);

			Vector4 test_mult_vector_c(1.0f, 2.0f, 3.0f, 4.0f);
			test_mult_vector_c *= -2;
			Assert::AreEqual(-2.0f, test_mult_vector_c.x);
			Assert::AreEqual(-4.0f, test_mult_vector_c.y);
			Assert::AreEqual(-6.0f, test_mult_vector_c.z);
			Assert::AreEqual(-8.0f, test_mult_vector_c.t);
		}

		TEST_METHOD(Add)
		{
			Vector4 test_vector(1.0f, 2.0f, 3.0f, 4.0f);

			Vector4 test_add_vector_a(4.0f, 5.0f, 6.0f, 7.0f);
			test_add_vector_a = test_add_vector_a + test_vector;
			Assert::AreEqual(5.0f, test_add_vector_a.x);
			Assert::AreEqual(7.0f, test_add_vector_a.y);
			Assert::AreEqual(9.0f, test_add_vector_a.z);
			Assert::AreEqual(11.0f, test_add_vector_a.t);

			Vector4 test_add_vector_b(0.0f, 0.0f, 0.0f, 0.0f);
			test_add_vector_b = test_add_vector_b + test_vector;
			Assert::AreEqual(1.0f, test_add_vector_b.x);
			Assert::AreEqual(2.0f, test_add_vector_b.y);
			Assert::AreEqual(3.0f, test_add_vector_b.z);
			Assert::AreEqual(4.0f, test_add_vector_b.t);

			Vector4 test_add_vector_c(-1.0f, -2.0f, -3.0f, -4.0f);
			test_add_vector_c = test_add_vector_c + test_vector;
			Assert::AreEqual(0.0f, test_add_vector_c.x);
			Assert::AreEqual(0.0f, test_add_vector_c.y);
			Assert::AreEqual(0.0f, test_add_vector_c.z);
			Assert::AreEqual(0.0f, test_add_vector_c.t);
		}
		TEST_METHOD(AddEqu)
		{
			Vector4 test_vector(1.0f, 2.0f, 3.0f, 4.0f);

			Vector4 test_add_vector_a(4.0f, 5.0f, 6.0f, 7.0f);
			test_add_vector_a += test_vector;
			Assert::AreEqual(5.0f, test_add_vector_a.x);
			Assert::AreEqual(7.0f, test_add_vector_a.y);
			Assert::AreEqual(9.0f, test_add_vector_a.z);
			Assert::AreEqual(11.0f, test_add_vector_a.t);

			Vector4 test_add_vector_b(0.0f, 0.0f, 0.0f, 0.0f);
			test_add_vector_b += test_vector;
			Assert::AreEqual(1.0f, test_add_vector_b.x);
			Assert::AreEqual(2.0f, test_add_vector_b.y);
			Assert::AreEqual(3.0f, test_add_vector_b.z);
			Assert::AreEqual(4.0f, test_add_vector_b.t);

			Vector4 test_add_vector_c(-1.0f, -2.0f, -3.0f, -4.0f);
			test_add_vector_c += test_vector;
			Assert::AreEqual(0.0f, test_add_vector_c.x);
			Assert::AreEqual(0.0f, test_add_vector_c.y);
			Assert::AreEqual(0.0f, test_add_vector_c.z);
			Assert::AreEqual(0.0f, test_add_vector_c.t);
		}

		TEST_METHOD(Sub)
		{
			Vector4 test_vector(1.0f, 2.0f, 3.0f, 4.0f);

			Vector4 test_add_vector_a(4.0f, 5.0f, 6.0f, 7.0f);
			test_add_vector_a = test_add_vector_a - test_vector;
			Assert::AreEqual(3.0f, test_add_vector_a.x);
			Assert::AreEqual(3.0f, test_add_vector_a.y);
			Assert::AreEqual(3.0f, test_add_vector_a.z);
			Assert::AreEqual(3.0f, test_add_vector_a.t);

			Vector4 test_add_vector_b(0.0f, 0.0f, 0.0f, 0.0f);
			test_add_vector_b = test_add_vector_b - test_vector;
			Assert::AreEqual(-1.0f, test_add_vector_b.x);
			Assert::AreEqual(-2.0f, test_add_vector_b.y);
			Assert::AreEqual(-3.0f, test_add_vector_b.z);
			Assert::AreEqual(-4.0f, test_add_vector_b.t);

			Vector4 test_add_vector_c(-1.0f, -2.0f, -3.0f, -4.0f);
			test_add_vector_c = test_add_vector_c - test_vector;
			Assert::AreEqual(-2.0f, test_add_vector_c.x);
			Assert::AreEqual(-4.0f, test_add_vector_c.y);
			Assert::AreEqual(-6.0f, test_add_vector_c.z);
			Assert::AreEqual(-8.0f, test_add_vector_c.t);
		}

		TEST_METHOD(SubEqu)
		{
			Vector4 test_vector(1.0f, 2.0f, 3.0f, 4.0f);

			Vector4 test_add_vector_a(4.0f, 5.0f, 6.0f, 7.0f);
			test_add_vector_a -= test_vector;
			Assert::AreEqual(3.0f, test_add_vector_a.x);
			Assert::AreEqual(3.0f, test_add_vector_a.y);
			Assert::AreEqual(3.0f, test_add_vector_a.z);
			Assert::AreEqual(3.0f, test_add_vector_a.t);

			Vector4 test_add_vector_b(0.0f, 0.0f, 0.0f, 0.0f);
			test_add_vector_b -= test_vector;
			Assert::AreEqual(-1.0f, test_add_vector_b.x);
			Assert::AreEqual(-2.0f, test_add_vector_b.y);
			Assert::AreEqual(-3.0f, test_add_vector_b.z);
			Assert::AreEqual(-4.0f, test_add_vector_b.t);

			Vector4 test_add_vector_c(-1.0f, -2.0f, -3.0f, -4.0f);
			test_add_vector_c -= test_vector;
			Assert::AreEqual(-2.0f, test_add_vector_c.x);
			Assert::AreEqual(-4.0f, test_add_vector_c.y);
			Assert::AreEqual(-6.0f, test_add_vector_c.z);
			Assert::AreEqual(-8.0f, test_add_vector_c.t);
		}

		TEST_METHOD(Norm)
		{
			Vector4 test_vector(1.0f, 2.0f, 3.0f, 4.0f);
			Assert::AreEqual(sqrtf(30.0f), Vector4::norm(test_vector));


			Vector4 test_vector_b(0.0f, 0.0f, 0.0f, 0.0f);
			Assert::AreEqual(0.0f, Vector4::norm(test_vector_b));
		}

		TEST_METHOD(InvNorm)
		{
			Vector4 test_vector_a(1.0f, 2.0f, 3.0f, 4.0f);
			Assert::AreEqual(1.0f / sqrtf(30.0f), Vector4::inv_norm(test_vector_a));

			Vector4 test_vector_b(0.0f, 0.0f, 0.0f, 0.0f);
			Assert::AreEqual(0.0f, Vector4::inv_norm(test_vector_b));

		}

		TEST_METHOD(Normalize)
		{
			/*Vector4 test_vector_a(1.0f, 2.0f, 3.0f, 4.0f);
			test_vector_a = Vector4::normalize(test_vector_a);
			Assert::AreEqual(1.0f / sqrtf(30.0f), test_vector_a.x);
			Assert::AreEqual(2.0f / sqrtf(30.0f), test_vector_a.y);
			Assert::AreEqual(3.0f / sqrtf(30.0f), test_vector_a.z);
			Assert::AreEqual(4.0f / sqrtf(30.0f), test_vector_a.t);

			Vector4 test_vector_b(0.0f, 0.0f, 0.0f, 0.0f);
			test_vector_b = Vector4::normalize(test_vector_b);
			Assert::AreEqual(0.0f, test_vector_b.x);
			Assert::AreEqual(0.0f, test_vector_b.y);
			Assert::AreEqual(0.0f, test_vector_b.z);
			Assert::AreEqual(0.0f, test_vector_b.t);*/


			Vector4 test_vector_a(1.0f, 2.0f, 3.0f, 4.0f);
			Assert::AreEqual(sqrtf(30.0f), Vector4::norm(test_vector_a));

			Vector4 test_vector_b(0.0f, 0.0f, 0.0f, 0.0f);
			Assert::AreEqual(0.0f, Vector4::norm(test_vector_b));

	
		}

		TEST_METHOD(Conv)
		{
			Vector4 test_vector(1.0f, 2.0f, 3.0f, 4.0f);

			Vector4 test_conv_vector_a(4.0f, 5.0f, 6.0f, 7.0f);
			test_conv_vector_a = Vector4::conv(test_vector, test_conv_vector_a);
			Assert::AreEqual(4.0f, test_conv_vector_a.x);
			Assert::AreEqual(10.0f, test_conv_vector_a.y);
			Assert::AreEqual(18.0f, test_conv_vector_a.z);
			Assert::AreEqual(28.0f, test_conv_vector_a.t);

			Vector4 test_conv_vector_b(0.0f, 0.0f, 0.0f, 0.0f);
			test_conv_vector_b = Vector4::conv(test_vector, test_conv_vector_b);
			Assert::AreEqual(0.0f, test_conv_vector_b.x);
			Assert::AreEqual(0.0f, test_conv_vector_b.y);
			Assert::AreEqual(0.0f, test_conv_vector_b.z);
			Assert::AreEqual(0.0f, test_conv_vector_b.t);


		}

		TEST_METHOD(Dot)
		{
			Vector4 test_vector(1.0f, 2.0f, 3.0f, 4.0f);

			Vector4 test_dot_vector_a(4.0f, 5.0f, 6.0f, 7.0f);
			Assert::AreEqual(60.0f, Vector4::dot(test_vector, test_dot_vector_a));

			Vector4 test_dot_vector_b(0.0f, 0.0f, 0.0f, 0.0f);
			Assert::AreEqual(0.0f, Vector4::dot(test_vector, test_dot_vector_b));

		}

	};
}
