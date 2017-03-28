#include <iostream>
#include <stdlib.h>
#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;

void mainMenu();
void insertParent();
void insertChild();
void viewParent();
void viewChild();
void viewRelasi();
void findParent();
void findChild();
void connectRelasi();
void disconnectRelasi();
void deleteParent();
void deleteChild();
void searchRelasi();
void sortRelasi();
void thankYou();

List_p Lp;
List_c Lc;
List_r Lr;
address_p Pp = NULL;
address_p Prec_p = NULL;
address_c Pc = NULL;
address_c Prec_c = NULL;
address_r Pr = NULL;
infotype_p Xp;
infotype_c Xc;

int main()
{
    createListParent(Lp);
    createListChild(Lc);
    createListRelasi(Lr);
    mainMenu();
    return 0;
}

void mainMenu()
{
    int pil;
    do
    {
        system("cls");
        cout<<" Aplikasi Rawat Inap\n "<<endl;
        cout<<"----------------------"<<endl;
        cout<<"Pilihan Menu"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"1. Masukkan Data Kamar"<<endl;
        cout<<"2. Masukkan Data Pasien"<<endl;
        cout<<"3. Lihat Data Kamar"<<endl;
        cout<<"4. Lihat Data Pasien"<<endl;
        cout<<"5. Lihat Data Relasi"<<endl;
        cout<<"6. Mencari Data Kamar"<<endl;
        cout<<"7. Mencari Data Pasien"<<endl;
        cout<<"8. Menyambungkan Relasi"<<endl;
        cout<<"9. Memutuskan Relasi"<<endl;
        cout<<"10. Menghapus Data Kamar"<<endl;
        cout<<"11. Menghapus Data Pasien"<<endl;
        cout<<"12. Mencari Relasi"<<endl;
        cout<<"13. Mengurutkan Relasi"<<endl;
        cout<<"0. Keluar\n"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"Pilih Menu yang ingin anda gunakan: ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            system("cls");
            insertParent();
            system("pause");
            break;
        case 2:
            system("cls");
            insertChild();
            system("pause");
            break;
        case 3:
            system("cls");
            viewParent();
            system("pause");
            break;
        case 4:
            system("cls");
            viewChild();
            system("pause");
            break;
        case 5:
            system("cls");
            viewRelasi();
            system("pause");
            break;
        case 6:
            system("cls");
            findParent();
            system("pause");
            break;
        case 7:
            system("cls");
            findChild();
            system("pause");
            break;
        case 8:
            system("cls");
            connectRelasi();
            system("pause");
            break;
        case 9:
            system("cls");
            disconnectRelasi();
            system("pause");
            break;
        case 10:
            system("cls");
            deleteParent();
            system("pause");
            break;
        case 11:
            system("cls");
            deleteChild();
            system("pause");
            break;
        case 12:
            system("cls");
            searchRelasi();
            system("pause");
            break;
        case 13:
            system("cls");
            sortRelasi();
            system("pause");
            break;
        case 0:
            system("cls");
            thankYou();
            system("pause");
            break;
        }
    } while(pil!=0);
}

void thankYou() {
    cout<<"\n Matur Suwun\n"<<endl;
}

void insertParent()
{
    cout<<"Masukkan Data Kamar\n"<<endl;
    cout<<"ID Kamar : ";
    cin>>Xp.id_kamar;
    cout<<" Tipe kamar :";
    cin>>Xp.tipe_kamar;
    cout<<"Lantai :";
    cin>>Xp.lantai;
    Pp = alokasiParent(Xp);
    if(first(Lp) == NULL)
    {
        insertAscendingP(Lp, Pp);
        cout<<"Data ditambah"<<endl;
    }
    else
    {
        if (findElmParent(Lp, Xp) == NULL)
        {
            insertAscendingP(Lp, Pp);
            cout<<"Data ditambah"<<endl;
        }
        else
        {
            cout<<"\nID" <<Xp.id_kamar<<"Data tersebut sudah digunakan, gunakan ID lain !\n"<<endl;
        }
    }
}

void findParent()
{
    cout<<"Pencarian Data"<<endl;
    cout<<"ID Kamar : ";
    cin>>Xp.id_kamar;
    Pp = findElmParent(Lp, Xp);
    if (Pp == NULL)
    {
        cout<<"Data tidak ada"<<endl;
    }
    else
    {
        printByidP(Lp,Pp);
    }
}

void viewParent()
{
    printInfoParent(Lp);
}

