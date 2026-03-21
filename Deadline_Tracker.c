#include <stdio.h>
#include <string.h>

#define MAX_TASK 20
#define MAX_LEN 100

struct DeadlineTask {
    char nama[MAX_LEN];
    int sisaHari;
};

int cariDeadlineTerdekat(struct DeadlineTask tasks[], int n) {
    int i, idx = 0;
    for (i = 1; i < n; i++) {
        if (tasks[i].sisaHari < tasks[idx].sisaHari) {
            idx = i;
        }
    }
    return idx;
}

int main() {
    struct DeadlineTask tasks[MAX_TASK];
    int n, i, idx;

    printf("Jumlah tugas: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_TASK) {
        printf("Jumlah tugas tidak valid.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\nTugas ke-%d\n", i + 1);
        printf("Nama tugas: ");
        scanf(" %[^\n]", tasks[i].nama);
        printf("Sisa hari menuju deadline: ");
        scanf("%d", &tasks[i].sisaHari);
    }

    idx = cariDeadlineTerdekat(tasks, n);

    printf("\n=== DEADLINE TRACKER ===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-25s | %d hari\n", i + 1, tasks[i].nama, tasks[i].sisaHari);
    }

    printf("\nDeadline terdekat: %s (%d hari lagi)\n",
           tasks[idx].nama, tasks[idx].sisaHari);

    if (tasks[idx].sisaHari <= 2) {
        printf("Warning: Ada tugas yang sangat dekat deadline!\n");
    } else {
        printf("Status : Deadline masih cukup aman.\n");
    }

    return 0;
}