#include <stdio.h>
#include <string.h>

#define MAX_DATA 30
#define MAX_LEN 50

struct Pengeluaran {
    char kategori[MAX_LEN];
    int jumlah;
};

int main() {
    struct Pengeluaran data[MAX_DATA];
    int pemasukan, n, i, totalPengeluaran = 0, sisa;

    printf("=== CASHFLOW ANAK KOS ===\n");
    printf("Masukkan total pemasukan bulan ini: ");
    scanf("%d", &pemasukan);

    printf("Masukkan jumlah data pengeluaran: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DATA) {
        printf("Jumlah data tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\nPengeluaran ke-%d\n", i + 1);
        printf("Kategori: ");
        scanf(" %[^\n]", data[i].kategori);
        printf("Jumlah: ");
        scanf("%d", &data[i].jumlah);
        totalPengeluaran += data[i].jumlah;
    }

    sisa = pemasukan - totalPengeluaran;

    printf("\n=== LAPORAN CASHFLOW ===\n");
    printf("Pemasukan        : Rp%d\n", pemasukan);
    printf("Total pengeluaran: Rp%d\n", totalPengeluaran);
    printf("Sisa uang        : Rp%d\n", sisa);

    if (sisa < 0) {
        printf("Status           : Pengeluaran melebihi pemasukan\n");
    } else if (sisa <= pemasukan * 0.2) {
        printf("Status           : Uang mulai menipis\n");
    } else {
        printf("Status           : Keuangan masih aman\n");
    }

    return 0;
}