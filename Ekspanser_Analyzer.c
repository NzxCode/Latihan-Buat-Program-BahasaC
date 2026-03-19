#include <stdio.h>
#include <string.h>

#define MAX_DATA 20
#define MAX_LEN 50

struct Expense {
    char kategori[MAX_LEN];
    int jumlah;
};

void inputData(struct Expense data[], int *n) {
    int i;
    printf("Masukkan jumlah data pengeluaran: ");
    scanf("%d", n);

    for (i = 0; i < *n; i++) {
        printf("\nData ke-%d\n", i + 1);
        printf("Kategori: ");
        scanf(" %[^\n]", data[i].kategori);
        printf("Jumlah pengeluaran: ");
        scanf("%d", &data[i].jumlah);
    }
}

int hitungTotal(struct Expense data[], int n) {
    int i, total = 0;
    for (i = 0; i < n; i++) {
        total += data[i].jumlah;
    }
    return total;
}

int cariTerbesar(struct Expense data[], int n) {
    int i, idx = 0;
    for (i = 1; i < n; i++) {
        if (data[i].jumlah > data[idx].jumlah) {
            idx = i;
        }
    }
    return idx;
}

void tampilLaporan(struct Expense data[], int n, int budget) {
    int total = hitungTotal(data, n);
    int idxTerbesar = cariTerbesar(data, n);

    printf("\n=== LAPORAN PENGELUARAN ===\n");
    printf("Total pengeluaran : Rp%d\n", total);
    printf("Pengeluaran terbesar: %s (Rp%d)\n",
           data[idxTerbesar].kategori, data[idxTerbesar].jumlah);

    if (total > budget) {
        printf("Status budget     : MELEBIHI budget\n");
    } else {
        printf("Status budget     : Masih aman\n");
    }
}

int main() {
    struct Expense data[MAX_DATA];
    int n, budget;

    inputData(data, &n);

    printf("\nMasukkan budget kamu: ");
    scanf("%d", &budget);

    tampilLaporan(data, n, budget);

    return 0;
}