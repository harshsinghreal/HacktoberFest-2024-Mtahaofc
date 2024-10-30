#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* link;
};
struct node* top = NULL;
void push() {
    int n;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("Enter number to add: ");
    scanf("%d", &n);
    new->data = n;
    if (top == NULL)
        new->link = NULL;
    else
        new->link = top;
    top = new;
}
void pop() {
    if (top == NULL)
        printf("Stack empty");
    else {
        struct node* temp = top;
        printf("Number popped is: %d", temp->data);
        top = top->link;
        free(temp);
    }
}
void show() {
    struct node* temp = top;
    if (top == NULL)
        printf("Stack is empty");
    else {
        printf("Stack:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}
int main() {
    int choice;
    while (1) {
        printf("\nOperations on stack:");
        printf("\n1. Push\n2. Pop\n3. Show stack\n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: show();
                break;
            default: exit(0);
        }
    }
    return 0;
}