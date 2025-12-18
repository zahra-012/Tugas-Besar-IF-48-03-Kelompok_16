#include "header.h"
#include <iostream>
using namespace std;

void createListTurnamen(List &L) {
    L.first = NULL;
}

adrTurnamen createElmTurnamen(dataTurnamen newData) {
    adrTurnamen P = new elemenTurnamen;
    P->info = newData;
    P->firstPemain = NULL;
    P->next = NULL;
    return P;
}

adrTurnamen findTurnamen(List L, string idDicari) {
    adrTurnamen P = L.first;
    while (P != NULL) {
        if (P->info.idTurnamen == idDicari) return P;
        P = P->next;
    }
    return NULL;
}

void insertFirstTurnamen(List &L, adrTurnamen P) {
    P->next = L.first;
    L.first = P;
}

void deleteFirstTurnamen(List &L, adrTurnamen &P) {
    if (L.first == NULL) {
        P = NULL;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void insertAfterTurnamen(adrTurnamen Prec, adrTurnamen P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void hapusTurnamen(List &L, string idHapus) {
    adrTurnamen P, Q;

    if (L.first != NULL && L.first->info.idTurnamen == idHapus) {
        deleteFirstTurnamen(L, P);
        cout << "Turnamen berhasil dihapus.\n";
        return;
    }

    Q = L.first;
    while (Q != NULL && Q->next != NULL && Q->next->info.idTurnamen != idHapus) {
        Q = Q->next;
    }

    if (Q != NULL && Q->next != NULL) {
        deleteAfterTurnamen(Q, P);
        cout << "Turnamen berhasil dihapus.\n";
    } else {
        cout << "Turnamen tidak ditemukan.\n";
    }
}

void showAllData(List L) {
    cout << "\n=== DAFTAR SEMUA TURNAMEN ===\n";

    adrTurnamen T = L.first;
    while (T != NULL) {
        cout << "\nID Turnamen : " << T->info.idTurnamen
             << "\nNama        : " << T->info.namaTurnamen
             << "\n--- Daftar Pemain ---\n";
        showPemain(T);
        cout << "---------------------------\n";

        T = T->next;
    }
}

int countPemain(adrTurnamen T) {
    int total = 0;
    adrPemain P = T->firstPemain;

    while (P != NULL) {
        total++;
        P = P->next;
    }

    return total;
}

adrTurnamen findTurnamenTeramai(List L) {
    adrTurnamen T = L.first;
    adrTurnamen terbesar = NULL;

    int maxPemain = -1;

    while (T != NULL) {
        int jumlah = countPemain(T);

        if (jumlah > maxPemain) {
            maxPemain = jumlah;
            terbesar = T;
        }

        T = T->next;
    }

    return terbesar;
}
