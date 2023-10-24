// QuickSort.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high) {

	int pivot = arr[low];
	int i = low;
	int j = high;
	while (i < j) {
		while (arr[i] <= pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap(&arr[i], &arr[j]);
		}

	}
	swap(&arr[low], &arr[j]);
	return j;
}

void quickSort(int arr[], int low, int high) {

	if (low < high) {
		int pivot = partition(arr, low, high);

		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

int main()
{
	int arr[] = { 10, 7, 8,9,1,5 };
	int N = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Unsorted array : " << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << std::endl;
	}
	quickSort(arr, 0, N-1);
	std::cout <<  "\n" << "Sorted array : " << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << std::endl;
	}
	return 0;
}

