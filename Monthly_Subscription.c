#include <stdio.h>
#include <string.h>

#define MAX_SUB 20
#define MAX_LEN 50

struct Subscription {
    char nama[MAX_LEN];
    int biayaBulanan;
};

int main() {
    struct Subscription subs[MAX_SUB];
    int n, i;
    int totalBulanan = 0, totalTahunan;

    printf("Jumlah subscription: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SUB) {
        printf("Jumlah tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\nSubscription ke-%d\n", i + 1);
        printf("Nama layanan: ");
        scanf(" %[^\n]", subs[i].nama);
        printf("Biaya per bulan: ");
        scanf("%d", &subs[i].biayaBulanan);
        totalBulanan += subs[i].biayaBulanan;
    }

    totalTahunan = totalBulanan * 12;

    printf("\n=== SUBSCRIPTION TRACKER ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-20s Rp%d/bulan\n", i + 1, subs[i].nama, subs[i].biayaBulanan);
    }

    printf("Total bulanan : Rp%d\n", totalBulanan);
    printf("Total tahunan : Rp%d\n", totalTahunan);

    return 0;
}