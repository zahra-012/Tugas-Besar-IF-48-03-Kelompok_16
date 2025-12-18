#include "header.h"

void menuParent(List &L);
void menuChild(List &L);
void menuLaporan(List &L);
void menuStatistikPemain(List &L);

void menuAdmin(List &L) {
    int option;
    do {
        system("cls");
        cout << "============ MENU ADMIN ============\n";
        cout << "1. Menu Turnamen\n";
        cout << "2. Menu Pemain\n";
        cout << "3. Menu Statistik Pemain (Poin/Menang/Kalah)\n";
        cout << "4. Menu Laporan & Statistik\n";
        cout << "0. Kembali\n";
        cout << "===================================\n";
        cout << "Pilih menu: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1:
                menuParent(L);
                break;
            case 2:
                menuChild(L);
                break;
            case 3:
                menuStatistikPemain(L);
                break;
            case 4:
                menuLaporan(L);
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                system("pause");
        }
    } while (option != 0);
}

void menuParent(List &L) {
    int option;
    dataTurnamen dt;
    adrTurnamen T, Prec;
    string idHapus, idPrec;

    do {
        system("cls");
        cout << "========= MENU TURNAMEN =========\n";
        cout << "1. Insert First Turnamen\n";
        cout << "2. Insert Last Turnamen\n";
        cout << "3. Insert After Turnamen\n";
        cout << "4. Delete First Turnamen\n";
        cout << "5. Delete Last Turnamen\n";
        cout << "6. Delete After Turnamen\n";
        cout << "7. Hapus Turnamen (By ID)\n";
        cout << "8. Tampilkan Semua Turnamen\n";
        cout << "0. Kembali\n";
        cout << "================================\n";
        cout << "Pilih menu: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: {
                cout << "\n--- Tambah Turnamen (First) ---\n";
                cout << "ID Turnamen    : ";
                cin >> dt.idTurnamen;

                if (findTurnamen(L, dt.idTurnamen) != NULL) {
                    cout << "Error: ID Turnamen sudah ada!\n";
                    system("pause");
                    break;
                }

                cin.ignore();
                cout << "Nama Turnamen  : ";
                getline(cin, dt.namaTurnamen);
                cout << "Lokasi         : ";
                getline(cin, dt.lokasi);
                cout << "Tahun          : ";
                cin >> dt.tahun;

                T = createElmTurnamen(dt);
                insertFirstTurnamen(L, T);
                cout << "Turnamen berhasil ditambahkan di awal!\n";
                system("pause");
                break;
            }

            case 2: {
                cout << "\n--- Tambah Turnamen (Last) ---\n";
                cout << "ID Turnamen    : ";
                cin >> dt.idTurnamen;

                if (findTurnamen(L, dt.idTurnamen) != NULL) {
                    cout << "Error: ID Turnamen sudah ada!\n";
                    system("pause");
                    break;
                }

                cin.ignore();
                cout << "Nama Turnamen  : ";
                getline(cin, dt.namaTurnamen);
                cout << "Lokasi         : ";
                getline(cin, dt.lokasi);
                cout << "Tahun          : ";
                cin >> dt.tahun;

                T = createElmTurnamen(dt);
                insertLastTurnamen(L, T);
                cout << "Turnamen berhasil ditambahkan di akhir!\n";
                system("pause");
                break;
            }

            case 3: {
                cout << "\n--- Tambah Turnamen (After) ---\n";

                if (L.first == NULL) {
                    cout << "List turnamen masih kosong! Gunakan Insert First/Last.\n";
                    system("pause");
                    break;
                }

                cout << "Daftar Turnamen:\n";
                showAllData(L);

                cout << "\nID Turnamen Predecessor (setelah turnamen ini): ";
                cin >> idPrec;

                Prec = findTurnamen(L, idPrec);
                if (Prec == NULL) {
                    cout << "Error: Turnamen predecessor tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                cout << "\n--- Data Turnamen Baru ---\n";
                cout << "ID Turnamen    : ";
                cin >> dt.idTurnamen;

                if (findTurnamen(L, dt.idTurnamen) != NULL) {
                    cout << "Error: ID Turnamen sudah ada!\n";
                    system("pause");
                    break;
                }

                cin.ignore();
                cout << "Nama Turnamen  : ";
                getline(cin, dt.namaTurnamen);
                cout << "Lokasi         : ";
                getline(cin, dt.lokasi);
                cout << "Tahun          : ";
                cin >> dt.tahun;

                T = createElmTurnamen(dt);
                insertAfterTurnamen(Prec, T);
                cout << "Turnamen berhasil ditambahkan setelah " << Prec->info.namaTurnamen << "!\n";
                system("pause");
                break;
            }

            case 4: {
                cout << "\n--- Hapus Turnamen (First) ---\n";

                if (L.first == NULL) {
                    cout << "List turnamen kosong!\n";
                    system("pause");
                    break;
                }

                cout << "Turnamen yang akan dihapus: " << L.first->info.namaTurnamen << "\n";
                cout << "Apakah Anda yakin? (y/n): ";
                char konfirmasi;
                cin >> konfirmasi;

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    deleteFirstTurnamen(L, T);
                    cout << "Turnamen berhasil dihapus dari awal!\n";
                    delete T;
                } else {
                    cout << "Penghapusan dibatalkan.\n";
                }
                system("pause");
                break;
            }

            case 5: {
                cout << "\n--- Hapus Turnamen (Last) ---\n";

                if (L.first == NULL) {
                    cout << "List turnamen kosong!\n";
                    system("pause");
                    break;
                }

                adrTurnamen last = L.first;
                while (last->next != NULL) {
                    last = last->next;
                }

                cout << "Turnamen yang akan dihapus: " << last->info.namaTurnamen << "\n";
                cout << "Apakah Anda yakin? (y/n): ";
                char konfirmasi;
                cin >> konfirmasi;

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    deleteLastTurnamen(L, T);
                    cout << "Turnamen berhasil dihapus dari akhir!\n";
                    delete T;
                } else {
                    cout << "Penghapusan dibatalkan.\n";
                }
                system("pause");
                break;
            }

            case 6: {
                cout << "\n--- Hapus Turnamen (After) ---\n";

                if (L.first == NULL || L.first->next == NULL) {
                    cout << "Tidak ada turnamen yang bisa dihapus dengan metode After!\n";
                    system("pause");
                    break;
                }

                cout << "Daftar Turnamen:\n";
                showAllData(L);

                cout << "\nID Turnamen Predecessor (hapus turnamen setelah ini): ";
                cin >> idPrec;

                Prec = findTurnamen(L, idPrec);
                if (Prec == NULL) {
                    cout << "Error: Turnamen predecessor tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                if (Prec->next == NULL) {
                    cout << "Error: Tidak ada turnamen setelah " << Prec->info.namaTurnamen << "!\n";
                    system("pause");
                    break;
                }

                cout << "Turnamen yang akan dihapus: " << Prec->next->info.namaTurnamen << "\n";
                cout << "Apakah Anda yakin? (y/n): ";
                char konfirmasi;
                cin >> konfirmasi;

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    deleteAfterTurnamen(Prec, T);
                    cout << "Turnamen berhasil dihapus!\n";
                    delete T;
                } else {
                    cout << "Penghapusan dibatalkan.\n";
                }
                system("pause");
                break;
            }

            case 7: {
                cout << "\n--- Hapus Turnamen (By ID) ---\n";
                cout << "ID Turnamen yang akan dihapus: ";
                cin >> idHapus;
                hapusTurnamen(L, idHapus);
                system("pause");
                break;
            }

            case 8: {
                showAllData(L);
                system("pause");
                break;
            }

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                system("pause");
        }
    } while (option != 0);
}

