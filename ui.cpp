#include <iostream>
#include "ui.h"
#include "conio.h"
#include "windows.h"

using namespace std;

List_parent L;
int pass_id = 000;


void mainmenu()
{
    int x;
    createList_parent(L);

    while (x != 8)
    {
        cout <<" ======================================="<<endl
             <<"|               STASIUN X               |"<<endl
             <<" ======================================="<<endl
             <<endl
             <<" 1. Insert Data"<<endl
             <<" 2. Search and View"<<endl
             <<" 3. Search and Delete"<<endl
             <<" 4. View All"<<endl
             <<" 5. Reporting"<<endl
             <<" 6. Search and Edit"<<endl
             <<" 7. Sorting Kereta"<<endl
             <<" 8. Exit"<<endl
             <<endl
             <<" Pilih menu : ";
        cin >> x;
        cout <<endl;

        if (x == 1)
        {
            menuinsert();
            system("cls");
        }
        else if (x == 2)
        {
            searchview();
            system("cls");

        }
        else if (x == 3)
        {
            searchdelete();
            system("cls");
        }
        else if (x == 4)
        {
            viewall();
            getch();
            system("cls");
        }
        else if (x == 5)
        {
            reporting();
            system("cls");
        }
        else if (x == 6)
        {
            searchandedit();
            system("cls");
        }
        else if (x == 7)
        {
            sorting_kereta();
            system("cls");
        }
    }

    cout <<endl;
    cout <<"TERIMA KASIH, TELAH MENGGUNAKAN APLIKASI KAMI"<<endl
         <<"ANJAR AFRIZAL - REGITA ANJANI"<<endl;
}

void menuinsert()
{
    int x;
    while (x != 4)
    {
        system("cls");
        cout <<" ======================================="<<endl
             <<"|               STASIUN X               |"<<endl
             <<" ======================================="<<endl
             <<endl
             <<" Menu Insert Data"<<endl
             <<" 1. Kereta"<<endl
             <<" 2. Gerbong"<<endl
             <<" 3. Penumpang"<<endl
             <<" 4. Back"<<endl
             <<endl
             <<" Pilih menu : ";
        cin >> x;
        cout <<endl;

        if (x == 1)
        {
            tambahkereta();
        }
        else if (x == 2)
        {
            tambahgerbong();
        }
        else if (x == 3)
        {
            input_penumpang();
        }
    }
}

void tambahkereta()
{
    adr_parent P,Q;
    infotype_parent x;

    cout <<"ID KERETA                 : ";
    cin >> x.ID_kereta;
    cout <<"NAMA KERETA               : ";
    cin >> x.nama_kereta;
    cout <<"ASAL                      : ";
    cin >> x.asal;
    cout <<"TUJUAN                    : ";
    cin >> x.tujuan;
    cout <<"TANGGAL KEBERANGKATAN     : ";
    cin >> x.tanggal;
    cout <<"WAKTU KEBERANGKATAN       : ";
    cin >> x.waktu;

    Q = alokasi_parent(x);

    if (first(L) == nil)
    {
        insertFirstParent(L,Q);
    }
    else
    {
        P = first(L);
        while (P != nil && x.ID_kereta != infoP(P).ID_kereta )
        {
            if (x.ID_kereta < infoP(P).ID_kereta && nextP(P) == nil)
            {
                insertFirstParent(L,Q);
                P = last(L);
            }
            else if (x.ID_kereta > infoP(P).ID_kereta && nextP(P) == nil)
            {
                insertLastParent(L,Q);
                P = last(L);
            }
            else if (x.ID_kereta > infoP(P).ID_kereta && x.ID_kereta < infoP(nextP(P)).ID_kereta)
            {
                insertAfterParent(P,Q);
                P = last(L);
            }
            P = nextP(P);
        }
    }
    getch();
    system("cls");
}

