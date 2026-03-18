#include <stdio.h>

int hitungBiayaKendaraan(int jenis, int jam) {
    int tarifDasar = 5000;
    int biaya;

    if (jenis == 1) {          // mobil
        biaya = tarifDasar * jam;
    } else if (jenis == 2) {   // motor
        biaya = (tarifDasar / 2) * jam;
    } else {                   // truk
        biaya = (tarifDasar * 2) * jam;
    }

    if (jam > 5) {
        biaya = biaya - (biaya * 10 / 100);
    }

    return biaya;
}

int hitungTotalBiaya(int biaya[], int n) {
    int i, total = 0;
    for (i = 0; i < n; i++) {
        total += biaya[i];
    }
    return total;
}

int main() {
    char nama[100];
    int n, i;
    int jenis[3], jam[3], biaya[3];

    printf("Nama pelanggan: ");
    scanf(" %[^\n]", nama);

    printf("Jumlah kendaraan (maks 3): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nKendaraan ke-%d\n", i + 1);
        printf("Jenis (1=Mobil, 2=Motor, 3=Truk): ");
        scanf("%d", &jenis[i]);
        printf("Lama parkir (jam): ");
        scanf("%d", &jam[i]);

        biaya[i] = hitungBiayaKendaraan(jenis[i], jam[i]);
    }

    printf("\n===== STRUK PEMBAYARAN =====\n");
    printf("Nama: %s\n", nama);

    for (i = 0; i < n; i++) {
        printf("Kendaraan %d -> Jenis: %d, Jam: %d, Biaya: Rp%d\n",
               i + 1, jenis[i], jam[i], biaya[i]);
    }

    printf("Total bayar: Rp%d\n", hitungTotalBiaya(biaya, n));

    return 0;
}