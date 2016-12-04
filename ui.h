#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#include <iostream>
#include "kereta.h"

using namespace std;

void mainmenu();

//============== INPUT DATA
void menuinsert();
void tambahkereta();
void tambahgerbong();
void input_penumpang();
void cek_kursi(adr_child P);


//============== SEARCH DATA
void searchview();
void view_kereta();
void view_gerbong();
void view_penumpang();
penumpang search_penumpang(penumpang x);


//============== SEARCH DELETE
void searchdelete();
void delete_kereta();
void delete_gerbong();
void delete_penumpang();

//============== VIEW DATA
void viewall();

//============== REPORTING
void reporting();
void jumlah_kereta();
void jumlah_gerbong();
void prosen_penumpang();


//============== SEARCH EDIT
void searchandedit();
void editkereta();
void editgerbong();

//============== SORTING DATA
void sorting_kereta();





#endif // UI_H_INCLUDED
