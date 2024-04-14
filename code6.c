#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

int main() {
  // Create the head node
  struct Node* head = NULL;

  // Create nodes with data and add them to the linked list (modify this section)
  head = createNode(1);
  head->next = createNode(2);
  head->next->next = createNode(3);

  // Print the linked list (optional, you can use a traversal function here)
  printf("Linked list: ");
  struct Node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");

  return 0;
}


