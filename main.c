#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"

int main() {
    Kota A[MAKS_KOTA]; // Array untuk menyimpan data kota
    int n = 0;        // Jumlah kota saat ini
    int pilihan;
    char kotaBaru[50], namaBaru[50], kotaHapus[50], namaHapus[50];

    do {
        printf("\n=== MENU ===\n");
        printf("1. Tambah Kota\n");
        printf("2. Hapus Kota\n");
        printf("3. Tambah Nama ke Kota\n");
        printf("4. Hapus Nama dari Kota\n");
        printf("5. Tampilkan Nama per Kota\n");
        printf("6. Tampilkan Semua Kota\n");
        printf("7. Cari Kota\n");
        printf("8. Hapus Semua Kota\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar(); // Membersihkan buffer input

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota baru: ");
                fgets(kotaBaru, sizeof(kotaBaru), stdin);
                kotaBaru[strcspn(kotaBaru, "\n")] = '\0';
                tambahKota(A, &n, kotaBaru);
                break;

            case 2:
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(kotaHapus, sizeof(kotaHapus), stdin);
                kotaHapus[strcspn(kotaHapus, "\n")] = '\0';
                hapusKota(A, &n, kotaHapus);
                break;

            case 3:
                printf("Masukkan nama kota: ");
                fgets(kotaBaru, sizeof(kotaBaru), stdin);
                kotaBaru[strcspn(kotaBaru, "\n")] = '\0';
                printf("Masukkan nama baru: ");
                fgets(namaBaru, sizeof(namaBaru), stdin);
                namaBaru[strcspn(namaBaru, "\n")] = '\0';
                tambahNama(A, n, kotaBaru, namaBaru);
                break;

            case 4:
                printf("Masukkan nama kota: ");
                fgets(kotaHapus, sizeof(kotaHapus), stdin);
                kotaHapus[strcspn(kotaHapus, "\n")] = '\0';
                printf("Masukkan nama yang ingin dihapus: ");
                fgets(namaHapus, sizeof(namaHapus), stdin);
                namaHapus[strcspn(namaHapus, "\n")] = '\0';
                hapusNama(A, n, kotaHapus, namaHapus);
                break;

            case 5:
                tampilNamaPerKota(A, n);
                break;

            case 6:
                tampilSemuaKota(A, n);
                break;

            case 7:
                printf("Masukkan nama kota yang ingin dicari: ");
                fgets(kotaBaru, sizeof(kotaBaru), stdin);
                kotaBaru[strcspn(kotaBaru, "\n")] = '\0';
                cariKota(A, n, kotaBaru);
                break;

            case 8:
                hapusSemuaKota(A, n);
                n = 0; // Reset jumlah kota
                break;

            case 0:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 0);

    return 0;
}