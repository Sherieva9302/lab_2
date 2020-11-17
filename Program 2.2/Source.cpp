#include <iostream>
#include "Array.h"
#include <ctime>
using namespace std;



void main()
{
	bool b;
	double runtime[2][5][11]; //function, dimension data, execution time, runtime[][][10] = average execution time
	int* array;
	int i, j, k, counter2, counter3, size = 10;
	clock_t t;

	for (counter2 = 0; counter2 < 5; counter2++)
	{
		array = new int[size];
		
		for (counter3 = 0; counter3 < 10; counter3++)
		{
			fill_random_array(array, size);
			t = clock();
			QuickSort(array, 0, size-1);
			t = clock() - t;
			runtime[0][counter2][counter3] = ((double)t *1000 / CLOCKS_PER_SEC);
			fill_random_array(array, size);
			t = clock();
			BubbleSort(array, size);
			t = clock() - t;
			runtime[1][counter2][counter3] = ((double)t * 1000 / CLOCKS_PER_SEC);
		}

		runtime[0][counter2][10] = double(0);
		runtime[1][counter2][10] = double(0);
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 10; j++)
				runtime[i][counter2][10] = runtime[i][counter2][10] + runtime[i][counter2][j];
			runtime[i][counter2][10] /= 10;
		}

		if (size<100000) size *= 10;
		delete[] array;
	}

	cout << "QuickSort\n";
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 5; j++)
		{
			for(k=0; k<11; k++)
			cout << runtime[i][j][k]<<' ';
			cout << '\n';
		}
		cout << "_____________________________\n";
		cout << '\n';
		cout << "BubbleSort\n";
	}
	
}
