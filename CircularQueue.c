#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Print (Traversal)
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(HEAD)\n");
}

// Insert At Head (IAH)
void insertAtHead(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {           // empty list
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

// Insert At Tail (IAT)
void insertAtTail(struct Node** head, int value) {
    if (*head == NULL) {
        insertAtHead(head, value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
}

// Insert At Position (IAP)
void insertAtPosition(struct Node** head, int pos, int value) {
    if (pos == 0) {
        insertAtHead(head, value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = *head;
    for (int i = 0; i < pos - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete At Head (DAH)
void deleteAtHead(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    if (temp->next == *head) {   // only one node
        free(temp);
        *head = NULL;
        return;
    }

    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    last->next = temp->next;
    *head = temp->next;
    free(temp);
}

// Delete At Tail (DAT)
void deleteAtTail(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    if (temp->next == *head) {   // only one node
        free(temp);
        *head = NULL;
        return;
    }

    struct Node* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp);
}

// Delete At Position (DAP)
void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL) return;

    if (pos == 0) {
        deleteAtHead(head);
        return;
    }

    struct Node* curr = *head;
    struct Node* prev = NULL;

    for (int i = 0; i < pos && curr->next != *head; i++) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    free(curr);
}

// Search (returns 1 if found else 0)
int search(struct Node* head, int key) {
    if (head == NULL) return 0;

    struct Node* temp = head;
    do {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    } while (temp != head);

    return 0;
}

int main() {
    struct Node* head = NULL;

    insertAtHead(&head, 1);      // IAH
    insertAtTail(&head, 3);      // IAT
    insertAtPosition(&head, 1, 2); // IAP

    printList(head);

    deleteAtHead(&head);         // DAH
    printList(head);

    deleteAtTail(&head);         // DAT
    printList(head);

    insertAtTail(&head, 4);
    insertAtTail(&head, 5);
    printList(head);

    deleteAtPosition(&head, 1);  // DAP
    printList(head);

    printf("Search 5: %s\n", search(head, 5) ? "Found" : "Not Found");
    printf("Search 10: %s\n", search(head, 10) ? "Found" : "Not Found");

    return 0;
}
