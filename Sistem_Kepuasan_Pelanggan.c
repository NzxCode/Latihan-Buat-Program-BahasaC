#include <stdio.h>

#define MAX 50

int main() {
    int rating[MAX];
    int n, i, total = 0;
    float rata;

    printf("Jumlah pelanggan: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Rating pelanggan ke-%d (1-5): ", i + 1);
        scanf("%d", &rating[i]);

        if (rating[i] < 1 || rating[i] > 5) {
            printf("Rating tidak valid.\n");
            return 0;
        }

        total += rating[i];
    }

    rata = (float) total / n;

    printf("\nRata-rata rating: %.2f\n", rata);

    if (rata >= 4)
        printf("Status: Pelanggan sangat puas\n");
    else if (rata >= 3)
        printf("Status: Cukup puas\n");
    else
        printf("Status: Perlu perbaikan\n");

    return 0;
}