//code 1:TRAVERSAL OF SINGLE LINKED LIST
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

int main() {
  // Sample linked list (modify this to create your own list)
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  // Allocate memory for nodes
  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));

  // Assign data to nodes
  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  // Traverse the linked list
  printf("Linked list: ");
  traverse(head);

  return 0;
}
