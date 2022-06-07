#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_oop_6.7\main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 2, -1, 0 };
			Assert::AreEqual(1, accumulate(&a[0], &a[3]));
		}
	};
}