void tambahgerbong()
{
    adr_child P,R;
    adr_parent Q;
    infotype_child x;
    infotype_parent y;

    cout <<"NOMOR GERBONG             : ";
    cin >> x.no_gerbong;
    cout <<"KATEGORI                  : ";
    cin >> x.kategori;

    x.kapasitas = 10;
    x.jumlah_penumpang = 0;

    for (int i=0; i<x.kapasitas; i++)
    {
        x.data_penumpang[i].id_penumpang = -1 ;
        x.data_penumpang[i].nama_penumpang = "" ;
        x.data_penumpang[i].alamat = "" ;
        x.data_penumpang[i].tujuan = "" ;
        x.data_penumpang[i].kategori = "" ;
        x.data_penumpang[i].nomor_kursi = i+1 ;
    }

    for (int i=0; i<x.kapasitas; i++)
    {
        x.nomor_kursi[i] = false;
    }

    P = alokasi_child(x);

    cout <<"PASANGAN KERETA (ID_kereta) : ";
    cin >> y.ID_kereta;
    Q = find_kereta(L,y);

    if (Q != nil)
    {
        infoC(P).ID_kereta = infoP(Q).ID_kereta;
        infoC(P).nama_kereta = infoP(Q).nama_kereta;

        if (child(Q) == nil)
        {
            insertFirstChild(Q,P);
        }
        else
        {
            R = child(Q);
            while (R != nil && infoC(R).no_gerbong != infoC(P).no_gerbong)
            {
                if (infoC(P).no_gerbong < infoC(R).no_gerbong && nextC(R) == nil)
                {
                    insertFirstChild(Q,P);
                }
                else if (infoC(P).no_gerbong > infoC(R).no_gerbong && nextC(R) == nil)
                {
                    insertLastChild(Q,P);
                }
                else if (infoC(P).no_gerbong > infoC(R).no_gerbong  && infoC(P).no_gerbong < infoC(nextC(R)).no_gerbong)
                {
                    insertAfterChild(R,P);
                }
                R = nextC(R);

            }
        }
    }
    else
    {
        cout <<"Kereta tidak ditemukan"<<endl;
    }

    getch();
    system("cls");
}
void input_penumpang()
{
    int j = 0;
    infotype_parent x;
    infotype_child y;
    adr_parent P;
    adr_child Q;
    penumpang passenger;

    if (first(L) != nil)
    {

        cout <<"Masukan Biodata Penumpang"<<endl;
        cout <<endl;
        pass_id = pass_id+001;
        passenger.id_penumpang = pass_id;
        cout <<"Nama Lengkap    : ";
        cin>>passenger.nama_penumpang;
        cout <<"Alamat          : ";
        cin>>passenger.alamat;
        cout <<endl;
        cout <<endl;

        printInfo(L);

        cout <<endl;
        cout <<"Masukan Tujuan Anda : ";
        cin >> passenger.tujuan;

        x.tujuan = passenger.tujuan;

        P = find_kereta_penumpang(L,x);
        if (P != nil)
        {
            cout <<"Masukan Jenis Gerbong : ";
            cin >>passenger.kategori;
            y.kategori = passenger.kategori;

            Q = find_gerbong_penumpang(P,y);

            if (Q != nil)
            {
                y.no_gerbong = infoC(Q).no_gerbong;

                cek_kursi(Q);

                cout <<endl;
                cout <<"Silahkan pilih kursi    : ";
                cin >> passenger.nomor_kursi;

                infoC(Q).data_penumpang[passenger.nomor_kursi-1] = passenger;
                infoC(Q).nomor_kursi[passenger.nomor_kursi-1] = true;

                for (int i=0; i<infoC(Q).kapasitas; i++)
                {
                    if (infoC(Q).nomor_kursi[i] == true)
                    {
                        j = j+1;
                        infoC(Q).jumlah_penumpang = j;
                    }
                }

                cout <<endl;
                cout <<"Input Penumpang Berhasil"<<endl;

            }
            else
            {
                cout <<"Gerbong tidak ditemukan"<<endl;
            }
        }
        else
        {
            cout <<"Kereta tidak ditemukan"<<endl;
        }
    }
    else
    {
        cout <<"Daftar kereta masih kosong"<<endl;
        cout <<"Tunggu hingga daftar kereta terisi"<<endl;
    }
    getch();
    system("cls");
}

