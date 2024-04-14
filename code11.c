//insertion of node at beginning of doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* prev; // Pointer to the previous node
  struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed!\n");
    return NULL;
  }
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  if (*head == NULL) {
    // List is empty
    *head = newNode;
  } else {
    // Update links for the new node and the current head
    newNode->next = *head;
    (*head)->prev = newNode;
    // Make the new node the head
    *head = newNode;
  }
}

// Function to traverse the doubly linked list (forward traversal)
void traverseForward(struct Node* head) {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  struct Node* temp = head;
  printf("Doubly linked list (forward): ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Node* head = NULL; // Initially empty list

  // Insert nodes at the beginning (modify data as needed)
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 1);

  // Traverse the doubly linked list (forward)
  traverseForward(head);

  return 0;
}
