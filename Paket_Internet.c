#include <stdio.h>

#define MAX_DAY 31

int main() {
    float penggunaan[MAX_DAY];
    int n, i;
    float kuotaBulanan, total = 0, sisa;

    printf("Masukkan total kuota bulanan (GB): ");
    scanf("%f", &kuotaBulanan);

    printf("Masukkan jumlah hari yang ingin dicatat: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DAY) {
        printf("Jumlah hari tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Pemakaian internet hari ke-%d (GB): ", i + 1);
        scanf("%f", &penggunaan[i]);

        if (penggunaan[i] < 0) {
            printf("Pemakaian tidak boleh negatif.\n");
            return 0;
        }

        total += penggunaan[i];
    }

    sisa = kuotaBulanan - total;

    printf("\n=== INTERNET USAGE MONITOR ===\n");
    printf("Total pemakaian : %.2f GB\n", total);
    printf("Sisa kuota      : %.2f GB\n", sisa);

    if (sisa < 0) {
        printf("Status          : Kuota sudah habis/melebihi batas\n");
    } else if (sisa <= kuotaBulanan * 0.2) {
        printf("Status          : Warning, kuota hampir habis\n");
    } else {
        printf("Status          : Kuota masih aman\n");
    }

    return 0;
}