#include <stdio.h>

int main() {
    int n, x, count = 0;
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
    printf("Nhap so x: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    printf("So lan xuat hien cua %d trong mang: %d\n", x, count);

    return 0;
}

