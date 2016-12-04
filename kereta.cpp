#include "kereta.h"

void createList_parent(List_parent &L)
{
    first(L) = nil;
    last(L) = nil;
}

adr_parent alokasi_parent (infotype_parent x)
{
    adr_parent P;
    P = new elmlist_parent;
    infoP(P) = x;
    nextP(P) = nil;
    child(P) = nil;
    prevP(P) = nil;
}

void insertFirstParent (List_parent &L, adr_parent P)
{
    if (first(L) == nil)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        nextP(P) = first(L);
        prevP(first(L)) = P;
        first(L) = P;
    }
}

void insertAfterParent (adr_parent Prec,adr_parent P)
{
    prevP(P) = Prec;
    nextP(P) = nextP(Prec);
    prevP(nextP(Prec)) = P;
    nextP(Prec) = P;

}

void insertLastParent (List_parent &L, adr_parent P)
{
    if (first(L) == nil)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        nextP(last(L)) = P;
        prevP(P) = last(L);
        last(L) = P;
    }
}
adr_parent find_kereta (List_parent L, infotype_parent x)
{
    adr_parent P = nil;

    if (first(L) == nil)
    {
        return nil;
    }
    else
    {
        P = first(L);
        while ((infoP(P).ID_kereta != x.ID_kereta) && nextP(P) != nil)
        {
            P = nextP(P);
        }

        if (infoP(P).ID_kereta == x.ID_kereta)
        {
            return P;
        }
        else
        {
            return nil;
        }

    }
}

adr_parent find_kereta_penumpang (List_parent L, infotype_parent x)
{
    adr_parent P = nil;

    if (first(L) == nil)
    {
        return nil;
    }
    else
    {
        P = first(L);
        while (infoP(P).tujuan != x.tujuan && nextP(P) != nil)
        {
            P = nextP(P);
        }

        if (infoP(P).tujuan == x.tujuan)
        {
            return P;
        }
        else
        {
            return nil;
        }

    }
}

void dealokasi(adr_parent &P)
{
    delete P;
}

void deleteFirstParent (List_parent &L, adr_parent &P)
{
    if(first(L) != NULL)
    {
        P = first(L);
        if (nextP(P) ==  NULL)
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            P = first(L);
            first(L)= nextP(P);
            nextP(P) = NULL;
            prevP(first(L)) = NULL;
            prevP(P) =NULL;
        }
    }
}

void deleteAfterParent (List_parent &L, adr_parent prec, adr_parent P)
{
    P = nextP(prec);
    nextP(prec) = nextP(P);
    prevP(nextP(P)) =prec;
    prevP(P) = nil;
    nextP(P) = nil;


}

void deleteLastParent (List_parent &L, adr_parent &P)
{
    if (last(L)!= NULL)
    {
        P = last(L);
        if(prevP(P) == NULL)
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            last(L) = prevP(P);
            prevP(P) = NULL;
            nextP(last(L)) = NULL;
        }
    }

}

List_parent sort_by_name(List_parent &L)
{
    List_parent L2;
    adr_parent P,Q;
    createList_parent(L2);

    if (first(L) != nil)
    {
        P = first(L);
        Q = P;
        if (nextP(P) == nil)
        {
            deleteFirstParent(L,P);
            insertLastParent(L2,P);
        }
        else
        {
            while (first(L) != nil)
            {
                P = first(L);
                Q = P;
                while (nextP(P) != nil)
                {
                    if (infoP(nextP(P)).nama_kereta < infoP(P).nama_kereta)
                    {
                        Q = nextP(P);
                    }
                    P = nextP(P);
                }

                if (Q == first(L))
                {
                    deleteFirstParent(L,Q);
                    insertLastParent(L2,Q);
                }
                else if (Q == last(L))
                {
                    deleteLastParent(L,Q);
                    insertLastParent(L2,Q);
                }
                else if (Q != first(L) && nextP(Q) != nil)
                {
                    deleteAfterParent(L,prevP(Q),Q);
                    insertLastParent(L2,Q);
                }
            }
        }
        return L2;
    }
}

