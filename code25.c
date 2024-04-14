//using BFS(BREADTH FIRST SEARCH ALGORITHM)
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct Node {
  int data;
  struct Node* next;
};

// Structure to represent a graph
struct Graph {
  int numVertices;
  struct Node* head[MAX_VERTICES];
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to create a graph
struct Graph* createGraph(int numVertices) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = numVertices;

  // Create an adjacency list for each vertex
  for (int i = 0; i < numVertices; i++) {
    graph->head[i] = NULL;
  }

  return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
  // Add an edge from src to dest
  struct Node* newNode = createNode(dest);
  newNode->next = graph->head[src];
  graph->head[src] = newNode;

  // Since graph is undirected, add an edge from dest to src also
  newNode = createNode(src);
  newNode->next = graph->head[dest];
  graph->head[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
  for (int i = 0; i < graph->numVertices; ++i) {
    printf("Adjacency list of vertex %d\n head ", i);
    struct Node* temp = graph->head[i];
    while (temp) {
      printf("-> %d", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

// Function for BFS traversal
void BFS(struct Graph* graph, int startVertex) {
  int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices

  // Create a queue for BFS
  struct Node* queue[MAX_VERTICES];
  int front = -1, rear = -1;

  // Mark the current node as visited and enqueue it
  visited[startVertex] = 1;
  queue[++rear] = graph->head[startVertex];

  // BFS loop
  while (front != rear) {
    // Dequeue a vertex from queue and print it
    struct Node* current = queue[++front];
    printf("%d ", current->data);

    // Get all adjacent vertices of the dequeued vertex
    while (current) {
      // If adjacent vertex is not visited, mark it visited and enqueue it
      if (!visited[current->data]) {
        visited[current->data] = 1;
        queue[++rear] = graph->head[current->data];
      }
      current = current->next;
    }
  }
}

int main() {
  int numVertices = 6;
  struct Graph* graph = createGraph(numVertices);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 3, 5);

  printf("Graph Representation:\n");
  printGraph(graph);

  printf("\nBFS Traversal (starting from vertex 0): ");
  BFS(graph, 0);

  return 0;
}
