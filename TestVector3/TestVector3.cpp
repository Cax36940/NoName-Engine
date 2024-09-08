#include "pch.h"
#include "CppUnitTest.h"

#include "Vector3.hpp"

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

	};
}
