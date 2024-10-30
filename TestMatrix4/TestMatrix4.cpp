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
			Matrix4 test_matrix(x,y,z,t);
			Assert::AreEqual(1.0f, test_matrix.x.x);
			
		}
	};
}
