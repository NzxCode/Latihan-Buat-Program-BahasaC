#include <stdio.h>

void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    printf("Masukkan x: ");
    scanf("%d", &x);
    printf("Masukkan y: ");
    scanf("%d", &y);

    printf("\nSebelum ditukar: x = %d, y = %d\n", x, y);

    tukar(&x, &y);

    printf("Sesudah ditukar: x = %d, y = %d\n", x, y);

    return 0;
}