void cek_kursi(adr_child P)
{
    int kursi = 0;

    for (int i=0; i<infoC(P).kapasitas; i++)
    {
        if (infoC(P).nomor_kursi[i] == false)
        {
            kursi++;
        }
    }

    if (kursi == 0)
    {
        cout <<"Kursi Penuh, Coba Gerbong Lain"<<endl;
    }
    else
    {
        cout <<"Daftar Kursi yang tersedia"<<endl;
        cout <<endl;
        for (int i=0; i<infoC(P).kapasitas; i++)
        {
            if (infoC(P).nomor_kursi[i] == false)
            {
                cout<<infoC(P).data_penumpang[i].nomor_kursi<<" | ";
            }
        }
    }
}

void searchview()
{
    int x;
    while (x != 4)
    {
        system("cls");
        cout <<" ======================================="<<endl
             <<"|               STASIUN X               |"<<endl
             <<" ======================================="<<endl
             <<endl
             <<" Menu Search & View"<<endl
             <<" 1. Kereta"<<endl
             <<" 2. Gerbong"<<endl
             <<" 3. Penumpang"<<endl
             <<" 4. Back"<<endl
             <<endl
             <<" Pilih menu : ";
        cin >> x;
        cout <<endl;

        if (x == 1)
        {
            view_kereta();
        }
        else if (x == 2)
        {
            view_gerbong();
        }
        else if (x == 3)
        {
            view_penumpang();
            system("cls");
        }
    }
}

void view_kereta()
{
    infotype_parent x;
    adr_parent P;

    cout <<"Masukan ID Kereta   : ";
    cin >> x.ID_kereta;
    cout <<endl;

    P = find_kereta(L,x);

    if (P != nil)
    {
        cout <<"ID Kereta               : "<<infoP(P).ID_kereta<<endl;
        cout <<"Nama Kereta             : "<<infoP(P).nama_kereta<<endl;
        cout <<"Asal                    : "<<infoP(P).asal<<endl;
        cout <<"Tujuan                  : "<<infoP(P).tujuan<<endl;
        cout <<"Tanggal Keberangkatan   : "<<infoP(P).tanggal<<endl;
        cout <<"Waktu Keberangkatan     : "<<infoP(P).waktu<<endl;
    }
    else
    {
        cout <<"Kereta Tidak Ditemukan"<<endl;
    }
    getch();
}

void view_gerbong()
{
    int j = 0;
    infotype_child x;
    infotype_parent y;
    adr_child P;
    adr_parent Q;

    cout <<"Masukan ID Kereta   : ";
    cin >> y.ID_kereta;

    Q = find_kereta(L,y);

    if (Q != nil)
    {
        cout <<"Masukan Nomor Gerbong   : ";
        cin >> x.no_gerbong;
        cout <<endl;

        P = find_gerbong(Q,x);

        if (P != nil)
        {
            for (int i=0; i<infoC(P).kapasitas; i++)
            {
                if (infoC(P).nomor_kursi[i] == true)
                {
                    j = j+1;
                    infoC(P).jumlah_penumpang = j;
                }
            }

            cout <<"No Gerbong              : "<<infoC(P).no_gerbong<<endl;
            cout <<"Kategori                : "<<infoC(P).kategori<<endl;
            cout <<"Kapasitas               : "<<infoC(P).kapasitas<<endl;
            cout <<"Jumlah Penumpang        : "<<infoC(P).jumlah_penumpang<<endl;
            cout <<"ID kereta               : "<<infoC(P).ID_kereta<<endl;
            cout <<"Nama Kereta             : "<<infoC(P).nama_kereta<<endl;
        }
        else
        {
            cout <<"Gerbong Tidak Ditemukan"<<endl;
        }
    }
    else
    {
        cout <<"Kereta tidak ditemukan"<<endl;
    }
    getch();
}

