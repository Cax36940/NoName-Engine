#include "pch.h"
#include "CppUnitTest.h"

#include "Component/Matrix3.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestMatrix3
{
	TEST_CLASS(TestMatrix3)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			Matrix3 test_matrix();
			Assert::AreEqual(1.0f, 1.0f);
		}
	};
}
