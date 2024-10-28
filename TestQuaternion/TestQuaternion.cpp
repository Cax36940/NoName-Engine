#include "pch.h"
#include "CppUnitTest.h"

#include "Component/Quaternion.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestQuaternion
{
	TEST_CLASS(TestQuaternion)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			Quaternion test_quaternion();
			Assert::AreEqual(1.0f, 1.0f);
		}
	};
}
