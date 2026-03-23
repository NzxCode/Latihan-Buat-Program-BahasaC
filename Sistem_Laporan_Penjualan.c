#include <stdio.h>
#include <string.h>

#define MAX_PENJUALAN 100
#define MAX_LEN 50

struct Penjualan {
    char namaProduk[MAX_LEN];
    int qty;
    int harga;
    int omzet;
};

int cariProdukTerlaris(struct Penjualan data[], int n) {
    int i, idx = 0;
    for (i = 1; i < n; i++) {
        if (data[i].qty > data[idx].qty) {
            idx = i;
        }
    }
    return idx;
}

int main() {
    struct Penjualan data[MAX_PENJUALAN];
    int n, i;
    int totalOmzet = 0, totalQty = 0, idx;

    printf("=== LAPORAN PENJUALAN HARIAN UMKM ===\n");
    printf("Masukkan jumlah transaksi produk hari ini: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PENJUALAN) {
        printf("Jumlah data tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\nData ke-%d\n", i + 1);
        printf("Nama produk: ");
        scanf(" %[^\n]", data[i].namaProduk);
        printf("Jumlah terjual: ");
        scanf("%d", &data[i].qty);
        printf("Harga satuan: ");
        scanf("%d", &data[i].harga);

        data[i].omzet = data[i].qty * data[i].harga;
        totalOmzet += data[i].omzet;
        totalQty += data[i].qty;
    }

    idx = cariProdukTerlaris(data, n);

    printf("\n=== HASIL LAPORAN PENJUALAN ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-20s | Qty: %d | Harga: Rp%d | Omzet: Rp%d\n",
               i + 1,
               data[i].namaProduk,
               data[i].qty,
               data[i].harga,
               data[i].omzet);
    }

    printf("Total omzet        : Rp%d\n", totalOmzet);
    printf("Total barang laku  : %d\n", totalQty);
    printf("Produk terlaris    : %s (%d unit)\n", data[idx].namaProduk, data[idx].qty);
    printf("Rata-rata omzet/item data: Rp%.2f\n", (float) totalOmzet / n);

    return 0;
}