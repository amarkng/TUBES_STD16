#include "lulus.h"


void createListMhs(listMhs &L){
    firstMhs(L) = NULL;
}

adrMhs createElemenMhs(infotypeMhs x){
    adrMhs P = new elmMhs;
    infoMhs(P) = x;
    child(P) = NULL;
    nextMhs(P) = NULL;
    return P;
}

infotypeMhs newMahasiswa(string namaMhs, string kelasMhs, string nimMhs,int nilai, int poin){
    mahasiswa mhs;
    mhs.namaMhs = namaMhs;
    mhs.nimMhs = nimMhs;
    mhs.kelasMhs = kelasMhs;
    mhs.nilai = nilai;
    mhs.poin = poin;
    return mhs;
}


bool isEmpty(listMhs &L){
    bool kondisi = false;
    if(firstMhs(L) == NULL){
        kondisi = true;
    }
    return kondisi;
}

bool isOne(listMhs &L){
    bool inpo = false;
    if(nextMhs(firstMhs(L)) == NULL){
        inpo = true;
    }
    return inpo;
}

void insertFirstMhs(listMhs &L, adrMhs P){
    if(isEmpty(L)){ //diganti awalnya pake isEmpty
        firstMhs(L) = P;
    }else{
        nextMhs(P) = firstMhs(L);
        firstMhs(L) = P;
    }
}

void showAllMhs(listMhs &L){
    if(firstMhs(L) == NULL){ //diganti awalnya pake isEmpty
        cout<<"List Kosong!"<<endl;
    }else{
        adrMhs P;
        P = firstMhs(L);
        while(P != NULL){
            //cout << P << endl ;
            cout<<"Nama Mahasiswa : "<<infoMhs(P).namaMhs<<endl;
            cout<<"NIM Mahasiswa : "<<infoMhs(P).nimMhs<<endl;
            cout<<"Kelas Mahasiswa : "<<infoMhs(P).kelasMhs<<endl;
            cout<<"Nilai Mahasiswa : "<<infoMhs(P).nilai<<endl;
            cout<<"Poin Mahasiswa : "<<infoMhs(P).poin<<endl;
            cout<<endl;
            P = nextMhs(P);
        }
    }
}

void deleteData(listMhs &L,listSts &LS, string lulus, string bermasalah, adrMhs &P, adrSts &Q){
    adrSts X = searchSts(LS, lulus, bermasalah);
    adrMhs prec = firstMhs(L);
    if(isEmpty(L)){
        cout<<"List Kosong!"<<endl;
    }else {
        while(nextMhs(prec) != NULL){
            if(child(firstMhs(L)) == X){
                child(firstMhs(L)) = NULL;
                deleteFirstMhs(L, P);
            }
            prec = nextMhs(prec);
            if(child(nextMhs(prec)) != X){
                P = nextMhs(prec);
                nextMhs(prec) = nextMhs(P);
            }
        }
        if(child(nextMhs(prec)) == X){
            P = nextMhs(prec);
            child(P) = NULL;
            deleteLastMhs(L, P);
        }
        if(X == firstSts(LS)){
            deleteFirstSts(LS, Q);
        }else if(nextSts(X) == NULL){
            deleteLastSts(LS, Q);
        }else{
            deleteAfterSts(LS, Q, lulus, bermasalah);
        }

    }
}

adrMhs searchParent(listMhs &L, string namaMhs){
    adrMhs prec;
    adrMhs P;
    if(isEmpty(L)){
        cout<<"List kosong!"<<endl;
    }else{
        prec = firstMhs(L);
        while(prec != NULL){
            if(infoMhs(prec).namaMhs == namaMhs){
                P = prec;
                break;
            }
            prec = nextMhs(prec);
        }
    }
    if(prec != NULL){
        return P;
    }else{
        return NULL;
    }
}

