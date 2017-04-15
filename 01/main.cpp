#include <stdio.h>
#include <string.h>

struct Rekaman {
    char npm[2];
    int kodeMk;
    char nilai[1];
    int sks;
} Mahasiswa;

int main() {
    FILE *file = fopen("file.txt", "r");
    int jumlahNilaiA = 0;
    int jumlahNilaiB = 0;
    char tempNpm[2];

    while (! feof(file)) {
        fscanf(file, "%s %i %s %i", Mahasiswa.npm, &Mahasiswa.kodeMk, Mahasiswa.nilai, &Mahasiswa.sks);

        if (strcmp(tempNpm, Mahasiswa.npm) == 0) {
            continue;
        } else {
            strcpy(tempNpm, Mahasiswa.npm);
        }

        FILE *file2 = fopen("file.txt", "r");

        while (! feof(file2)) {
            fscanf(file2, "%s %i %s %i", Mahasiswa.npm, &Mahasiswa.kodeMk, Mahasiswa.nilai, &Mahasiswa.sks);

            if (strcmp(tempNpm, Mahasiswa.npm) == 0) {
                if (strcmp(Mahasiswa.nilai, "A") == 0) {
                    jumlahNilaiA++;
                } else if (strcmp(Mahasiswa.nilai, "B") == 0) {
                    jumlahNilaiB++;
                }
            }
        }

        printf("NPM %s: Jumlah nilai A = %i, Jumlah nilai B = %i\n", tempNpm, jumlahNilaiA, jumlahNilaiB);
        jumlahNilaiA = 0;
        jumlahNilaiB = 0;

        fclose(file2);
    }

    fclose(file);

    return 0;
}