void menuChild(List &L) {
    int option;
    string idTurnamen, idPemain, idPrec;
    dataPemain dp;
    adrTurnamen T;
    adrPemain P, Prec;

    do {
        system("cls");
        cout << "=========== MENU PEMAIN ===========\n";
        cout << "1. Insert First Pemain\n";
        cout << "2. Insert Last Pemain\n";
        cout << "3. Insert After Pemain\n";
        cout << "4. Delete First Pemain\n";
        cout << "5. Delete Last Pemain\n";
        cout << "6. Delete After Pemain\n";
        cout << "7. Hapus Pemain (By ID)\n";
        cout << "8. Tampilkan Pemain Turnamen\n";
        cout << "0. Kembali\n";
        cout << "==================================\n";
        cout << "Pilih menu: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: {
                cout << "\n--- Tambah Pemain (First) ---\n";
                cout << "ID Turnamen : ";
                cin >> idTurnamen;
                T = findTurnamen(L, idTurnamen);

                if (T != NULL) {
                    cout << "ID Pemain   : ";
                    cin >> dp.idPemain;

                    if (findPemain(T, dp.idPemain) != NULL) {
                        cout << "Error: Pemain sudah terdaftar di turnamen ini!\n";
                        system("pause");
                        break;
                    }

                    cin.ignore();
                    cout << "Nama Pemain : ";
                    getline(cin, dp.namaPemain);
                    cout << "Ranking     : ";
                    cin >> dp.ranking;

                    dp.menang = 0;
                    dp.kalah = 0;
                    dp.poin = 0;

                    P = createElmPemain(dp);
                    insertFirstPemain(T, P);
                    cout << "Pemain berhasil ditambahkan di awal!\n";
                } else {
                    cout << "Turnamen tidak ditemukan!\n";
                }
                system("pause");
                break;
            }

            case 2: {
                cout << "\n--- Tambah Pemain (Last) ---\n";
                cout << "ID Turnamen : ";
                cin >> idTurnamen;
                T = findTurnamen(L, idTurnamen);

                if (T != NULL) {
                    cout << "ID Pemain   : ";
                    cin >> dp.idPemain;

                    if (findPemain(T, dp.idPemain) != NULL) {
                        cout << "Error: Pemain sudah terdaftar di turnamen ini!\n";
                        system("pause");
                        break;
                    }

                    cin.ignore();
                    cout << "Nama Pemain : ";
                    getline(cin, dp.namaPemain);
                    cout << "Ranking     : ";
                    cin >> dp.ranking;

                    dp.menang = 0;
                    dp.kalah = 0;
                    dp.poin = 0;

                    P = createElmPemain(dp);
                    insertLastPemain(T, P);
                    cout << "Pemain berhasil ditambahkan di akhir!\n";
                } else {
                    cout << "Turnamen tidak ditemukan!\n";
                }
                system("pause");
                break;
            }

            case 3: {
                cout << "\n--- Tambah Pemain (After) ---\n";
                cout << "ID Turnamen : ";
                cin >> idTurnamen;
                T = findTurnamen(L, idTurnamen);

                if (T == NULL) {
                    cout << "Turnamen tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                if (T->firstPemain == NULL) {
                    cout << "List pemain masih kosong! Gunakan Insert First/Last.\n";
                    system("pause");
                    break;
                }

                cout << "\nDaftar Pemain:\n";
                showPemain(T);

                cout << "\nID Pemain Predecessor (setelah pemain ini): ";
                cin >> idPrec;

                Prec = findPemain(T, idPrec);
                if (Prec == NULL) {
                    cout << "Error: Pemain predecessor tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                cout << "\n--- Data Pemain Baru ---\n";
                cout << "ID Pemain   : ";
                cin >> dp.idPemain;

                if (findPemain(T, dp.idPemain) != NULL) {
                    cout << "Error: Pemain sudah terdaftar di turnamen ini!\n";
                    system("pause");
                    break;
                }

                cin.ignore();
                cout << "Nama Pemain : ";
                getline(cin, dp.namaPemain);
                cout << "Ranking     : ";
                cin >> dp.ranking;

                dp.menang = 0;
                dp.kalah = 0;
                dp.poin = 0;

                P = createElmPemain(dp);
                insertAfterPemain(T, Prec, P);
                cout << "Pemain berhasil ditambahkan setelah " << Prec->info.namaPemain << "!\n";
                system("pause");
                break;
            }

            case 4: {
                cout << "\n--- Hapus Pemain (First) ---\n";
                cout << "ID Turnamen : ";
                cin >> idTurnamen;
                T = findTurnamen(L, idTurnamen);

                if (T == NULL) {
                    cout << "Turnamen tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                if (T->firstPemain == NULL) {
                    cout << "List pemain kosong!\n";
                    system("pause");
                    break;
                }

                cout << "Pemain yang akan dihapus: " << T->firstPemain->info.namaPemain << "\n";
                cout << "Apakah Anda yakin? (y/n): ";
                char konfirmasi;
                cin >> konfirmasi;

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    deleteFirstPemain(T, P);
                    cout << "Pemain berhasil dihapus dari awal!\n";
                    delete P;
                } else {
                    cout << "Penghapusan dibatalkan.\n";
                }
                system("pause");
                break;
            }

            case 5: {
                cout << "\n--- Hapus Pemain (Last) ---\n";
                cout << "ID Turnamen : ";
                cin >> idTurnamen;
                T = findTurnamen(L, idTurnamen);

                if (T == NULL) {
                    cout << "Turnamen tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                if (T->firstPemain == NULL) {
                    cout << "List pemain kosong!\n";
                    system("pause");
                    break;
                }

                adrPemain last = T->firstPemain;
                while (last->next != NULL) {
                    last = last->next;
                }

                cout << "Pemain yang akan dihapus: " << last->info.namaPemain << "\n";
                cout << "Apakah Anda yakin? (y/n): ";
                char konfirmasi;
                cin >> konfirmasi;

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    deleteLastPemain(T, P);
                    cout << "Pemain berhasil dihapus dari akhir!\n";
                    delete P;
                } else {
                    cout << "Penghapusan dibatalkan.\n";
                }
                system("pause");
                break;
            }

            case 6: {
                cout << "\n--- Hapus Pemain (After) ---\n";
                cout << "ID Turnamen : ";
                cin >> idTurnamen;
                T = findTurnamen(L, idTurnamen);

                if (T == NULL) {
                    cout << "Turnamen tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                if (T->firstPemain == NULL || T->firstPemain->next == NULL) {
                    cout << "Tidak ada pemain yang bisa dihapus dengan metode After!\n";
                    system("pause");
                    break;
                }

                cout << "\nDaftar Pemain:\n";
                showPemain(T);

                cout << "\nID Pemain Predecessor (hapus pemain setelah ini): ";
                cin >> idPrec;

                Prec = findPemain(T, idPrec);
                if (Prec == NULL) {
                    cout << "Error: Pemain predecessor tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                if (Prec->next == NULL) {
                    cout << "Error: Tidak ada pemain setelah " << Prec->info.namaPemain << "!\n";
                    system("pause");
                    break;
                }

                cout << "Pemain yang akan dihapus: " << Prec->next->info.namaPemain << "\n";
                cout << "Apakah Anda yakin? (y/n): ";
                char konfirmasi;
                cin >> konfirmasi;

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    deleteAfterPemain(T, Prec, P);
                    cout << "Pemain berhasil dihapus!\n";
                    delete P;
                } else {
                    cout << "Penghapusan dibatalkan.\n";
                }
                system("pause");
                break;
            }

            case 7: {
                cout << "\n--- Hapus Pemain (By ID) ---\n";
                cout << "ID Turnamen : ";
                cin >> idTurnamen;
                cout << "ID Pemain   : ";
                cin >> idPemain;

                hapusPemainDariTurnamen(L, idTurnamen, idPemain);
                system("pause");
                break;
            }

            case 8: {
                cout << "\n--- Tampilkan Pemain ---\n";
                cout << "ID Turnamen : ";
                cin >> idTurnamen;
                T = findTurnamen(L, idTurnamen);

                if (T != NULL) {
                    cout << "\nTurnamen: " << T->info.namaTurnamen << "\n";
                    cout << "Jumlah Pemain: " << countPemain(T) << "\n";
                    cout << "----------------------------\n";
                    showPemain(T);
                } else {
                    cout << "Turnamen tidak ditemukan!\n";
                }
                system("pause");
                break;
            }

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                system("pause");
        }
    } while (option != 0);
}

