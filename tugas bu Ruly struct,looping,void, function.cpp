#include <iostream>
using namespace std;

struct tanggal {
    int hari, bulan, tahun;
};

struct nilai {
    float uts;
    float uas;
    float tugas;
};

struct mahasiswa {
    string nama;
    int umur;
    string jurusan;
    tanggal tanggal_lahir;
    nilai nilai_mhs;
};

    float nilaiakhir (nilai nilai_mhs){
        return (nilai_mhs.uas*0.40)+(nilai_mhs.uts*0.35)+(nilai_mhs.tugas*0.25);
        }


void input(int total, mahasiswa m1[]) {
    for (int i = 0; i < total; i++) {
        cout << "\n======================================" << endl;
        cout << "         DATA MAHASISWA KE-" << i + 1 << endl;
        cout << "======================================" << endl;

        cout << "Masukkan nama: ";
        cin >> m1[i].nama;
        cout << "Masukkan umur: ";
        cin >> m1[i].umur;
        cout << "Masukkan jurusan: ";
        cin >> m1[i].jurusan;

        cout << "Masukkan tanggal lahir : ";
        cin >> m1[i].tanggal_lahir.hari;
        cout << "Masukkan bulan lahir: ";
        cin >> m1[i].tanggal_lahir.bulan;
        cout << "Masukkan tahun lahir: ";
        cin >> m1[i].tanggal_lahir.tahun;

        cout << "Masukkan nilai UTS: ";
        cin >> m1[i].nilai_mhs.uts;
        cout << "Masukkan nilai UAS: ";
        cin >> m1[i].nilai_mhs.uas;
        cout << "Masukkan nilai Tugas: ";
        cin >> m1[i].nilai_mhs.tugas;
    }
}


void output(int total, mahasiswa m1[]) {
    for (int i = 0; i < total; i++) {
        cout << "\n======================================" << endl;
        cout << "         DATA MAHASISWA KE-" << i + 1 << endl;
        cout << "======================================" << endl;

        cout << "Nama: " << m1[i].nama << endl;
        cout << "Umur: " << m1[i].umur << endl;
        cout << "Jurusan: " << m1[i].jurusan << endl;

        cout << "Tanggal lahir: " 
             << m1[i].tanggal_lahir.hari << "-"
             << m1[i].tanggal_lahir.bulan << "-"
             << m1[i].tanggal_lahir.tahun << endl;

        cout << "\nNilai Mahasiswa:" << endl;
        cout << "UTS  = " << m1[i].nilai_mhs.uts << endl;
        cout << "UAS  = " << m1[i].nilai_mhs.uas << endl;
        cout << "Tugas = " << m1[i].nilai_mhs.tugas << endl;

        cout << "uts 35% : "<< m1[i].nilai_mhs.uts * 0.35 << endl;
        cout << "uas 40% : "<<  m1[i].nilai_mhs.uas * 0.40 << endl;
        cout << "tugas 25% : "<<  m1[i].nilai_mhs.tugas * 0.25 << endl;
        cout << "nilai akhir : "<<(m1[i].nilai_mhs.uts * 0.35)+(m1[i].nilai_mhs.uas * 0.40)+(m1[i].nilai_mhs.tugas * 0.25)<< endl;


    }
}

int main() {
    int total;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> total;

    mahasiswa *m1 = new mahasiswa[total];

    input(total, m1);
    output(total, m1);

    delete[] m1; 
    return 0;
}