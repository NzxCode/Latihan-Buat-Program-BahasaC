#include <stdio.h>
#include <string.h>

#define MAX_MK 20
#define MAX_LEN 50

struct MataKuliah {
    char nama[MAX_LEN];
    int sks;
    float bobot;
};

int main() {
    struct MataKuliah mk[MAX_MK];
    int n, i, totalSks = 0;
    float totalMutu = 0, ip;

    printf("=== MINI GPA CALCULATOR ===\n");
    printf("Masukkan jumlah mata kuliah: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_MK) {
        printf("Jumlah mata kuliah tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\nMata kuliah ke-%d\n", i + 1);
        printf("Nama mata kuliah: ");
        scanf(" %[^\n]", mk[i].nama);
        printf("Jumlah SKS: ");
        scanf("%d", &mk[i].sks);
        printf("Bobot nilai (contoh A=4.0, B=3.0): ");
        scanf("%f", &mk[i].bobot);

        totalSks += mk[i].sks;
        totalMutu += mk[i].sks * mk[i].bobot;
    }

    ip = totalMutu / totalSks;

    printf("\n=== HASIL IP ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-20s SKS: %d | Bobot: %.2f\n",
               i + 1, mk[i].nama, mk[i].sks, mk[i].bobot);
    }

    printf("Total SKS : %d\n", totalSks);
    printf("IP        : %.2f\n", ip);

    if (ip >= 3.5) {
        printf("Predikat  : Sangat Baik\n");
    } else if (ip >= 3.0) {
        printf("Predikat  : Baik\n");
    } else if (ip >= 2.5) {
        printf("Predikat  : Cukup\n");
    } else {
        printf("Predikat  : Perlu peningkatan\n");
    }

    return 0;
}