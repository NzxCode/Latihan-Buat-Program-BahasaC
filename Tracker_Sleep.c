#include <stdio.h>

#define MAX_HARI 30

int cariTidurTerbaik(float tidur[], int n) {
    int i, idx = 0;
    for (i = 1; i < n; i++) {
        if (tidur[i] > tidur[idx]) {
            idx = i;
        }
    }
    return idx;
}

int main() {
    float tidur[MAX_HARI];
    int n, i, idx;
    float total = 0, rata;

    printf("=== QUALITY SLEEP TRACKER ===\n");
    printf("Masukkan jumlah hari: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_HARI) {
        printf("Jumlah hari tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Jam tidur hari ke-%d: ", i + 1);
        scanf("%f", &tidur[i]);

        if (tidur[i] < 0 || tidur[i] > 24) {
            printf("Jam tidur tidak valid.\n");
            return 0;
        }

        total += tidur[i];
    }

    rata = total / n;
    idx = cariTidurTerbaik(tidur, n);

    printf("\n=== LAPORAN TIDUR ===\n");
    for (i = 0; i < n; i++) {
        printf("Hari %d : %.1f jam\n", i + 1, tidur[i]);
    }

    printf("Rata-rata tidur : %.2f jam\n", rata);
    printf("Tidur terbaik   : Hari ke-%d (%.1f jam)\n", idx + 1, tidur[idx]);

    if (rata >= 7 && rata <= 9) {
        printf("Status          : Pola tidur sehat\n");
    } else if (rata < 7) {
        printf("Status          : Kurang tidur\n");
    } else {
        printf("Status          : Tidur terlalu lama\n");
    }

    return 0;
}