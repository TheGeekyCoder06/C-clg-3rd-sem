#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

// insert a new node at the head of the linked list
void insertAtHead(struct Node **head, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(struct Node **head, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

void insertAtPosition(struct Node **head, int position, int newData)
{
    if (position == 0)
    {
        insertAtHead(head, newData);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = newData;

    struct Node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("The previous node is null.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void deleteHead(struct Node **head)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteTail(struct Node **head)
{
    if (*head == NULL)
        return;

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL)
        return;

    if (position == 0)
    {
        deleteHead(head);
        return;
    }

    struct Node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("The node to be deleted is null.\n");
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

bool search(struct Node **head, int key)
{
    struct Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

int countNumberOfNodes(struct Node* head){
    int count = 0;
    struct Node* current = head;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

void concatenate(struct Node** head1, struct Node** head2){
    if(*head1 == NULL){
        *head1 = *head2;
        return;
    }
    struct Node* temp = *head1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = *head2;
}

// merge two sorted linked lists (recursion)
struct Node* mergeSortedLists(struct Node* head1 , struct Node* head2) {
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    struct Node* result;

    if(head1->data <= head2->data){
        result = head1;
        result->next = mergeSortedLists(head1->next , head2);
    } else {
        result = head2;
        result->next = mergeSortedLists(head1 , head2->next);
    }

    return result;
}

void reverseList(struct Node** head){
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    struct Node *head = NULL;

    insertAtHead(&head, 1);
    insertAtTail(&head, 3);
    insertAtPosition(&head, 1, 2); // Insert 2 at position 1
    deleteAtPosition(&head, 1);    // Delete node at position 1

    printList(head);               // expected: 1 -> 3 -> NULL

    return 0;
}
