#include "header.h"

void studiKasus1(List &L);
void studiKasus2(List &L);
void studiKasus3(List &L);
void studiKasus4(List &L);
void studiKasus5(List &L);
void loadDataDummy(List &L);

void loadDataDummy(List &L) {
    // Data Dummy Turnamen 1
    dataTurnamen dt1;
    dt1.idTurnamen = "T001";
    dt1.namaTurnamen = "Australian Open 2024";
    dt1.lokasi = "Melbourne, Australia";
    dt1.tahun = 2024;
    adrTurnamen T1 = createElmTurnamen(dt1);
    insertLastTurnamen(L, T1);

    // Pemain untuk Turnamen 1
    dataPemain dp1;
    dp1.idPemain = "P001";
    dp1.namaPemain = "Novak Djokovic";
    dp1.ranking = 1;
    dp1.poin = 9850;
    dp1.menang = 45;
    dp1.kalah = 5;
    insertLastPemain(T1, createElmPemain(dp1));

    dataPemain dp2;
    dp2.idPemain = "P002";
    dp2.namaPemain = "Carlos Alcaraz";
    dp2.ranking = 2;
    dp2.poin = 8850;
    dp2.menang = 42;
    dp2.kalah = 8;
    insertLastPemain(T1, createElmPemain(dp2));

    dataPemain dp3;
    dp3.idPemain = "P003";
    dp3.namaPemain = "Daniil Medvedev";
    dp3.ranking = 3;
    dp3.poin = 7700;
    dp3.menang = 38;
    dp3.kalah = 10;
    insertLastPemain(T1, createElmPemain(dp3));

    dataPemain dp4;
    dp4.idPemain = "P004";
    dp4.namaPemain = "Jannik Sinner";
    dp4.ranking = 4;
    dp4.poin = 7200;
    dp4.menang = 40;
    dp4.kalah = 12;
    insertLastPemain(T1, createElmPemain(dp4));

    // Data Dummy Turnamen 2
    dataTurnamen dt2;
    dt2.idTurnamen = "T002";
    dt2.namaTurnamen = "French Open 2024";
    dt2.lokasi = "Paris, France";
    dt2.tahun = 2024;
    adrTurnamen T2 = createElmTurnamen(dt2);
    insertLastTurnamen(L, T2);

    // Pemain untuk Turnamen 2
    dataPemain dp5;
    dp5.idPemain = "P001";
    dp5.namaPemain = "Novak Djokovic";
    dp5.ranking = 1;
    dp5.poin = 10500;
    dp5.menang = 48;
    dp5.kalah = 5;
    insertLastPemain(T2, createElmPemain(dp5));

    dataPemain dp6;
    dp6.idPemain = "P003";
    dp6.namaPemain = "Daniil Medvedev";
    dp6.ranking = 3;
    dp6.poin = 8200;
    dp6.menang = 41;
    dp6.kalah = 11;
    insertLastPemain(T2, createElmPemain(dp6));

    dataPemain dp7;
    dp7.idPemain = "P005";
    dp7.namaPemain = "Rafael Nadal";
    dp7.ranking = 5;
    dp7.poin = 6800;
    dp7.menang = 35;
    dp7.kalah = 8;
    insertLastPemain(T2, createElmPemain(dp7));

    dataPemain dp8;
    dp8.idPemain = "P006";
    dp8.namaPemain = "Alexander Zverev";
    dp8.ranking = 6;
    dp8.poin = 6500;
    dp8.menang = 36;
    dp8.kalah = 14;
    insertLastPemain(T2, createElmPemain(dp8));

    dataPemain dp9;
    dp9.idPemain = "P007";
    dp9.namaPemain = "Stefanos Tsitsipas";
    dp9.ranking = 7;
    dp9.poin = 6200;
    dp9.menang = 34;
    dp9.kalah = 15;
    insertLastPemain(T2, createElmPemain(dp9));

    // Data Dummy Turnamen 3
    dataTurnamen dt3;
    dt3.idTurnamen = "T003";
    dt3.namaTurnamen = "Wimbledon 2024";
    dt3.lokasi = "London, England";
    dt3.tahun = 2024;
    adrTurnamen T3 = createElmTurnamen(dt3);
    insertLastTurnamen(L, T3);

    // Pemain untuk Turnamen 3
    dataPemain dp10;
    dp10.idPemain = "P002";
    dp10.namaPemain = "Carlos Alcaraz";
    dp10.ranking = 2;
    dp10.poin = 9500;
    dp10.menang = 46;
    dp10.kalah = 8;
    insertLastPemain(T3, createElmPemain(dp10));

    dataPemain dp11;
    dp11.idPemain = "P004";
    dp11.namaPemain = "Jannik Sinner";
    dp11.ranking = 4;
    dp11.poin = 7800;
    dp11.menang = 43;
    dp11.kalah = 13;
    insertLastPemain(T3, createElmPemain(dp11));

    dataPemain dp12;
    dp12.idPemain = "P008";
    dp12.namaPemain = "Holger Rune";
    dp12.ranking = 8;
    dp12.poin = 5800;
    dp12.menang = 30;
    dp12.kalah = 12;
    insertLastPemain(T3, createElmPemain(dp12));

    // Data Dummy Turnamen 4
    dataTurnamen dt4;
    dt4.idTurnamen = "T004";
    dt4.namaTurnamen = "US Open 2024";
    dt4.lokasi = "New York, USA";
    dt4.tahun = 2024;
    adrTurnamen T4 = createElmTurnamen(dt4);
    insertLastTurnamen(L, T4);

    // Pemain untuk Turnamen 4
    dataPemain dp13;
    dp13.idPemain = "P001";
    dp13.namaPemain = "Novak Djokovic";
    dp13.ranking = 1;
    dp13.poin = 11000;
    dp13.menang = 52;
    dp13.kalah = 6;
    insertLastPemain(T4, createElmPemain(dp13));

    dataPemain dp14;
    dp14.idPemain = "P002";
    dp14.namaPemain = "Carlos Alcaraz";
    dp14.ranking = 2;
    dp14.poin = 10200;
    dp14.menang = 50;
    dp14.kalah = 9;
    insertLastPemain(T4, createElmPemain(dp14));

    dataPemain dp15;
    dp15.idPemain = "P005";
    dp15.namaPemain = "Rafael Nadal";
    dp15.ranking = 5;
    dp15.poin = 7500;
    dp15.menang = 38;
    dp15.kalah = 10;
    insertLastPemain(T4, createElmPemain(dp15));

    dataPemain dp16;
    dp16.idPemain = "P009";
    dp16.namaPemain = "Taylor Fritz";
    dp16.ranking = 9;
    dp16.poin = 5500;
    dp16.menang = 28;
    dp16.kalah = 11;
    insertLastPemain(T4, createElmPemain(dp16));

    dataPemain dp17;
    dp17.idPemain = "P010";
    dp17.namaPemain = "Frances Tiafoe";
    dp17.ranking = 10;
    dp17.poin = 5200;
    dp17.menang = 26;
    dp17.kalah = 13;
    insertLastPemain(T4, createElmPemain(dp17));

    cout << "\n========================================\n";
    cout << "  DATA DUMMY BERHASIL DIMUAT!\n";
    cout << "========================================\n";
    cout << "Total Turnamen : 4\n";
    cout << "Total Pemain   : 10 (unik)\n";
    cout << "========================================\n";
    cout << "\nDaftar Turnamen:\n";
    cout << "1. Australian Open 2024 (4 pemain)\n";
    cout << "2. French Open 2024 (5 pemain)\n";
    cout << "3. Wimbledon 2024 (3 pemain)\n";
    cout << "4. US Open 2024 (5 pemain)\n";
    cout << "========================================\n";
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void menuUtama(List &L) {
    int option = -99;

    while (option != 0) {
        system("cls");
        cout << "============================================\n";
        cout << "||   SISTEM MANAJEMEN TURNAMEN BADMINTON  ||\n";
        cout << "============================================\n";
        cout << "|| 1. Menu Admin                          ||\n";
        cout << "|| 2. Menu User (Studi Kasus)             ||\n";
        cout << "|| 3. Load Data Dummy                     ||\n";
        cout << "|| 0. Keluar                              ||\n";
        cout << "============================================\n";
        cout << "Pilih menu: ";
        cin >> option;

        switch(option) {
            case 1:
                menuAdmin(L);
                break;
            case 2:
                menuUser(L);
                break;
            case 3:
                loadDataDummy(L);
                break;
            case 0:
                cout << "\nTerima kasih telah menggunakan sistem ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                system("pause");
        }
    }
}

void menuUser(List &L) {
    int option = -99;

    while (option != 0) {
        system("cls");
        cout << "========================================\n";
        cout << "||        MENU STUDI KASUS           ||\n";
        cout << "========================================\n";
        cout << "|| 1. Lihat Semua Data Turnamen      ||\n";
        cout << "|| 2. Cari Turnamen Berdasarkan ID   ||\n";
        cout << "|| 3. Cari Pemain di Turnamen        ||\n";
        cout << "|| 4. Statistik Turnamen             ||\n";
        cout << "|| 5. Ranking Pemain                 ||\n";
        cout << "|| 0. Kembali                        ||\n";
        cout << "========================================\n";
        cout << "Pilih menu: ";
        cin >> option;

        switch(option) {
            case 1:
                studiKasus1(L);
                break;
            case 2:
                studiKasus2(L);
                break;
            case 3:
                studiKasus3(L);
                break;
            case 4:
                studiKasus4(L);
                break;
            case 5:
                studiKasus5(L);
                break;
            case 0:
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                system("pause");
        }
    }
}

// Studi Kasus 1: Lihat Semua Data Turnamen
void studiKasus1(List &L) {
    system("cls");
    cout << "========================================\n";
    cout << "   STUDI KASUS 1: LIHAT SEMUA DATA\n";
    cout << "========================================\n\n";

    if (L.first == NULL) {
        cout << "Belum ada data turnamen!\n";
    } else {
        showAllData(L);

        cout << "\n--- STATISTIK UMUM ---\n";
        cout << "Total Turnamen       : " << countTotalTurnamen(L) << "\n";
        cout << "Total Pemain (All)   : " << totalSemuaPemain(L) << "\n";

        adrTurnamen teramai = findTurnamenTeramai(L);
        if (teramai != NULL) {
            cout << "Turnamen Teramai     : " << teramai->info.namaTurnamen
                 << " (" << countPemain(teramai) << " pemain)\n";
        }
    }

    cout << "\n";
    system("pause");
}

// Studi Kasus 2: Cari Turnamen Berdasarkan ID
void studiKasus2(List &L) {
    system("cls");
    cout << "========================================\n";
    cout << "   STUDI KASUS 2: CARI TURNAMEN\n";
    cout << "========================================\n\n";

    string idCari;
    cout << "Masukkan ID Turnamen: ";
    cin >> idCari;

    adrTurnamen T = findTurnamen(L, idCari);

    if (T != NULL) {
        cout << "\n--- TURNAMEN DITEMUKAN ---\n";
        cout << "ID Turnamen    : " << T->info.idTurnamen << "\n";
        cout << "Nama Turnamen  : " << T->info.namaTurnamen << "\n";
        cout << "Lokasi         : " << T->info.lokasi << "\n";
        cout << "Tahun          : " << T->info.tahun << "\n";
        cout << "Jumlah Pemain  : " << countPemain(T) << "\n";

        cout << "\n--- DAFTAR PEMAIN ---\n";
        showPemain(T);

        // Cari pemain terbaik di turnamen ini
        adrPemain terbaik = NULL;
        adrPemain P = T->firstPemain;
        while (P != NULL) {
            if (terbaik == NULL || P->info.poin > terbaik->info.poin) {
                terbaik = P;
            }
            P = P->next;
        }

        if (terbaik != NULL) {
            cout << "\n--- PEMAIN TERBAIK DI TURNAMEN INI ---\n";
            cout << "Nama: " << terbaik->info.namaPemain
                 << " (Poin: " << terbaik->info.poin << ")\n";
        }
    } else {
        cout << "\nTurnamen dengan ID '" << idCari << "' tidak ditemukan!\n";
    }

    cout << "\n";
    system("pause");
}

// Studi Kasus 3: Cari Pemain di Turnamen
void studiKasus3(List &L) {
    system("cls");
    cout << "========================================\n";
    cout << "   STUDI KASUS 3: CARI PEMAIN\n";
    cout << "========================================\n\n";

    string idTurnamen, idPemain;
    cout << "Masukkan ID Turnamen: ";
    cin >> idTurnamen;

    adrTurnamen T = findTurnamen(L, idTurnamen);

    if (T == NULL) {
        cout << "Turnamen tidak ditemukan!\n";
    } else {
        cout << "Masukkan ID Pemain: ";
        cin >> idPemain;

        adrPemain P = findPemain(T, idPemain);

        if (P != NULL) {
            cout << "\n--- PEMAIN DITEMUKAN ---\n";
            cout << "ID Pemain      : " << P->info.idPemain << "\n";
            cout << "Nama Pemain    : " << P->info.namaPemain << "\n";
            cout << "Ranking        : " << P->info.ranking << "\n";
            cout << "Poin           : " << P->info.poin << "\n";
            cout << "Menang         : " << P->info.menang << "\n";
            cout << "Kalah          : " << P->info.kalah << "\n";

            // Hitung win rate
            int totalMatch = P->info.menang + P->info.kalah;
            if (totalMatch > 0) {
                float winRate = (float)P->info.menang / totalMatch * 100;
                cout << "Win Rate       : " << winRate << "%\n";
            }

            cout << "\nTurnamen       : " << T->info.namaTurnamen << "\n";
        } else {
            cout << "\nPemain dengan ID '" << idPemain << "' tidak ditemukan di turnamen ini!\n";
        }
    }

    cout << "\n";
    system("pause");
}

// Studi Kasus 4: Statistik Turnamen
void studiKasus4(List &L) {
    system("cls");
    cout << "========================================\n";
    cout << "   STUDI KASUS 4: STATISTIK TURNAMEN\n";
    cout << "========================================\n\n";

    if (L.first == NULL) {
        cout << "Belum ada data turnamen!\n";
    } else {
        // 1. Total Turnamen
        int totalTurnamen = 0;
        adrTurnamen T = L.first;
        while (T != NULL) {
            totalTurnamen++;
            T = T->next;
        }

        // 2. Total Pemain (duplikat)
        int totalPemainDuplikat = totalSemuaPemain(L);

        // 3. Turnamen Teramai
        adrTurnamen teramai = findTurnamenTeramai(L);

        // 4. Pemain Terbaik
        adrPemain terbaik = findPemainTerbaik(L);

        // 5. Rata-rata pemain per turnamen
        float rataRata = (totalTurnamen > 0) ? (float)totalPemainDuplikat / totalTurnamen : 0;

        cout << "--- STATISTIK UMUM ---\n";
        cout << "Total Turnamen              : " << totalTurnamen << "\n";
        cout << "Total Pemain (All)          : " << totalPemainDuplikat << "\n";
        cout << "Rata-rata Pemain/Turnamen   : " << rataRata << "\n\n";

        if (teramai != NULL) {
            cout << "--- TURNAMEN TERAMAI ---\n";
            cout << "Nama         : " << teramai->info.namaTurnamen << "\n";
            cout << "Lokasi       : " << teramai->info.lokasi << "\n";
            cout << "Jumlah Pemain: " << countPemain(teramai) << "\n\n";
        }

        if (terbaik != NULL) {
            cout << "--- PEMAIN TERBAIK (POIN TERTINGGI) ---\n";
            cout << "ID           : " << terbaik->info.idPemain << "\n";
            cout << "Nama         : " << terbaik->info.namaPemain << "\n";
            cout << "Ranking      : " << terbaik->info.ranking << "\n";
            cout << "Poin         : " << terbaik->info.poin << "\n";
            cout << "Menang/Kalah : " << terbaik->info.menang << "/" << terbaik->info.kalah << "\n\n";
        }

        cout << "--- DAFTAR SEMUA PEMAIN UNIK ---\n";
        showAllPemainUnik(L);
    }

    cout << "\n";
    system("pause");
}

// Studi Kasus 5: Ranking Pemain
void studiKasus5(List &L) {
    system("cls");
    cout << "========================================\n";
    cout << "   STUDI KASUS 5: RANKING PEMAIN\n";
    cout << "========================================\n\n";

    string idTurnamen;
    cout << "Masukkan ID Turnamen (kosongkan untuk semua): ";
    cin.ignore();
    getline(cin, idTurnamen);

    if (idTurnamen.empty()) {
        // Tampilkan semua pemain unik dengan sorting berdasarkan poin
        cout << "\n--- RANKING SEMUA PEMAIN ---\n";

        // Kumpulkan semua pemain unik
        struct PemainData {
            string id;
            string nama;
            int ranking;
            int poin;
            int menang;
            int kalah;
        };

        PemainData daftarPemain[100]; // Max 100 pemain unik
        int jumlah = 0;

        adrTurnamen T = L.first;
        while (T != NULL) {
            adrPemain P = T->firstPemain;
            while (P != NULL) {
                // Cek apakah sudah ada
                bool sudahAda = false;
                for (int i = 0; i < jumlah; i++) {
                    if (daftarPemain[i].id == P->info.idPemain) {
                        sudahAda = true;
                        // Update jika poin lebih tinggi
                        if (P->info.poin > daftarPemain[i].poin) {
                            daftarPemain[i].poin = P->info.poin;
                            daftarPemain[i].menang = P->info.menang;
                            daftarPemain[i].kalah = P->info.kalah;
                        }
                        break;
                    }
                }

                if (!sudahAda && jumlah < 100) {
                    daftarPemain[jumlah].id = P->info.idPemain;
                    daftarPemain[jumlah].nama = P->info.namaPemain;
                    daftarPemain[jumlah].ranking = P->info.ranking;
                    daftarPemain[jumlah].poin = P->info.poin;
                    daftarPemain[jumlah].menang = P->info.menang;
                    daftarPemain[jumlah].kalah = P->info.kalah;
                    jumlah++;
                }

                P = P->next;
            }
            T = T->next;
        }

        // Bubble sort berdasarkan poin (descending)
        for (int i = 0; i < jumlah - 1; i++) {
            for (int j = 0; j < jumlah - i - 1; j++) {
                if (daftarPemain[j].poin < daftarPemain[j + 1].poin) {
                    PemainData temp = daftarPemain[j];
                    daftarPemain[j] = daftarPemain[j + 1];
                    daftarPemain[j + 1] = temp;
                }
            }
        }

        // Tampilkan hasil
        if (jumlah == 0) {
            cout << "Belum ada pemain!\n";
        } else {
            cout << "Rank | ID       | Nama              | Ranking | Poin  | W/L\n";
            cout << "-----+----------+-------------------+---------+-------+-------\n";
            for (int i = 0; i < jumlah; i++) {
                cout << (i + 1) << "    | "
                     << daftarPemain[i].id << " | "
                     << daftarPemain[i].nama << " | "
                     << daftarPemain[i].ranking << "     | "
                     << daftarPemain[i].poin << "    | "
                     << daftarPemain[i].menang << "/" << daftarPemain[i].kalah << "\n";
            }
        }

    } else {
        // Tampilkan ranking untuk turnamen tertentu
        adrTurnamen T = findTurnamen(L, idTurnamen);

        if (T == NULL) {
            cout << "Turnamen tidak ditemukan!\n";
        } else {
            cout << "\n--- RANKING PEMAIN: " << T->info.namaTurnamen << " ---\n";

            // Hitung jumlah pemain
            int jumlah = countPemain(T);

            if (jumlah == 0) {
                cout << "Belum ada pemain di turnamen ini!\n";
            } else {
                cout << "Rank | ID       | Nama              | Ranking | Poin  | W/L\n";
                cout << "-----+----------+-------------------+---------+-------+-------\n";

                // Tampilkan (tanpa sorting untuk simplicity, bisa ditambah sorting)
                int rank = 1;
                adrPemain P = T->firstPemain;
                while (P != NULL) {
                    cout << rank << "    | "
                         << P->info.idPemain << " | "
                         << P->info.namaPemain << " | "
                         << P->info.ranking << "     | "
                         << P->info.poin << "    | "
                         << P->info.menang << "/" << P->info.kalah << "\n";
                    rank++;
                    P = P->next;
                }
            }
        }
    }

    cout << "\n";
    system("pause");
}
