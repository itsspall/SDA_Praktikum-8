#include "fungsi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk menambah kota baru yang di input user
void tambahKota(Kota *A, int *n, char *kotaBaru) {
    // *n disini adalah pointer yang menunjuk ke jumlah kota saat ini
    // A adalah array dari struktur Kota
    // kotaBaru adalah nama kota baru yang ingin ditambahkan
    if (*n < MAKS_KOTA) { // Pemeriksaan apakah jumlah kota sudah mencapai maksimum
        A[*n].kt = (char *)malloc(strlen(kotaBaru) + 1); //menyimpan kotaBaru ke dalam array A element ke-n
        if (A[*n].kt != NULL ){ // Pemeriksaan apakan alokasi berhasil
            strcpy(A[*n].kt, kotaBaru); // Menyalin nama kota baru ke dalam elemen ke-n
            (*n)++; // Menambah jumlah kota
        } else {
            printf("Gagal alokasi memori untuk kota baru\n"); // Pesan kesalahan jika alokasi gagal
        }
    } else {
        printf("Jumlah kota sudah mencapai maksimum\n"); // Pesan kesalahan jika jumlah kota sudah maksimum
    }
}

void hapusKota(Kota *A, int *n, char *kotaHapus) {
    // A adalah array dari struct Kota
    // *n adalah pointer yang menunjuk ke jumlah kota saat ini
    // kotaHapus adalah nama kota yang ingin dihapus
    for (int i = 0; i < *n; i++) {
        if (strcmp(A[i].kt, kotaHapus) == 0) { // Mencari kota yang ingin dihapus 
            free(A[i].kt); // Menghapus alokasi memori untuk nama kota
            for (int j = i; j < *n - 1; j++) {
                A[j] = A[j + 1]; // Menggeser elemen setelahnya ke depan
            }
            (*n)--; // Mengurangi jumlah kota
            break;
        }
    }
}

void hapusSemuaKota(Kota *A, int n) {
    // A adalah array dari struct Kota
    // n adalah jumlah kota saat ini
    for (int i = 0; i < n; i++) {
        free(A[i].kt); // Menghapus alokasi memori untuk nama kota
        Node *current = A[i].p;
        while (current != NULL) { // Bebaskan semua node dalam linked list
            Node *temp = current;
            current = current->next;
            free(temp->nm);
            free(temp);
        }
    }
    printf("Semua kota berhasil dihapus.\n");
}

void tambahNama(Kota *A, int n, char *kotaBaru, char *namaBaru) {
    // A adalah array dari struct Kota
    // n adalah jumlah kota saat ini
    // kotaBaru adalah nama kota yang ingin ditambahkan nama baru
    // namaBaru adalah nama baru yang ingin ditambahkan ke kota tersebut
    for (int i = 0; i < n; i++) {
        if (strcmp(A[i].kt, kotaBaru) == 0) { // Mencari kota yang sesuai
            Node *newNode = (Node *)malloc(sizeof(Node)); // Alokasi memori untuk node baru
            if (newNode != NULL) {
                newNode->nm = (char *)malloc(strlen(namaBaru) + 1); // Alokasi memori untuk nama baru
                if (newNode->nm != NULL) {
                    strcpy(newNode->nm, namaBaru); // Menyalin nama baru ke dalam node
                    newNode->next = A[i].p; // Menyambungkan node baru ke linked list
                    A[i].p = newNode; // Menetapkan node baru sebagai head dari linked list
                } else {
                    printf("Gagal alokasi memori untuk nama baru\n"); // Pesan kesalahan jika alokasi gagal
                }
            } else {
                printf("Gagal alokasi memori untuk node baru\n"); // Pesan kesalahan jika alokasi gagal
            }
            break;
        }
    }
}

void hapusNama(Kota *A, int n, char *kotaHapus, char *namaHapus) {
    // A adalah array dari struct Kota
    // n adalah jumlah kota saat ini
    // kotaHapus adalah nama kota yang ingin dihapus nama baru
    // namaHapus adalah nama baru yang ingin dihapus dari kota tersebut
    for (int i = 0; i < n; i++) {
        if (strcmp(A[i].kt, kotaHapus) == 0) { // Mencari kota yang sesuai
            Node *current = A[i].p;
            Node *prev = NULL;
            while (current != NULL) {
                if (strcmp(current->nm, namaHapus) == 0) {
                    if (prev == NULL) {
                        A[i].p = current->next; // Menghapus node dari head linked list
                    } else {
                        prev->next = current->next; // Menghapus node dari linked list
                    }
                    free(current->nm); // Menghapus alokasi memori untuk nama baru
                    free(current); // Menghapus alokasi memori untuk node
                    printf("Nama '%s' berhasil dihapus dari kota '%s'.\n", namaHapus, kotaHapus);
                    return;
                }
                prev = current;
                current = current->next;
            }
            printf("Nama '%s' tidak ditemukan di kota '%s'.\n", namaHapus, kotaHapus);
            return;
        }
    }
    printf("Kota '%s' tidak ditemukan.\n", kotaHapus);
}

void hapusSemuaNama(Kota *A, int n, char *kotaHapus) {
    // A adalah array dari struct Kota
    // n adalah jumlah kota saat ini
    // kotaHapus adalah nama kota yang ingin dihapus semua nama baru
    for (int i = 0; i < n; i++) {
        if (strcmp(A[i].kt, kotaHapus) == 0) { // Mencari kota yang sesuai
            Node *current = A[i].p;
            while (current != NULL) {
                Node *temp = current;
                current = current->next; // Menghapus semua node dalam linked list
                free(temp->nm); // Menghapus alokasi memori untuk nama baru
                free(temp); // Menghapus alokasi memori untuk node
            }
            A[i].p = NULL; // Menetapkan head linked list menjadi NULL
            printf("Semua nama di kota '%s' berhasil dihapus.\n", kotaHapus);
            return;
        }
    }
    printf("Kota '%s' tidak ditemukan.\n", kotaHapus);
}

// Fungsi untuk tampilkan nama per kota
void tampilNamaPerKota(Kota *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("Kota: %s\n", A[i].kt);
        Node *current = A[i].p;
        while (current != NULL) {
            printf(" - Nama: %s\n", current->nm); // Menampilkan nama orang di kota tersebut
            current = current->next; // Melanjutkan ke node berikutnya
        }
    }
}

// Fungsi untuk menampilkan semua kota
void tampilSemuaKota(Kota *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("Kota: %s\n", A[i].kt);
    }
}

// Fungsi untuk mencari kota
void cariKota(Kota *A, int n, char *kotaBaru) {
    for (int i = 0; i < n; i++) {
        if (strcmp(A[i].kt, kotaBaru) == 0) {
            printf("Kota '%s' ditemukan.\n", kotaBaru);
            return;
        }
    }
    printf("Kota '%s' tidak ditemukan.\n", kotaBaru);
}