//insertion a node at node after data 
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

// Function to insert a node after a specific node in the doubly linked list
void insertAfter(struct Node* prevNode, int data) {
  if (prevNode == NULL) {
    printf("Previous node cannot be NULL\n");
    return;
  }

  struct Node* newNode = createNode(data);

  // Handle insertion at the beginning if prevNode is the head
  if (prevNode == *(struct Node**)head) {
    newNode->next = prevNode->next;
    prevNode->next->prev = newNode;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    return;
  }

  // Handle normal insertion in the middle or at the end
  newNode->next = prevNode->next;
  prevNode->next->prev = newNode;
  prevNode->next = newNode;
  newNode->prev = prevNode;
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

  // Create sample nodes (modify data as needed)
  struct Node* node1 = createNode(1);
  struct Node* node2 = createNode(3);
  struct Node* node3 = createNode(5);

  // Connect the nodes (assuming you want to insert after node1)
  head = node1;
  node1->next = node2;
  node2->prev = node1;
  node2->next = node3;
  node3->prev = node2;

  // Insert a node with data 4 after node1
  insertAfter(node1, 4);

  // Traverse the list to see the inserted node
  traverseForward(head);

  return 0;
}
