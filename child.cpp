#include "child.h"

/** NIM : 1301164426
    Nama : Taufiq Akmal Dawami **/

void createListChild(List_c &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_c alokasiChild(infotype_c x)
{
    address_c P = new elmList_c;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void dealokasiChild(address_c &P)
{
    delete P;
    P = NULL;
}

void insertFirstChild(List_c &L, address_c P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLastChild(List_c &L, address_c P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }

}

void insertAfterChild(List_c &L, address_c Prec, address_c P)
{
    if(next(Prec) == NULL)
    {
        insertLastChild(L,P);
    }
    else
    {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

void insertAscendingC(List_c &L, address_c P)
{
    address_c Q;
    if ((first(L) == NULL) || (info(first(L)).id_pasien) > (info(P).id_pasien))
    {
        insertFirstChild(L,P);
    }
    else
    {
        Q = first(L);
        while((next(Q) != NULL) && (info(next(Q)).id_pasien < info(P).id_pasien))
        {
            Q = next(Q);
        }
        if(next(Q) == NULL)
        {
            insertLastChild(L,P);
        }
        else
        {
            insertAfterChild(L,Q,P);
        }
    }
}

address_c findElmChild(List_c L, infotype_c x) {
	address_c P = first(L);
	do
	{
		if(info(P).id_pasien == x.id_pasien)
        {
			return P;
		}
		P = next(P);
	}
	while(P != NULL);
	return NULL;
}


void deleteFirstChild(List_c &L, address_c &P)
{
    P = first(L);
    if (((first(L) == NULL) || (next(first(L)) == NULL)))
    {
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}
void deleteLastChild(List_c &L, address_c &P)
{
    P = last(L);
    if (first(L) == NULL)
    {
        first(L) = NULL;
    }
    else
    {
        last(L) = prev(last(L));
        prev(P) = NULL;
        next(last(L)) = NULL;
    }
}
void printInfoChild(List_c L)
{
    address_c P;
    P = first(L);
    if (first(L) == NULL)
    {
        cout<<"List tidak ada"<<endl;
    }
    else
    {
        while ((P) != NULL)
        {
            cout<<endl;
            cout<<endl;
            cout<<"ID :"<<info(P).id_pasien<<endl;
            cout<<"Nama : "<<info(P).nama_pasien<<endl;
            cout<<"Alamat: "<<info(P).alamat_pasien<<endl;
            cout<<"Jenis Kelamin: "<<info(P).jeniskelamin_pasien<<endl;
            cout<<"Nomor Telpon: "<<info(P).notelp_pasien<<endl;
            cout<<"Tempat Tanggal Lahir: "<<info(P).tempat_lahir<<", "<<info(P).tanggal_lahir<<endl;
            P = next(P);
        }
    }
}

void printByidC(List_c L, address_c P)
{
    cout<<"Data Pasien\n"<<endl;
    cout<<"ID :"<<info(P).id_pasien<<endl;
    cout<<"Nama : "<<info(P).nama_pasien<<endl;
    cout<<"Alamat: "<<info(P).alamat_pasien<<endl;
    cout<<"Jenis Kelamin: "<<info(P).jeniskelamin_pasien<<endl;
    cout<<"Nomor Telpon: "<<info(P).notelp_pasien<<endl;
    cout<<"Tempat Tanggal Lahir: "<<info(P).tempat_lahir<<", "<<info(P).tanggal_lahir<<endl;
}

void deleteAfterChild(List_c &L, address_c Prec, address_c &P)
{
    P = Prec;
    Prec = prev(P);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}

void deleteByidC(List_c &L, infotype_c x)
{
    address_c P,Q;
    if(first(L) == NULL)
    {
        cout<<"List tidak ada"<<endl;
    }
    else
    {
        P = findElmChild(L,x);
        if(P == NULL)
        {
            cout<<"ID yang anda maksud tidak ditemukan"<<endl;
        }
        else if (P == first(L))
        {
            deleteFirstChild(L,P);
        }
        else if (P == last(L))
        {
            deleteLastChild(L,P);
        }
        else
        {
            Q = first(L);
            while(next(Q) != P)
            {
                Q = next(Q);
            }
            deleteAfterChild(L,Q,P);
        }
        cout<<"Data telah dihapus"<<endl;
    }
}
