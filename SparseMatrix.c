#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    int row;
    int col;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value, int row, int col) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end of the list
void insert(struct Node** head, int value, int row, int col) {
    struct Node* newNode = createNode(value, row, col);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display sparse matrix linked list
void display(struct Node* head) {
    struct Node* temp = head;
    printf("Sparse Matrix Linked List Format:\n");
    printf("(Row, Column, Value)\n");

    while (temp != NULL) {
        printf("(%d, %d, %d)", temp->row, temp->col, temp->value);
        temp = temp->next;
        if (temp != NULL) printf(" -> ");
    }
    printf(" -> NULL\n");
}

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    printf("Enter matrix elements:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    struct Node* head = NULL;

    // Convert matrix to sparse linked list
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                insert(&head, matrix[i][j], i, j);
            }
        }
    }

    display(head);

    return 0;
}
