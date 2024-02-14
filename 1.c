#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertNode(struct Node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    } else {
        head->next = insertNode(head->next, data);
        return head;
    }
}


void printList(struct Node* head) {
    if (head == NULL) {
        return;
    } else {
        printf("%d ", head->data);
        printList(head->next);
    }
}


int findLength(struct Node* head) {
    if (head == NULL) {
        return 0;
    } else {
        return 1 + findLength(head->next);
    }
}

int main() {

    struct Node* head = NULL;

    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);


    printf("Bagli Liste: ");
    printList(head);
    printf("\n");

    int length = findLength(head);
    printf("Bagli Listenin Uzunlugu: %d\n", length);

    return 0;
}
