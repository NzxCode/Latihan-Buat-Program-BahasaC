#include <stdio.h>

#define MAX 100

int main() {
    int data[MAX];
    int n, i;
    int total = 0, max;
    float rata;

    printf("Jumlah data penjualan: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Data ke-%d: ", i+1);
        scanf("%d", &data[i]);
        total += data[i];
    }

    max = data[0];
    for (i = 1; i < n; i++) {
        if (data[i] > max)
            max = data[i];
    }

    rata = (float) total / n;

    printf("\n=== DASHBOARD ===\n");
    printf("Total     : %d\n", total);
    printf("Rata-rata : %.2f\n", rata);
    printf("Tertinggi : %d\n", max);

    return 0;
}