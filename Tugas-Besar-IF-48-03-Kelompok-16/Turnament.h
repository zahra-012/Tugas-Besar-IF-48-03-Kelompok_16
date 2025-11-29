#ifndef TURNAMEN_H_INCLUDED
#define TURNAMEN_H_INCLUDED

#include <iostream>
using namespace std;

struct dataTurnamen {
    string idTurnamen;
    string namaTurnamen;
    string lokasi;
    int tahun;
};

struct elemenTurnamen {
    dataTurnamen info;
    elemenTurnamen *next;
    elemenTurnamen *prev;

    struct elemenPemain *firstPemain;
    struct elemenPemain *lastPemain;
};

struct listTurnamen {
    elemenTurnamen *first;
    elemenTurnamen *last;
};

void buatListTurnamen(listTurnamen &L);
bool listTurnamenKosong(listTurnamen L);
int hitungJumlahTurnamen(listTurnamen L);
elemenTurnamen* buatElemenTurnamen(dataTurnamen dataBaru);
void tampilkanSemuaTurnamen(listTurnamen L);
void sisipTurnamenAwal(listTurnamen &L, elemenTurnamen *p);
void sisipTurnamenAkhir(listTurnamen &L, elemenTurnamen *p);
void sisipTurnamenSetelah(listTurnamen &L, string idPatokan, elemenTurnamen *p);
elemenTurnamen* cariTurnamen(listTurnamen L, string idDicari);
void hapusTurnamenAwal(listTurnamen &L);
void hapusTurnamenAkhir(listTurnamen &L);
void hapusTurnamenTertentu(listTurnamen &L, string idHapus);
void menuKelolaTurnamen(listTurnamen &LT, listPemain &LP);


#endif
