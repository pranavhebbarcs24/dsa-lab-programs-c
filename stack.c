#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top=-1;
int size;

void push(int ele);
void pop();
void display();

int main() {
    int choice, ele;

    printf("Enter stack size:");
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid", MAX_SIZE);
        size = MAX_SIZE;
    }

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit");
                return 0;
            default:
                printf("Invalid choice");
        }
    }
}

void push(int ele) {
    if (top == size - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = ele;
        printf("Pushed %d onto the stack\n", ele);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}




