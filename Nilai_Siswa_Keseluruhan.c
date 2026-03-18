#include <stdio.h>

int cariMaks(int arr[], int n) {
    int i, maks = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

int hitungJumlah(int arr[], int n) {
    int i, total = 0;
    for (i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

float hitungRata(int arr[], int n) {
    int total = hitungJumlah(arr, n);
    return (float) total / n;
}

int main() {
    int n, i;
    int nilai[100];

    printf("Jumlah siswa: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Nilai siswa ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
    }

    printf("\nNilai maksimum = %d\n", cariMaks(nilai, n));
    printf("Jumlah nilai   = %d\n", hitungJumlah(nilai, n));
    printf("Rata-rata      = %.2f\n", hitungRata(nilai, n));

    return 0;
}