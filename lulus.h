#ifndef LULUS_H_INCLUDED
#define LULUS_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

#define infoMhs(P) (P)->infoMhs
#define child(P) (P)->child
#define nextMhs(P) (P)->nextMhs
#define firstMhs(L) ((L).firstMhs)

#define infoSts(P) (P)->infoSts
#define nextSts(P) (P)->nextSts
#define firstSts(LS) ((LS).firstSts)

struct mahasiswa{
    string namaMhs, kelasMhs, nimMhs;
    int nilai, poin;
};

struct status{
    string lulus;
    string bermasalah ;
};

typedef mahasiswa infotypeMhs;
typedef struct elmStatus *adrSts;
typedef struct elmMhs *adrMhs;
typedef status infotypeSts;


struct elmMhs{
    infotypeMhs infoMhs;
    adrSts child;
    adrMhs nextMhs;
};

struct elmStatus{
    infotypeSts infoSts;
    adrSts nextSts;
};


struct listMhs{
    adrMhs firstMhs;
};


struct listSts{
    adrSts firstSts;
};


void createListMhs(listMhs &L);
adrMhs createElemenMhs(infotypeMhs x);
//
infotypeMhs newMahasiswa(string namaMhs, string nimMhs, string kelasMhs,int nilai, int poin);
infotypeSts newStatus(string lulus, string bermasalah);
// string lulus, string bermasalah,
bool isEmpty(listMhs &L);
bool isOne(listMhs &L);
void insertFirstMhs(listMhs &L, adrMhs P);
void showAllMhs(listMhs &L);
void deleteDataMhs(listMhs &L,adrMhs &P, string namaMhs);
adrMhs searchParent(listMhs &L, string namaMhs);
void connecting(listMhs &L, listSts &LS);
void showAll(listMhs L);
int Menu();
void deleteFirstMhs(listMhs &L, adrMhs &P);
void deleteLastMhs(listMhs &L, adrMhs &P);

adrSts searchChildOnParent(listMhs &L,string namaMhs)
void createListSts(listSts &LS);
adrSts createElemenSts(infotypeSts x);
adrSts searchSts(listSts LS, string lulus, string bermasalah);
void insertLastSts(listSts &LS, adrSts P);
void deleteChildonParent(listMhs &L, adrSts &P, string namaMhs);
void deleteFirstSts(listSts &LS, adrSts &P);
void deleteAfterSts(listSts &LS, adrSts &P, string lulus, string bermasalah);
void deleteLastSts(listSts &LS, adrSts &P);

void showchild(listSts LS);
#endif // LULUS_H_INCLUDED
