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

void insertAtPosition(struct Node** head, struct Node** tail, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int count = 0;
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL || count != position - 1) {
        printf("Loi vi tri khong hop le\n");
        exit(0); 
    }
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
    if (newNode->next == NULL) {
        *tail = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf(" <-> NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n, data, position;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &data);
        append(&head, &tail, data);
    }
    printf("Danh sach ban dau: ");
    printList(head);
    printf("Gia tri can chen: ");
    scanf("%d", &data);
    printf("Vi tri can chen: ");
    scanf("%d", &position);
    insertAtPosition(&head, &tail, data, position);
    printList(head);

    return 0;
}

