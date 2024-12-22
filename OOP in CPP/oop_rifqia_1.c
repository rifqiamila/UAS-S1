#include <iostream>
#include <string>
using namespace std;

class wargaKampus {
protected:
    string nama;
    int tinggi;
    float berat;
    int umur;

public:
    wargaKampus(string nama, int tinggi, float berat, int umur) {
        this->nama = nama;
        this->tinggi = tinggi;
        this->berat = berat;
        this->umur = umur;
    }

    void introduce() {
        cout << "Perkenalkan nama saya " << nama << endl;
    }

    void apakahMuat() {
        try {
            if (tinggi < 190 && berat < 80) {
                cout << nama << " muat dan bisa masuk lift" << endl;
            } else {
                throw berat;
            }
        } catch (float beratnya) {
            if (beratnya < 100) {
                cout << nama << " masih aman boleh masuk lift" << endl;
            } else {
                cout << nama << " tidak boleh masuk lift, nanti ambrol" << endl;
            }
        }
    }

    void posisi() {
        cout << nama << " belum tahu posisinya" << endl;
    }
};

class mahasigma : public wargaKampus {
    float ipk;
    string nim;

public:
    mahasigma(string nama, int tinggi, float berat, int umur, float ipk, string nim) 
        : wargaKampus(nama, tinggi, berat, umur) {
        this->ipk = ipk;
        this->nim = nim;
    }

    void tampilkanData() {
        cout << "Nama   : " << nama << endl
            << "NIM    : " << nim << endl
            << "IPK    : " << ipk << endl
            << "Umur   : " << umur << endl
            << "Tinggi : " << tinggi << endl
            << "Berat  : " << berat << endl;
    }

    void apakahPantas() {
        try{
            if (ipk > 3.00 && nim == "L0124074") {
                cout << nama << " pantas dipanggil mahasigma" << endl;
            } 
            else {
                throw ipk;
            }
        }
        catch (float ipkne) {
            if (ipkne > 3.50) {
                cout << nama << " bisa dipanggil mahasigma setelah makan 100 ular" << endl;
            }
            else {
                cout << nama << " tidak bisa dipanggil mahasigma sampai semester depan";
            }
        }
    }

    void posisi() {
        cout << "posisi " << nama << " di kampus ini adalah sebagai mahasiswa" << endl;
    }
};

int main() {
    wargaKampus wk("Inisial A", 177, 75.5, 27);
    wk.introduce();
    wk.apakahMuat();
    cout << endl;

    mahasigma ms("Inisial F", 180, 85.0, 22, 3.6, "L0124200");
    ms.introduce();
    ms.apakahMuat();
    ms.tampilkanData();
    ms.apakahPantas();
    ms.posisi();

    return 0;
}
