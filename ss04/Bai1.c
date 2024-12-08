#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createList(int n) {
    Node* head = NULL;
    Node* temp = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL) {
            printf("Cap phat bo nho khong thanh cong\n");
            return NULL;
        }
        printf("Nhap gia tri cho nut %d: ", i + 1);
        scanf("%d", &(temp->data));
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    printf("Danh sach lien ket chua: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    printf("Nhap so phan tu cho danh sach lien ket: ");
    scanf("%d", &n);
    Node* head = createList(n);
    printList(head);
    freeList(head);

    return 0;
}

