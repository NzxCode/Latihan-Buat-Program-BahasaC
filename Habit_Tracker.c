#include <stdio.h>
#include <string.h>

#define MAX_HABIT 10
#define MAX_LEN 50

struct Habit {
    char nama[MAX_LEN];
    int selesai;
};

void tampilMenu() {
    printf("\n=== HABIT TRACKER ===\n");
    printf("1. Tambah habit\n");
    printf("2. Tandai habit selesai\n");
    printf("3. Lihat semua habit\n");
    printf("4. Simpan ke file\n");
    printf("5. Keluar\n");
    printf("Pilih menu: ");
}

void tambahHabit(struct Habit habits[], int *jumlah) {
    if (*jumlah >= MAX_HABIT) {
        printf("Habit sudah penuh!\n");
        return;
    }

    printf("Masukkan nama habit: ");
    scanf(" %[^\n]", habits[*jumlah].nama);
    habits[*jumlah].selesai = 0;
    (*jumlah)++;

    printf("Habit berhasil ditambahkan.\n");
}

void tandaiSelesai(struct Habit habits[], int jumlah) {
    int i, pilih;

    if (jumlah == 0) {
        printf("Belum ada habit.\n");
        return;
    }

    printf("\nDaftar habit:\n");
    for (i = 0; i < jumlah; i++) {
        printf("%d. %s [%s]\n", i + 1, habits[i].nama,
               habits[i].selesai ? "Selesai" : "Belum");
    }

    printf("Pilih nomor habit yang selesai: ");
    scanf("%d", &pilih);

    if (pilih < 1 || pilih > jumlah) {
        printf("Pilihan tidak valid.\n");
        return;
    }

    habits[pilih - 1].selesai = 1;
    printf("Habit ditandai selesai.\n");
}

void lihatHabit(struct Habit habits[], int jumlah) {
    int i;

    if (jumlah == 0) {
        printf("Belum ada habit.\n");
        return;
    }

    printf("\n=== DAFTAR HABIT ===\n");
    for (i = 0; i < jumlah; i++) {
        printf("%d. %-20s [%s]\n", i + 1, habits[i].nama,
               habits[i].selesai ? "✓" : " ");
    }
}

void simpanKeFile(struct Habit habits[], int jumlah) {
    FILE *file = fopen("habit_tracker.txt", "w");
    int i;

    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (i = 0; i < jumlah; i++) {
        fprintf(file, "%s;%d\n", habits[i].nama, habits[i].selesai);
    }

    fclose(file);
    printf("Data berhasil disimpan ke habit_tracker.txt\n");
}

int main() {
    struct Habit habits[MAX_HABIT];
    int jumlah = 0;
    int pilihan;

    do {
        tampilMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahHabit(habits, &jumlah);
                break;
            case 2:
                tandaiSelesai(habits, jumlah);
                break;
            case 3:
                lihatHabit(habits, jumlah);
                break;
            case 4:
                simpanKeFile(habits, jumlah);
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Menu tidak valid.\n");
        }

    } while (pilihan != 5);

    return 0;
}