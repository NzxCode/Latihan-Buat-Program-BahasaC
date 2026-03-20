#include <stdio.h>
#include <string.h>

#define MAX_APP 20
#define MAX_LEN 50

struct Activity {
    char nama[MAX_LEN];
    int durasi;
};

int cariTerlama(struct Activity data[], int n) {
    int i, idx = 0;
    for (i = 1; i < n; i++) {
        if (data[i].durasi > data[idx].durasi) {
            idx = i;
        }
    }
    return idx;
}

int main() {
    struct Activity data[MAX_APP];
    int n, i, total = 0, idx;

    printf("Jumlah aktivitas/aplikasi: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_APP) {
        printf("Jumlah tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\nData ke-%d\n", i + 1);
        printf("Nama aktivitas/aplikasi: ");
        scanf(" %[^\n]", data[i].nama);
        printf("Durasi (menit): ");
        scanf("%d", &data[i].durasi);
        total += data[i].durasi;
    }

    idx = cariTerlama(data, n);

    printf("\n=== SCREEN TIME ANALYZER ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-20s %d menit\n", i + 1, data[i].nama, data[i].durasi);
    }

    printf("Total screen time : %d menit\n", total);
    printf("Aktivitas terlama : %s (%d menit)\n", data[idx].nama, data[idx].durasi);

    if (total > 480) {
        printf("Warning           : Screen time terlalu tinggi\n");
    } else {
        printf("Status            : Screen time masih aman\n");
    }

    return 0;
}