void view_penumpang()
{
    penumpang x,y;
    cout <<"Masukan ID Penumpang    : ";
    cin >>x.id_penumpang;
    y = search_penumpang(x);

    if (y.id_penumpang != -1)
    {
        cout <<"Data Penumpang ditemukan"<<endl;
        cout <<endl;
        cout <<"ID_Penumpang     : "<<y.id_penumpang<<endl;
        cout <<"Nama_Penumpang   : "<<y.nama_penumpang<<endl;
        cout <<"Alamat           : "<<y.alamat<<endl;
        cout <<"Nomor Kursi      : "<<y.nomor_kursi<<endl;
        cout <<"Kategori gerbong : "<<y.kategori<<endl;
        cout <<"Tujuan           : "<<y.tujuan<<endl;

    }
    else
    {
        cout <<"Data Penumpang tidak ada"<<endl;
    }
    getch();
}

penumpang search_penumpang(penumpang x)
{
    penumpang y;
    adr_child Q;
    adr_parent P;
    int i;

    bool stat = false;


    if (first(L) != nil)
    {
        P = first(L);
        if (nextP(P) == nil)
        {
            if (child(P) != nil)
            {
                stat = false;
                Q = child(P);
                do
                {
                    i = 0;
                    while (infoC(Q).data_penumpang[i].id_penumpang != x.id_penumpang && i<infoC(Q).kapasitas)
                    {
                        i = i+1;
                    }
                    if (infoC(Q).data_penumpang[i].id_penumpang == x.id_penumpang)
                    {
                        return infoC(Q).data_penumpang[i];
                        stat = true;
                    }
                    else
                    {
                        y.id_penumpang = -1;
                    }

                    Q = nextC(Q);
                }
                while (nextC(Q) != nil && stat != true);
            }
        }
        else
        {

            do
            {
                if (child(P) != nil)
                {
                    stat = false;
                    Q = child(P);
                    do
                    {
                        i = 0;
                        while (infoC(Q).data_penumpang[i].id_penumpang != x.id_penumpang && i<infoC(Q).kapasitas)
                        {
                            i = i+1;
                        }
                        if (infoC(Q).data_penumpang[i].id_penumpang == x.id_penumpang)
                        {
                            return infoC(Q).data_penumpang[i];
                            stat = true;
                        }
                        else
                        {
                            y.id_penumpang = -1;
                        }

                        Q = nextC(Q);
                    }
                    while (Q != nil && stat != true);

                }
                P = nextP(P);
            }
            while (P != nil && stat != true);
        }
    }
    else
    {
        y.id_penumpang = -1;
    }

    return y;
}

void searchdelete()
{

    int x;
    while (x != 4)
    {
        system("cls");
        cout <<" ======================================="<<endl
             <<"|               STASIUN X               |"<<endl
             <<" ======================================="<<endl
             <<endl
             <<" Menu Search & Delete"<<endl
             <<" 1. Kereta"<<endl
             <<" 2. Gerbong"<<endl
             <<" 3. Penumpang"<<endl
             <<" 4. Back"<<endl
             <<endl
             <<" Pilih menu : ";
        cin >> x;
        cout <<endl;

        if (x == 1)
        {
            delete_kereta();
        }
        else if (x == 2)
        {
            delete_gerbong();
        }
        else if (x == 3)
        {
            delete_penumpang();
        }
    }


}

