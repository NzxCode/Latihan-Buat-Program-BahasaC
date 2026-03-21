#include <stdio.h>

int hitungBiaya(int jenis, float berat) {
    int hargaPerKg;
    int total;

    if (jenis == 1) {
        hargaPerKg = 7000;   // cuci biasa
    } else if (jenis == 2) {
        hargaPerKg = 10000;  // cuci setrika
    } else {
        hargaPerKg = 15000;  // express
    }

    total = (int)(hargaPerKg * berat);

    if (berat >= 5) {
        total = total - (total * 10 / 100);
    }

    return total;
}

int main() {
    int jenis;
    float berat;
    int total;

    printf("=== LAUNDRY BUDGET ESTIMATOR ===\n");
    printf("Jenis laundry:\n");
    printf("1. Cuci biasa\n");
    printf("2. Cuci + setrika\n");
    printf("3. Express\n");
    printf("Pilih jenis: ");
    scanf("%d", &jenis);

    printf("Masukkan berat pakaian (kg): ");
    scanf("%f", &berat);

    if (berat <= 0) {
        printf("Berat tidak valid.\n");
        return 0;
    }

    total = hitungBiaya(jenis, berat);

    printf("\nEstimasi total biaya laundry: Rp%d\n", total);

    if (berat >= 5) {
        printf("Kamu mendapat diskon 10%% karena berat >= 5 kg.\n");
    }

    return 0;
}