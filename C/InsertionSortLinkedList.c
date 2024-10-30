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
Node *insertion_sort_execution(Node *linkedlist);
void printLinkedList(const Node *head);

int main()
{
    // Pointer for the linked lists
    Node *head_node;

    // Input array elements with validation
    head_node = input_LinkedList();

    printf("\nEntered Input Linked List is: ");
    printLinkedList(head_node);

    head_node = insertion_sort_execution(head_node);
    printf("\nFinal Insertion Sorted Linked List is: ");
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

Node *insertion_sort_execution(Node *linkedlist)
{
    Node *track_insertion_node, *sorted = NULL;
    // Insertion Sort algorithm on the Linked list.
    // Start from the head of the original list
    track_insertion_node = linkedlist;
    // Traverse the original list
    while (track_insertion_node != NULL)
    {
        // Store the next node temporarily
        Node *next_node = track_insertion_node->next;
        // Insert at the beginning
        if (sorted == NULL || sorted->data >= track_insertion_node->data)
        {
            // Link new node to sorted list
            track_insertion_node->next = sorted;
            // Update sorted list head
            sorted = track_insertion_node;
        }
        // Insert in the correct position in the sorted list
        else
        {
            // Pointer to traverse the sorted list
            Node *track_node = sorted;
            // Find the correct position
            while (track_node->next != NULL && track_node->next->data < track_insertion_node->data)
            {
                // Move to the next node
                track_node = track_node->next;
            }
            // Link new node to the found position
            track_insertion_node->next = track_node->next;
            // Update the sorted list
            track_node->next = track_insertion_node;
        }
        // Move to the next node in the original list
        track_insertion_node = next_node;
    }
    // Update the original list to the sorted list
    linkedlist = sorted;
    return linkedlist;
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