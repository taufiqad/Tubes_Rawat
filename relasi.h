#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "parent.h"
#include "child.h"

using namespace std;

#define first(L) L.first
#define parent(P) P->parent
#define child(P) P->child
#define next(P) P->next

typedef struct elmList_r *address_r;

struct elmList_r
{
    address_p parent;
    address_c child;
    address_r next;
};

struct List_r
{
    address_r first;
};

void createListRelasi(List_r &L);
void dealokasiRelasi(address_r &P);
void insertFirstRelasi(List_r &L, address_r P);
void insertLastRelasi(List_r &L, address_r P);
void insertAfterRelasi(List_r L, address_r Prec, address_r P);
void deleteFirstRelasi(List_r &L, address_r &P);
void deleteLastRelasi(List_r &L, address_r &P);
void deleteAfterRelasi(List_r L, address_r Prec, address_r &P);
address_r connectRelasi(address_p P, address_c C);
address_r findElmRelasi(List_r L, address_p P, address_c C);
address_r findRelasiP(List_r L, address_p P);
address_r findRelasiC(List_r L, address_c C);
void printInfoRelasi(List_r &L);
void disconnectRelasi(List_r &L, address_r P);
void sortRelasi(List_r &L);
void deleteRelasiByParent(List_r &L, address_p P);
void deleteRelasiByChild(List_r &L, address_c C);



#endif // RELASI_H_INCLUDED