List_parent sort_by_id(List_parent &L)
{
    List_parent L2;
    adr_parent P,Q;
    createList_parent(L2);

    if (first(L) != nil)
    {
        P = first(L);
        Q = P;
        if (nextP(P) == nil)
        {
            deleteFirstParent(L,P);
            insertLastParent(L2,P);
        }
        else
        {
            while (first(L) != nil)
            {
                P = first(L);
                Q = P;
                while (nextP(P) != nil)
                {
                    if (infoP(nextP(P)).ID_kereta < infoP(P).ID_kereta)
                    {
                        Q = nextP(P);
                    }
                    P = nextP(P);
                }

                if (Q == first(L))
                {
                    deleteFirstParent(L,Q);
                    insertLastParent(L2,Q);
                }
                else if (Q == last(L))
                {
                    deleteLastParent(L,Q);
                    insertLastParent(L2,Q);
                }
                else if (Q != first(L) && nextP(Q) != nil)
                {
                    deleteAfterParent(L,prevP(Q),Q);
                    insertLastParent(L2,Q);
                }
            }
        }
        return L2;
    }
}


//PROCEDURE UNTUK CHILD
//====================================================

adr_child alokasi_child(infotype_child x)
{
    adr_child P;
    P = new elmlist_child;
    infoC(P) = x;
    nextC(P) = nil;
    return P;
}

void insertFirstChild (adr_parent Q, adr_child P)
{
    if (child(Q) == nil)
    {
        child(Q) = P;
    }
    else
    {
        nextC(P) = child(Q);
        child(Q) = P;
    }
}

void insertLastChild (adr_parent Q, adr_child P)
{
    adr_child R;
    if (child(Q) == nil)
    {
        child(Q) = P;
    }
    else
    {
        R = child(Q);
        while (nextC(R) != nil)
        {
            R = nextC(R);
        }
        nextC(R) = P;
    }
}

void insertAfterChild (adr_child Prec, adr_child P)
{
    nextC(P) = nextC(Prec);
    nextC(Prec) = P;
}

adr_child find_gerbong (adr_parent P, infotype_child x)
{
    adr_child Q;

    if (child(P) == nil)
    {
        return nil;
    }
    else
    {
        Q = child(P);
        while ((infoC(Q).no_gerbong != x.no_gerbong) && nextC(Q) != nil)
        {
            Q = nextC(Q);
        }

        if (infoC(Q).no_gerbong == x.no_gerbong)
        {
            return Q;
        }
        else
        {
            return nil;
        }

    }
}

adr_child find_gerbong_penumpang (adr_parent P, infotype_child x)
{
    adr_child Q;

    if (child(P) == nil)
    {
        return nil;
    }
    else
    {
        Q = child(P);
        while ((infoC(Q).kategori != x.kategori) && nextC(Q) != nil)
        {
            Q = nextC(Q);
        }

        if (infoC(Q).kategori == x.kategori)
        {
            return Q;
        }
        else
        {
            return nil;
        }

    }
}

void deleteFirstChild (adr_parent &Q, adr_child &P)
{
    if(child(Q) != NULL)
    {
        P = child(Q);
        if (nextC(P) ==  NULL)
        {
            child(Q) = NULL;
        }
        else
        {
            P = child(Q);
            child(Q)= nextC(P);
            nextC(P) = NULL;
        }
    }
}

void deleteAfterChild (adr_parent &Q, adr_child Prec, adr_child P)
{
    Prec = child(Q);
    while (infoC(nextC(Prec)).no_gerbong != infoC(P).no_gerbong)
    {
        Prec = nextC(Prec);
    }

    P = nextC(Prec);
    nextC(Prec) = nextC(P);
    nextC(P) = nil;

}

void deleteLastChild (adr_parent &Q, adr_child &P)
{
    adr_child R;

    if (child(Q)!= NULL)
    {
        P = child(Q);
        if(nextC(P) == NULL)
        {
            child(Q) == NULL;
        }
        else
        {
            R = child(Q);
            while (nextC(nextC(R)) != nil)
            {
                R = nextC(R);
            }
            P = nextC(R);
            nextC(R) = nil;
        }
    }
}


