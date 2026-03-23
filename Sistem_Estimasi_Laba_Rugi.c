#include <stdio.h>

struct Keuangan {
    int pendapatan;
    int bahanBaku;
    int operasional;
    int transport;
    int lainLain;
    int totalBiaya;
    int labaBersih;
};

int hitungTotalBiaya(struct Keuangan k) {
    return k.bahanBaku + k.operasional + k.transport + k.lainLain;
}

int hitungLabaBersih(struct Keuangan k) {
    return k.pendapatan - k.totalBiaya;
}

int main() {
    struct Keuangan k;
    float margin;

    printf("=== ESTIMASI LABA RUGI UMKM ===\n");

    printf("Masukkan total pendapatan: ");
    scanf("%d", &k.pendapatan);

    printf("Biaya bahan baku: ");
    scanf("%d", &k.bahanBaku);

    printf("Biaya operasional: ");
    scanf("%d", &k.operasional);

    printf("Biaya transport: ");
    scanf("%d", &k.transport);

    printf("Biaya lain-lain: ");
    scanf("%d", &k.lainLain);

    k.totalBiaya = hitungTotalBiaya(k);
    k.labaBersih = hitungLabaBersih(k);

    if (k.pendapatan > 0) {
        margin = ((float) k.labaBersih / k.pendapatan) * 100;
    } else {
        margin = 0;
    }

    printf("\n=== LAPORAN KEUANGAN ===\n");
    printf("Pendapatan     : Rp%d\n", k.pendapatan);
    printf("Total biaya    : Rp%d\n", k.totalBiaya);
    printf("Laba/Rugi      : Rp%d\n", k.labaBersih);
    printf("Margin usaha   : %.2f%%\n", margin);

    if (k.labaBersih > 0) {
        printf("Status         : UNTUNG\n");
    } else if (k.labaBersih < 0) {
        printf("Status         : RUGI\n");
    } else {
        printf("Status         : IMPAS\n");
    }

    return 0;
}