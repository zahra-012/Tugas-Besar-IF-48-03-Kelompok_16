#include "header.h"
#include <iostream>
using namespace std;

void insertLastTurnamen(List &L, adrTurnamen P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adrTurnamen Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
    P->next = NULL;
}

void deleteLastTurnamen(List &L, adrTurnamen &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first->next == NULL) {
        P = L.first;
        L.first = NULL;
    } else {
        adrTurnamen Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

void deleteAfterTurnamen(adrTurnamen Prec, adrTurnamen &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    } else {
        P = NULL;
    }
}

void showAllPemainUnik(List L) {
    cout << "\n== DAFTAR SEMUA PEMAIN (UNIK) ==\n";

    List tempList;
    createListTurnamen(tempList);

    adrTurnamen T = L.first;
    while (T != NULL) {
        adrPemain P = T->firstChild;
        while (P != NULL) {
            if (!isPemainTerdaftar(tempList, P->info.idPemain)) {
                cout << "- " << P->info.idPemain << " | " << P->info.namaPemain;
                cout << " | Ranking: " << P->info.ranking << endl;
                adrPemain baru = createElmPemain(P->info);
                insertLastPemain((adrTurnamen&)tempList.first, baru);
            }
            P = P->next;
        }
        T = T->next;
    }
}

int totalSemuaPemain(List L) {
    int total = 0;
    adrTurnamen T = L.first;

    while (T != NULL) {
        total += countPemain(T);
        T = T->next;
    }

    return total;
}
