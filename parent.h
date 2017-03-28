#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

/** NIM : 1301164324
    Nama : Refin Heryanto **/

#include <iostream>
#include <string>
using namespace std;

#define nil NULL
#define next(P) P->next
#define first(L) (L).first
#define info(P) (P)->info

struct kamar{
    string id_kamar;
    string tipe_kamar;
    string lantai;
};

typedef kamar infotype_p;
typedef struct elmList_p *address_p;

struct elmList_p {
    infotype_p info;
    address_p next;
};

struct List_p{
    address_p first;
};

void createListParent(List_p &L);
address_p alokasiParent(infotype_p x);
void dealokasiParent(address_p &P);
void insertFirstParent(List_p &L, address_p P);
void insertLastParent(List_p &L, address_p P);
void insertAfterParent(List_p &L, address_p Prec, address_p P);
void insertAscendingP(List_p &L, address_p P);
address_p findElmParent(List_p L, infotype_p x);
void deleteFirstParent(List_p &L, address_p &P);
void deleteLastParent(List_p &L, address_p &P);
void deleteAfterParent(List_p &L, address_p Prec, address_p &P);
void deleteByidP(List_p &L, infotype_p x);
void printInfoParent(List_p L);
void printByidP(List_p L, address_p P);


#endif // CHILD_H_INCLUDED
