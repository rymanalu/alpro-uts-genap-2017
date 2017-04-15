#include <stdio.h>
#include <string.h>

struct Rekaman {
    char npm[2];
    int kodeMk;
    char kelas[1];
} Mahasiswa;

int main() {
    FILE *fileB = fopen("file_b.txt", "r");
    FILE *fileC = fopen("file_c.txt", "w");

    Rekaman MahasiswaA = Mahasiswa;
    Rekaman MahasiswaB = Mahasiswa;
    char tempNpm[2];

    while (! feof(fileB)) {
        fscanf(fileB, "%s %i %s", MahasiswaB.npm, &MahasiswaB.kodeMk, MahasiswaB.kelas);

        if (strcmp(tempNpm, MahasiswaB.npm) != 0) {
            strcpy(tempNpm, MahasiswaB.npm);

            FILE *fileA = fopen("file_a.txt", "r");

            while (! feof(fileA)) {
                fscanf(fileA, "%s %i %s", MahasiswaA.npm, &MahasiswaA.kodeMk, MahasiswaA.kelas);

                if (strcmp(MahasiswaA.npm, MahasiswaB.npm) == 0) {
                    fprintf(fileC, "%s %i %s\n", MahasiswaA.npm, MahasiswaA.kodeMk, MahasiswaA.kelas);
                }
            }

            fclose(fileA);
        }

        fprintf(fileC, "%s %i %s\n", MahasiswaB.npm, MahasiswaB.kodeMk, MahasiswaB.kelas);
    }

    fclose(fileB);
    fclose(fileC);

    return 0;
}
