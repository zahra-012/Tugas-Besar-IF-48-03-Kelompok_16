#include <iostream>
#include <string>

using namespace std;

typedef elemenPemain *adrPemain;
typedef elemenTurnamen *adrTurnamen;
typedef listTurnamen List;

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
    elemenPemain *next;
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

void createListTurnamen(List &L);
adrTurnamen createElmTurnamen(dataTurnamen newData);
adrPemain createElmPemain(dataPemain newData);

adrTurnamen findTurnamen(List L, string idDicari);
void insertFirstTurnamen(List &L, adrTurnamen P);
void insertLastTurnamen(List &L, adrTurnamen P);
void insertAfterTurnamen(adrTurnamen Prec, adrTurnamen P);
void deleteFirstTurnamen(List &L, adrTurnamen &P);
void deleteLastTurnamen(List &L, adrTurnamen &P);
void deleteAfterTurnamen(adrTurnamen Prec, adrTurnamen &P);

bool isEmptyPemain(adrTurnamen T);
adrPemain findPemain(adrTurnamen T, string idDicari);
void insertFirstPemain(adrTurnamen T, adrPemain P);
void insertLastPemain(adrTurnamen T, adrPemain P);
void deleteFirstPemain(adrTurnamen T, adrPemain &P);
void deleteLastPemain(adrTurnamen T, adrPemain &P);
void deletePemainByIdInternal(adrTurnamen T, string idHapus, adrPemain &P);

void daftarPemain(List &L, string idTurnamen, adrPemain P);
void hapusTurnamen(List &L, string idHapus);
void hapusPemainDariTurnamen(List &L, string idTurnamen, string idPemain);

void showAllData(List L);
void showAllPemainUnik(List L);
void showPemain(adrTurnamen T);

bool isPemainTerdaftar(List L, string idPemain);

int countPemain(adrTurnamen T);
int totalSemuaPemain(List L);
adrTurnamen findTurnamenTeramai(List L);
adrPemain findPemainTerbaik(List L);

void menuAdmin(List &L);
void menuUtama(List &L);