void delete_kereta()
{
    infotype_parent x;
    adr_parent P,Q = nil;

    cout <<"Masukan ID Kereta       : ";
    cin >> x.ID_kereta;

    P = find_kereta(L,x);

    if (P != nil)
    {
        if (child(P) == nil)
        {
            if (P == first(L))
            {
                deleteFirstParent(L,P);
            }
            else if (P == last(L))
            {
                deleteLastParent(L,Q);
            }
            else if (nextP(P) != nil)
            {
                deleteAfterParent(L,prevP(P),Q);
            }

        }
        else
        {
            cout <<"Kereta masih memliki gerbong"<<endl;
            cout <<"Lepas semua gerbong terlebih dahulu"<<endl;
        }
    }
    else
    {
        cout <<"Kereta Tidak Ditemukan"<<endl;
    }

    getch();
}


void delete_gerbong()
{
    infotype_child x;
    infotype_parent y;
    adr_child P,R;
    adr_parent Q;

    cout <<"Masukan ID Kereta   : ";
    cin >> y.ID_kereta;

    Q = find_kereta(L,y);


    if (Q != nil)
    {
        if (child(Q) != nil)
        {
            cout <<"Masukan ID Gerbong  : ";
            cin >> x.no_gerbong;

            P = find_gerbong(Q,x);

            if (P != nil)
            {
                cout <<"Gerbong ditemukan"<<endl;

                if (P == child(Q))
                {
                    deleteFirstChild(Q,P);
                }
                else if (P != child(Q) && nextC(P) != nil)
                {
                    deleteAfterChild(Q,R,P);
                }
                else if (P != child(Q) && nextC(P) == nil)
                {
                    deleteLastChild(Q,P);
                }
            }
            else
            {
                cout <<"Gerbong tidak ditemukan"<<endl;
            }
        }
        else
        {
            cout <<"Kereta tidak memiliki Gerbong"<<endl;
        }

    }
    else
    {
        cout <<"Kereta tidak ditemukan"<<endl;
    }
    getch();
}

void delete_penumpang()
{
    penumpang x;
    adr_child Q;
    adr_parent P;
    int i;

    cout <<"Masukan ID Penumpang yang akan dihapus :";
    cin >> x.id_penumpang;

    bool stat = false;


    if (first(L) != nil)
    {
        P = first(L);
        if (nextP(P) == nil)
        {
            if (child(P) != nil)
            {
                stat = false;
                Q = child(P);
                do
                {
                    i = 0;
                    while (infoC(Q).data_penumpang[i].id_penumpang != x.id_penumpang && i<infoC(Q).kapasitas)
                    {
                        i = i+1;
                    }
                    if (infoC(Q).data_penumpang[i].id_penumpang == x.id_penumpang)
                    {
                        infoC(Q).data_penumpang[i].id_penumpang = -1;
                        infoC(Q).data_penumpang[i].nama_penumpang ="0";
                        infoC(Q).data_penumpang[i].alamat ="0";
                        infoC(Q).data_penumpang[i].tujuan ="0";
                        infoC(Q).data_penumpang[i].kategori ="0";
                        infoC(Q).data_penumpang[i].no_gerbong = -1;
                        infoC(Q).data_penumpang[i].nomor_kursi =i+1;
                        infoC(Q).nomor_kursi[i] = false;



                        stat = true;
                    }
                    else
                    {
                        stat = false;
                    }

                    Q = nextC(Q);
                }
                while (Q != nil && stat != true);
            }
        }
        else
        {

            do
            {
                if (child(P) != nil)
                {
                    stat = false;
                    Q = child(P);
                    do
                    {
                        i = 0;
                        while (infoC(Q).data_penumpang[i].id_penumpang != x.id_penumpang && i<infoC(Q).kapasitas)
                        {
                            i = i+1;
                        }
                        if (infoC(Q).data_penumpang[i].id_penumpang == x.id_penumpang)
                        {
                            infoC(Q).data_penumpang[i].id_penumpang = -1;
                            infoC(Q).data_penumpang[i].nama_penumpang ="0";
                            infoC(Q).data_penumpang[i].alamat ="0";
                            infoC(Q).data_penumpang[i].tujuan ="0";
                            infoC(Q).data_penumpang[i].kategori ="0";
                            infoC(Q).data_penumpang[i].no_gerbong = -1;
                            infoC(Q).data_penumpang[i].nomor_kursi =i+1;
                            infoC(Q).nomor_kursi[i] = false;



                            stat = true;
                        }
                        else
                        {
                            stat = false;
                        }

                        Q = nextC(Q);
                    }
                    while (Q != nil && stat != true);

                }
                P = nextP(P);
            }
            while (P != nil && stat != true);
        }
    }
    else
    {
        stat = false;
    }


    if (stat == true)
    {
        cout <<"Data Penumpang Berhasil Di Hapus"<<endl;
    }
    else
    {
        cout <<"Data Penumpang tidak ditemukan"<<endl;
    }

    getch();
}


