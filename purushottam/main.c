#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int stack[SIZE], top = -1;

int main() {
    int choice, value, i;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (top == SIZE - 1) {
                    printf("Stack Overflow\n");
                } else {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    top++;
                    stack[top] = value;
                }
                break;

            case 2:
                if (top == -1) {
                    printf("Stack Underflow\n");
                } else {
                    printf("Popped: %d\n", stack[top]);
                    top--;
                }
                break;

            case 3:
                if (top == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Top element: %d\n", stack[top]);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
