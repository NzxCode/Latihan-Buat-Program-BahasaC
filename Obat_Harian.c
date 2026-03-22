#include <stdio.h>
#include <string.h>

#define MAX_OBAT 20
#define MAX_LEN 50

struct Obat {
    char nama[MAX_LEN];
    char jam[10];
    int sudahDiminum;
};

void tampilDaftar(struct Obat obat[], int n) {
    int i;
    if (n == 0) {
        printf("Belum ada data obat.\n");
        return;
    }

    printf("\n=== DAFTAR OBAT ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-20s Jam: %-8s Status: %s\n",
               i + 1,
               obat[i].nama,
               obat[i].jam,
               obat[i].sudahDiminum ? "Sudah" : "Belum");
    }
}

int main() {
    struct Obat obat[MAX_OBAT];
    int n, i, pilih;

    printf("=== PENGINGAT OBAT HARIAN ===\n");
    printf("Masukkan jumlah obat: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_OBAT) {
        printf("Jumlah obat tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\nObat ke-%d\n", i + 1);
        printf("Nama obat: ");
        scanf(" %[^\n]", obat[i].nama);
        printf("Jam minum (contoh 08:00): ");
        scanf("%s", obat[i].jam);
        obat[i].sudahDiminum = 0;
    }

    tampilDaftar(obat, n);

    printf("\nPilih nomor obat yang sudah diminum: ");
    scanf("%d", &pilih);

    if (pilih >= 1 && pilih <= n) {
        obat[pilih - 1].sudahDiminum = 1;
    }

    tampilDaftar(obat, n);

    return 0;
}