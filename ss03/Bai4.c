#include <stdio.h>
#include <string.h>

void daoNguocChuoi(char str[], int left, int right) {
    if (left >= right) {
        return; 
    }

    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    daoNguocChuoi(str, left + 1, right - 1);
}

int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    daoNguocChuoi(str, 0, strlen(str) - 1);
    printf("Chuoi dao nguoc: %s\n", str);

    return 0;
}

