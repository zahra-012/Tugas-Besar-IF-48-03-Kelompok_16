#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

typedef struct elemenPemain* adrPemain;
typedef struct elemenTurnamen* adrTurnamen;
typedef struct listTurnamen List;

struct dataPemain {
    string idPemain;
    string namaPemain;
    int ranking;
    int menang;
    int kalah;
    int poin;
};

struct elemenPemain {
    dataPemain info;
    adrPemain next;
};

struct dataTurnamen {
    string idTurnamen;
    string namaTurnamen;
    string lokasi;
    int tahun;
};

struct elemenTurnamen {
    dataTurnamen info;
    elemenTurnamen *next;
    elemenPemain *firstPemain;
};

struct listTurnamen {
    elemenTurnamen *first;
};

// FUNGSI TURNAMEN
void createListTurnamen(List &L);
adrTurnamen createElmTurnamen(dataTurnamen newData);
adrTurnamen findTurnamen(List L, string idDicari);
void insertFirstTurnamen(List &L, adrTurnamen P);
void insertLastTurnamen(List &L, adrTurnamen P);
void insertAfterTurnamen(adrTurnamen Prec, adrTurnamen P);
void deleteFirstTurnamen(List &L, adrTurnamen &P);
void deleteLastTurnamen(List &L, adrTurnamen &P);
void deleteAfterTurnamen(adrTurnamen Prec, adrTurnamen &P);

// FUNGSI PEMAIN
adrPemain createElmPemain(dataPemain newData);
bool isEmptyPemain(adrTurnamen T);
adrPemain findPemain(adrTurnamen T, string idDicari);
void insertFirstPemain(adrTurnamen T, adrPemain P);
void insertLastPemain(adrTurnamen T, adrPemain P);
void insertAfterPemain(adrTurnamen T, adrPemain Prec, adrPemain P);
void deleteFirstPemain(adrTurnamen T, adrPemain &P);
void deleteLastPemain(adrTurnamen T, adrPemain &P);
void deleteAfterPemain(adrTurnamen T, adrPemain Prec, adrPemain &P);  // TAMBAHKAN INI
void deletePemainByIdInternal(adrTurnamen T, string idHapus, adrPemain &P);

// FUNGSI RELASI
void daftarPemain(List &L, string idTurnamen, adrPemain P);
void hapusTurnamen(List &L, string idHapus);
void hapusPemainDariTurnamen(List &L, string idTurnamen, string idPemain);

// FUNGSI DISPLAY
void showAllData(List L);
void showAllPemainUnik(List L);
void showPemain(adrTurnamen T);
void printPemainDetail(adrPemain P);  // TAMBAHKAN INI

// FUNGSI STATISTIK
bool isPemainTerdaftar(List L, string idPemain);
int countPemain(adrTurnamen T);
int totalSemuaPemain(List L);
int countTotalTurnamen(List L);
adrTurnamen findTurnamenTeramai(List L);
adrPemain findPemainTerbaik(List L);

// FUNGSI MENU
void menuAdmin(List &L);
void menuUtama(List &L);
void menuUser(List &L);

#endif // HEADER_H_INCLUDED
