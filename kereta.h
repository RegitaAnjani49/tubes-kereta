#ifndef KERETA_H_INCLUDED
#define KERETA_H_INCLUDED
#include <iostream>

#define nil NULL
#define first(L) L.first
#define last(L) L.last
#define child(P) P->child
#define infoP(P) P->infoP
#define infoC(P) P->infoC
#define nextP(P) P->nextP
#define prevP(P) P->prevP
#define nextC(C) C->nextC

using namespace std;

struct penumpang
{
    int id_penumpang;
    string nama_penumpang;
    string alamat;
    string tujuan;
    string kategori;
    int no_gerbong;
    int nomor_kursi;
};


struct kereta
{
    int ID_kereta;
    string nama_kereta;
    string asal;
    string tujuan;
    string tanggal;
    string waktu;
};

struct gerbong
{
    int no_gerbong;
    string kategori;
    int kapasitas;
    penumpang data_penumpang[10];
    bool nomor_kursi[10];
    int jumlah_penumpang;
    int ID_kereta;
    string nama_kereta;
};

typedef gerbong infotype_child;
typedef kereta infotype_parent;
typedef struct elmlist_parent *adr_parent;
typedef struct elmlist_child *adr_child;

struct elmlist_parent
{
    infotype_parent infoP;
    adr_parent nextP;
    adr_parent prevP;
    adr_child child;
};

struct elmlist_child
{
    infotype_child infoC;
    adr_child nextC;
};

struct List_parent
{
    adr_parent first,last;
};

void createList_parent(List_parent &L);

adr_parent alokasi_parent (infotype_parent x);
void insertFirstParent (List_parent &L, adr_parent P);
void insertAfterParent (adr_parent Prec, adr_parent P);
void insertLastParent (List_parent &L, adr_parent P);
void dealokasi(adr_parent &P);
adr_parent find_kereta (List_parent L, infotype_parent x);
adr_parent find_kereta_penumpang (List_parent L, infotype_parent x);
void deleteFirstParent (List_parent &L, adr_parent &P);
void deleteAfterParent (List_parent &L, adr_parent Prec, adr_parent P);
void deleteLastParent (List_parent &L, adr_parent &P);
List_parent sort_by_name(List_parent &L);
List_parent sort_by_id(List_parent &L);


adr_child alokasi_child (infotype_child x);
void insertFirstChild (adr_parent Q, adr_child P);
void insertLastChild (adr_parent Q, adr_child P);
void insertAfterChild (adr_child Prec, adr_child P);
adr_child find_gerbong (adr_parent P, infotype_child x);
adr_child find_gerbong_penumpang (adr_parent P, infotype_child x);
void deleteFirstChild (adr_parent &Q, adr_child &P);
void deleteAfterChild (adr_parent &Q, adr_child Prec, adr_child P);
void deleteLastChild (adr_parent &Q, adr_child &P);

void printInfo(List_parent L);
void printInfoAll(List_parent L);

#endif // KERETA_H_INCLUDED
