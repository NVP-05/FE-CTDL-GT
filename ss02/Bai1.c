#include <stdio.h>

int main() {
    int n;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        return 0; 
    }
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Phan tu lon nhat la: %d\n", max);

    return 0;
}

