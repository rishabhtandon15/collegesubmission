//insertion of node at end of circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed!\n");
    return NULL;
  }
  newNode->data = data;
  return newNode;
}

// Function to insert a node at the end of a circular linked list
void insertAtEnd(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  if (*head == NULL) {
    // List is empty, make the new node point to itself
    newNode->next = newNode;
    *head = newNode;
  } else {
    // Find the last node
    struct Node* temp = *head;
    while (temp->next != *head) {
      temp = temp->next;
    }
    // Update links: new node -> next points to head, last node -> next points to new node
    newNode->next = *head;
    temp->next = newNode;
  }
}

// Function to traverse the circular linked list
void traverse(struct Node* head) {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  struct Node* temp = head;
  printf("Circular linked list: ");

  // Loop to print all nodes until we reach the starting node again
  do {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != head);

  printf("\n");
}

int main() {
  struct Node* head = NULL; // Initially empty list

  // Insert nodes at the end (modify data as needed)
  insertAtEnd(&head, 5);
  insertAtEnd(&head, 3);
  insertAtEnd(&head, 1);

  // Traverse the circular linked list
  traverse(head);

  return 0;
}
