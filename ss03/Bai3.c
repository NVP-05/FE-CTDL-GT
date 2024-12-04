#include <stdio.h>

// Hàm d? quy tính s? Fibonacci th? n
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Vui long nhap mot so nguyen duong lon hon 0.\n");
    } else {
        printf("Day Fibonacci: ");
        for (int i = 0; i < n; i++) {
            printf("%d", fibonacci(i));
            if (i < n - 1) {
                printf(","); 
            }
        }
        printf("\n");
    }

    return 0;
}

