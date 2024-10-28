#include "pch.h"
#include "CppUnitTest.h"

#include "Component/Matrix4.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestMatrix4
{
	TEST_CLASS(TestMatrix4)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			Matrix4 test_matrix();
			Assert::AreEqual(1.0f, 1.0f);
		}
	};
}
