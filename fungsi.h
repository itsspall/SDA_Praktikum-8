#ifndef FUNGSI_H
#define FUNGSI_H

#define MAKS_KOTA 10

// Deklarasi pointer untuk linked list
typedef struct tNode *address;

// Struct untuk node nama orang
typedef struct tNode {
    char *nm;         // nama orang (alokasi dinamis)
    address next;     // pointer ke node berikutnya
} Node;

// Struct untuk data kota
typedef struct {
    char *kt;         // nama kota (alokasi dinamis)
    address p;        // pointer ke linked list orang
} Kota;

//ini adalah deklarasi fungsi yang ada di fungsi.c
void tambahKota(Kota *A, int *n, char *kotaBaru);
void hapusKota(Kota *A, int *n, char *kotaHapus);
void hapusSemuaKota(Kota *A, int n);
void tambahNama(Kota *A, int n, char *kotaBaru, char *namaBaru);
void hapusNama(Kota *A, int n, char *kotaHapus, char *namaHapus);
void hapusSemuaNama(Kota *A, int n, char *kotaHapus);
void tampilNamaPerKota(Kota *A, int n);
void tampilSemuaKota(Kota *A, int n);
void cariKota(Kota *A, int n, char *kotaBaru);

#endif