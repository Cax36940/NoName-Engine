#include "CppUnitTest.h"
#include "Vector4.hpp"
#include "Transform.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestTransform
{
	TEST_CLASS(TestTransform)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			Vector4 x = Vector4(1, 2, 3, 4);
			Vector4 y = Vector4(5, 6, 7, 8);
			Vector4 z = Vector4(9, 10, 11, 12);
			Transform matrix(x,y,z);
			Assert::AreEqual(1.0f, matrix.x.x);
			Assert::AreEqual(2.0f, matrix.x.y);
			Assert::AreEqual(3.0f, matrix.x.z);
			Assert::AreEqual(4.0f, matrix.x.t);

			Assert::AreEqual(5.0f, matrix.y.x);
			Assert::AreEqual(6.0f, matrix.y.y);
			Assert::AreEqual(7.0f, matrix.y.z);
			Assert::AreEqual(8.0f, matrix.y.t);

			Assert::AreEqual(9.0f, matrix.z.x);
			Assert::AreEqual(10.0f, matrix.z.y);
			Assert::AreEqual(11.0f, matrix.z.z);
			Assert::AreEqual(12.0f, matrix.z.t);

		}

		TEST_METHOD(Mult_scalar)
		{
			Vector4 x(1, 2, 3, 4);
			Vector4 y(5, 6, 7, 8);
			Vector4 z(9, 10, 11, 12);
			Transform matrix(x, y, z);

			float scalar = 2.0f;
			Transform result = matrix * scalar;

			Assert::AreEqual(2.0f, result.x.x);
			Assert::AreEqual(4.0f, result.x.y);
			Assert::AreEqual(6.0f, result.x.z);
			Assert::AreEqual(8.0f, result.x.t);

			Assert::AreEqual(10.0f, result.y.x);
			Assert::AreEqual(12.0f, result.y.y);
			Assert::AreEqual(14.0f, result.y.z);
			Assert::AreEqual(16.0f, result.y.t);

			Assert::AreEqual(18.0f, result.z.x);
			Assert::AreEqual(20.0f, result.z.y);
			Assert::AreEqual(22.0f, result.z.z);
			Assert::AreEqual(24.0f, result.z.t);

		}

		TEST_METHOD(MultEqu_scalar)
		{
			Vector4 x(1, 2, 3, 4);
			Vector4 y(5, 6, 7, 8);
			Vector4 z(9, 10, 11, 12);
			Transform matrix(x, y, z);

			float scalar = 2.0f;
			matrix *= scalar;

			Assert::AreEqual(2.0f, matrix.x.x);
			Assert::AreEqual(4.0f, matrix.x.y);
			Assert::AreEqual(6.0f, matrix.x.z);
			Assert::AreEqual(8.0f, matrix.x.t);

			Assert::AreEqual(10.0f, matrix.y.x);
			Assert::AreEqual(12.0f, matrix.y.y);
			Assert::AreEqual(14.0f, matrix.y.z);
			Assert::AreEqual(16.0f, matrix.y.t);

			Assert::AreEqual(18.0f, matrix.z.x);
			Assert::AreEqual(20.0f, matrix.z.y);
			Assert::AreEqual(22.0f, matrix.z.z);
			Assert::AreEqual(24.0f, matrix.z.t);

		}

		TEST_METHOD(MatrixMultiplication)
		{
			Transform matrix1(Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0), Vector4(0, 0, 1, 0));
			Transform matrix2(Vector4(2, 3, 4, 5), Vector4(6, 7, 8, 9), Vector4(10, 11, 12, 13));
			Transform result = matrix1 * matrix2;

			Assert::AreEqual(2.0f, result.x.x);
			Assert::AreEqual(3.0f, result.x.y);
			Assert::AreEqual(4.0f, result.x.z);
			Assert::AreEqual(5.0f, result.x.t);

			Assert::AreEqual(6.0f, result.y.x);
			Assert::AreEqual(7.0f, result.y.y);
			Assert::AreEqual(8.0f, result.y.z);
			Assert::AreEqual(9.0f, result.y.t);

			Assert::AreEqual(10.0f, result.z.x);
			Assert::AreEqual(11.0f, result.z.y);
			Assert::AreEqual(12.0f, result.z.z);
			Assert::AreEqual(13.0f, result.z.t);

		}

		TEST_METHOD(MatrixVectorMultiplication)
		{
			Transform matrix(Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0), Vector4(0, 0, 1, 0));
			Vector4 vector(2, 3, 4, 5);
			Vector4 result = matrix * vector;

			Assert::AreEqual(2.0f, result.x);
			Assert::AreEqual(3.0f, result.y);
			Assert::AreEqual(4.0f, result.z);
			Assert::AreEqual(5.0f, result.t);
		}


		TEST_METHOD(MatrixAddition)
		{
			Transform matrix1(Vector4(1, 2, 3, 4), Vector4(5, 6, 7, 8), Vector4(9, 10, 11, 12));
			Transform matrix2(Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1));
			Transform result = matrix1 + matrix2;

			Assert::AreEqual(2.0f, result.x.x);
			Assert::AreEqual(3.0f, result.x.y);
			Assert::AreEqual(4.0f, result.x.z);
			Assert::AreEqual(5.0f, result.x.t);

			Assert::AreEqual(6.0f, result.y.x);
			Assert::AreEqual(7.0f, result.y.y);
			Assert::AreEqual(8.0f, result.y.z);
			Assert::AreEqual(9.0f, result.y.t);

			Assert::AreEqual(10.0f, result.z.x);
			Assert::AreEqual(11.0f, result.z.y);
			Assert::AreEqual(12.0f, result.z.z);
			Assert::AreEqual(13.0f, result.z.t);

		}

		TEST_METHOD(MatrixAddEqu)
		{
			Transform matrix1(Vector4(1, 2, 3, 4), Vector4(5, 6, 7, 8), Vector4(9, 10, 11, 12));
			Transform matrix2(Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1));
			matrix1 += matrix2;

			Assert::AreEqual(2.0f, matrix1.x.x);
			Assert::AreEqual(3.0f, matrix1.x.y);
			Assert::AreEqual(4.0f, matrix1.x.z);
			Assert::AreEqual(5.0f, matrix1.x.t);

			Assert::AreEqual(6.0f, matrix1.y.x);
			Assert::AreEqual(7.0f, matrix1.y.y);
			Assert::AreEqual(8.0f, matrix1.y.z);
			Assert::AreEqual(9.0f, matrix1.y.t);

			Assert::AreEqual(10.0f, matrix1.z.x);
			Assert::AreEqual(11.0f, matrix1.z.y);
			Assert::AreEqual(12.0f, matrix1.z.z);
			Assert::AreEqual(13.0f, matrix1.z.t);

		}

		TEST_METHOD(MatrixSubtraction)
		{
			Transform matrix1(Vector4(2, 3, 4, 5), Vector4(6, 7, 8, 9), Vector4(10, 11, 12, 13));
			Transform matrix2(Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1));
			Transform result = matrix1 - matrix2;

			Assert::AreEqual(1.0f, result.x.x);
			Assert::AreEqual(2.0f, result.x.y);
			Assert::AreEqual(3.0f, result.x.z);
			Assert::AreEqual(4.0f, result.x.t);

			Assert::AreEqual(5.0f, result.y.x);
			Assert::AreEqual(6.0f, result.y.y);
			Assert::AreEqual(7.0f, result.y.z);
			Assert::AreEqual(8.0f, result.y.t);

			Assert::AreEqual(9.0f, result.z.x);
			Assert::AreEqual(10.0f, result.z.y);
			Assert::AreEqual(11.0f, result.z.z);
			Assert::AreEqual(12.0f, result.z.t);

		}

		TEST_METHOD(MatrixSubEqu)
		{
			Transform matrix1(Vector4(2, 3, 4, 5), Vector4(6, 7, 8, 9), Vector4(10, 11, 12, 13));
			Transform matrix2(Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1));
			matrix1 -= matrix2;

			Assert::AreEqual(1.0f, matrix1.x.x);
			Assert::AreEqual(2.0f, matrix1.x.y);
			Assert::AreEqual(3.0f, matrix1.x.z);
			Assert::AreEqual(4.0f, matrix1.x.t);

			Assert::AreEqual(5.0f, matrix1.y.x);
			Assert::AreEqual(6.0f, matrix1.y.y);
			Assert::AreEqual(7.0f, matrix1.y.z);
			Assert::AreEqual(8.0f, matrix1.y.t);

			Assert::AreEqual(9.0f, matrix1.z.x);
			Assert::AreEqual(10.0f, matrix1.z.y);
			Assert::AreEqual(11.0f, matrix1.z.z);
			Assert::AreEqual(12.0f, matrix1.z.t);

		}

		/*TEST_METHOD(Determinant)
		{
			Transform matrix(Vector4(1, 2, 3, 4), Vector4(5, 6, 7, 8), Vector4(9, 10, 11, 12), Vector4(13, 14, 15, 16));
			float result = Transform::determinant(matrix);

			// Pour cette matrice, le déterminant est connu pour être 0
			Assert::AreEqual(0.0f, result);



			Transform matrix2(Vector4(1, 0, 1, 0), Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0), Vector4(0, 1, 4, 2));
			float res2 = Transform::determinant(matrix2);

			// Pour cette matrice, le déterminant est connu pour être 0
			Assert::AreEqual(2.0f, res2);
		}*/


		/*TEST_METHOD(Inverse)
		{
			Transform matrix(Vector4(2, 2, 3, 3), Vector4(2, 3, 3, 2), Vector4(5, 3, 7, 9), Vector4(3, 2, 4, 7));
			Transform matrix_inv = Transform::inv(matrix);
			Vector4 xinv = Vector4(26, -11, -7, 1) * (-0.5);
			Vector4 yinv = Vector4(0, -1, 1, -1) * (-0.5);
			Vector4 zinv = Vector4(-16, 7, 3, 1) * (-0.5);
			Vector4 tinv = Vector4(-2, 1, 1, -1) * (-0.5);
			
			Assert::AreEqual(xinv.x, matrix_inv.x.x, 0.0001f);
			Assert::AreEqual(xinv.y, matrix_inv.x.y, 0.0001f);
			Assert::AreEqual(xinv.z, matrix_inv.x.z, 0.0001f);
			Assert::AreEqual(xinv.t, matrix_inv.x.t, 0.0001f);

			Assert::AreEqual(yinv.x, matrix_inv.y.x, 0.0001f);
			Assert::AreEqual(yinv.y, matrix_inv.y.y, 0.0001f);
			Assert::AreEqual(yinv.z, matrix_inv.y.z, 0.0001f);
			Assert::AreEqual(yinv.t, matrix_inv.y.t, 0.0001f);

			Assert::AreEqual(zinv.x, matrix_inv.z.x, 0.0001f);
			Assert::AreEqual(zinv.y, matrix_inv.z.y, 0.0001f);
			Assert::AreEqual(zinv.z, matrix_inv.z.z, 0.0001f);
			Assert::AreEqual(zinv.t, matrix_inv.z.t, 0.0001f);

			Assert::AreEqual(tinv.x, matrix_inv.t.x, 0.0001f);
			Assert::AreEqual(tinv.y, matrix_inv.t.y, 0.0001f);
			Assert::AreEqual(tinv.z, matrix_inv.t.z, 0.0001f);
			Assert::AreEqual(tinv.t, matrix_inv.t.t, 0.0001f);
		}*/


	};
}
