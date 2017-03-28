#include "parent.h"

/** NIM : 1301164324
    Nama :  Refin Heryanto **/

void createListParent(List_p &L)
{
    first(L) = NULL;
}

address_p alokasiParent(infotype_p x)
{
    address_p P;
    P = new elmList_p;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiParent(address_p &P)
{
    delete P;
    P = NULL;
}

void insertFirstParent(List_p &L, address_p P)
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

void insertLastParent(List_p &L, address_p P)
{
    address_p Q;
    if (first(L) == NULL)
    {
        first(L) = P;
    }
    else
    {
        Q = first(L);
        while(next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfterParent(List_p &L, address_p Prec, address_p P)
{
    if (next(Prec) == NULL)
    {
        insertLastParent(L,P);
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertAscendingP(List_p &L, address_p P)
{
    address_p Q;
    if ((first(L) == NULL) || ((info(first(L)).id_kamar) > (info(P).id_kamar)))
    {
        insertFirstParent(L,P);
    }
    else
    {
        Q = first(L);
        while(next(Q) != NULL && info(next(Q)).id_kamar < info(P).id_kamar)
        {
            Q = next(Q);
        }
        if(next(Q) == NULL)
        {
            insertLastParent(L,P);
        }
        else
        {
            insertAfterParent(L,Q,P);
        }
    }

}
address_p findElmParent(List_p L, infotype_p x)
{
    address_p P = first(L);
    do
    {
        if(info(P).id_kamar == x.id_kamar)
        {
            return P;
        }
        P = next(P);
    }
    while(P != NULL);
    return NULL;
}

void deleteFirstParent(List_p &L, address_p &P)
{
    P = first(L);
    if (first(L) == NULL || next(P) == NULL)
    {
        first(L) = NULL;
    }
    else
    {
        first(L) = next(first(L));
        next(P) = NULL;
    }
}

void deleteLastParent(List_p &L, address_p &P)
{
    address_p Q;
    P = first(L);
    if (first(L) == NULL)
    {
        first(L) == NULL;
    }
    else
    {
        Q = first(L);
        while (next(next(Q)) != NULL)
        {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}

void deleteAfterParent(List_p &L, address_p Prec, address_p &P)
{
    P = first(L);
    if(next(Prec) == NULL)
    {
        next(Prec) = NULL;
    }
    else
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

void deleteByidP(List_p &L, infotype_p x)
{
    address_p P,Q;
    if(first(L) == NULL)
    {
        cout<<"List tidak ada" <<endl;
    }
    else
    {
        P = findElmParent(L, x);
        if (P == NULL)
        {
            cout<<"ID Tidak Ada" <<endl;
        }
        else if (P == first(L))
        {
            deleteFirstParent(L,P);
        }
        else if (next(P) == NULL && P != first(L))
        {
            deleteLastParent(L,P);
        }
        else
        {
            Q = first(L);
            while(next(Q) != P)
            {
                Q = next(Q);
            }
            deleteAfterParent(L, Q, P);
        }
        cout<<"Data Telah Dihapus"<<endl;

    }
}

void printInfoParent(List_p L)
{
    if (first(L) == NULL)
    {
        cout<<"List tidak ada"<<endl;
    }
    else
    {
        address_p P = first(L);
        cout<<"Daftar Kamar\n"<<endl;
        while (P != NULL)
        {
            cout<<"ID Kamar : "<<info(P).id_kamar<<endl;
            cout<<"Tipe Kamar : "<<info(P).tipe_kamar<<endl;
            cout<<"Lantai : "<<info(P).lantai<<endl;
            cout<<endl;
            P = next(P);
        }
    }
}

void printByidP(List_p L, address_p P)
{
    cout<<"Data Kamar\n"<<endl;
    cout<<"ID Kamar : "<<info(P).id_kamar<<endl;
    cout<<"Tipe Kamar: "<<info(P).tipe_kamar<<endl;
    cout<<"Lantai : "<<info(P).lantai<<endl;
}