void printInfo(List_parent L)
{
    adr_parent P;
    adr_child Q;

    if (first(L) != nil)
    {
        cout <<" ------------------------- "<<endl;
        cout <<"|       DAFTAR KERETA      |"<<endl;
        cout <<" ------------------------- "<<endl;
        P = first(L);
        if (nextP(P) == nil)
        {
            cout <<"ID KERETA   : "<<infoP(P).ID_kereta<<endl;
            cout <<"NAMA KERETA : "<<infoP(P).nama_kereta<<endl;
            cout <<"TUJUAN      : "<<infoP(P).tujuan<<endl;
            cout <<endl;
            if (child(P) != nil)
            {
                Q = child(P);
                if (nextC(Q) == nil)
                {
                    cout <<"NO GERBONG  : "<<infoC(Q).no_gerbong<<endl;
                    cout <<"KATEGORI    : "<<infoC(Q).kategori<<endl;
                    cout <<endl;
                    cout <<"-----------------------------"<<endl;
                }
                else
                {
                    while(Q != nil)
                    {
                        cout <<"NO GERBONG  : "<<infoC(Q).no_gerbong<<endl;
                        cout <<"KATEGORI    : "<<infoC(Q).kategori<<endl;
                        cout <<endl;
                        Q = nextC(Q);
                    }
                    cout <<endl;
                    cout <<"-----------------------------"<<endl;
                }
            }
            else
            {
                cout <<"BELUM ADA GERBONG"<<endl;
                cout <<endl;
                cout <<"-----------------"<<endl;
            }
        }
        else
        {
            do
            {
                cout <<"ID KERETA   : "<<infoP(P).ID_kereta<<endl;
                cout <<"NAMA KERETA : "<<infoP(P).nama_kereta<<endl;
                cout <<"TUJUAN      : "<<infoP(P).tujuan<<endl;
                cout <<endl;
                if (child(P) != nil)
                {
                    Q = child(P);
                    if (nextC(Q) == nil)
                    {
                        cout <<"NO GERBONG  : "<<infoC(Q).no_gerbong<<endl;
                        cout <<"KATEGORI    : "<<infoC(Q).kategori<<endl;
                        cout <<endl;
                        cout <<"-----------------------------"<<endl;
                    }
                    else
                    {
                        while(Q != nil)
                        {
                            cout <<"NO GERBONG  : "<<infoC(Q).no_gerbong<<endl;
                            cout <<"KATEGORI    : "<<infoC(Q).kategori<<endl;
                            cout <<endl;
                            Q = nextC(Q);
                        }
                        cout <<endl;
                        cout <<"-----------------------------"<<endl;
                    }
                }
                else
                {
                    cout <<"BELUM ADA GERBONG"<<endl;
                    cout <<endl;
                    cout <<"-----------------"<<endl;
                }
                P = nextP(P);
            }
            while (P != nil);
        }
    }
    else
    {
        cout <<"BELUM ADA KERETA"<<endl;
    }
}

