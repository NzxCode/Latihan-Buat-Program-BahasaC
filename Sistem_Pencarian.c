#include <stdio.h>
#include <string.h>

#define MAX 20

struct Produk {
    char nama[50];
    int harga;
};

int main() {
    struct Produk data[MAX];
    int n, i;
    char cari[50];
    int ditemukan = 0;

    printf("Jumlah produk: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Nama: ");
        scanf(" %[^\n]", data[i].nama);
        printf("Harga: ");
        scanf("%d", &data[i].harga);
    }

    printf("\nMasukkan nama produk yang dicari: ");
    scanf(" %[^\n]", cari);

    for (i = 0; i < n; i++) {
        if (strcmp(cari, data[i].nama) == 0) {
            printf("Ditemukan: %s - Rp%d\n", data[i].nama, data[i].harga);
            ditemukan = 1;
        }
    }

    if (!ditemukan)
        printf("Produk tidak ditemukan.\n");

    return 0;
}