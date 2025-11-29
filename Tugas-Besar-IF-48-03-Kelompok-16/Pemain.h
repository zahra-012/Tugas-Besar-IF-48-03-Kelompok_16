#ifndef PEMAIN_H_INCLUDED
#define PEMAIN_H_INCLUDED

#include <iostream>
using namespace std;

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

bool listPemainKosong(elemenTurnamen *T);
int hitungJumlahPemain(elemenTurnamen *T);
elemenPemain* buatElemenPemain(dataPemain dataBaru);
void tampilkanPemainDalamTurnamen(elemenTurnamen *T);
void tampilkanSemuaPemainUnik(listTurnamen LT);
void sisipPemainAwal(elemenTurnamen *T, elemenPemain *p);
void sisipPemainAkhir(elemenTurnamen *T, elemenPemain *p);
void sisipPemainSetelah(elemenTurnamen *T, string idPatokan, elemenPemain *p);
elemenPemain* cariPemainDalamTurnamen(elemenTurnamen *T, string idDicari);
void hapusPemainAwal(elemenTurnamen *T);
void hapusPemainAkhir(elemenTurnamen *T);
void hapusPemainTertentu(elemenTurnamen *T, string idHapus);
void menuKelolaPemain(listTurnamen &LT);


#endif
