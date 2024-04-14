//code of merge sort
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // create temp arrays
  int leftArr[n1], rightArr[n2];

  // copy data to temp arrays leftArr[] and rightArr[]
  for (int i = 0; i < n1; i++) {
    leftArr[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    rightArr[j] = arr[mid + 1 + j];
  }

  // Merge the temp arrays back into arr[left..right]
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (leftArr[i] <= rightArr[j]) {
      arr[k] = leftArr[i];
      i++;
    } else {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of leftArr[] if there are any
  while (i < n1) {
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  // Copy the remaining elements of rightArr[] if there are any
  while (j < n2) {
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    // find the middle point
    int mid = left + (right - left) / 2;

    // Sort first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

int main() {
  int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, n - 1);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
