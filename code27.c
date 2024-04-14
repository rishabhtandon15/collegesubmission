//code of rat in maze program
#include <stdio.h>

#define N 4 // Size of the maze

bool isValid(int maze[N][N], int row, int col) {
  // Check if row and col are within maze boundaries and the cell is not blocked
  return (row >= 0) && (row < N) && (col >= 0) && (col < N) && maze[row][col] == 1;
}

bool solveMaze(int maze[N][N], int row, int col, int soln[N][N]) {
  // Base case: if rat reaches the destination (bottom right corner)
  if (row == N - 1 && col == N - 1) {
    soln[row][col] = 1;
    return true;
  }

  // Mark current cell (row, col) as part of the solution path
  soln[row][col] = 1;

  // Try moving right
  if (isValid(maze, row, col + 1)) {
    if (solveMaze(maze, row, col + 1, soln)) {
      return true; // Path found through right move
    }
  }

  // Try moving down (if right move fails)
  if (isValid(maze, row + 1, col)) {
    if (solveMaze(maze, row + 1, col, soln)) {
      return true; // Path found through down move
    }
  }

  // If none of the above movements work, then backtrack (unmark current cell)
  soln[row][col] = 0;
  return false;
}

void printSolution(int soln[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf(" %d ", soln[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int maze[N][N] = {
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 0},
      {0, 1, 1, 1}
  };

  int soln[N][N] = {0};

  if (solveMaze(maze, 0, 0, soln)) {
    printf("Solution found:\n");
    printSolution(soln);
  } else {
    printf("No solution exists\n");
  }

  return 0;
}

