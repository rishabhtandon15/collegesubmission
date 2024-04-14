//code 2:- Insert a node at beginningof a single linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
  // Allocate memory for the new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // Assign data to the new node
  new_node->data = new_data;

  // Make the new node point to the current head
  new_node->next = *head_ref;

  // Update the head pointer to point to the new node
  *head_ref = new_node;
}

// Function to traverse the linked list
void traverse(struct Node* head) {
  struct Node* temp = head;

  // Check if the list is empty
  if (temp == NULL) {
    printf("List is empty.\n");
    return;
  }

  // Traverse through the linked list
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Node* head = NULL;

  // Sample linked list (modify this to create your own list)
  insertAtBeginning(&head, 3); // Insert 3 at the beginning
  insertAtBeginning(&head, 2); // Insert 2 at the beginning
  insertAtBeginning(&head, 1); // Insert 1 at the beginning

  printf("Linked list after insertion: ");
  traverse(head);

  return 0;
}
