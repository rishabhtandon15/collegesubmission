//insert a node at end of linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

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

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
  // Create a new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = NULL;

  // If the list is empty, make the new node as the head
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  // Traverse to the last node
  struct Node* last = *head_ref;
  while (last->next != NULL) {
    last = last->next;
  }

  // Insert the new node at the end
  last->next = new_node;
}

int main() {
  struct Node* head = NULL;

  // Sample linked list (modify this to create your own list)
  insertAtEnd(&head, 1);
  insertAtEnd(&head, 2);
  insertAtEnd(&head, 3);

  printf("Original list: ");
  traverse(head);

  // Insert a new node at the end
  int new_data = 4;
  insertAtEnd(&head, new_data);

  printf("List after insertion: ");
  traverse(head);

  return 0;
}
