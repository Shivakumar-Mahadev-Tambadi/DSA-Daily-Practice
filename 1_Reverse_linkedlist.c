#include<stdio.h>
#include<stdlib.h> // Include stdlib for memory allocation

struct node{
    int data;
    struct node *next;
};

// Function to create a new node and append it at the end of the list
struct node *createNode(struct node *head, int num){
    struct node *ptr, *new_node = (struct node*)malloc(sizeof(struct node)); // Allocate memory for new_node
    new_node->data = num;
    new_node->next = NULL;
    if(head == NULL) // If the list is empty, new_node becomes the head
    {
        return new_node;
    }
    else { // Otherwise, find the last node and append new_node
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        return head; // Return the head of the list
    } 
}

// Function to reverse the linked list
void revLL(struct node **head)
{
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev; // Update head to the new first node
}

// Function to display the linked list
void display(struct node *head)
{
    struct node *ptr = head;
    if(ptr == NULL) // Check if the list is empty
    {
        printf("LIST IS EMPTY...\n");
    }
    else
    {
        while(ptr != NULL) // Traverse and print each node
        {
            printf("%d   ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n"); // Print newline at the end
    }
}

// Main function
int main(){
    struct node *head = NULL; // Initialize head to NULL
    int num;

    printf("Enter data to insert or -1 to stop :\n");
    scanf("%d", &num);
    while(num != -1)
    {
        head = createNode(head, num);
        printf("Enter data to insert or -1 to stop :\n");
        scanf("%d", &num);
    }
    revLL(&head); // Pass address of head to revLL
    display(head);

    return 0; // Return 0 to indicate successful execution
}