void deleteParent()
{
    cout <<"Menghapus Data Kamar\n"<<endl;
    cout<<"Masukan id kamar :";
    cin>> Xp.id_kamar;
    deleteByidP(Lp,Xp);
}

void disconnectRelasi()
{
    cout<<"Masukkan ID Kamar"<<endl;
    cout<<"ID Kamar : ";
    cin>> Xp.id_kamar;
    Pp = findElmParent(Lp, Xp);
    cout<<"Masukkan ID Pasien"<<endl;
    cout<<"ID Pasien : ";
    cin>> Xc.id_pasien;
    Pc = findElmChild(Lc, Xc);
    if(Pp == NULL || Pc == NULL)
    {
        cout<<"Data Tidak Ada"<<endl;
    }
    else
    {
        Pr = findElmRelasi(Lr, Pp, Pc);
        disconnectRelasi(Lr, Pr);
    }

}

void searchRelasi()
{
    cout<< "Masukkan ID Kamar" << endl;
    cout<< "ID Kamar: ";
    cin>>Xp.id_kamar;
    Pp = findElmParent(Lp, Xp);
    cout<< "Masukkan ID Pasien" << endl;
    cout<<"ID Pasien : ";
    cin>>Xc.id_pasien;
    Pc = findElmChild(Lc, Xc);
    if(Pp == NULL || Pc == NULL)
    {
        cout<<"Data Tidak Ada"<< endl;
    }
    else
    {
        Pr = findElmRelasi(Lr, Pp, Pc);
        if(Pr != NULL)
        {
            cout << "Relasi Ditemukan" << endl;
        }
        else
        {
            cout << "Relasi Tidak Ditemukan" << endl;
        }
    }
}

void sortRelasi()
{
    sortRelasi(Lr);
}

void insertChild()
{
    cout<<"Masukkan Data Pasien : "<< endl;
    cout<<"ID Pasien : ";
    cin>> Xc.id_pasien;
    cout<<"Nama pasien : ";
    cin>> Xc.nama_pasien;
    cout<<"Alamat Pasien : ";
    cin>>Xc.alamat_pasien;
    cout<<"Jenis Kelamin Pasien : ";
    cin>>Xc.jeniskelamin_pasien;
    cout<<"No Telp Pasien : ";
    cin>>Xc.notelp_pasien;
    cout<<"Tempat Lahir Pasien: ";
    cin>>Xc.tempat_lahir;
    cout<<"Tanggal Lahir Pasien: ";
    cin >> Xc.tanggal_lahir;
    Pc = alokasiChild(Xc);
    if(first(Lc) == NULL)
    {
        insertAscendingC(Lc, Pc);
    }
    else
    {
        if(findElmChild(Lc, Xc) == NULL)
        {
            insertAscendingC(Lc, Pc);
        }
        else
        {
            cout << "\nID " << Xc.id_pasien << " Sudah Dipakai, Gunakan ID Lain\n" << endl;
        }
    }
}

void findChild()
{
    cout<<"Pencarian Data Pasien" << endl;
    cout<<"ID Pasien : ";
    cin>>Xc.id_pasien;
    Pc = findElmChild(Lc, Xc);
    if(Pc == NULL)
    {
        cout<<"Data Tidak Ada"<<endl;
    }
    else
    {
        printByidC(Lc, Pc);
    }
}

void viewChild()
{
    printInfoChild(Lc);
}

void deleteChild()
{
    cout<<"Menghapus Data Pasien\n" << endl;
    cout<<"Masukkan ID Pasien : ";
    cin>>Xc.id_pasien;
    deleteByidC(Lc,Xc);
}

void connectRelasi()
{
    cout<<"Masukkan ID Kamar" << endl;
    cout<<"ID Kamar : ";
    cin>> Xp.id_kamar;
    Pp = findElmParent(Lp, Xp);
    cout<<"Masukkan ID pasien"<< endl;
    cout << "ID pasien : ";
    cin >> Xc.id_pasien;
    Pc = findElmChild(Lc, Xc);
    if(Pp == NULL || Pc == NULL)
    {
        cout << "Data Tidak Ada" << endl;
    }
    else
    {
        Pr = findElmRelasi(Lr, Pp, Pc);
        if(Pr == NULL)
        {
            insertLastRelasi(Lr, connectRelasi(Pp, Pc));
        }
        else
        {
            cout << "Relasi tersebut sudah tersedia!" << endl;
        }
    }
}

void viewRelasi()
{
    printInfoRelasi(Lr);
}