void viewall()
{
    printInfoAll(L);
};
void reporting()
{
    {
        int x;
        while (x != 4)
        {
            system("cls");
            cout <<" ======================================="<<endl
                 <<"|               STASIUN X               |"<<endl
                 <<" ======================================="<<endl
                 <<endl
                 <<" Menu Search & Delete"<<endl
                 <<" 1. Menampilkan Jumlah Kereta"<<endl
                 <<" 2. Menampilkan Jumlah Gerbong"<<endl
                 <<" 3. Menampilkan prosentase penumpang tiap kereta"<<endl
                 <<" 4. Back"<<endl
                 <<endl
                 <<" Pilih menu : ";
            cin >> x;
            cout <<endl;

            if (x == 1)
            {
                jumlah_kereta();
            }
            else if (x == 2)
            {
                jumlah_gerbong();
            }
            else if (x == 3)
            {
                prosen_penumpang();
            }
        }

    }

}

void jumlah_kereta()
{
    adr_parent P;
    int x = 0;

    if (first(L) != nil)
    {
        P = first(L);
        do
        {
            x = x+1;
            P = nextP(P);
        }
        while (P != nil);

        cout <<" Jumlah kereta di stasiun adalah "<<x<<" Unit"<<endl;
    }
    else
    {

        cout <<" Jumlah kereta di stasiun adalah "<<x<<" Unit"<<endl;
    }
    getch();
}


void jumlah_gerbong()
{
    adr_parent P;
    adr_child Q;
    int x = 0;
    int y = 0;
    if (first(L) != nil)
    {
        P = first(L);
        do
        {
            x = 0;
            if (child(P) != nil)
            {
                x = 0;
                Q = child(P);
                do
                {
                    x = x+1;
                    Q = nextC(Q);
                }
                while (Q != nil);

                cout <<" Jumlah gerbong di kereta "<<infoP(P).nama_kereta<<" adalah "<<x<<" Unit"<<endl;
            }
            y = y+x;
            P = nextP(P);

        }
        while (P != nil);

        cout <<" Jumlah seluruh gerbong di stasiun adalah "<<y<<" Unit"<<endl;
    }
    else
    {

        cout <<" Jumlah seluruh gerbong di stasiun adalah "<<x<<" Unit"<<endl;
    }
    getch();
}

void prosen_penumpang()
{
    adr_parent P;
    adr_child Q;
    double passen = 0;
    double tampung = 0;
    double z = 0;

    if (first(L) != nil)
    {
        P = first(L);
        do
        {
            if (child(P) != nil)
            {
                Q = child(P);
                do
                {
                    passen = passen + infoC(Q).jumlah_penumpang;
                    tampung = tampung + infoC(Q).kapasitas;
                    Q = nextC(Q);

                }
                while (Q != nil);
            }
            P = nextP(P);

        }
        while (P != nil);

        z = (passen/tampung)*100;

        cout <<" Prosentase Jumlah seluruh Penumpang adalah "<<z<<" %"<<endl;
    }
    else
    {
        cout <<" Prosentase Jumlah seluruh Penumpang adalah "<<z<<" %"<<endl;
    }
    getch();
}



