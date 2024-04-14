//Binary search tree implementation code
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed!\n");
    return NULL;
  }
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
  if (root == NULL) {
    return createNode(data); // Create a new node if tree is empty
  }

  if (data < root->data) {
    root->left = insert(root->left, data); // Insert in left subtree for values less than root
  } else if (data > root->data) {
    root->right = insert(root->right, data); // Insert in right subtree for values greater than root
  } else {
    // Handle duplicates (optional): modify or print a message here
  }

  return root; // Return the (unchanged) root node
}

// Function to search for a node in the BST
struct Node* search(struct Node* root, int data) {
  if (root == NULL || root->data == data) {
    return root; // Found the node or reached an empty subtree
  }

  if (data < root->data) {
    return search(root->left, data); // Search in left subtree
  } else {
    return search(root->right, data); // Search in right subtree
  }
}

// Function to perform in-order traversal (left, root, right)
void inorderTraversal(struct Node* root) {
  if (root != NULL) {
    inorderTraversal(root->left); // Traverse left subtree
    printf("%d ", root->data);    // Visit the root node
    inorderTraversal(root->right); // Traverse right subtree
  }
}

int main() {
  struct Node* root = NULL;

  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Inorder traversal: ");
  inorderTraversal(root);
  printf("\n");

  struct Node* searchedNode = search(root, 40);
  if (searchedNode != NULL) {
    printf("Node with data %d found\n", searchedNode->data);
  } else {
    printf("Node not found\n");
  }

  return 0;
}
