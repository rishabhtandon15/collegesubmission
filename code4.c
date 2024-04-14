//wap to insert a node after a given data in single linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// Function to insert a node after a given data
void insertAfter(struct Node** head_ref, int prev_data, int new_data) {
  // 1. Check if the given list is empty
  if (*head_ref == NULL) {
    printf("List is empty.\n");
    return;
  }

  // 2. Create a new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = NULL;

  // 3. Traverse the list to find the given node
  struct Node* temp = *head_ref;
  while (temp != NULL) {
    if (temp->data == prev_data) {
      break;
    }
    temp = temp->next;
  }

  // 4. Check if the given data was found
  if (temp == NULL) {
    printf("Node with data %d not found.\n", prev_data);
    return;
  }

  // 5. Insert the new node after the found node
  new_node->next = temp->next;
  temp->next = new_node;
}

// Function to traverse the linked list
void traverse(struct Node* head) {
  struct Node* temp = head;
  printf("Linked list: ");
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

  // Insert a node after data 2
  int new_data = 4;
  insertAfter(&head, 2, new_data);

  // Traverse the modified linked list
  traverse(head);

  return 0;
}

