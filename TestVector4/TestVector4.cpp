#include "pch.h"
#include "CppUnitTest.h"

#include "Component/Vector4.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestVector4
{
	TEST_CLASS(TestVector4)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Vector4 test_vector();
			Assert::AreEqual(1.0f, 1.0f);
		}
	};
}
