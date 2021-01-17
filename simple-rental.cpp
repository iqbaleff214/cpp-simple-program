#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>

using namespace std;

// Membuat class Mobil
class Mobil {
    public: string nama; int harga;
};

// Deklarasi fungsi bantu
void bersihkanLayar();
void cetakJudul(string judul);

int main() {
    // indikator perulangan utama program
    bool lanjutkan = true;
    // membuat objek mobil
    Mobil mobil[3];
    mobil[0].nama = "Toyota";   mobil[0].harga = 50000;
    mobil[1].nama = "Avanza";   mobil[1].harga = 55000;
    mobil[2].nama = "Yamaha";   mobil[2].harga = 60000;
    // pajak
    const float pajak = 0.1;

    do
    {
        // indikator untuk keluar program
        char perintah;
        // menampung nomor mobil yang dipilih
        int noMobil;
        // variable untuk transaksi
        int lama, total, bayar, kembalian;
        // variable untuk penyewa
        string nama, noHp;
        // objek mobil yang disewa
        Mobil mobilSewa;

        bersihkanLayar();
        cetakJudul("PILIH MOBIL");     
        // mencetak pilihan sewa  
        for (int i = 0; i < end(mobil) - begin(mobil); i++) {
            cout << i+1 << ". " << mobil[i].nama << "\tRp" << mobil[i].harga << endl;
        }
        // memasukkan input mobil yang disewa
        cout << endl << "Pilih mobil! [no. mobil] "; cin >> noMobil;
        // menentukan mobil yang disewa berdasarkan input nomor mobil, jika tidak tersedia program akan mengulang
        if (noMobil > 0 && noMobil <= end(mobil) - begin(mobil)) mobilSewa = mobil[noMobil-1];
        else continue;
        // lama waktu sewa
        cout << "Berapa lama? [hari] "; cin >> lama;
        // menghitung harga sewa
        total = mobilSewa.harga * lama;

        bersihkanLayar();
        cetakJudul("PEMBAYARAN");
        // memasukkan data penyewa dan pembayaran
        cout << "Penyewa\t\t: "; cin >> nama;
        cout << "No. Hp\t\t: "; cin >> noHp;
        cout << "Mobil\t\t: " << mobilSewa.nama << endl;
        cout << "Sewa\t\t: " << "Rp" << mobilSewa.harga << "/hari" << endl;
        cout << "Lama\t\t: " << lama << " hari" << endl;
        cout << "Harga\t\t: " << "Rp" << total << endl;
        cout << "Pajak10%\t: " << "Rp" << pajak*total << endl;
        // memperbarui nilai total setelah ditambah pajak 10% dari harga penyewaan
        total = total+(pajak*total);
        cout << "Total\t\t: " << "Rp" << total << endl;
        // memasukkan pembayaran penyewa
        cout << endl << "Bayar\t\t: Rp"; cin >> bayar;
        // menghitung kembalian
        kembalian = bayar - total;
        cout << "Kembali\t\t: " << "Rp" << kembalian << endl;
        cetakJudul("TERIMA KASIH");
        // konfirmasi pengulangan program
        cout << endl << "Apakah ingin melakukan transaksi lagi? [y/n] "; cin >> perintah;
        // apabila memasukkan huruf 'y' maka program akan mengulang, selain itu program berhenti
        if(perintah == 'Y' || perintah == 'y') {
            bersihkanLayar();
        } else {
            lanjutkan = false;
        }
    } while (lanjutkan);
    
    return 0;
}

// membersihkan layar
void bersihkanLayar() {
    #ifdef __linux__
        system("clear");
    #else
        system("cls");
    #endif
}

// membuat header
void cetakJudul(string judul) {
    int panjangJudul = judul.size();
    string garis, tengah;
    for (int i = 0; i < 32; i++)
    {
        if (i == 0 || i == 31) tengah += "|";
        else {
            int sisa = floor((30-panjangJudul)/2);
            if ( i>sisa && i<=(sisa+panjangJudul) ) tengah += judul[i-sisa-1];
            else tengah += " ";
        }
        garis += "=";
    }
    cout << garis << endl << tengah << endl << garis << endl;
}