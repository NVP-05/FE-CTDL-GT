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
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            tail->next = temp;
        }
        tail = temp;
    }

    return head;
}

Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return NULL;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    int currentPosition = 0;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL || current->next == NULL) {
        printf("Vi tri khong hop le\n");
        return NULL;  
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);

    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sach trong\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
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
    int n, position;
    printf("Nhap so phan tu cho danh sach lien ket: ");
    scanf("%d", &n);
    
    Node* head = NULL;
    if (n > 0) {
        head = createList(n);
    }

    printf("Nhap vi tri can xoa: ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);
    if (head == NULL) {
        return 0;
    }

    printf("Danh sach sau khi xoa: ");
    printList(head);

    freeList(head);
    return 0;
}

