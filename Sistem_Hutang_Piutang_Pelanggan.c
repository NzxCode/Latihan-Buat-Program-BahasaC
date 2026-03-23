#include <stdio.h>
#include <string.h>

#define MAX_PELANGGAN 100
#define MAX_LEN 50

struct Piutang {
    char namaPelanggan[MAX_LEN];
    int totalHutang;
    int totalBayar;
    int sisaHutang;
};

void tambahPelanggan(struct Piutang data[], int *n) {
    if (*n >= MAX_PELANGGAN) {
        printf("Data pelanggan penuh.\n");
        return;
    }

    printf("Nama pelanggan: ");
    scanf(" %[^\n]", data[*n].namaPelanggan);

    data[*n].totalHutang = 0;
    data[*n].totalBayar = 0;
    data[*n].sisaHutang = 0;

    (*n)++;
    printf("Pelanggan berhasil ditambahkan.\n");
}

void tampilPiutang(struct Piutang data[], int n) {
    int i;

    if (n == 0) {
        printf("Belum ada data pelanggan.\n");
        return;
    }

    printf("\n=== DATA PIUTANG PELANGGAN ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-20s | Hutang: Rp%d | Bayar: Rp%d | Sisa: Rp%d",
               i + 1,
               data[i].namaPelanggan,
               data[i].totalHutang,
               data[i].totalBayar,
               data[i].sisaHutang);

        if (data[i].sisaHutang == 0) {
            printf(" [LUNAS]");
        }
        printf("\n");
    }
}

void catatHutang(struct Piutang data[], int n) {
    int pilih, nominal;

    tampilPiutang(data, n);
    if (n == 0) return;

    printf("Pilih nomor pelanggan: ");
    scanf("%d", &pilih);

    if (pilih < 1 || pilih > n) {
        printf("Pilihan tidak valid.\n");
        return;
    }

    printf("Nominal hutang baru: ");
    scanf("%d", &nominal);

    if (nominal <= 0) {
        printf("Nominal tidak valid.\n");
        return;
    }

    data[pilih - 1].totalHutang += nominal;
    data[pilih - 1].sisaHutang += nominal;

    printf("Hutang berhasil dicatat.\n");
}

void catatPembayaran(struct Piutang data[], int n) {
    int pilih, nominal;

    tampilPiutang(data, n);
    if (n == 0) return;

    printf("Pilih nomor pelanggan: ");
    scanf("%d", &pilih);

    if (pilih < 1 || pilih > n) {
        printf("Pilihan tidak valid.\n");
        return;
    }

    printf("Nominal pembayaran: ");
    scanf("%d", &nominal);

    if (nominal <= 0) {
        printf("Nominal tidak valid.\n");
        return;
    }

    if (nominal > data[pilih - 1].sisaHutang) {
        printf("Pembayaran melebihi sisa hutang.\n");
        return;
    }

    data[pilih - 1].totalBayar += nominal;
    data[pilih - 1].sisaHutang -= nominal;

    printf("Pembayaran berhasil dicatat.\n");
}

int main() {
    struct Piutang data[MAX_PELANGGAN];
    int n = 0, menu;

    do {
        printf("\n=== SISTEM HUTANG PIUTANG UMKM ===\n");
        printf("1. Tambah pelanggan\n");
        printf("2. Lihat data piutang\n");
        printf("3. Catat hutang\n");
        printf("4. Catat pembayaran\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: tambahPelanggan(data, &n); break;
            case 2: tampilPiutang(data, n); break;
            case 3: catatHutang(data, n); break;
            case 4: catatPembayaran(data, n); break;
            case 5: printf("Program selesai.\n"); break;
            default: printf("Menu tidak valid.\n");
        }
    } while (menu != 5);

    return 0;
}