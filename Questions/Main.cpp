#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


void Swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void merge(int arr[], int i_left, int i_right, int i_mid)
{
	const int n1 = i_mid - i_left + 1;
	const int n2 = i_right - i_mid;
	
	vector<int> left(n1);
	vector<int> right(n2);

	//int **left = new int*[n1];
	//int **right = new int*[n2];

	for (int i = 0; i < n1; i++)
		left[i] = arr[i_left + i];

	for (int i = 0; i < n2; i++)
		right[i] = arr[i_mid + 1 + i];

	int k = i_left;
	int i = 0;
	int j = 0;
	while (i < n1 && j < n2)
	{
		if (left[i] < right[j])
		{
			arr[k] = right[j];			
			j++;
		}
		else
		{
			arr[k] = left[i];
			i++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
	//delete &left;
	//delete &right;
}

void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			Swap(arr, i, 1+1);
	}
	if (n - 1 > 1)
		BubbleSort(arr, n - 1);
}

void InsertionSort(int arr[], int n)
{
	if (n <= 1)
		return;

	InsertionSort(arr, n - 1);

	int last = arr[n-1];
	int j = n - 2;

	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}

	arr[j + 1] = last;
}

void MergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;	//prevents overflow for large

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		merge(arr, left, right, mid);
	}
}

int Partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i!=j)
				Swap(arr, i, j);
		}
	}

	Swap(arr, i+1 ,high);
	return i+1;
}

void QuickSort(int arr[], int low, int high)
{
	// Use a pivot and arrange elements around that pivot
	//int pivot = arr[high];
	if (low < high)
	{
		int pivot = Partition(arr, low, high);
		QuickSort(arr, low, pivot-1);
		QuickSort(arr, pivot + 1, high);
	}
}

int main()
	{

#pragma region Question10: Bubble Sort Recursive

#pragma endregion

#pragma region Question11: Insertion Sort Recursive

#pragma endregion

#pragma region Question12: Merge Sort
		int arr[] = {12, 324, 64, 45, 88, 31, 11};
		MergeSort(arr, 0, 6);

		for (int i = 0; i < 7; i++)
			printf("%d, ", arr[i]);

#pragma endregion

#pragma region Question13: Quick Sort
		//Get a pivot, place pivot properly during first execution
		//Smaller element on left, higher on right
		//Sort left and right separately

		int myArray[] = { 10, 45, 115, 20, 28, 40, 50 };
		QuickSort(myArray, 0, 6);

		for (int i = 0; i < 7; i++)
			printf("%d ", myArray[i]);
#pragma endregion

		return 0;
	}

