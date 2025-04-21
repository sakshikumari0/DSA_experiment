#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

// Push operation
void push(int value) { 
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, value;

    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
