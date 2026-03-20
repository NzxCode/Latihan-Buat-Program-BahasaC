#include <stdio.h>

#define MAX_DATA 20
#define TARGET_ML 2000
#define PER_GELAS 250

int main() {
    int n, i;
    int gelas[MAX_DATA];
    int totalGelas = 0, totalML;

    printf("Berapa kali kamu minum hari ini? ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DATA) {
        printf("Jumlah data tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Jumlah gelas pada minum ke-%d: ", i + 1);
        scanf("%d", &gelas[i]);
        totalGelas += gelas[i];
    }

    totalML = totalGelas * PER_GELAS;

    printf("\n=== WATER INTAKE TRACKER ===\n");
    printf("Total gelas : %d\n", totalGelas);
    printf("Total ml    : %d ml\n", totalML);

    if (totalML >= TARGET_ML) {
        printf("Status      : Target air harian tercapai\n");
    } else {
        printf("Status      : Belum tercapai, kurang %d ml\n", TARGET_ML - totalML);
    }

    return 0;
}