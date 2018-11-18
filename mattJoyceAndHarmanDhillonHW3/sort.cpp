#include "mysort.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <cstdio>
#include <ctime>    
using namespace std;

default_random_engine e;  // used by a distribution object to generate random numbers
uniform_real_distribution<double> u(0, 1); // a distribution object that generates random doubles in the range: [0,1]

// Helper routines
void randfill(vector<double> &a, int size)
{
	a.resize(0);
	for (int i = 0; i < size; i++)
		a.push_back(u(e));
}

void nearlyRandom(vector<double> &a, int size)
{
	a.resize(0);
	for (int i = 0; i < size; ++i)
		a.push_back(u(e)*20 + i - 10);
}

int main()
{     
	clock_t start, finish;
	double  duration;
	vector<double> a;

	/* Draw Chart Heading */
	cout << setw(11) << " | ";
	cout << setw(16) << "InsertionSort";
	cout << setw(16) << "ShellSort";
	cout << setw(16) << "MergeSort";
	cout << setw(16) << "QuickSort"
		<< endl;
	cout << setw(8) << " Size" << " | ";
	for (int i = 1; i <= 4; i++)
		cout << setw(8) << "  rand" << setw(8) << "  nstd";
	cout << endl;
	for (int i = 1; i <= 79; i++)
		cout << '-';
	cout << endl;

	/*randfill(a, 10);
	shellsort(a);
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	cout << endl;

	randfill(a, 10);
	mergesort(a);
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";*/

	vector<int> sizeVector = { 25000,100000,500000,1000000,2000000,8000000,24000000 };
	int size = 0;
	for (int i = 0; i < sizeVector.size(); ++i)
	{
		size = sizeVector[i];

		cout << setw(8) << size;
		cout << " | ";

		if (size <= 500000)
		{
			//insertion sort random
			randfill(a, size);
			start = clock();
			insertionsort(a);
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("%8.3f", duration);
		}
		else
			printf("%8.3f", 0.000);

		//nearly random insertionsort
		nearlyRandom(a, size);
		start = clock();
		insertionsort(a);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);

		//shellsort random
		randfill(a, size);
		start = clock();
		shellsort(a);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);

		//nearly random shellsort
		nearlyRandom(a, size);
		start = clock();
		shellsort(a);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);

		//mergesort random
		randfill(a, size);
		start = clock();
		mergesort(a);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);

		//nearly random mergesort
		nearlyRandom(a, size);
		start = clock();
		mergesort(a);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);

		//quicksort random
		randfill(a, size);
		start = clock();
		sort(a.begin(), a.end());
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);

		//nearly random quicksort
		nearlyRandom(a, size);
		start = clock();
		sort(a.begin(), a.end());
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);

		cout << endl;
	}
	cin.get();  // wait for Enter key
	return EXIT_SUCCESS;
}