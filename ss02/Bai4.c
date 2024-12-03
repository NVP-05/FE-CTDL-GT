#include <stdio.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("So phan tu khong hop le.\n");
        return 0;
    }
    int arr[n], temp;
    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    printf("Mang sau khi sap xep: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}

