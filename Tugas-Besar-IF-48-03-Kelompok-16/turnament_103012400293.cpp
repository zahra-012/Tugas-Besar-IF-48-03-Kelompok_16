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

    // Array sederhana untuk menyimpan ID pemain yang sudah ditampilkan
    string idSudahAda[100];
    int jumlahUnik = 0;

    adrTurnamen T = L.first;
    while (T != NULL) {
        adrPemain P = T->firstPemain;
        while (P != NULL) {
            // Cek apakah ID sudah ada
            bool sudahAda = false;
            for (int i = 0; i < jumlahUnik; i++) {
                if (idSudahAda[i] == P->info.idPemain) {
                    sudahAda = true;
                    break;
                }
            }

            // Jika belum ada, tampilkan dan tambahkan ke array
            if (!sudahAda && jumlahUnik < 100) {
                cout << "- " << P->info.idPemain << " | " << P->info.namaPemain
                     << " | Ranking: " << P->info.ranking << endl;
                idSudahAda[jumlahUnik] = P->info.idPemain;
                jumlahUnik++;
            }

            P = P->next;
        }
        T = T->next;
    }

    if (jumlahUnik == 0) {
        cout << "(Belum ada pemain)\n";
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

int countTotalTurnamen(List L) {
    int total = 0;
    adrTurnamen T = L.first;

    while (T != NULL) {
        total++;
        T = T->next;
    }

    return total;
}
