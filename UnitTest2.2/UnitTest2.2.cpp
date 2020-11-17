#include "CppUnitTest.h"
#include "../Program 2.2/Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest22
{
	TEST_CLASS(UnitTest22)
	{

	public:
		int* array;

		// before each test
		TEST_METHOD_INITIALIZE(setUp)
		{
			array = new int[10];
		}
		// after each test
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete[] array;
		}
		TEST_METHOD(BinarySearch_different_elements)
		{
			int index;
			for (int i = 0; i < 10; i++)
			{
				array[i] = i;
			}
			index = BinarySearch(array, 10, 8);
			Assert::AreEqual(index, 8);
		}
		TEST_METHOD(BinarySearch_border_elem)
		{
			int index;
			for (int i = 0; i < 10; i++)
			{
				array[i] = i;
			}
			index = BinarySearch(array, 10, 9);
			Assert::AreEqual(index, 9);
		}
		TEST_METHOD(BinarySearch_few_identical_elements)
		{
			int index;
			for (int i = 0; i < 10; i++)
			{
				array[i] = i;
			}
			array[7] = 6;

			index = BinarySearch(array, 10, 6);
			Assert::AreEqual(array[index], 6);
		}

		TEST_METHOD(BinarySearch_elem_missing)
		{

			try
			{
				int index;
				for (int i = 0; i < 10; i++)
				{
					array[i] = i;
				}
				index = BinarySearch(array, 10, 10);

			}
			catch (std::out_of_range e) {
				Assert::AreEqual("The requested elem is missing", e.what());
			}
		}

		TEST_METHOD(Check_array_true)
		{
			for (int i = 0; i < 10; i++)
			{
				array[i] = i;
			}
			array[7] = 6;
			Assert::IsTrue(Check_array(array, 10));
		}

		TEST_METHOD(Check_array_all_elements_are_equal_true)
		{
			for (int i = 0; i < 10; i++)
			{
				array[i] = 100;
			}
			Assert::IsTrue(Check_array(array, 10));
		}
		TEST_METHOD(Check_array_false)
		{
			for (int i = 0; i < 10; i++)
			{
				array[i] = i;
			}
			array[7] = 5;
			Assert::IsFalse(Check_array(array, 10));
		}
		TEST_METHOD(QuickSort_random)
		{
			fill_random_array(array, 10);
			QuickSort(array, 0, 9);
			Assert::IsTrue(Check_array(array, 10));
		}
		TEST_METHOD(QuickSort_few_identical_elements)
		{
			fill_random_array(array, 10);
			array[1] = array[6];
			array[7] = array[6];
			QuickSort(array, 0, 9);
			Assert::IsTrue(Check_array(array, 10));
		}
		TEST_METHOD(QuickSort_all_elements_are_equal) 
		{
			for (int i = 0; i < 10; i++)
			{
				array[i] = 100;
			}
			QuickSort(array, 0, 9);
			Assert::IsTrue(Check_array(array, 10));
		}
		TEST_METHOD(BubbleSort_back_to_front)
		{
			for (int i = 0; i < 10; i++)
			{
				array[i] = 9-i;
			}
			BubbleSort(array, 10);
			Assert::IsTrue(Check_array(array, 10));
		}
		TEST_METHOD(BubbleSort_all_elements_are_equal)
		{
			for (int i = 0; i < 10; i++)
			{
				array[i] = 100;
			}
			BubbleSort(array, 10);
			Assert::IsTrue(Check_array(array, 10));
		}
		TEST_METHOD(BogoSort_random)
		{
			fill_random_array(array, 10);

			BogoSort(array, 10);
			Assert::IsTrue(Check_array(array, 10));
		}

		TEST_METHOD(CountingSort_few_identical_elements)
		{
			bool b;
			char* array_char;
			array_char = new char[10];
			char_fill_random_array(array_char, 10);
			array_char[1] = array_char[4];
			array_char[5] = array_char[4];
			CountingSort(array_char, 10);
			b = char_Check_array(array_char, 10);
			delete[] array_char;
			Assert::AreEqual(b, bool(1));
		}

		TEST_METHOD(CountingSort_random)
		{
			bool b;
			char* array_char;
			array_char = new char[10];
			char_fill_random_array(array_char, 10);
			CountingSort(array_char, 10);
			b = char_Check_array(array_char, 10);
			delete[] array_char;
			Assert::AreEqual(b, bool(1));
		}
	};
}