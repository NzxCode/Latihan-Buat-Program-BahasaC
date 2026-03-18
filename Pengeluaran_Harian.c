#include <stdio.h>

int totalPengeluaran(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    return arr[n - 1] + totalPengeluaran(arr, n - 1);
}

int pengeluaranTerbesar(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }

    int maksSebelumnya = pengeluaranTerbesar(arr, n - 1);

    if (arr[n - 1] > maksSebelumnya) {
        return arr[n - 1];
    } else {
        return maksSebelumnya;
    }
}

float rataRataPengeluaran(int arr[], int n) {
    int total = totalPengeluaran(arr, n);
    return (float) total / n;
}

int main() {
    int n, i;
    int pengeluaran[100];

    printf("Masukkan jumlah hari: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Pengeluaran hari ke-%d: ", i + 1);
        scanf("%d", &pengeluaran[i]);
    }

    printf("\n===== LAPORAN PENGELUARAN =====\n");
    printf("Total pengeluaran     = Rp%d\n", totalPengeluaran(pengeluaran, n));
    printf("Pengeluaran terbesar  = Rp%d\n", pengeluaranTerbesar(pengeluaran, n));
    printf("Rata-rata pengeluaran = Rp%.2f\n", rataRataPengeluaran(pengeluaran, n));

    return 0;
}