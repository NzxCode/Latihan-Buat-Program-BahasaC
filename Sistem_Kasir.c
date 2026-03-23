#include <stdio.h>
#include <string.h>

#define MAX_PRODUK 50
#define MAX_TRANSAKSI 50
#define MAX_LEN 50

struct Produk {
    char nama[MAX_LEN];
    int harga;
    int stok;
};

struct ItemTransaksi {
    char nama[MAX_LEN];
    int harga;
    int qty;
    int subtotal;
};

void tambahProduk(struct Produk produk[], int *n) {
    if (*n >= MAX_PRODUK) {
        printf("Data produk penuh.\n");
        return;
    }

    printf("Nama produk: ");
    scanf(" %[^\n]", produk[*n].nama);
    printf("Harga produk: ");
    scanf("%d", &produk[*n].harga);
    printf("Stok produk: ");
    scanf("%d", &produk[*n].stok);

    (*n)++;
    printf("Produk berhasil ditambahkan.\n");
}

void lihatProduk(struct Produk produk[], int n) {
    int i;
    if (n == 0) {
        printf("Belum ada produk.\n");
        return;
    }

    printf("\n=== DAFTAR PRODUK ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-20s | Harga: Rp%d | Stok: %d\n",
               i + 1, produk[i].nama, produk[i].harga, produk[i].stok);
    }
}

void prosesTransaksi(struct Produk produk[], int n) {
    struct ItemTransaksi keranjang[MAX_TRANSAKSI];
    int jumlahItem = 0;
    int pilih, qty, i;
    int total = 0, bayar, kembalian;

    if (n == 0) {
        printf("Belum ada produk untuk dijual.\n");
        return;
    }

    do {
        lihatProduk(produk, n);
        printf("Pilih nomor produk (0 untuk selesai): ");
        scanf("%d", &pilih);

        if (pilih == 0) break;

        if (pilih < 1 || pilih > n) {
            printf("Pilihan tidak valid.\n");
            continue;
        }

        printf("Jumlah beli: ");
        scanf("%d", &qty);

        if (qty <= 0) {
            printf("Jumlah beli tidak valid.\n");
            continue;
        }

        if (qty > produk[pilih - 1].stok) {
            printf("Stok tidak cukup.\n");
            continue;
        }

        strcpy(keranjang[jumlahItem].nama, produk[pilih - 1].nama);
        keranjang[jumlahItem].harga = produk[pilih - 1].harga;
        keranjang[jumlahItem].qty = qty;
        keranjang[jumlahItem].subtotal = qty * produk[pilih - 1].harga;

        produk[pilih - 1].stok -= qty;
        total += keranjang[jumlahItem].subtotal;
        jumlahItem++;

        printf("Item ditambahkan ke transaksi.\n");

    } while (1);

    if (jumlahItem == 0) {
        printf("Tidak ada transaksi.\n");
        return;
    }

    printf("\n=== STRUK BELANJA ===\n");
    for (i = 0; i < jumlahItem; i++) {
        printf("%d. %-20s %d x Rp%d = Rp%d\n",
               i + 1,
               keranjang[i].nama,
               keranjang[i].qty,
               keranjang[i].harga,
               keranjang[i].subtotal);
    }

    printf("Total belanja: Rp%d\n", total);

    do {
        printf("Uang bayar: ");
        scanf("%d", &bayar);

        if (bayar < total) {
            printf("Uang kurang. Masukkan lagi.\n");
        }
    } while (bayar < total);

    kembalian = bayar - total;
    printf("Kembalian: Rp%d\n", kembalian);
}

int main() {
    struct Produk produk[MAX_PRODUK];
    int n = 0;
    int menu;

    do {
        printf("\n=== SISTEM KASIR UMKM ===\n");
        printf("1. Tambah produk\n");
        printf("2. Lihat produk\n");
        printf("3. Proses transaksi\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: tambahProduk(produk, &n); break;
            case 2: lihatProduk(produk, n); break;
            case 3: prosesTransaksi(produk, n); break;
            case 4: printf("Program selesai.\n"); break;
            default: printf("Menu tidak valid.\n");
        }
    } while (menu != 4);

    return 0;
}