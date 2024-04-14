//Binary Search
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
  if (low > high) {
    return -1; // Element not found
  }

  int mid = low + (high - low) / 2; // Avoid overflow

  if (arr[mid] == target) {
    return mid; // Element found at the middle index
  } else if (arr[mid] < target) {
    return binarySearch(arr, mid + 1, high, target); // Search in the right half
  } else {
    return binarySearch(arr, low, mid - 1, target); // Search in the left half
  }
}

int main() {
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 23;

  int result = binarySearch(arr, 0, n - 1, target);

  if (result == -1) {
    printf("Element is not present in array\n");
  } else {
    printf("Element is found at index %d\n", result);
  }

  return 0;
}
