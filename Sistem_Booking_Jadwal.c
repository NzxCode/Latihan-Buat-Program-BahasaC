#include <stdio.h>
#include <string.h>

#define MAX 20

struct Booking {
    char nama[50];
    char jam[10];
};

int main() {
    struct Booking data[MAX];
    int n, i;

    printf("Jumlah booking: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nBooking ke-%d\n", i + 1);
        printf("Nama: ");
        scanf(" %[^\n]", data[i].nama);
        printf("Jam (contoh 14:00): ");
        scanf("%s", data[i].jam);
    }

    printf("\n=== JADWAL BOOKING ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i + 1, data[i].nama, data[i].jam);
    }

    return 0;
}