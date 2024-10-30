#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *first = NULL;
void display() {
    struct node *ptr;
    ptr = first;
    do{
        printf("%d ", ptr->info);
        ptr = ptr->link;
    } while(ptr != first);
    printf("\n");
}
void insertbeg() {
    struct node *new, *ptr;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d", &new->info);
    if(first == NULL) {
        first = new;
        new->link = first;
    }
    else {
        ptr = first;
        while(ptr->link != first)
            ptr = ptr->link;
        new->link = first;
        first = new;
        ptr->link = first;
    }
    printf("Node inserted\n");
    display();
}
void insertend() {
    struct node *new, *ptr;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d", &new->info);
    if(first == NULL) {
        first = new;
        new->link = first;
    } else {
        ptr = first;
        while(ptr->link != first)
            ptr = ptr->link;
        new->link = first;
        ptr->link = new;
    }
    printf("Node inserted\n");
    display();
}
void insertmid() {
    struct node *new, *ptr;
    int val;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d", &new->info);
    printf("Enter the value after which to insert: ");
    scanf("%d", &val);
    ptr = first;
    while(ptr->info != val)
        ptr = ptr->link;
    new->link = ptr->link;
    ptr->link = new;
    printf("Node inserted\n");
    display();
}
void deletebeg() {
    struct node *ptr;
    ptr = first;
    while(ptr->link != first)
        ptr = ptr->link;
    ptr->link = first->link;
    free(first);
    first = ptr->link;
    printf("Node deleted\n");
    display();
}
void deleteend() {
    struct node *ptr, *temp;
    ptr = first;
    while(ptr->link != first) {
        temp = ptr;
        ptr = ptr->link;
    }
    temp->link = first;
    free(ptr);
    printf("Node deleted\n");
    display();
}
void deletemid() {
    struct node *ptr, *temp;
    int data;
    printf("Enter the value to delete: ");
    scanf("%d", &data);
    ptr = first;
    while(ptr->info != data) {
        temp = ptr;
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    free(ptr);
    printf("Node deleted\n");
    display();
}
int main() {
    int ch;
    first = NULL;
    while(1) {
        printf("\nOperations on circular linked list:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at middle\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from middle\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insertbeg();
                    break;
            case 2: insertend();
                    break;
            case 3: insertmid();
                    break;
            case 4: deletebeg();
                    break;
            case 5: deleteend();
                    break;
            case 6: deletemid();
                    break;
            case 7: display();
                    break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}