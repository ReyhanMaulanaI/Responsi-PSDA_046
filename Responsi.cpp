#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi tempat pariwisata
struct TempatPariwisata {
    string nama;
    string deskripsi;
    string lokasi;
    string rating;
};

// Array untuk menyimpan data tempat pariwisata
vector<TempatPariwisata> tempat_pariwisata;

// Fungsi untuk menambahkan tempat pariwisata baru
void tambahTempat() {
    TempatPariwisata tempat;
    cout << "Masukkan informasi tempat pariwisata:" << endl;
    cout << "Nama Tempat: ";
    getline(cin >> ws, tempat.nama);
    cout << "Deskripsi Tempat: ";
    getline(cin, tempat.deskripsi);
    cout << "Lokasi: ";
    getline(cin, tempat.lokasi);
    cout << "Rating: ";
    getline(cin, tempat.rating);
    tempat_pariwisata.push_back(tempat); // Simpan data ke dalam vektor
    cout << "Tempat pariwisata berhasil ditambahkan!" << endl;
}

// Fungsi untuk mencari tempat pariwisata berdasarkan kata kunci
void cariTempat(const vector<string>& kataKunci) {
    bool ditemukan = false;
    for (const auto& tempat : tempat_pariwisata) {
        bool semuaKataKunciDitemukan = true;
        for (const auto& keyword : kataKunci) {
            if (tempat.deskripsi.find(keyword) == string::npos) {
                semuaKataKunciDitemukan = false;
                break;
            }
        }
        if (semuaKataKunciDitemukan) {
            ditemukan = true;
            cout << "Nama Tempat: " << tempat.nama << endl;
            cout << "Deskripsi Tempat: " << tempat.deskripsi << endl;
            cout << "Lokasi: " << tempat.lokasi << endl;
            cout << "Rating: " << tempat.rating << endl << endl;
        }
    }
    if (!ditemukan) {
        cout << "Tidak ada tempat pariwisata yang cocok dengan kata kunci tersebut." << endl << endl;
    }
}

int main() {
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah Tempat Pariwisata" << endl;
        cout << "2. Cari Tempat Pariwisata" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer stdin

        switch (pilihan) {
            case 1:
                tambahTempat();
                break;
            case 2: {
                cout << "Masukkan kata kunci pencarian: ";
                string input;
                getline(cin, input);
                vector<string> kataKunci;
                size_t pos = 0;
                string token;
                while ((pos = input.find(" ")) != string::npos) {
                    token = input.substr(0, pos);
                    kataKunci.push_back(token);
                    input.erase(0, pos + 1);
                }
                kataKunci.push_back(input);
                cariTempat(kataKunci);
                break;
            }
            case 3:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                return 0;
            default:
                cout << "Menu tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }
}