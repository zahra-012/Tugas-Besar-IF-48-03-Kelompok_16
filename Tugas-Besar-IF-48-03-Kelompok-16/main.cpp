#include "header.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createListTurnamen(L);

    // Menampilkan splash screen
    system("cls");
    cout << "===============================================\n";
    cout << "||                                           ||\n";
    cout << "||   SISTEM MANAJEMEN TURNAMEN BADMINTON     ||\n";
    cout << "||                                           ||\n";
    cout << "||               Selamat Datang!             ||\n";
    cout << "||                                           ||\n";
    cout << "===============================================\n";
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get();

    // Memanggil menu utama
    menuUtama(L);

    // Pesan penutup
    system("cls");
    cout << "\n========================================\n";
    cout << "     Terima kasih telah menggunakan\n";
    cout << "   Sistem Manajemen Turnamen Badminton!\n";
    cout << "========================================\n\n";

    return 0;
}
