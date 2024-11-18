#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(string("A B C"), Spaces("   A     B    C  "));
		}
	};
}
