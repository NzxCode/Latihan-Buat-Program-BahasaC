#include <stdio.h>

void tampilRekomendasi(int mood, int energi, int waktu) {
    printf("\n=== REKOMENDASI KEGIATAN ===\n");

    if (mood == 1) {
        if (energi == 1) {
            printf("- Istirahat 20 menit\n");
            printf("- Minum air putih\n");
            printf("- Dengarkan musik santai\n");
        } else {
            printf("- Jalan santai\n");
            printf("- Bereskan meja belajar\n");
            printf("- Nonton video singkat\n");
        }
    } else if (mood == 2) {
        if (waktu <= 30) {
            printf("- Baca 5 halaman buku\n");
            printf("- Review catatan\n");
            printf("- Rapikan to-do list\n");
        } else {
            printf("- Belajar materi baru\n");
            printf("- Kerjakan latihan coding\n");
            printf("- Lanjutkan tugas kuliah\n");
        }
    } else if (mood == 3) {
        if (energi == 3) {
            printf("- Kerjakan soal competitive programming\n");
            printf("- Belajar algoritma baru\n");
            printf("- Buat mini project C\n");
        } else {
            printf("- Kerjakan tugas ringan\n");
            printf("- Review hasil belajar hari ini\n");
            printf("- Latihan soal dasar\n");
        }
    } else {
        printf("Input mood tidak valid.\n");
    }
}

int main() {
    int mood, energi, waktu;

    printf("=== SISTEM REKOMENDASI KEGIATAN ===\n");
    printf("Mood kamu?\n");
    printf("1. Capek\n");
    printf("2. Biasa\n");
    printf("3. Semangat\n");
    printf("Pilih: ");
    scanf("%d", &mood);

    printf("\nEnergi kamu?\n");
    printf("1. Rendah\n");
    printf("2. Sedang\n");
    printf("3. Tinggi\n");
    printf("Pilih: ");
    scanf("%d", &energi);

    printf("\nBerapa menit waktu luang kamu? ");
    scanf("%d", &waktu);

    tampilRekomendasi(mood, energi, waktu);

    return 0;
}