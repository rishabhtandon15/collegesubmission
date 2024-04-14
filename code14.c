//linear search 
#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i; // Element found at index i
    }
  }
  return -1; // Element not found
}

int main() {
  int arr[] = {10, 20, 8, 5, 17};
  int n = sizeof(arr) / sizeof(arr[0]); // Get the array size
  int target = 8;

  int result = linearSearch(arr, n, target);

  if (result == -1) {
    printf("Element is not present in array\n");
  } else {
    printf("Element is found at index %d\n", result);
  }

  return 0;
}

