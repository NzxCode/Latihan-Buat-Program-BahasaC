#include <stdio.h>
#include <string.h>

#define MAX_BARANG 20
#define MAX_LEN 50

struct Barang {
    char nama[MAX_LEN];
    int jumlah;
};

void tambahBarang(struct Barang daftar[], int *n) {
    if (*n >= MAX_BARANG) {
        printf("Data barang penuh.\n");
        return;
    }

    printf("Nama barang: ");
    scanf(" %[^\n]", daftar[*n].nama);
    printf("Jumlah stok: ");
    scanf("%d", &daftar[*n].jumlah);

    (*n)++;
    printf("Barang berhasil ditambahkan.\n");
}

void updateStok(struct Barang daftar[], int n) {
    int i, pilih, tambah;

    if (n == 0) {
        printf("Belum ada data barang.\n");
        return;
    }

    printf("\nDaftar barang:\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s - %d\n", i + 1, daftar[i].nama, daftar[i].jumlah);
    }

    printf("Pilih nomor barang: ");
    scanf("%d", &pilih);

    if (pilih < 1 || pilih > n) {
        printf("Pilihan tidak valid.\n");
        return;
    }

    printf("Tambah / kurangi stok (contoh: 3 atau -2): ");
    scanf("%d", &tambah);

    daftar[pilih - 1].jumlah += tambah;

    if (daftar[pilih - 1].jumlah < 0) {
        daftar[pilih - 1].jumlah = 0;
    }

    printf("Stok berhasil diperbarui.\n");
}

void lihatBarang(struct Barang daftar[], int n) {
    int i;

    if (n == 0) {
        printf("Belum ada data barang.\n");
        return;
    }

    printf("\n=== INVENTORY ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-20s : %d", i + 1, daftar[i].nama, daftar[i].jumlah);

        if (daftar[i].jumlah == 0) {
            printf("  [HABIS]");
        } else if (daftar[i].jumlah <= 2) {
            printf("  [HAMPIR HABIS]");
        }
        printf("\n");
    }
}

int main() {
    struct Barang daftar[MAX_BARANG];
    int n = 0;
    int pilihan;

    do {
        printf("\n=== INVENTORY TRACKER ===\n");
        printf("1. Tambah barang\n");
        printf("2. Update stok\n");
        printf("3. Lihat inventory\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahBarang(daftar, &n);
                break;
            case 2:
                updateStok(daftar, n);
                break;
            case 3:
                lihatBarang(daftar, n);
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Menu tidak valid.\n");
        }

    } while (pilihan != 4);

    return 0;
}