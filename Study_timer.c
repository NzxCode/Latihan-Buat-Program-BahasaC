#include <stdio.h>

#define MAX_SESSION 100

void tambahSesi(int sesi[], int *n) {
    if (*n >= MAX_SESSION) {
        printf("Session sudah penuh.\n");
        return;
    }

    printf("Masukkan durasi belajar (menit): ");
    scanf("%d", &sesi[*n]);

    if (sesi[*n] <= 0) {
        printf("Durasi tidak valid.\n");
        return;
    }

    (*n)++;
    printf("Session berhasil ditambahkan.\n");
}

int totalWaktu(int sesi[], int n) {
    int i, total = 0;
    for (i = 0; i < n; i++) {
        total += sesi[i];
    }
    return total;
}

float rataRata(int sesi[], int n) {
    if (n == 0) {
        return 0.0;
    }
    return (float) totalWaktu(sesi, n) / n;
}

void lihatLaporan(int sesi[], int n) {
    int i;

    if (n == 0) {
        printf("Belum ada session belajar.\n");
        return;
    }

    printf("\n=== LAPORAN BELAJAR ===\n");
    for (i = 0; i < n; i++) {
        printf("Session %d : %d menit\n", i + 1, sesi[i]);
    }

    printf("Total waktu : %d menit\n", totalWaktu(sesi, n));
    printf("Rata-rata   : %.2f menit\n", rataRata(sesi, n));
}

int main() {
    int sesi[MAX_SESSION];
    int n = 0;
    int pilihan;

    do {
        printf("\n=== STUDY TIMER TRACKER ===\n");
        printf("1. Tambah session belajar\n");
        printf("2. Lihat laporan belajar\n");
        printf("3. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahSesi(sesi, &n);
                break;
            case 2:
                lihatLaporan(sesi, n);
                break;
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Menu tidak valid.\n");
        }

    } while (pilihan != 3);

    return 0;
}