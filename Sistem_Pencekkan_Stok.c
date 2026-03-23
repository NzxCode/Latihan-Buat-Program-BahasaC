#include <stdio.h>
#include <string.h>

#define MAX_BARANG 100
#define MAX_LEN 50

struct Barang {
    char kode[20];
    char nama[MAX_LEN];
    int stok;
    int batasMinimum;
};

void tambahBarang(struct Barang barang[], int *n) {
    if (*n >= MAX_BARANG) {
        printf("Data barang penuh.\n");
        return;
    }

    printf("Kode barang: ");
    scanf("%s", barang[*n].kode);
    printf("Nama barang: ");
    scanf(" %[^\n]", barang[*n].nama);
    printf("Stok awal: ");
    scanf("%d", &barang[*n].stok);
    printf("Batas minimum stok: ");
    scanf("%d", &barang[*n].batasMinimum);

    (*n)++;
    printf("Barang berhasil ditambahkan.\n");
}

void tampilBarang(struct Barang barang[], int n) {
    int i;
    if (n == 0) {
        printf("Belum ada data barang.\n");
        return;
    }

    printf("\n=== DATA STOK GUDANG ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. [%s] %-20s | Stok: %d | Min: %d",
               i + 1, barang[i].kode, barang[i].nama, barang[i].stok, barang[i].batasMinimum);

        if (barang[i].stok == 0) {
            printf(" [HABIS]");
        } else if (barang[i].stok <= barang[i].batasMinimum) {
            printf(" [RESTOCK]");
        }
        printf("\n");
    }
}

void stokMasuk(struct Barang barang[], int n) {
    int pilih, jumlah;

    tampilBarang(barang, n);
    if (n == 0) return;

    printf("Pilih nomor barang: ");
    scanf("%d", &pilih);

    if (pilih < 1 || pilih > n) {
        printf("Pilihan tidak valid.\n");
        return;
    }

    printf("Jumlah stok masuk: ");
    scanf("%d", &jumlah);

    if (jumlah <= 0) {
        printf("Jumlah tidak valid.\n");
        return;
    }

    barang[pilih - 1].stok += jumlah;
    printf("Stok berhasil ditambahkan.\n");
}

void stokKeluar(struct Barang barang[], int n) {
    int pilih, jumlah;

    tampilBarang(barang, n);
    if (n == 0) return;

    printf("Pilih nomor barang: ");
    scanf("%d", &pilih);

    if (pilih < 1 || pilih > n) {
        printf("Pilihan tidak valid.\n");
        return;
    }

    printf("Jumlah stok keluar: ");
    scanf("%d", &jumlah);

    if (jumlah <= 0) {
        printf("Jumlah tidak valid.\n");
        return;
    }

    if (jumlah > barang[pilih - 1].stok) {
        printf("Stok tidak mencukupi.\n");
        return;
    }

    barang[pilih - 1].stok -= jumlah;
    printf("Stok berhasil dikurangi.\n");
}

int main() {
    struct Barang barang[MAX_BARANG];
    int n = 0, menu;

    do {
        printf("\n=== SISTEM STOK GUDANG UMKM ===\n");
        printf("1. Tambah barang\n");
        printf("2. Lihat stok\n");
        printf("3. Stok masuk\n");
        printf("4. Stok keluar\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: tambahBarang(barang, &n); break;
            case 2: tampilBarang(barang, n); break;
            case 3: stokMasuk(barang, n); break;
            case 4: stokKeluar(barang, n); break;
            case 5: printf("Program selesai.\n"); break;
            default: printf("Menu tidak valid.\n");
        }
    } while (menu != 5);

    return 0;
}