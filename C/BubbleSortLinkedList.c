#include <stdio.h>
#include <stdlib.h>
#define SPECIFIER "%d"
#define MAXIMUMSIZE 20

// data types
typedef int dtype;

typedef struct node
{
    dtype data;
    struct node *next;
} Node;

Node *input_LinkedList();
void bubble_sort_execution(Node *linkedlist);
void printLinkedList(const Node *head);

int main()
{
    // Pointer for the linked lists
    Node *head_node;

    // Input array elements with validation
    head_node = input_LinkedList();

    printf("\nEntered Input Linked List is: ");
    printLinkedList(head_node);

    bubble_sort_execution(head_node);
    printf("\nFinal Bubble Sorted Linked List is: ");
    printLinkedList(head_node);

    free(head_node);
    return 0;
}

// Function to create the input Linked List.
Node *input_LinkedList()
{
    dtype size, element, result;

    // Prompt user for number of elements
    printf("Enter the number of elements (up to %d): ", MAXIMUMSIZE);
    result = scanf(SPECIFIER, &size);
    // Validate number of elements
    while (result != 1 || (size > MAXIMUMSIZE || size < 1))
    {
        if (result == 0)
        {
            // Clear the invalid input
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
        }
        else
            printf("Invalid number of elements!\n");
        // Prompt user for number of elements
        printf("Enter the number of elements (up to %d): ", MAXIMUMSIZE);
        result = scanf(SPECIFIER, &size);
    }

    // Allocate memory for the head node
    Node *head = NULL, *track_node = NULL;

    // Prompt user to input array elements
    printf("Enter the elements:\n");
    for (dtype i = 0; i < size; i++)
    {
        // Allocate memory for a new node
        Node *data_node = calloc(1, sizeof(Node));
        if (!data_node)
        {
            // Check for memory allocation failure
            printf("Memory allocation failed!\n");
            return NULL; // Return NULL on allocation failure
        }
        printf("Element %d: ", i + 1);
        scanf(SPECIFIER, &element);
        // Set data for the new node
        data_node->data = element;
        // Initialize next pointer to NULL
        data_node->next = NULL;
        // Link the head node on the first iteration
        if (head == NULL)
        {
            head = data_node; // Set head to the first node
        }
        else
        {
            track_node->next = data_node; // Link the current node to the new node
        }
        // Move the tracker to the new node
        track_node = data_node;
    }
    // Return the head of the linked list
    return head;
}

void bubble_sort_execution(Node *linkedlist)
{
    dtype swapped;
    Node *track_bubble_node, *last_node = NULL;
    // Bubble Sort algorithm on the Linked list.
    do
    {
        swapped = 0;
        // Start from the head of the list
        track_bubble_node = linkedlist;
        // Traverse the list until the last sorted node
        while (track_bubble_node->next != last_node)
        {
            // Swap if necessary
            if (track_bubble_node->data > track_bubble_node->next->data)
            {
                dtype temp = track_bubble_node->data;
                track_bubble_node->data = track_bubble_node->next->data;
                track_bubble_node->next->data = temp;
                // Indicate a swap occurred
                swapped = 1;
            }
            // Move to the next node
            track_bubble_node = track_bubble_node->next;
        }
        // Mark the last node as sorted
        last_node = track_bubble_node;
    } while (swapped); // Repeat until no swaps occur
}

// Function to print a linked list
void printLinkedList(const Node *head)
{
    // Pointer to track the current node
    const Node *track_node = head;
    // Traverse until the second last node
    while (track_node->next)
    {
        // Print each element followed by a comma
        printf(SPECIFIER ", ", track_node->data);
        // Move to the next node
        track_node = track_node->next;
    }
    // Print the last element without a comma
    printf(SPECIFIER, track_node->data);
}