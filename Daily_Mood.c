#include <stdio.h>

#define MAX_DAY 30

int cariMoodTerbaik(int mood[], int n) {
    int i, idx = 0;
    for (i = 1; i < n; i++) {
        if (mood[i] > mood[idx]) {
            idx = i;
        }
    }
    return idx;
}

int main() {
    int mood[MAX_DAY];
    int n, i, total = 0, idx;
    float rata;

    printf("Berapa hari ingin dicatat? ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DAY) {
        printf("Jumlah hari tidak valid.\n");
        return 0;
    }

    printf("Gunakan skala mood 1 - 10\n");
    for (i = 0; i < n; i++) {
        printf("Mood hari ke-%d: ", i + 1);
        scanf("%d", &mood[i]);

        if (mood[i] < 1 || mood[i] > 10) {
            printf("Mood harus 1 sampai 10.\n");
            return 0;
        }

        total += mood[i];
    }

    rata = (float) total / n;
    idx = cariMoodTerbaik(mood, n);

    printf("\n=== DAILY MOOD LOGGER ===\n");
    for (i = 0; i < n; i++) {
        printf("Hari %d : %d\n", i + 1, mood[i]);
    }

    printf("Rata-rata mood : %.2f\n", rata);
    printf("Mood terbaik   : Hari ke-%d (%d)\n", idx + 1, mood[idx]);

    if (rata >= 8) {
        printf("Status         : Minggu yang sangat baik\n");
    } else if (rata >= 5) {
        printf("Status         : Mood cukup stabil\n");
    } else {
        printf("Status         : Perlu lebih banyak istirahat/self-care\n");
    }

    return 0;
}