#include "pch.h"
#include "CppUnitTest.h"
#include"../ASD3/heap.h"
#include"../ASD3/heap.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASD3test
{
	TEST_CLASS(ASD3test)
	{
	public:
		heap* lot;
		int elem;
		
		TEST_METHOD_INITIALIZE(setup) {
			elem = 1;
			lot = new heap(elem);
		}
		TEST_METHOD_CLEANUP(cleanup) {
			delete lot;
		}
		TEST_METHOD(find0) {
			Assert::AreEqual(lot->contains(elem), true);
		}
	};
}