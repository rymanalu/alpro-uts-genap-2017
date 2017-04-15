#include <stdio.h>

struct Rekaman {
    char kode[2];
    int stok;
    char nama[100];
} Barang;

int main() {
    FILE *barang = fopen("barang.txt", "r");
    FILE *stokLebih = fopen("barang_stok_lebih.txt", "w");
    FILE *stokKurang = fopen("barang_stok_kurang.txt", "w");

    while (! feof(barang)) {
        fscanf(barang, "%s %s %i\n", Barang.kode, Barang.nama, &Barang.stok);

        if (Barang.stok < 10) {
            fprintf(stokKurang, "%s %s %i\n", Barang.kode, Barang.nama, Barang.stok);
        } else {
            fprintf(stokLebih, "%s %s %i\n", Barang.kode, Barang.nama, Barang.stok);
        }
    }

    fclose(barang);
    fclose(stokLebih);
    fclose(stokKurang);

    stokLebih = fopen("barang_stok_lebih.txt", "r");
    printf("Barang Stok > 10\n");
    printf("|   Kode   |   Nama   |   Stok   |\n");
    while (! feof(stokLebih)) {
        fscanf(barang, "%s %s %i\n", Barang.kode, Barang.nama, &Barang.stok);

        printf("     %s       %s       %i\n", Barang.kode, Barang.nama, Barang.stok);
    }
    fclose(stokLebih);

    stokKurang = fopen("barang_stok_kurang.txt", "r");
    printf("Barang Stok < 10\n");
    printf("|   Kode   |   Nama   |   Stok   |\n");
    while (! feof(stokKurang)) {
        fscanf(barang, "%s %s %i\n", Barang.kode, Barang.nama, &Barang.stok);

        printf("     %s       %s       %i\n", Barang.kode, Barang.nama, Barang.stok);
    }
    fclose(stokKurang);

    return 0;
}
