#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<ctime>

using namespace std;

// Membuat class Buku
class Buku {
    public: string judul; int jumlah;
};
// menetapkan jumlah garis pada judul
const int jumlahGaris = 42;
// menetapkan jumlah buku yang tersedia
const int jumlahBuku = 3;
// membuat objek buku
Buku buku[jumlahBuku];

// Deklarasi fungsi bantu
const string waktuSekarang(int pil);
const string waktuKembali(int hari);
const void bersihkanLayar();
const void cetakJudul(string judul);

int main() {
    // indikator perulangan utama program
    bool lanjutkan = true;
    // inisialisasi objek buku
    buku[0].judul = "Ayat-ayat Cinta";   buku[0].jumlah = 1;
    buku[1].judul = "Laskar Pelangi";    buku[1].jumlah = 5;
    buku[2].judul = "KKN Desa Penari";   buku[2].jumlah = 4;

    do
    {
        // indikator untuk keluar program
        char perintah;
        // menampung nomor buku yang dipilih
        int noBuku;
        // variable untuk peminjaman
        int lama;
        // variable untuk peminjam
        string nama, noHp;
        // objek buku yang dipinjam
        Buku bukuPinjam;

        bersihkanLayar();
        cetakJudul("DAFTAR BUKU");     
        // mencetak pilihan pinjam  
        cout << "No Judul\t\tStok" << endl;
        for (int i = 0; i < end(buku) - begin(buku); i++) {
            cout << i+1 << ". " << buku[i].judul << "\t" << buku[i].jumlah << " buah" << endl;
        }
        // memasukkan input buku yang dipinjam
        cout << endl << "Pilih buku! [no. buku]: "; cin >> noBuku;
        // menentukan buku yang dipinjam berdasarkan input nomor buku, jika tidak tersedia program akan mengulang
        if (noBuku > 0 && noBuku <= end(buku) - begin(buku)) {
            if (buku[noBuku-1].jumlah > 0) bukuPinjam = buku[noBuku-1];
            else continue;
        } else continue;
        // mengurangi jumlah buku yang dipinjam
        buku[noBuku-1].jumlah--;

        bersihkanLayar();
        cetakJudul("PEMINJAMAN");
        cout << "Peminjam\t: "; cin >> nama;
        cout << "No. Hp\t\t: "; cin >> noHp;
        cout << "Judul buku\t: " << bukuPinjam.judul << endl;
        cout << "Tanggal\t\t: " << waktuSekarang(0) << endl;
        cout << "Jam\t\t: " << waktuSekarang(1) << endl;
        cout << "Lama (hari)\t: "; cin >> lama;
        cout << "Batas kembali\t: " << waktuKembali(lama) << endl;
        cetakJudul("HARAP KEMBALIKAN TEPAT WAKTU");
        
        cout << endl << "Apakah ingin melakukan pinjaman lagi? [y/n] "; cin >> perintah;
        // apabila memasukkan huruf 'y' maka program akan mengulang, selain itu program berhenti
        if(perintah == 'Y' || perintah == 'y') {
            bersihkanLayar();
        } else {
            lanjutkan = false;
        }
    } while (lanjutkan);

    return 0;
}

// mengambil waktu sekarang dengan, pil 0 => tanggal, pil 1 => jam
const string waktuSekarang(int pil = 0) {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    if (pil == 1) {
        strftime(buf, sizeof(buf), "%X", &tstruct);
    } else {
        strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);
    }
    return buf;
}

// mengambil waktu pengembalian
const string waktuKembali(int hari) {
    time_t     now = time(0) + 60*60*24*hari;
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);
    return buf;
}

// membersihkan layar
const void bersihkanLayar() {
    #ifdef __linux__
        system("clear");
    #else
        system("cls");
    #endif
}

// membuat header
const void cetakJudul(string judul) {
    int panjangJudul = judul.size();
    string garis, tengah;
    for (int i = 0; i < jumlahGaris; i++)
    {
        if (i == 0 || i == jumlahGaris-1) tengah += "|";
        else {
            int sisa = floor((jumlahGaris-2-panjangJudul)/2);
            if ( i>sisa && i<=(sisa+panjangJudul) ) tengah += judul[i-sisa-1];
            else tengah += " ";
        }
        garis += "=";
    }
    cout << garis << endl << tengah << endl << garis << endl;
}