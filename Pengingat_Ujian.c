#include <stdio.h>
#include <string.h>

#define MAX_MAPEL 20
#define MAX_LEN 50

struct Belajar {
    char matkul[MAX_LEN];
    int jam;
};

int cariTargetTerbesar(struct Belajar data[], int n) {
    int i, idx = 0;
    for (i = 1; i < n; i++) {
        if (data[i].jam > data[idx].jam) {
            idx = i;
        }
    }
    return idx;
}

int main() {
    struct Belajar data[MAX_MAPEL];
    int n, i, total = 0, idx;

    printf("=== PLANNER BELAJAR UJIAN ===\n");
    printf("Masukkan jumlah mata kuliah: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_MAPEL) {
        printf("Jumlah tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\nData ke-%d\n", i + 1);
        printf("Nama mata kuliah: ");
        scanf(" %[^\n]", data[i].matkul);
        printf("Target jam belajar: ");
        scanf("%d", &data[i].jam);
        total += data[i].jam;
    }

    idx = cariTargetTerbesar(data, n);

    printf("\n=== RENCANA BELAJAR ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-20s %d jam\n", i + 1, data[i].matkul, data[i].jam);
    }

    printf("Total target belajar : %d jam\n", total);
    printf("Target terbesar      : %s (%d jam)\n", data[idx].matkul, data[idx].jam);

    return 0;
}