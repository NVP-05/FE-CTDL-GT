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

int searchList(Node* head, int target) {
    int index = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return index; 
        }
        current = current->next;
        index++;
    }
    return -1;
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
    int n, searchValue;
    printf("Nhap so phan tu cho danh sach lien ket: ");
    scanf("%d", &n);
    
    if (n == 0) {
        printf("Danh sach trong\n");
        return 0; 
    }
    
    Node* head = createList(n);

    printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);

    int result = searchList(head, searchValue);
    if (result != -1) {
        printf("Vi tri cua phan tu %d trong danh sach la: %d\n", searchValue, result);
    } else {
        printf("-1\n");
    }

    freeList(head);
    return 0;
}

