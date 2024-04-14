// creation of single linked list
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
  newNode->next = NULL;
  return newNode;
}

int main() {
  // Create the head node
  struct Node* head = NULL;

  // Build the linked list (modify this loop to create your desired list)
  for (int i = 1; i <= 5; i++) 
  {
    struct Node* newNode = createNode(i);
    if (head == NULL) 
    {
      head = newNode;
    } else {
      // Add the new node to the end of the list
      struct Node* temp = head;
      while (temp->next != NULL) 
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  // Print the linked list (optional)
  printf("Linked list: ");
  struct Node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");

  return 0;
}
