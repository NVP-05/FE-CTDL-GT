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

void replaceValue(struct Node* head, int oldValue, int newValue) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == oldValue) {
            current->data = newValue;
            return;  
        }
        current = current->next;
    }

    printf("Khong tim thay phan tu thay the\n");
    exit(0);
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
    int n, data, oldValue, newValue;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &data);
        append(&head, &tail, data);
    }
    printf("Gia tri can thay the: ");
    scanf("%d", &oldValue);
    printf("Gia tri moi: ");
    scanf("%d", &newValue);
    replaceValue(head, oldValue, newValue);
    printList(head);

    return 0;
}

