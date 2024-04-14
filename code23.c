//height of a binary tree
#include <stdio.h>

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

// Function to calculate the height of a binary tree
int height(struct Node* root) {
  if (root == NULL) {
    return -1; // Height of an empty tree is -1 (considering root as level 0)
  }

  // Find height of left and right subtrees
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  // Return the maximum height of the left and right subtrees + 1 (for the current level)
  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
  struct Node* root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);

  int treeHeight = height(root);
  printf("Height of the tree: %d\n", treeHeight);

  return 0;
}
