#include <iostream>
#include <stdlib.h>

using namespace std;

//insert sort
void insertSort(int* p, int size)
{
	if (p == NULL)
		return;

	for (int i = 1; i < size; ++i)
	{
		int target = p[i];

		for (int j = 0; j < i; ++j)
		{
			if (target < p[j])
				swap(p[i], p[j]);
		}
	}
}

//bubble sort
void bubbleSort(int* p, int size)
{
	if (p == NULL)
		return;

	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (p[i] > p[j])
				swap(p[i], p[j]);
		}
	}
}

//quick sort
int partition(int* p, int start, int end)
{
	//int left = start;
	//int right = end - 1;
	//int mid = end;

	//if (left < right)
	//{	
	//	while (left < right && p[left] <=  p[mid])
	//		left++;
	//	while (left < right && p[right] > p[mid])
	//		right--;

	//	swap(p[left], p[right]);
	//}

	//if (p[left] > p[mid])
	//	swap(p[left], p[mid]);
	//else
	//	left++;

	//return left;

	int temp = p[end];
	int i = start, j = start - 1;

	for (; i < end; ++i)
	{
		if (p[i] <= temp)
		{
			j++;
			if (i != j)
			{
				swap(p[i], p[j]);
			}
		}
	}

	swap(p[j + 1], p[end]);

	return j + 1;
}

void quickSortRecursive(int* p, int start, int end)
{
	if (start > end)
		return;

	int mid = partition(p, start, end);

	quickSortRecursive(p, start, mid - 1);
	quickSortRecursive(p, mid + 1, end);
}

void quickSort(int* p, int size)
{
	quickSortRecursive(p, 0, size - 1);
}

int main(void)
{
	int a[] = {6, 3, 2, 7, 8, 4, 9, 5, 1, 10};
	int size = sizeof(a) / sizeof(int);

	//quickSort(a, size);
	//bubbleSort(a, size);
	insertSort(a, size);

	for (int i = 0; i < size; ++i)
	{
		
		if (size - 1 != i)
			cout << a[i] << ", ";
		else
			cout << a[i] << endl;
	}

	system("pause");
	return 0;
}