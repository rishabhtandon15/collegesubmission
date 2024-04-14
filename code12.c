//insert at end of doubly linked list
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

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  if (*head == NULL) {
    // List is empty, make the new node the head and tail
    *head = newNode;
  } else {
    // Find the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    // Update links: connect the new node to the last node and make it the new tail
    temp->next = newNode;
    newNode->prev = temp;
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

  // Insert nodes at the end (modify data as needed)
  insertAtEnd(&head, 5);
  insertAtEnd(&head, 3);
  insertAtEnd(&head, 1);

  // Traverse the doubly linked list (forward)
  traverseForward(head);

  return 0;
}
