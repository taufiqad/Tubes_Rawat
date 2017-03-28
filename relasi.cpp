#include "relasi.h"
#include "parent.h"

/** NIM : 1301164426
    Nama : Taufiq Akmal Dawami **/

/** NIM : 1301164324
    Nama : Refin Heryanto **/

void createListRelasi(List_r &L)
{
    first(L)= NULL;
}

void dealokasiRelasi(address_r &P)
{
    delete P;
    P = NULL;
}

void insertFirstRelasi(List_r &L, address_r P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastRelasi(List_r &L, address_r P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
    }
    else
    {
        address_r Q = first(L);
        while(next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfterRelasi(List_r L, address_r Prec, address_r P)
{
    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteFirstRelasi(List_r &L, address_r &P)
{
    if(next(first(L)) == NULL)
    {
        P = first(L);
        first(L) = NULL;
        dealokasiRelasi(P);
    }
    else
    {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        dealokasiRelasi(P);
    }
}

void deleteLastRelasi(List_r &L, address_r &P)
{
    address_r Q;
    Q = first(L);
    while(next(next(Q)) != NULL)
    {
        Q = next(Q);
    }
    P = next(Q);
    next(Q) = NULL;
    dealokasiRelasi(P);
}

void deleteAfterRelasi(List_r L, address_r Prec, address_r &P)
{
    if(Prec == first(L))
    {
        deleteFirstRelasi(L, P);
    }
    else
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
        dealokasiRelasi(P);
    }
}

address_r connectRelasi(address_p P, address_c C)
{
    address_r Q = new elmList_r;
    parent(Q) = P;
    child(Q) = C;
    next(Q) = NULL;
    return Q;
}

address_r findElmRelasi(List_r L, address_p P, address_c C)
{
    address_r Q = first(L);
    while(Q != NULL)
    {
        if(parent(Q) == P && child(Q) == C)
        {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

address_r findRelasiP(List_r L, address_p P)
{
    address_r Q = first(L);
    while(Q != NULL)
    {
        if(parent(Q) == P)
        {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

address_r findRelasiC(List_r L, address_c C)
{
    address_r Q = first(L);
    while(Q != NULL)
    {
        if(child(Q) == C)
        {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void printInfoRelasi(List_r &L)
{
    if(first(L) == NULL)
    {
        cout << "List Kosong" << endl;
    }
    else
    {
        address_r P = first(L);
        cout << "Daftar Relasi" << endl;
        while(P != NULL)
        {
            cout << "(" << info(parent(P)).id_kamar << ")"
                 << info(parent(P)).tipe_kamar
                 << " -> "
                 << "(" << info(child(P)).id_pasien << ")"
                 << info(child(P)).nama_pasien << endl;
            P = next(P);
        }
    }
}

void disconnectRelasi(List_r &L, address_r P)
{
    address_r Q;
    if(P == first(L))
    {
        deleteFirstRelasi(L, P);
    }
    else if(next(P) == NULL)
    {
        deleteLastRelasi(L, P);
    }
    else
    {
        Q = first(L);
        while(next(Q) != P)
        {
            Q = next(Q);
        }
        deleteAfterRelasi(L, Q, P);
    }
}

void sortRelasi(List_r &L)
{
    List_r S;
    address_r P, Q, A;
    if(first(L) == NULL)
    {
        cout << "List kosong nich !" << endl;
    }
    else
    {
        createListRelasi(S);
        P = first(L);
        while(P != NULL)
        {
            A = next(P);
            if((first(S) == NULL) || (info(parent(first(S))).id_kamar > info(parent(P)).id_kamar))
            {
                next(P) = first(S);
                first(S) = P;
            }
            else
            {
                Q = first(S);
                while (next(Q) != NULL && info(parent(next(Q))).id_kamar < info(parent(P)).id_kamar)
                {
                    Q = next(Q);
                }
                next(P) = next(Q);
                next(Q) = P;
            }
            P = A;
        }
        L = S;
        cout << "List terurut berdasarkan ID !" << endl;
    }
}
void deleteRelasiByParent(List_r &L, address_p P){
    address_r A,B,T;
    if(first(L) == NULL)
    {
        cout<<"List Tidak Ada"<<endl;
    }
    else
    {
        A = findRelasiP(L,P);
    }
    if(A == NULL)
    {
        cout<<"ID tidak ditemukan"<<endl;
    }
    else
    {
        while(A != NULL)
        {
            if(A == first(L))
            {
                deleteFirstRelasi(L,T);
            }
            else if(next(A) == NULL && A != first(L))
            {
                deleteLastRelasi(L,T);
            }
            else
            {
                B = first(L);
                while(parent(next(B)) != P)
                {
                    B = next(B);
                }
            }
            deleteAfterRelasi(L,B,T);

        }
        A = findRelasiP(L,P);
    }
}
void deleteRelasiByChild(List_r &L, address_c C)
{
    address_r A,B,T;
    if(first(L) == NULL)
    {
        cout<<"List Tidak Ada"<<endl;
    }
    else
    {
        A = findRelasiC(L,C);
    }
    if(A == NULL)
    {
        cout<<"ID tidak ditemukan"<<endl;
    }
    else
    {
        while(A != NULL)
        {
            if(A == first(L))
            {
                deleteFirstRelasi(L,T);
            }
            else if(next(A) == NULL && A != first(L))
            {
                deleteLastRelasi(L,T);
            }
            else
            {
                B = first(L);
                while(child(next(B)) != C)
                {
                    B = next(B);
                }
            }
            deleteAfterRelasi(L,B,T);

        }
        A = findRelasiC(L,C);
    }
}

