#include "pch.h"
#include "CppUnitTest.h"
#include"../ASD3/heap.h"
#include"../ASD3/heap.cpp"
#include"../ASD3/Stack.h"
#include"../ASD3/Stack.cpp"

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

		TEST_METHOD(find1) {
			lot->insert(1);
			Assert::AreEqual(lot->contains(1), true);
		}

		TEST_METHOD(find2) {
			lot->insert(2);
			lot->insert(1);
			Assert::AreEqual(lot->contains(2), true);
		}

		TEST_METHOD(insert0) {
			lot->insert(2);
			lot->insert(1);
			Assert::AreEqual((int)lot->get_size(), 3);
		}

		TEST_METHOD(remove0) {
			lot->insert(2);
			lot->insert(1);
			lot->remove(elem);
			Assert::AreEqual((int)lot->get_size(), 2);
		}

		TEST_METHOD(deep) {
			lot->insert(0);
			lot->insert(2);
			lot->insert(3);
			lot->insert(4);
			lot->insert(10);
			Iterator* deep = lot->create_dft_iterator();
			Assert::AreEqual(deep->next(), 3);
			Assert::AreEqual(deep->next(), 4);
			Assert::AreEqual(deep->next(), 1);
			Assert::AreEqual(deep->next(), 10);
			Assert::AreEqual(deep->next(), 2);
			Assert::AreEqual(deep->next(), 0);
		}

		TEST_METHOD(wide) {
			lot->insert(0);
			lot->insert(2);
			lot->insert(3);
			lot->insert(4);
			lot->insert(10);
			Iterator* wide = lot->create_bft_iterator();
			Assert::AreEqual(wide->next(), 0);
			Assert::AreEqual(wide->next(), 1);
			Assert::AreEqual(wide->next(), 2);
			Assert::AreEqual(wide->next(), 3);
			Assert::AreEqual(wide->next(), 4);
			Assert::AreEqual(wide->next(), 10);
		}
	};
}