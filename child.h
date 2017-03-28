#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

/** NIM : 1301164426
    Nama : Taufiq Akmal Dawami **/

#include <iostream>
#include <string>
using namespace std;

#define nil NULL
#define first(L)(L).first
#define last(L) (L).last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

struct pasien{
    string id_pasien;
    string nama_pasien;
    string alamat_pasien;
    string jeniskelamin_pasien;
    string notelp_pasien;
    string tempat_lahir;
    string tanggal_lahir;
};

typedef pasien infotype_c;
typedef struct elmList_c *address_c;

struct elmList_c {
    infotype_c info;
    address_c next;
    address_c prev;
};

struct List_c{
    address_c first;
    address_c last;
};

void createListChild(List_c &L);
address_c alokasiChild(infotype_c x);
void dealokasiChild(address_c &P);
void insertFirstChild(List_c &L, address_c P);
void insertLastChild(List_c &L, address_c P);
void insertAfterChild(List_c &L, address_c Prec, address_c P);
void insertAscendingC(List_c &L, address_c P);
address_c findElmChild(List_c L, infotype_c x);
void deleteFirstChild(List_c &L, address_c &P);
void deleteLastChild(List_c &L, address_c &P);
void deleteAfterChild(List_c &L, address_c Prec, address_c &P);
void deleteByidC(List_c &L, infotype_c x);
void printInfoChild(List_c L);
void printByidC(List_c L, address_c P);

#endif // CHILD_H_INCLUDED
