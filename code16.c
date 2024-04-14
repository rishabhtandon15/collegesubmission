//finding max and min using divide and conquer approach
#include <stdio.h>

struct Result {
  int max;
  int min;
};

struct Result findMinMax(int arr[], int low, int high) {
  struct Result result;
  // Base case: single element array
  if (low == high) {
    result.max = arr[low];
    result.min = arr[low];
    return result;
  }

  // Find the middle index
  int mid = low + (high - low) / 2;

  // Recursively find min and max in both halves
  struct Result left = findMinMax(arr, low, mid);
  struct Result right = findMinMax(arr, mid + 1, high);

  // Combine results: find the overall maximum and minimum
  result.max = left.max > right.max ? left.max : right.max;
  result.min = left.min < right.min ? left.min : right.min;

  return result;
}

int main() {
  int arr[] = {12, 34, 5, 90, 2, 67};
  int n = sizeof(arr) / sizeof(arr[0]);

  struct Result result = findMinMax(arr, 0, n - 1);

  printf("Maximum element: %d\n", result.max);
  printf("Minimum element: %d\n", result.min);

  return 0;
}





//code for bubble sort




//code of merge sort



//code for insert sort



//code for quick sort







