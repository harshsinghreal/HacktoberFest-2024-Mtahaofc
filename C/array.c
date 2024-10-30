#include <stdio.h>
void display(int a[], int s) {
    printf("Array elements: ");
    for (int i = 0; i < s; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int insert(int a[], int s, int e, int pos) {
    if (pos < 0 || pos > s) {
        printf("Invalid pos for insertion.\n");
        return s;
    }
    for (int i = s - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }
    a[pos] = e;
    return s + 1;
}
int delete(int a[], int s, int pos) {
    if (pos < 0 || pos >= s) {
        printf("Invalid pos for deletion.\n");
        return s;
    }
    for (int i = pos; i < s - 1; i++) {
        a[i] = a[i + 1];
    }
    return s - 1;
}
int search(int a[], int s, int e) {
    for (int i = 0; i < s; i++) {
        if (a[i] == e) {
            return i;
        }
    }
    return -1;
}
void update(int a[], int s, int pos, int new) {
    if (pos >= 0 && pos < s) {
        a[pos] = new;
    } else {
        printf("Invalid pos for updating.\n");
    }
}
int main() {
    int a[100];
    int s = 0;
    s = insert(a, s, 10, 0);
    s = insert(a, s, 20, 1);
    s = insert(a, s, 30, 2);
    printf("After insertion:\n");
    display(a, s);
    s = delete(a, s, 1);
    printf("After deletion:\n");
    display(a, s);
    int ind = search(a, s, 30);
    if (ind != -1) {
        printf("Element 30 found at index %d\n", ind);
    } else {
        printf("Element 30 not found.\n");
    }
    update(a, s, 1, 40);
    printf("After updating:\n");
    display(a, s);
    return 0;
}