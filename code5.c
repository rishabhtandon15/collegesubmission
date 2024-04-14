//code 4:- implement deletion of node at beginning of linked list, deletion at end,deletion of given data
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// Function to traverse the linked list
void traverse(struct Node* head) {
  struct Node* temp = head;

  if (temp == NULL) {
    printf("List is empty.\n");
    return;
  }

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
  // Check if list is empty
  if (*head == NULL) {
    printf("List is empty, cannot delete.\n");
    return;
  }

  // Store the head node in a temporary variable
  struct Node* temp = *head;

  // Update the head to point to the next node
  *head = (*head)->next;

  // Free the memory of the deleted node
  free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
  // Check if list is empty
  if (*head == NULL) {
    printf("List is empty, cannot delete.\n");
    return;
  }

  // Traverse to the second last node
  struct Node* temp = *head;
  struct Node* prev = NULL;
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }

  // If there's only one node (head), update head to NULL
  if (prev == NULL) {
    *head = NULL;
  } else {
    // Update the second last node's next to NULL
    prev->next = NULL;
  }

  // Free the memory of the deleted node
  free(temp);
}

// Function to delete a node with a given data value
void deleteByValue(struct Node** head, int value) {
  // Check if list is empty
  if (*head == NULL) {
    printf("List is empty, cannot delete.\n");
    return;
  }

  // Traverse to find the node
  struct Node* temp = *head;
  struct Node* prev = NULL;
  while (temp != NULL && temp->data != value) {
    prev = temp;
    temp = temp->next;
  }

  // If node not found
  if (temp == NULL) {
    printf("Value %d not found in the list.\n", value);
    return;
  }

  // If deleting the head node
  if (prev == NULL) {
    *head = temp->next;
  } else {
    prev->next = temp->next;
  }

  // Free the memory of the deleted node
  free(temp);
}

int main() {
  struct Node* head = NULL;
  // ... (Create your linked list here)

  printf("Original list: ");
  traverse(head);

  // Delete from beginning
  deleteAtBeginning(&head);
  printf("After deleting from beginning: ");
  traverse(head);

  // Delete from end
  deleteAtEnd(&head);
  printf("After deleting from end: ");
  traverse(head);

  // Delete by value (modify value to test)
  int valueToDelete = 2;
  deleteByValue(&head, valueToDelete);
  printf("After deleting value %d: ", valueToDelete);
  traverse(head);

  return 0;
}
