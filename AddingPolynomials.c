#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

// Create a new polynomial term
struct Node* createNode(int coef, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert term in descending exponent order
void insertTerm(struct Node** head, int coef, int exp) {
    struct Node* newNode = createNode(coef, exp);

    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->exp > exp)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Add two polynomial lists
struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sum = p1->coef + p2->coef;
            if (sum != 0)
                insertTerm(&result, sum, p1->exp);

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else {
            insertTerm(&result, p2->coef, p2->exp);
            p2 = p2->next;
        }
    }

    // Remaining terms
    while (p1 != NULL) {
        insertTerm(&result, p1->coef, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Display polynomial
void printPoly(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dX^%d", temp->coef, temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node *p1 = NULL, *p2 = NULL, *result = NULL;

    // Example polynomial 1: 3X^8 + 5X^7 - 2X^6 + 8X^4
    insertTerm(&p1, 3, 8);
    insertTerm(&p1, 5, 7);
    insertTerm(&p1, -2, 6);
    insertTerm(&p1, 8, 4);

    // Example polynomial 2: 4X^7 + 5X^6 - X^3 + 7X^2 - 3X^0
    insertTerm(&p2, 4, 7);
    insertTerm(&p2, 5, 6);
    insertTerm(&p2, -1, 3);
    insertTerm(&p2, 7, 2);
    insertTerm(&p2, -3, 0);

    printf("Polynomial 1: ");
    printPoly(p1);

    printf("Polynomial 2: ");
    printPoly(p2);

    result = addPolynomials(p1, p2);

    printf("Result:      ");
    printPoly(result);

    return 0;
}
