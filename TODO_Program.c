#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define the structure for a node
struct Node {
    char* data;
    struct Node* next;
};
void plan();//universal function to print the main menu
void add(const char* task);//universal function to add a new task
void delete(const char* task);//universal function to delete a task
void print();
struct Node* head = NULL;
void add(const char* task) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = strdup(task);
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Find the last node in the list
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Append the new node to the end of the list
        current->next = newNode;
    }
}
void delete(const char* task) {
    // If the list is empty, nothing to delete
    if (head == NULL) {
        return;
    }
    // If the head node matches the task, delete it
    if (strcmp(head->data, task) == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    // Find the node to delete
    struct Node* current = head;
    struct Node* previous = NULL;
    while (current != NULL && strcmp(current->data, task) != 0) {
        previous = current;
        current = current->next;
    }
    // If the node is found, delete it
    if (current != NULL) {
        previous->next = current->next;
        free(current);
    }
}
void print() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}
int main() {
    int choice;
    char task[100];
    plan();
    while (1) {
        scanf("%d", &choice);
    
        switch (choice) {
            case 1:
                printf("Enter the task: ");
                fflush(stdin); // Clear the input buffer
                fgets(task, sizeof(task), stdin);
                task[strcspn(task, "\n")] = '\0'; // Remove the newline character from the input
                add(task);
                break;
            case 2:
                printf("Enter the task: ");
                fflush(stdin); // Clear the input buffer
                fgets(task, sizeof(task), stdin);
                task[strcspn(task, "\n")] = '\0'; // Remove the newline character from the input
                delete(task);
                break;
            case 3:
                printf("Tasks:\n");
                print();
                break;
            case 4: {
                struct Node* cur = head;
                while (cur != NULL) {
                    struct Node* temp = cur;
                    cur = cur->next;
                    free(temp->data);
                    free(temp);
                }
                head = NULL;
                exit(0);
            }
            default:
                printf("Invalid choice\n");
        }
        
        plan();
    }
    return 0;
}
void plan() {
    printf("1. Add a task\n");
    printf("2. Delete a task\n");
    printf("3. Print the tasks\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}