#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct tanggal {
    int hari, bulan, tahun;
};

struct nilai {
    float uts;
    float uas;
    float tugas;
};

struct mapel {
    float mtk;
    float ipa;
    float bind;
    float bing;
};

struct mahasiswa {
    string nama;
    string nisn;
    int umur;
    string jurusan;
    tanggal tanggal_lahir;
    nilai nilai_mhs;
    mapel n;
};

// Hitung nilai akhir umum
float nilaiakhir(nilai n) {
    return (n.uas * 0.40) + (n.uts * 0.35) + (n.tugas * 0.25);
}

// Hitung nilai akhir per mapel
float nilaimapel(mapel n) {
    return (n.mtk * 0.35) + (n.bind * 0.2) + (n.bing * 0.2) + (n.ipa * 0.25);
}

// Input data mahasiswa
void input(int total, mahasiswa m1[]) {
    for (int i = 0; i < total; i++) {
        cout << "\n======================================" << endl;
        cout << "         DATA MAHASISWA KE-" << i + 1 << endl;
        cout << "======================================" << endl;

        cin.ignore();
        cout << "Masukkan nama: ";
        getline(cin, m1[i].nama);
        cout << "Masukkan NISN: ";
        getline(cin, m1[i].nisn);
        cout << "Masukkan umur: ";
        cin >> m1[i].umur;
        cin.ignore();
        cout << "Masukkan jurusan: ";
        getline(cin, m1[i].jurusan);

        cout << "Masukkan tanggal lahir (hari bulan tahun): ";
        cin >> m1[i].tanggal_lahir.hari >> m1[i].tanggal_lahir.bulan >> m1[i].tanggal_lahir.tahun;

        cout << "Masukkan nilai Matematika : ";
        cin >> m1[i].n.mtk;
        cout << "Masukkan nilai Bahasa Indonesia: ";
        cin >> m1[i].n.bind;
        cout << "Masukkan nilai Bahasa Inggris: ";
        cin >> m1[i].n.bing;
        cout << "Masukkan nilai IPA: ";
        cin >> m1[i].n.ipa;

        cout << "Masukkan nilai UTS: ";
        cin >> m1[i].nilai_mhs.uts;
        cout << "Masukkan nilai UAS: ";
        cin >> m1[i].nilai_mhs.uas;
        cout << "Masukkan nilai Tugas: ";
        cin >> m1[i].nilai_mhs.tugas;
    }
}

// Output data ke file
void output(int total, mahasiswa m1[]) {
    ofstream file("siswa.txt", ios::app);

    for (int i = 0; i < total; i++) {
        file << "\n======================================" << endl;
        file << "         DATA MAHASISWA KE-" << i + 1 << endl;
        file << "======================================" << endl;

        file << "Nama: " << m1[i].nama << endl;
        file << "NISN: " << m1[i].nisn << endl;
        file << "Umur: " << m1[i].umur << endl;
        file << "Jurusan: " << m1[i].jurusan << endl;
        file << "Tanggal lahir: "
             << m1[i].tanggal_lahir.hari << "-"
             << m1[i].tanggal_lahir.bulan << "-"
             << m1[i].tanggal_lahir.tahun << endl;

        file << "Nilai Matematika: " << m1[i].n.mtk << endl;
        file << "Nilai Bahasa Indonesia: " << m1[i].n.bind << endl;
        file << "Nilai Bahasa Inggris: " << m1[i].n.bing << endl;
        file << "Nilai IPA: " << m1[i].n.ipa << endl;

        file << "Nilai UTS: " << m1[i].nilai_mhs.uts << endl;
        file << "Nilai UAS: " << m1[i].nilai_mhs.uas << endl;
        file << "Nilai Tugas: " << m1[i].nilai_mhs.tugas << endl;

        file << "Nilai akhir mapel: " << nilaimapel(m1[i].n) << endl;
        file << "Nilai akhir siswa: " << nilaiakhir(m1[i].nilai_mhs) << endl;
    }

    file.close();
}

// Mencari data berdasarkan NISN
void mencari() {
    string nisn;
    cout << "Masukkan NISN yang ingin dicari: ";
    cin >> nisn;

    ifstream file("siswa.txt");
    string baris;
    bool ketemu = false;

    while (getline(file, baris)) {
        if (baris.find("NISN: " + nisn) != string::npos) {
            cout << "\nData ditemukan:\n";
            cout << baris << endl;
            ketemu = true;
        }
    }

    if (!ketemu) {
        cout << "Siswa dengan NISN " << nisn << " tidak ditemukan." << endl;
    }

    file.close();
}

// Menampilkan peringkat berdasarkan nilai mapel
void peringkat(int total, mahasiswa m1[]) {
    for (int a = 0; a < total - 1; a++) {
        for (int l = 0; l < total - a - 1; l++) {
            if (nilaimapel(m1[l].n) < nilaimapel(m1[l + 1].n)) {
                mahasiswa temp = m1[l];
                m1[l] = m1[l + 1];
                m1[l + 1] = temp;
            }
        }
    }

    cout << "\n==== Peringkat Siswa ====\n";
    for (int i = 0; i < total; i++) {
        cout << "Rangking " << i + 1 << endl;
        cout << "Nama: " << m1[i].nama << endl;
        cout << "NISN: " << m1[i].nisn << endl;
        cout << "Nilai Akhir: " << nilaimapel(m1[i].n) << endl;
        cout << "-------------------------\n";
    }
}

// Program utama
int main() {
    int total;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> total;

    mahasiswa m1[total];
    input(total, m1);
    output(total, m1);
    peringkat(total, m1);

    char opsi;
    cout << "Apakah ingin mencari siswa? (y/t): ";
    cin >> opsi;
    if (opsi == 'y' || opsi == 'Y') {
        mencari();
    }

    cout << "\nData berhasil disimpan ke file siswa.txt\n";
    return 0;
}