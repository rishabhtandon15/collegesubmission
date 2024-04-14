//program using heap sort
#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to heapify a subtree rooted with node i
// which is an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) {
  int largest = i;  // Initialize largest as root
  int left = 2 * i + 1;  // left = 2*i + 1 (since indexing starts from 0)
  int right = 2 * i + 2; // right = 2*i + 2

  // If left child is larger than root
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // If right child is larger than largest so far
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // If largest is not root
  if (largest != i) {
    swap(&arr[i], &arr[largest]);

    // Recursively heapify the affected subtrees
    heapify(arr, n, largest);
  }
}

// Function to build a max heap (rearrange array)
void buildHeap(int arr[], int n) {
  // Start from (n / 2 - 1) because the last parent node is at (n - 2)/2
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
}

// Function to sort an array (arr) of size n using Heap Sort
void heapSort(int arr[], int n) {
  // Build a max heap
  buildHeap(arr, n);

  // One by one extract an element from heap
  for (int i = n - 1; i >= 0; i--) {
    // Move current root to end
    swap(&arr[0], &arr[i]);

    // Call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

// Function to print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  heapSort(arr, n);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}