adrSts searchSts(listSts LS, string lulus, string bermasalah){
    adrSts P;
    adrSts prec;
    if(firstSts(LS) == NULL){
        cout<<"List Kosong!"<<endl;
    }else{
        prec = firstSts(LS);
        while (prec != NULL && (infoSts(prec).lulus != lulus || infoSts(prec).bermasalah != bermasalah)){

            cout <<infoSts(prec).lulus ;
            cout <<infoSts(prec).bermasalah ;
            //cout <<"HOPP" << endl;
            prec = nextSts(prec);
        }
        if(infoSts(prec).lulus == lulus && infoSts(prec).bermasalah == bermasalah){
            P = prec;
            //cout <<"TESTADAGA" << endl ;
        }
    }
    if(prec != NULL){
        cout <<infoSts(P).lulus ;
        cout <<infoSts(P).bermasalah ;
        cout << endl ;
        return P;
    }else{
        return NULL;
    }
}

void connecting(listMhs &L, listSts &LS){
    adrSts LT, LB, TT, TB;
    adrMhs prec = firstMhs(L);
    LT = searchSts(LS, "Lulus", "TidakBermasalah");
    LB = searchSts(LS, "Lulus", "Bermasalah");
    TT = searchSts(LS, "TidakLulus", "TidakBermasalah");
    TB = searchSts(LS, "TidakLulus", "Bermasalah");

    if(firstMhs(L) == NULL){
        cout<<"List Kosong"<<endl;
    }else{
        cout<<"TESS";
        while(prec != NULL){
            if(infoMhs(prec).nilai >= 40 && infoMhs(prec).poin < 50){
                child(prec) = LT;
                cout<<"JAHIM1";
            }else if(infoMhs(prec).nilai >= 40 && infoMhs(prec).poin >= 50){
                child(prec) = LB;
                cout<<"JAHIM2";
            }else if(infoMhs(prec).nilai < 40 && infoMhs(prec).poin < 50){
                child(prec) = TT;
                cout<<prec;
            }else if(infoMhs(prec).nilai < 40 && infoMhs(prec).poin >= 50){
                child(prec) = TB;
                cout<<"JAHIM4";
            }
            cout<<"BOLA";
            prec = nextMhs(prec);
        }
        cout << "TESTER" ;
    }
}

void showchild(listSts LS){
    adrSts p = firstSts(LS);
    while(p!=NULL){
        cout << p << endl ;
        cout<<"lulus : " <<infoSts(p).lulus<<endl;
        cout<<"bermasalah : " << infoSts(p).bermasalah<<endl;
        p = nextSts(p);
    }
}

void showAll(listMhs L){
    adrSts Q;
    if(isEmpty(L)){
        cout<<"List Kosong"<<endl;
    }else{
        adrMhs P = firstMhs(L);
        while(P != NULL){
            cout<<"==========Data Mahasiswa=========="<<endl;
            cout<<"Nama Mahasiswa : "<<infoMhs(P).namaMhs<<endl;
            cout<<"NIM Mahasiswa : "<<infoMhs(P).nimMhs<<endl;
            cout<<"Kelas Mahasiswa : "<<infoMhs(P).kelasMhs<<endl;
            cout<<"Nilai Mahasiswa : "<<infoMhs(P).nilai<<endl;
            cout<<"Poin Mahasiswa : "<<infoMhs(P).poin<<endl;
            if(child(P) != NULL){
                Q = child(P);
                cout<<"Status Kelulusan mahasiswa : " << infoSts(Q).lulus<<","<<infoSts(Q).bermasalah<<endl;
            }
            cout<<endl;
            P = nextMhs(P);
        }
    }
}
int Menu(){ //diganti lagi hei
    cout << "=========MENU=========" << endl;
    cout << "1. Menambah Data Mahasiswa" << endl;
    cout << "2. Menambah Data Kategori Kelulusan" << endl;
    cout << "3. Menampilkan Data Mahasiswa" << endl;
    cout << "4. Melakukan Proses connect " << endl;
    cout << "5. Menampilkan Seluruh Data Mahasiswa Beserta Kategori Kelulusan (belum)" << endl;
    cout << "6. Mencari Data Mahasiswa" << endl;
    cout << "7. Mencari Data Kategori Kelulusan Dari Data Mahasiswa" << endl;
    cout << "8. Menghapus Data Mahasiswa Beserta Kategorinya" << endl;
    cout << "9. Menghapus Data Kategori Kelulusan Dari Data Mahasiswa" << endl;
    cout << "10.Menghitung Ada Berapa Mahasiswa Yang Termasuk Pada Kategori Tertentu" << endl;
    cout<<endl;
    cout << "0. Keluar Dari Program" <<endl;
    cout<<endl;
    cout << "Pilihan menu: ";

    int input;
    cin >> input;
    return input;
}

