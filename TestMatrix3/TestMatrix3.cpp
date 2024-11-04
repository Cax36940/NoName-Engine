#include "pch.h"
#include "CppUnitTest.h"

#include "Component/Matrix3.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestMatrix3
{
	TEST_CLASS(TestMatrix3)
	{
	public:
		
		TEST_METHOD(Default_Constructor)
		{
			Matrix3 test_matrix;
			Assert::AreEqual(1.0f, test_matrix.x.x);
			Assert::AreEqual(0.0f, test_matrix.x.y);
			Assert::AreEqual(0.0f, test_matrix.x.z);
			Assert::AreEqual(0.0f, test_matrix.y.x);
			Assert::AreEqual(1.0f, test_matrix.y.y);
			Assert::AreEqual(0.0f, test_matrix.y.z);
			Assert::AreEqual(0.0f, test_matrix.z.x);
			Assert::AreEqual(0.0f, test_matrix.z.y);
			Assert::AreEqual(1.0f, test_matrix.z.z);
		}

		TEST_METHOD(Constructor)
		{
			Matrix3 test_matrix(Vector3(1,2,3), Vector3(4,5,6), Vector3(7,8,9));
			Assert::AreEqual(1.0f, test_matrix.x.x);
			Assert::AreEqual(2.0f, test_matrix.x.y);
			Assert::AreEqual(3.0f, test_matrix.x.z);
			Assert::AreEqual(4.0f, test_matrix.y.x);
			Assert::AreEqual(5.0f, test_matrix.y.y);
			Assert::AreEqual(6.0f, test_matrix.y.z);
			Assert::AreEqual(7.0f, test_matrix.z.x);
			Assert::AreEqual(8.0f, test_matrix.z.y);
			Assert::AreEqual(9.0f, test_matrix.z.z);
		}

		TEST_METHOD(Scalar_Mult_Right)
		{
			Matrix3 test_matrix(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(7, 8, 9));
			Matrix3 result = 10 * test_matrix;
			Assert::AreEqual(10.0f, result.x.x);
			Assert::AreEqual(20.0f, result.x.y);
			Assert::AreEqual(30.0f, result.x.z);
			Assert::AreEqual(40.0f, result.y.x);
			Assert::AreEqual(50.0f, result.y.y);
			Assert::AreEqual(60.0f, result.y.z);
			Assert::AreEqual(70.0f, result.z.x);
			Assert::AreEqual(80.0f, result.z.y);
			Assert::AreEqual(90.0f, result.z.z);
		}

		TEST_METHOD(Scalar_Mult_Left)
		{
			Matrix3 test_matrix(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(7, 8, 9));
			Matrix3 result = test_matrix * 10;
			Assert::AreEqual(10.0f, result.x.x);
			Assert::AreEqual(20.0f, result.x.y);
			Assert::AreEqual(30.0f, result.x.z);
			Assert::AreEqual(40.0f, result.y.x);
			Assert::AreEqual(50.0f, result.y.y);
			Assert::AreEqual(60.0f, result.y.z);
			Assert::AreEqual(70.0f, result.z.x);
			Assert::AreEqual(80.0f, result.z.y);
			Assert::AreEqual(90.0f, result.z.z);
		}

		TEST_METHOD(Scalar_Mult_Assignment)
		{
			Matrix3 test_matrix(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(7, 8, 9));
			test_matrix *= 10;
			Assert::AreEqual(10.0f, test_matrix.x.x);
			Assert::AreEqual(20.0f, test_matrix.x.y);
			Assert::AreEqual(30.0f, test_matrix.x.z);
			Assert::AreEqual(40.0f, test_matrix.y.x);
			Assert::AreEqual(50.0f, test_matrix.y.y);
			Assert::AreEqual(60.0f, test_matrix.y.z);
			Assert::AreEqual(70.0f, test_matrix.z.x);
			Assert::AreEqual(80.0f, test_matrix.z.y);
			Assert::AreEqual(90.0f, test_matrix.z.z);
		}

		TEST_METHOD(Matrix_Mult)
		{
			Matrix3 test_matrix(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(7, 8, 9));
			Matrix3 result = test_matrix * test_matrix;
			Assert::AreEqual(30.0f, result.x.x);
			Assert::AreEqual(36.0f, result.x.y);
			Assert::AreEqual(42.0f, result.x.z);
			Assert::AreEqual(66.0f, result.y.x);
			Assert::AreEqual(81.0f, result.y.y);
			Assert::AreEqual(96.0f, result.y.z);
			Assert::AreEqual(102.0f, result.z.x);
			Assert::AreEqual(126.0f, result.z.y);
			Assert::AreEqual(150.0f, result.z.z);
		}

		TEST_METHOD(Vectorial_Product)
		{
			Matrix3 test_matrix(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(7, 8, 9));
			Vector3 vect(1, 2, 3);
			Vector3 result = test_matrix * vect;
			Assert::AreEqual(30.0f, result.x);
			Assert::AreEqual(36.0f, result.y);
			Assert::AreEqual(42.0f, result.z);
		}

		TEST_METHOD(Matrix_Add)
		{
			Matrix3 test_matrix(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(7, 8, 9));
			Matrix3 result = test_matrix + test_matrix;
			Assert::AreEqual(2.0f, result.x.x);
			Assert::AreEqual(4.0f, result.x.y);
			Assert::AreEqual(6.0f, result.x.z);
			Assert::AreEqual(8.0f, result.y.x);
			Assert::AreEqual(10.0f, result.y.y);
			Assert::AreEqual(12.0f, result.y.z);
			Assert::AreEqual(14.0f, result.z.x);
			Assert::AreEqual(16.0f, result.z.y);
			Assert::AreEqual(18.0f, result.z.z);
		}

		TEST_METHOD(Matrix_Add_Assignment)
		{
			Matrix3 test_matrix(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(7, 8, 9));
			test_matrix += test_matrix;
			Assert::AreEqual(2.0f, test_matrix.x.x);
			Assert::AreEqual(4.0f, test_matrix.x.y);
			Assert::AreEqual(6.0f, test_matrix.x.z);
			Assert::AreEqual(8.0f, test_matrix.y.x);
			Assert::AreEqual(10.0f, test_matrix.y.y);
			Assert::AreEqual(12.0f, test_matrix.y.z);
			Assert::AreEqual(14.0f, test_matrix.z.x);
			Assert::AreEqual(16.0f, test_matrix.z.y);
			Assert::AreEqual(18.0f, test_matrix.z.z);
		}

		TEST_METHOD(Matrix_Rem)
		{
			Matrix3 test_matrix(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(7, 8, 9));
			Matrix3 result = test_matrix - test_matrix;
			Assert::AreEqual(.0f, result.x.x);
			Assert::AreEqual(.0f, result.x.y);
			Assert::AreEqual(.0f, result.x.z);
			Assert::AreEqual(.0f, result.y.x);
			Assert::AreEqual(.0f, result.y.y);
			Assert::AreEqual(.0f, result.y.z);
			Assert::AreEqual(.0f, result.z.x);
			Assert::AreEqual(.0f, result.z.y);
			Assert::AreEqual(.0f, result.z.z);
		}

		TEST_METHOD(Matrix_Rem_Assignment)
		{
			Matrix3 test_matrix(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(7, 8, 9));
			test_matrix -= test_matrix;
			Assert::AreEqual(.0f, test_matrix.x.x);
			Assert::AreEqual(.0f, test_matrix.x.y);
			Assert::AreEqual(.0f, test_matrix.x.z);
			Assert::AreEqual(.0f, test_matrix.y.x);
			Assert::AreEqual(0.0f, test_matrix.y.y);
			Assert::AreEqual(.0f, test_matrix.y.z);
			Assert::AreEqual(.0f, test_matrix.z.x);
			Assert::AreEqual(.0f, test_matrix.z.y);
			Assert::AreEqual(.0f, test_matrix.z.z);
		}

		TEST_METHOD(Determinant)
		{
			Matrix3 test_matrix(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(7, 8, 9));
			float det = Matrix3::determinant(test_matrix);
			Assert::AreEqual(.0f, det);
		}

		TEST_METHOD(Inverse)
		{
			const float epsilon = 1e-5f;
			Matrix3 test_matrix(Vector3(1, 2, 3), Vector3(2, 3, 1), Vector3(3, 1, 2));
			Matrix3 inv = Matrix3::inv(test_matrix);
			Assert::AreEqual((float) - 5 / 18, inv.x.x, epsilon);
			Assert::AreEqual((float) 1 / 18, inv.x.y, epsilon);
			Assert::AreEqual((float) 7 / 18, inv.x.z, epsilon);
			Assert::AreEqual((float)1 / 18, inv.y.x, epsilon);
			Assert::AreEqual((float)7 / 18, inv.y.y, epsilon);
			Assert::AreEqual((float)-5 / 18, inv.y.z, epsilon);
			Assert::AreEqual((float)7 / 18, inv.z.x, epsilon);
			Assert::AreEqual((float)-5 / 18, inv.z.y, epsilon);
			Assert::AreEqual((float)1 / 18, inv.z.z, epsilon);

			Matrix3 test_matrix2(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(7, 8, 9));
			Matrix3 inv2 = Matrix3::inv(test_matrix2);
			Assert::AreEqual(.0f, inv2.x.x);
			Assert::AreEqual(.0f, inv2.x.y);
			Assert::AreEqual(.0f, inv2.x.z);
			Assert::AreEqual(.0f, inv2.y.x);
			Assert::AreEqual(.0f, inv2.y.y);
			Assert::AreEqual(.0f, inv2.y.z);
			Assert::AreEqual(.0f, inv2.z.x);
			Assert::AreEqual(.0f, inv2.z.y);
			Assert::AreEqual(.0f, inv2.z.z);
		}

		/*TEST_METHOD(Gram Schmidt)
		{
			const float epsilon = 1e-5f;
			Vector3 dir = Vector3(1, 2, 3);
			Matrix3 base = Matrix3::get_orthonormal_base(dir);
			Assert::AreEqual((float)-5 / 18, inv.x.x, epsilon);
			Assert::AreEqual((float)1 / 18, inv.x.y, epsilon);
			Assert::AreEqual((float)7 / 18, inv.x.z, epsilon);
			Assert::AreEqual((float)1 / 18, inv.y.x, epsilon);
			Assert::AreEqual((float)7 / 18, inv.y.y, epsilon);
			Assert::AreEqual((float)-5 / 18, inv.y.z, epsilon);
			Assert::AreEqual((float)7 / 18, inv.z.x, epsilon);
			Assert::AreEqual((float)-5 / 18, inv.z.y, epsilon);
			Assert::AreEqual((float)1 / 18, inv.z.z, epsilon);
		}*/
	};
}