void menuStatistikPemain(List &L) {
    int option;
    string idTurnamen, idPemain;
    adrTurnamen T;
    adrPemain P;

    do {
        system("cls");
        cout << "====== MENU STATISTIK PEMAIN ======\n";
        cout << "1. Update Poin Pemain\n";
        cout << "2. Update Menang/Kalah Pemain\n";
        cout << "3. Input Hasil Pertandingan\n";
        cout << "4. Lihat Detail Statistik Pemain\n";
        cout << "0. Kembali\n";
        cout << "===================================\n";
        cout << "Pilih menu: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: {
                cout << "\n--- Update Poin Pemain ---\n";
                cout << "ID Turnamen : ";
                cin >> idTurnamen;
                cout << "ID Pemain   : ";
                cin >> idPemain;

                T = findTurnamen(L, idTurnamen);
                if (T == NULL) {
                    cout << "Turnamen tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                P = findPemain(T, idPemain);
                if (P == NULL) {
                    cout << "Pemain tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                cout << "\nData Saat Ini:\n";
                cout << "Nama  : " << P->info.namaPemain << "\n";
                cout << "Poin  : " << P->info.poin << "\n";

                int poinBaru;
                cout << "\nMasukkan Poin Baru: ";
                cin >> poinBaru;

                P->info.poin = poinBaru;
                cout << "\nPoin berhasil diupdate!\n";
                system("pause");
                break;
            }

            case 2: {
                cout << "\n--- Update Menang/Kalah Pemain ---\n";
                cout << "ID Turnamen : ";
                cin >> idTurnamen;
                cout << "ID Pemain   : ";
                cin >> idPemain;

                T = findTurnamen(L, idTurnamen);
                if (T == NULL) {
                    cout << "Turnamen tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                P = findPemain(T, idPemain);
                if (P == NULL) {
                    cout << "Pemain tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                cout << "\nData Saat Ini:\n";
                cout << "Nama   : " << P->info.namaPemain << "\n";
                cout << "Menang : " << P->info.menang << "\n";
                cout << "Kalah  : " << P->info.kalah << "\n";

                int menangBaru, kalahBaru;
                cout << "\nMasukkan Jumlah Menang: ";
                cin >> menangBaru;
                cout << "Masukkan Jumlah Kalah : ";
                cin >> kalahBaru;

                P->info.menang = menangBaru;
                P->info.kalah = kalahBaru;

                cout << "\nStatistik berhasil diupdate!\n";
                system("pause");
                break;
            }

            case 3: {
                cout << "\n--- Input Hasil Pertandingan ---\n";
                cout << "ID Turnamen     : ";
                cin >> idTurnamen;

                T = findTurnamen(L, idTurnamen);
                if (T == NULL) {
                    cout << "Turnamen tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                string idPemain1, idPemain2;
                cout << "ID Pemain 1     : ";
                cin >> idPemain1;
                cout << "ID Pemain 2     : ";
                cin >> idPemain2;

                adrPemain P1 = findPemain(T, idPemain1);
                adrPemain P2 = findPemain(T, idPemain2);

                if (P1 == NULL || P2 == NULL) {
                    cout << "Salah satu atau kedua pemain tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                cout << "\n" << P1->info.namaPemain << " vs " << P2->info.namaPemain << "\n";
                cout << "Siapa yang menang?\n";
                cout << "1. " << P1->info.namaPemain << "\n";
                cout << "2. " << P2->info.namaPemain << "\n";
                cout << "Pilihan: ";

                int pemenang;
                cin >> pemenang;

                if (pemenang == 1) {
                    P1->info.menang++;
                    P1->info.poin += 3;
                    P2->info.kalah++;
                    cout << "\n" << P1->info.namaPemain << " menang! (+3 poin)\n";
                } else if (pemenang == 2) {
                    P2->info.menang++;
                    P2->info.poin += 3;
                    P1->info.kalah++;
                    cout << "\n" << P2->info.namaPemain << " menang! (+3 poin)\n";
                } else {
                    cout << "Pilihan tidak valid!\n";
                }

                system("pause");
                break;
            }

            case 4: {
                cout << "\n--- Detail Statistik Pemain ---\n";
                cout << "ID Turnamen : ";
                cin >> idTurnamen;
                cout << "ID Pemain   : ";
                cin >> idPemain;

                T = findTurnamen(L, idTurnamen);
                if (T == NULL) {
                    cout << "Turnamen tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                P = findPemain(T, idPemain);
                if (P == NULL) {
                    cout << "Pemain tidak ditemukan!\n";
                    system("pause");
                    break;
                }

                printPemainDetail(P);
                cout << "Turnamen: " << T->info.namaTurnamen << "\n";

                system("pause");
                break;
            }

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                system("pause");
        }
    } while (option != 0);
}

void menuLaporan(List &L) {
    int option;
    adrTurnamen T;
    adrPemain P;

    do {
        system("cls");
        cout << "====== MENU LAPORAN & STATISTIK ======\n";
        cout << "1. Tampilkan Semua Pemain Unik\n";
        cout << "2. Total Semua Pemain (Duplikat)\n";
        cout << "3. Turnamen Teramai\n";
        cout << "4. Pemain Terbaik\n";
        cout << "0. Kembali\n";
        cout << "======================================\n";
        cout << "Pilih menu: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: {
                showAllPemainUnik(L);
                system("pause");
                break;
            }

            case 2: {
                cout << "\nTotal semua pemain (termasuk duplikat): "
                     << totalSemuaPemain(L) << " pemain\n";
                system("pause");
                break;
            }

            case 3: {
                T = findTurnamenTeramai(L);
                if (T != NULL) {
                    cout << "\n=== TURNAMEN TERAMAI ===\n";
                    cout << "ID         : " << T->info.idTurnamen << "\n";
                    cout << "Nama       : " << T->info.namaTurnamen << "\n";
                    cout << "Lokasi     : " << T->info.lokasi << "\n";
                    cout << "Tahun      : " << T->info.tahun << "\n";
                    cout << "Jumlah     : " << countPemain(T) << " pemain\n";
                } else {
                    cout << "Belum ada turnamen.\n";
                }
                system("pause");
                break;
            }

            case 4: {
                P = findPemainTerbaik(L);
                if (P != NULL) {
                    cout << "\n=== PEMAIN TERBAIK ===\n";
                    printPemainDetail(P);
                } else {
                    cout << "Belum ada pemain.\n";
                }
                system("pause");
                break;
            }

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                system("pause");
        }
    } while (option != 0);
}
