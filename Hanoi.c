#include <stdio.h>
void hanoi(int n, char from_stack, char to_stack, char temp_stack) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_stack, to_stack);
        return;
    }
    hanoi(n - 1, from_stack, temp_stack, to_stack);
    printf("Move disk %d from %c to %c\n", n, from_stack, to_stack);
    hanoi(n - 1, temp_stack, to_stack, from_stack);
}

int main() {
    int num_disks;
    printf("Enter number of disks: ");
    scanf_s("%d", &num_disks);
    hanoi(num_disks, 'A', 'B', 'C');
    return 0;
}
