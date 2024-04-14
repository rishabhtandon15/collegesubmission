//code for tower of hanoi 
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
  if (n == 1) {
    printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
    return;
  }

  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); // Move n-1 disks from source to auxiliary rod
  printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod); // Move nth disk to destination rod
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); // Move n-1 disks from auxiliary rod to destination rod (using the source rod as helper)
}

int main() {
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  towerOfHanoi(num_disks, 'A', 'C', 'B'); // Assuming rods are named A, B, and C

  return 0;
}

