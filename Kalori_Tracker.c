#include <stdio.h>
#include <string.h>

#define MAX_FOOD 20
#define MAX_LEN 50
#define LIMIT_KALORI 2200

struct Food {
    char nama[MAX_LEN];
    int kalori;
};

int main() {
    struct Food foods[MAX_FOOD];
    int n, i, total = 0;

    printf("Jumlah makanan/minuman hari ini: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_FOOD) {
        printf("Jumlah tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\nData ke-%d\n", i + 1);
        printf("Nama makanan/minuman: ");
        scanf(" %[^\n]", foods[i].nama);
        printf("Kalori: ");
        scanf("%d", &foods[i].kalori);
        total += foods[i].kalori;
    }

    printf("\n=== KALORI HARIAN TRACKER ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-20s %d kalori\n", i + 1, foods[i].nama, foods[i].kalori);
    }

    printf("Total kalori: %d\n", total);

    if (total > LIMIT_KALORI) {
        printf("Status      : Melebihi batas harian\n");
    } else {
        printf("Status      : Masih dalam batas aman\n");
    }

    return 0;
}