void createListSts(listSts &LS){
    firstSts(LS) = NULL;
}

adrSts createElemenSts(infotypeSts x){
    adrSts P = new elmStatus;
    infoSts(P) = x;
    nextSts(P) = NULL;
    return P;
}

infotypeSts newStatus(string lulus, string bermasalah){
    status sts;
    sts.lulus = lulus;
    sts.bermasalah = bermasalah;
    return sts;
}

void insertLastSts(listSts &LS, adrSts P){
    if(firstSts(LS) == NULL){
        firstSts(LS) = P;
    }else{
        adrSts prec = firstSts(LS);
        while(nextSts(prec) != NULL){
            prec = nextSts(prec);
        }
        nextSts(prec) = P;
    }
}

bool searchChildOnParent(listMhs &L, listSts &LS, string lulus, string bermasalah, string namaMhs){
    bool kondisi = false;
    adrMhs P = searchParent(L, namaMhs);
    adrSts Q = searchSts(LS, lulus,bermasalah);
    if(P != NULL && Q != NULL){
        if(child(P) != NULL){
            if(child(P) == Q){
                kondisi = true;
            }
        }
    }
    return kondisi;
}

void deleteChildonParent(listMhs &L, string namaMhs){
    adrMhs Q = searchParent(L, namaMhs);
    if(isEmpty(L)){
        cout<<"List kosong!"<<endl;
    }else if(Q == NULL){
        cout<<"Data tidak ditemukan"<<endl;
    }else{
        if(child(Q) != NULL){
            child(Q) = NULL;
        }
    }
}

int counting(listMhs &L, listSts &LS, string lulus, string bermasalah){
    int total = 0;
    adrMhs prec;
    adrSts Q = searchSts(LS, lulus, bermasalah);
    if(Q != NULL){
        if(firstMhs(L) != NULL){
            prec = firstMhs(L);
            while(prec != NULL){
                if(child(prec) == Q){
                    total++;
                }
                prec = nextMhs(prec);
            }
        }
    }
    return total;
}

void deleteFirstSts(listSts &LS, adrSts &P){
    if(firstSts(LS) == NULL){
        cout<<"List Kosong"<<endl;
    }else if(nextSts(firstSts(LS)) == NULL){
        P = firstSts(LS);
        firstSts(LS) = NULL;
    }else{
        P = firstSts(LS);
        firstSts(LS) = nextSts(P);
        nextSts(P) = NULL;
    }
}

void deleteAfterSts(listSts &LS, string lulus, string bermasalah, adrSts &P){
    adrSts Q = searchSts(LS, lulus, bermasalah);
    adrSts prec;
    if(firstSts(LS) == NULL){
        cout<<"List Kosong"<<endl;
    }else if(nextSts(firstSts(LS)) == NULL){
        P = firstSts(LS);
        firstSts(LS) = NULL;
    }else{
        prec = firstSts(LS);
        if(P != NULL){
            while(nextSts(prec) != Q){
                prec = nextSts(prec);
            }
        }
        prec = nextSts(Q);
        P = Q;
        nextSts(P) = NULL;
    }
}

void deleteLastSts(listSts &LS, adrSts &P){
    adrSts prec;
    if(firstSts(LS) == NULL){
        cout<<"List Kosong"<<endl;
    }else if(nextSts(firstSts(LS)) == NULL){
        P = firstSts(LS);
        firstSts(LS) = NULL;
    }else{
        prec = firstSts(LS);
        while(nextSts(nextSts(prec)) != NULL){
            prec = nextSts(prec);
        }
        P = nextSts(prec);
        nextSts(prec) = NULL;
    }
}
