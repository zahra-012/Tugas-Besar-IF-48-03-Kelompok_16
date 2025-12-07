#include "header.h"
#include <iostream>
using namespace std;

void insertLastPemain(adrTurnamen T, adrPemain P) {
    if (T->firstChild == NULL) {
        T->firstChild = P;
    } else {
        adrPemain Q = T->firstChild;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
    P->next = NULL;
}

void deleteLastPemain(adrTurnamen T, adrPemain &P) {
    if (T->firstChild == NULL) {
        P = NULL;
    } else if (T->firstChild->next == NULL) {
        P = T->firstChild;
        T->firstChild = NULL;
    } else {
        adrPemain Q = T->firstChild;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

void deletePemainByIdInternal(adrTurnamen T, string idHapus, adrPemain &P) {
    P = NULL;

    if (T->firstChild == NULL) return;

    if (T->firstChild->info.idPemain == idHapus) {
        deleteFirstPemain(T, P);
        return;
    }

    adrPemain Q = T->firstChild;
    while (Q->next != NULL && Q->next->info.idPemain != idHapus) {
        Q = Q->next;
    }

    if (Q->next != NULL) {
        P = Q->next;
        Q->next = P->next;
        P->next = NULL;
    }
}

void hapusPemainDariTurnamen(List &L, string idTurnamen, string idPemain) {
    adrTurnamen T = findTurnamen(L, idTurnamen);
    if (T == NULL) {
        cout << "Turnamen tidak ditemukan.\n";
        return;
    }

    adrPemain P;
    deletePemainByIdInternal(T, idPemain, P);

    if (P != NULL)
        cout << "Pemain " << idPemain << " berhasil dihapus.\n";
    else
        cout << "Pemain tidak ditemukan.\n";
}

bool isPemainTerdaftar(List L, string idPemain) {
    adrTurnamen T = L.first;

    while (T != NULL) {
        adrPemain P = T->firstChild;
        while (P != NULL) {
            if (P->info.idPemain == idPemain) return true;
            P = P->next;
        }
        T = T->next;
    }
    return false;
}

adrPemain findPemainTerbaik(List L) {
    adrPemain terbaik = NULL;

    adrTurnamen T = L.first;
    while (T != NULL) {
        adrPemain P = T->firstChild;
        while (P != NULL) {
            if (terbaik == NULL || P->info.poin > terbaik->info.poin) {
                terbaik = P;
            }
            P = P->next;
        }
        T = T->next;
    }

    return terbaik;
}
