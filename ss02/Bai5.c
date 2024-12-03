#include <stdio.h>

int main() {
    int n, k, found = 0;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("So phan tu khong hop le.\n");
        return 0;
    }

    int arr[n];
    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Nhap phan tu k can xoa: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            found = 1;
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--;
            break;
        }
    }

    if (found) {
        printf("Mang sau khi xoa phan tu %d: [", k);
        for (int i = 0; i < n; i++) {
            printf("%d", arr[i]);
            if (i < n - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    } else {
        printf("Khong co phan tu %d trong mang.\n", k);
    }

    return 0;
}

