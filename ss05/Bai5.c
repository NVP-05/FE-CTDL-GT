#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void reverseList(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* temp = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n, data;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &data);
        append(&head, &tail, data);
    }
    reverseList(&head);
    printList(head);

    return 0;
}

