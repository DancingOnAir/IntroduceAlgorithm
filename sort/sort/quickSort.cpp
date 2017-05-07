#include <iostream>
#include <stdlib.h>

using namespace std;

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

	quickSort(a, size);

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