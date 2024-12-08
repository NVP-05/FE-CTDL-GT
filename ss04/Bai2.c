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
        } else {
            tail->next = temp;  
        }
        tail = temp; 
    }

    return head;
}

Node* insertAtHead(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Cap phat bo nho khong thanh cong\n");
        return head;
    }
    newNode->data = value;  
    newNode->next = head;    
    head = newNode;       

    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
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
    printf(" -> NULL\n");
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
    int n, value;
    printf("Nhap so phan tu cho danh sach lien ket: ");
    scanf("%d", &n);
    Node* head = NULL;
    if (n > 0) {
        head = createList(n); 
    }
    printf("Nhap gia tri chen vao dau danh sach: ");
    scanf("%d", &value);
    head = insertAtHead(head, value);
    printList(head);
    freeList(head);

    return 0;
}

