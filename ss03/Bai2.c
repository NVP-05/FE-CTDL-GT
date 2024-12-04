#include <stdio.h>

int tinhTong(int n, int m) {
    if (n > m) {
        return 0;
    }
    return n + tinhTong(n + 1, m);
}

int main() {
    int n, m;
    printf("Nhap so n: ");
    scanf("%d", &n);
    printf("Nhap so m: ");
    scanf("%d", &m);
    if (n > m) {
        printf("Vui long nhap n nho hon hoac bang m.\n");
    } else {
        printf("Tong day so tu %d den %d la: %d\n", n, m, tinhTong(n, m));
    }

    return 0;
}

