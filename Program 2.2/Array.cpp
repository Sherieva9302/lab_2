#include <stdexcept>
#include "Array.h"
#include <iostream>
#include <ctime>

using namespace std;




void fill_random_array(int *array, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() - rand();
	}
}

void char_fill_random_array(char* array_char, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		array_char[i] = rand() % 128;
	}
}

bool Check_array(int *array, int size)
{
	for (int i = 1; i < size; i++)
		if (array[i] < array[i - 1]) return 0;

	return 1;
}

bool char_Check_array(char* array, int size)
{
	for (int i = 1; i < size; i++)
		if (array[i] < array[i - 1]) return 0;

	return 1;
}

int BinarySearch(int* array, int mid, int number)
{

	int left = 0, right = mid - 1;
	mid = mid / 2;

	while ((array[mid] != number)&&(left<right))
	{
		if (array[mid] > number) 
			right = mid-1; 

		else
			left = mid+1;

		mid = (right + left) / 2;
	}

	if (left>right)
	{
		throw out_of_range("The requested elem is missing");
	}

	return mid;
	
}

void QuickSort(int* Array, int left, int right)
{
	int i = left, j = right, temp, pivot = Array[(left+right )/ 2];


	while (i <= j) {
		while (Array[i] < pivot)
			i++;
		while (Array[j] > pivot)
			j--;
		if (i <= j) {
			temp = Array[i]; //swap
			Array[i] = Array[j];
			Array[j] = temp;
			i++;
			j--;
		}
	}

	if (j > left)
		QuickSort(Array, left, j);
	if (i < right)
		QuickSort(Array, i, right);
}


void BubbleSort(int* array, int size)
{
	while (size > 1)
	{
		for (int i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{
				array[i] = array[i] + array[i - 1]; //swap
				array[i - 1] = array[i] - array[i - 1];
				array[i] = array[i] - array[i - 1];
			}
		}
		size--;
	}

}

void BogoSort(int* array, int size)
{
	int random_index, index;
	srand(time(NULL));
	while (!Check_array(array, size))
	{
		for (index = 0; index < size; index++)
		{
			random_index = rand() % size;
			array[index] = array[index] + array[random_index]; //swap
			array[random_index] = array[index] - array[random_index];
			array[index] = array[index] - array[random_index];
		}
	}

}

void CountingSort(char* array_char, int size)
{
	int max = 0, i, j=0;
	int* array_count;


	for (i = 0; i < size; i++)
	{
		if (max < int(array_char[i]))
			max = int(array_char[i]);
	}
	array_count = new int[max + 1];
	for (i = 0; i <= max; i++)
		array_count[i] = 0;
	for (i = 0; i < size; i++)
	{
		array_count[int(array_char[i])]++;
	}
	for (i = 0; i <= max; i++)
	{
		while (array_count[i] != 0)
		{
			array_char[j] = i;
			array_count[i]--;
			j++;
		}
	}

}