#include "header.h"
#include <iostream>
using namespace std;

adrPemain createElmPemain(dataPemain newData) {
    adrPemain P = new elmPemain;
    P->info = newData;
    P->next = NULL;
    return P;
}

bool isEmptyPemain(adrTurnamen T) {
    return (T->firstChild == NULL);
}

void insertFirstPemain(adrTurnamen T, adrPemain P) {
    P->next = T->firstChild;
    T->firstChild = P;
}

void deleteFirstPemain(adrTurnamen T, adrPemain &P) {
    if (T->firstChild == NULL) {
        P = NULL;
    } else {
        P = T->firstChild;
        T->firstChild = P->next;
        P->next = NULL;
    }
}

adrPemain findPemain(adrTurnamen T, string idDicari) {
    adrPemain P = T->firstChild;
    while (P != NULL) {
        if (P->info.idPemain == idDicari) return P;
        P = P->next;
    }
    return NULL;
}

void daftarPemain(List &L, string idTurnamen, adrPemain P) {
    adrTurnamen T = findTurnamen(L, idTurnamen);
    if (T == NULL) {
        cout << "Turnamen tidak ditemukan!\n";
        return;
    }

    insertLastPemain(T, P);
    cout << "Pemain berhasil didaftarkan.\n";
}

void showPemain(adrTurnamen T) {
    if (T->firstChild == NULL) {
        cout << "(Belum ada pemain)\n";
        return;
    }

    adrPemain P = T->firstChild;
    while (P != NULL) {
        cout << "- " << P->info.idPemain << " | " << P->info.namaPemain
             << " | Ranking: " << P->info.ranking
             << " | Poin: " << P->info.poin << endl;
        P = P->next;
    }
}