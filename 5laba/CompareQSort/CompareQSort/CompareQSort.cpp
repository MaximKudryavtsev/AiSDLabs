#include "stdafx.h"

using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int l, int r)
{
	int x = arr[r];
	int i = (l - 1);

	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

void RecursiveQSort(int A[], int l, int r)
{
	if (l < r)
	{
		int p = partition(A, l, r);
		RecursiveQSort(A, l, p - 1);
		RecursiveQSort(A, p + 1, r);
	}
}

void NonRecursiveQSort(int arr[], int l, int r)
{
	int stack[ARR_SIZE + 1];
	int top = -1;
	stack[++top] = l;
	stack[++top] = r;
	while (top >= 0)
	{
		r = stack[top--];
		l = stack[top--];
		int p = partition(arr, l, r);
		if (p - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = p - 1;
		}
		if (p + 1 < r)
		{
			stack[++top] = p + 1;
			stack[++top] = r;
		}
	}
}

int main()
{
	int arr[ARR_SIZE];
	int arr1[ARR_SIZE];
	clock_t t;
	clock_t t1;
	for (int i = 0; i < ARR_SIZE; i++) arr[i] = rand() % RANGE;
	for (int i = 0; i < ARR_SIZE; i++) arr1[i] = rand() % RANGE;
	cout << "Entered arr: ";
	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	//t = clock();
	RecursiveQSort(arr, 0, ARR_SIZE - 1);
	//t = clock() - t;
	cout << endl;
	cout << "Sorted by recursive qsort: ";
	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	//cout << "Time with recursion: " << (float)t / CLOCKS_PER_SEC << endl;
	cout << endl;
	cout << endl;
	cout << "Entered arr: ";
	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		cout << arr1[i] << " ";
	}
	//t1 = clock();
	NonRecursiveQSort(arr1, 0, ARR_SIZE - 1);
	cout << endl;
	//t1 = clock() - t1;
	cout << "Sorted by non-recursive qsort: ";
	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		cout << arr1[i] << " ";
	}
	//cout << "Time without recursion: " << (float)t1 / CLOCKS_PER_SEC << endl;
	cout << endl;
    return 0;
}

