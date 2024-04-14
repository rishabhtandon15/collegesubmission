//code for quick sort
#include <stdio.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // Select last element as pivot
  int i = (low - 1); // index of smaller element

  for (int j = low; j <= high - 1; j++) {
    // If current element is smaller than the pivot
    if (arr[j] <= pivot) {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]); // Place pivot at the correct position
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // pi is partitioning index, arr[p] is now at right place
    int pi = partition(arr, low, high);

    // Recursively sort elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, n - 1);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