void printInfoAll(List_parent L)
{
    adr_parent P;
    adr_child Q;

    if (first(L) != nil)
    {
        cout <<" ------------------------- "<<endl;
        cout <<"|       DAFTAR KERETA      |"<<endl;
        cout <<" ------------------------- "<<endl;
        P = first(L);
        if (nextP(P) == nil)
        {
            cout <<"ID KERETA   : "<<infoP(P).ID_kereta<<endl;
            cout <<"NAMA KERETA : "<<infoP(P).nama_kereta<<endl;
            cout <<"TUJUAN      : "<<infoP(P).tujuan<<endl;
            cout <<endl;
            if (child(P) != nil)
            {
                Q = child(P);
                if (nextC(Q) == nil)
                {
                    cout <<"NO GERBONG  : "<<infoC(Q).no_gerbong<<endl;
                    cout <<"KATEGORI    : "<<infoC(Q).kategori<<endl;
                    cout <<endl;
                    cout <<"DAFTAR PENUMPANG GERBONG"<<endl;
                    cout <<endl;
                    cout <<"-----------------------------------------"<<endl;
                    cout <<"ID PENUMPANG | NAMA PENUMPANG | NO KURSI "<<endl;
                    cout <<"-----------------------------------------"<<endl;

                    for (int i=0; i<infoC(Q).kapasitas; i++)
                    {
                        if (infoC(Q).nomor_kursi[i] == true)
                        {
                            cout <<infoC(Q).data_penumpang[i].id_penumpang<<" ";
                            cout <<infoC(Q).data_penumpang[i].nama_penumpang<<" ";
                            cout <<infoC(Q).data_penumpang[i].nomor_kursi<<" ";
                            cout <<endl;
                        }
                    }
                    cout <<endl;
                    cout <<"------------------------------------------"<<endl;

                }
                else
                {
                    while(Q != nil)
                    {
                        cout <<"NO GERBONG  : "<<infoC(Q).no_gerbong<<endl;
                        cout <<"KATEGORI    : "<<infoC(Q).kategori<<endl;
                        cout <<endl;
                        cout <<"DAFTAR PENUMPANG GERBONG"<<endl;
                        cout <<endl;
                        cout <<"-----------------------------------------"<<endl;
                        cout <<"ID PENUMPANG | NAMA PENUMPANG | NO KURSI "<<endl;
                        cout <<"-----------------------------------------"<<endl;

                        for (int i=0; i<infoC(Q).kapasitas; i++)
                        {
                            if (infoC(Q).nomor_kursi[i] == true)
                            {
                                cout <<infoC(Q).data_penumpang[i].id_penumpang<<" ";
                                cout <<infoC(Q).data_penumpang[i].nama_penumpang<<" ";
                                cout <<infoC(Q).data_penumpang[i].nomor_kursi<<" ";
                                cout <<endl;
                            }
                        }
                        cout <<endl;
                        cout <<"------------------------------------------"<<endl;

                        Q = nextC(Q);
                    }
                }
            }
            else
            {
                cout <<"BELUM ADA GERBONG"<<endl;
                cout <<endl;
                cout <<"-----------------"<<endl;
            }
        }
        else
        {
            do
            {
                cout <<"ID KERETA   : "<<infoP(P).ID_kereta<<endl;
                cout <<"NAMA KERETA : "<<infoP(P).nama_kereta<<endl;
                cout <<"TUJUAN      : "<<infoP(P).tujuan<<endl;
                cout <<endl;
                if (child(P) != nil)
                {
                    Q = child(P);
                    if (nextC(Q) == nil)
                    {
                        cout <<"NO GERBONG  : "<<infoC(Q).no_gerbong<<endl;
                        cout <<"KATEGORI    : "<<infoC(Q).kategori<<endl;
                        cout <<endl;
                        cout <<"DAFTAR PENUMPANG GERBONG"<<endl;
                        cout <<endl;
                        cout <<"-----------------------------------------"<<endl;
                        cout <<"ID PENUMPANG | NAMA PENUMPANG | NO KURSI "<<endl;
                        cout <<"-----------------------------------------"<<endl;

                        for (int i=0; i<infoC(Q).kapasitas; i++)
                        {
                            if (infoC(Q).nomor_kursi[i] == true)
                            {
                                cout <<infoC(Q).data_penumpang[i].id_penumpang<<" ";
                                cout <<infoC(Q).data_penumpang[i].nama_penumpang<<" ";
                                cout <<infoC(Q).data_penumpang[i].nomor_kursi<<" ";
                                cout <<endl;
                            }
                        }
                        cout <<endl;
                        cout <<"------------------------------------------"<<endl;

                    }
                    else
                    {
                        while(Q != nil)
                        {
                            cout <<"NO GERBONG  : "<<infoC(Q).no_gerbong<<endl;
                            cout <<"KATEGORI    : "<<infoC(Q).kategori<<endl;
                            cout <<endl;
                            cout <<"DAFTAR PENUMPANG GERBONG"<<endl;
                            cout <<endl;
                            cout <<"-----------------------------------------"<<endl;
                            cout <<"ID PENUMPANG | NAMA PENUMPANG | NO KURSI "<<endl;
                            cout <<"-----------------------------------------"<<endl;

                            for (int i=0; i<infoC(Q).kapasitas; i++)
                            {
                                if (infoC(Q).nomor_kursi[i] == true)
                                {
                                    cout <<infoC(Q).data_penumpang[i].id_penumpang<<" ";
                                    cout <<infoC(Q).data_penumpang[i].nama_penumpang<<" ";
                                    cout <<infoC(Q).data_penumpang[i].nomor_kursi<<" ";
                                    cout <<endl;
                                }
                            }
                            cout <<endl;
                            cout <<"------------------------------------------"<<endl;

                            Q = nextC(Q);
                        }

                    }
                }
                else
                {
                    cout <<"BELUM ADA GERBONG"<<endl;
                    cout <<endl;
                    cout <<"-----------------"<<endl;
                }
                P = nextP(P);
            }
            while (P != nil);
        }
    }
    else
    {
        cout <<"BELUM ADA KERETA"<<endl;
    }
}
