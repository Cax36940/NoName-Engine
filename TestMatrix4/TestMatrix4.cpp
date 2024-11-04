#include "pch.h"
#include "CppUnitTest.h"
#include "Component/Vector4.hpp"
#include "Component/Matrix4.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestMatrix4
{
	TEST_CLASS(TestMatrix4)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			Vector4 x = Vector4(1, 2, 3, 4);
			Vector4 y = Vector4(5, 6, 7, 8);
			Vector4 z = Vector4(9, 10, 11, 12);
			Vector4 t = Vector4(13, 14, 15, 16);
			Matrix4 matrix(x,y,z,t);
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

			Assert::AreEqual(13.0f, matrix.t.x);
			Assert::AreEqual(14.0f, matrix.t.y);
			Assert::AreEqual(15.0f, matrix.t.z);
			Assert::AreEqual(16.0f, matrix.t.t);
		}

		TEST_METHOD(Mult_scalar)
		{
			Vector4 x(1, 2, 3, 4);
			Vector4 y(5, 6, 7, 8);
			Vector4 z(9, 10, 11, 12);
			Vector4 t(13, 14, 15, 16);
			Matrix4 matrix(x, y, z, t);

			float scalar = 2.0f;
			Matrix4 result = matrix * scalar;

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

			Assert::AreEqual(26.0f, result.t.x);
			Assert::AreEqual(28.0f, result.t.y);
			Assert::AreEqual(30.0f, result.t.z);
			Assert::AreEqual(32.0f, result.t.t);
		}

		TEST_METHOD(MultEqu_scalar)
		{
			Vector4 x(1, 2, 3, 4);
			Vector4 y(5, 6, 7, 8);
			Vector4 z(9, 10, 11, 12);
			Vector4 t(13, 14, 15, 16);
			Matrix4 matrix(x, y, z, t);

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

			Assert::AreEqual(26.0f, matrix.t.x);
			Assert::AreEqual(28.0f, matrix.t.y);
			Assert::AreEqual(30.0f, matrix.t.z);
			Assert::AreEqual(32.0f, matrix.t.t);
		}

		TEST_METHOD(MatrixMultiplication)
		{
			Matrix4 matrix1(Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0), Vector4(0, 0, 1, 0), Vector4(0, 0, 0, 1));
			Matrix4 matrix2(Vector4(2, 3, 4, 5), Vector4(6, 7, 8, 9), Vector4(10, 11, 12, 13), Vector4(14, 15, 16, 17));
			Matrix4 result = matrix1 * matrix2;

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

			Assert::AreEqual(14.0f, result.t.x);
			Assert::AreEqual(15.0f, result.t.y);
			Assert::AreEqual(16.0f, result.t.z);
			Assert::AreEqual(17.0f, result.t.t);
		}

		TEST_METHOD(MatrixVectorMultiplication)
		{
			Matrix4 matrix(Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0), Vector4(0, 0, 1, 0), Vector4(0, 0, 0, 1));
			Vector4 vector(2, 3, 4, 5);
			Vector4 result = matrix * vector;

			Assert::AreEqual(2.0f, result.x);
			Assert::AreEqual(3.0f, result.y);
			Assert::AreEqual(4.0f, result.z);
			Assert::AreEqual(5.0f, result.t);
		}


		TEST_METHOD(MatrixAddition)
		{
			Matrix4 matrix1(Vector4(1, 2, 3, 4), Vector4(5, 6, 7, 8), Vector4(9, 10, 11, 12), Vector4(13, 14, 15, 16));
			Matrix4 matrix2(Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1));
			Matrix4 result = matrix1 + matrix2;

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

			Assert::AreEqual(14.0f, result.t.x);
			Assert::AreEqual(15.0f, result.t.y);
			Assert::AreEqual(16.0f, result.t.z);
			Assert::AreEqual(17.0f, result.t.t);
		}

		TEST_METHOD(MatrixAddEqu)
		{
			Matrix4 matrix1(Vector4(1, 2, 3, 4), Vector4(5, 6, 7, 8), Vector4(9, 10, 11, 12), Vector4(13, 14, 15, 16));
			Matrix4 matrix2(Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1));
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

			Assert::AreEqual(14.0f, matrix1.t.x);
			Assert::AreEqual(15.0f, matrix1.t.y);
			Assert::AreEqual(16.0f, matrix1.t.z);
			Assert::AreEqual(17.0f, matrix1.t.t);
		}

		TEST_METHOD(MatrixSubtraction)
		{
			Matrix4 matrix1(Vector4(2, 3, 4, 5), Vector4(6, 7, 8, 9), Vector4(10, 11, 12, 13), Vector4(14, 15, 16, 17));
			Matrix4 matrix2(Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1));
			Matrix4 result = matrix1 - matrix2;

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

			Assert::AreEqual(13.0f, result.t.x);
			Assert::AreEqual(14.0f, result.t.y);
			Assert::AreEqual(15.0f, result.t.z);
			Assert::AreEqual(16.0f, result.t.t);
		}

		TEST_METHOD(MatrixSubEqu)
		{
			Matrix4 matrix1(Vector4(2, 3, 4, 5), Vector4(6, 7, 8, 9), Vector4(10, 11, 12, 13), Vector4(14, 15, 16, 17));
			Matrix4 matrix2(Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1), Vector4(1, 1, 1, 1));
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

			Assert::AreEqual(13.0f, matrix1.t.x);
			Assert::AreEqual(14.0f, matrix1.t.y);
			Assert::AreEqual(15.0f, matrix1.t.z);
			Assert::AreEqual(16.0f, matrix1.t.t);
		}

		TEST_METHOD(Determinant)
		{
			Matrix4 matrix(Vector4(1, 2, 3, 4), Vector4(5, 6, 7, 8), Vector4(9, 10, 11, 12), Vector4(13, 14, 15, 16));
			float result = Matrix4::determinant(matrix);

			// Pour cette matrice, le déterminant est connu pour être 0
			Assert::AreEqual(0.0f, result);



			Matrix4 matrix2(Vector4(1, 0, 1, 0), Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0), Vector4(0, 1, 4, 2));
			float res2 = Matrix4::determinant(matrix2);

			// Pour cette matrice, le déterminant est connu pour être 0
			Assert::AreEqual(2.0f, res2);
		}


		/*TEST_METHOD(Inverse)
		{
			Matrix4 matrix(Vector4(2, 2, 3, 3), Vector4(2, 3, 3, 2), Vector4(5, 3, 7, 9), Vector4(3, 2, 4, 7));
			Matrix4 matrix_inv = Matrix4::inv(matrix);
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