void searchandedit()
{
    int x;
    while (x != 3)
    {
        system("cls");
        cout <<" ======================================="<<endl
             <<"|               STASIUN X               |"<<endl
             <<" ======================================="<<endl
             <<endl
             <<" Menu Search & Edit"<<endl
             <<" 1. Kereta"<<endl
             <<" 2. Gerbong"<<endl
             <<" 3. Back"<<endl
             <<endl
             <<" Pilih menu : ";
        cin >> x;
        cout <<endl;

        if (x == 1)
        {
            editkereta();
        }
        else if (x == 2)
        {
            editgerbong();
        }
    }

}

void editkereta()
{
    infotype_parent x;
    adr_parent P;

    cout <<"Masukan ID Kereta untuk merubah data    : ";
    cin >> x.ID_kereta;

    P = find_kereta(L,x);

    if (P != nil)
    {
        cout <<"Kereta di temukan"<<endl;
        cout <<endl;
        cout <<"Isi dengan data baru"<<endl;
        cout <<endl;
        cout <<"Nama Kereta             : ";
        cin  >> infoP(P).nama_kereta;
        cout <<"Asal                    : ";
        cin  >> infoP(P).asal;
        cout <<"Tujuan                  : ";
        cin  >> infoP(P).tujuan;
        cout <<"Tanggal Keberangkatan   : ";
        cin  >> infoP(P).tanggal;
        cout <<"Waktu Keberangkatan     : ";
        cin  >> infoP(P).waktu;
        cout <<endl;
        cout <<"Data berhasil diperbaharui"<<endl;

    }
    else
    {
        cout <<"kereta tidak ditemukan"<<endl;
    }
    getch();
}


void editgerbong()
{
    infotype_parent x;
    infotype_child y;
    adr_parent P;
    adr_child Q;

    cout <<"Masukan ID Kereta untuk mencari gerbong    : ";
    cin >> x.ID_kereta;

    P = find_kereta(L,x);

    if (P!= nil)
    {
        cout <<"Kereta ditemukan"<<endl;
        cout <<endl;
        cout <<"Masukan ID gerbong untuk merubah data : ";
        cin  >> y.no_gerbong;

        Q = find_gerbong(P,y);

        if (Q != nil)
        {
            cout <<"Gerbong Ditemukan"<<endl;
            cout <<endl;
            cout <<"Isi dengan data baru"<<endl;
            cout <<endl;
            cout <<"Kategori                : ";
            cin  >> infoC(Q).kategori;
            cout <<endl;
            cout <<"Data berhasil diperbaharui"<<endl;

        }
        else
        {
            cout <<"Gerbong tidak ditemukan"<<endl;
        }
    }
    else
    {
        cout <<"Kereta tidak ditemukan"<<endl;
    }
    getch();
}

void sorting_kereta()
{
    int x;
    while (x != 3)
    {
        system("cls");
        cout <<" ======================================="<<endl
             <<"|               STASIUN X               |"<<endl
             <<" ======================================="<<endl
             <<endl
             <<" Menu Sorting Kereta"<<endl
             <<" 1. berdasarkan ID"<<endl
             <<" 2. berdasarkan Nama Kereta"<<endl
             <<" 3. Back"<<endl
             <<endl
             <<" Pilih menu : ";
        cin >> x;
        cout <<endl;

        if (x == 1)
        {
            L = sort_by_id(L);
            if (first(L) != nil)
            {
                cout <<"Data berhasil diurut"<<endl;
            }
            else
            {
                cout <<"Daftar kereta masih ksosong"<<endl;
            }
            getch();
            system("cls");
        }
        else if (x == 2)
        {
            L = sort_by_name(L);
            if (first(L) != nil)
            {
                cout <<"Data berhasil diuurt"<<endl;
            }
            else
            {
                cout <<"Daftar kereta masih ksosong"<<endl;
            }
            getch();
            system("cls");
        }
    }

}
