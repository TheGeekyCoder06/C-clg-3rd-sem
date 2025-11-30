#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert digit at beginning
void insertAtHead(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Print list (optional)
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to add two long integers represented as linked lists
struct Node* addNumbers(struct Node *num1, struct Node *num2) {
    int carry = 0, sum = 0;
    struct Node *result = NULL;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        sum = carry;

        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        insertAtHead(&result, sum);
    }

    return result;
}

int main() {
    struct Node *num1 = NULL, *num2 = NULL, *result = NULL;
    char str1[1000], str2[1000];

    printf("Enter first long integer: ");
    scanf("%s", str1);

    printf("Enter second long integer: ");
    scanf("%s", str2);

    // Insert digits at head for first number
    for (int i = 0; i < strlen(str1); i++) {
        insertAtHead(&num1, str1[i] - '0');  // convert char to int
    }

    // Insert digits at head for second number
    for (int i = 0; i < strlen(str2); i++) {
        insertAtHead(&num2, str2[i] - '0');
    }

    result = addNumbers(num1, num2);

    printf("Result: ");
    printList(result);

    return 0;
}
