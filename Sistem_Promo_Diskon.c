#include <stdio.h>

int main() {
    int total, diskon = 0;

    printf("Masukkan total belanja: ");
    scanf("%d", &total);

    if (total >= 500000) {
        diskon = total * 20 / 100;
    } else if (total >= 200000) {
        diskon = total * 10 / 100;
    } else if (total >= 100000) {
        diskon = total * 5 / 100;
    }

    printf("\nTotal awal : Rp%d\n", total);
    printf("Diskon     : Rp%d\n", diskon);
    printf("Total bayar: Rp%d\n", total - diskon);

    return 0;
}