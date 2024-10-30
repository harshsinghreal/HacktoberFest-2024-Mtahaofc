#include <stdio.h>
#include <stdlib.h>
#define max 100
int stack[max], top = -1;
void push() {
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);
    if (top == max - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element is %d\n", stack[top--]);
}
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", stack[top]);
}
int isEmpty() {
    return top == -1;
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}
int main() {
    int choice;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: peek();
                break;
        case 4: display();
                break;
        case 5: exit(0);
        default: printf("Invalid choice\n");
        }
    }
    return 0;
}