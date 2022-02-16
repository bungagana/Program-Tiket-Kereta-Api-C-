#include <iostream>
#include <iomanip>
#include <fstream>  // file eksternal

using namespace std;

int pilih;
int count; //menampilkan data ke layar-menghitung total data
char kembali;

struct penumpang {
    string nama,nik,no_tempatduduk;
    string jurusan,waktu,kelas, status, harga, kode;
};

int hitungData(fstream &file);
void menu ();
void input (fstream &file, int count);
void daftar ();
void ekonomi ();
void bisnis ();
void eksekutif ();
void bayar(fstream &file, int totalBayar);
void nama (fstream &file, int count);
void nik(fstream &file, int count);
void output (fstream &file, int count);
void output (fstream &file, int count);
void searching (fstream &file, int count);
void hapus (fstream &file, int count);

int main(){
    fstream file;
    do {
        count = hitungData(file);
        menu();

        switch (pilih) {
            case 1 :
            input (file,count);
            break;
            case 2 :
            daftar();
            break;
            case 3 :
            output(file,count);
            break;
            case 4 :
            searching(file,count);
            break;
            case 5 :
            hapus(file,count);
            break;
            case 6 :
            exit(0);
        }

    }while (true);
}
int hitungData(fstream &file){
    penumpang ukurData;
    string nikTemp;
    int ukuran = 0,ukuransebelumnya;

    file.open("penumpang.txt");
    do
    {
        nikTemp = ukurData.nik;
        ukuransebelumnya = ukuran;

        getline(file,ukurData.nama);
        getline(file,ukurData.nik);
        getline(file,ukurData.no_tempatduduk);
        getline(file,ukurData.jurusan);
        getline(file,ukurData.kelas);
        getline(file,ukurData.waktu);
        getline(file,ukurData.status);
        getline(file,ukurData.harga);
        getline(file,ukurData.kode);

        if (ukurData.nik != nikTemp)
            ukuran++;
    }
    while (ukuran != ukuransebelumnya);
    file.close();
    return ukuran;
}
void menu () {
    system ("CLS");
    cout << "+ ==================================================== +\n";
    cout << "           Selamat Datang di Reservasi Tiket\n";
    cout << "          ---Stasiun Kereta Api Purwokerto---\n";
    cout << "+ ==================================================== +\n\n";
    cout << "1. Beli Tiket\n";
    cout << "2. Daftar Jurusan dan Harga Tiket\n";
    cout << "3. Daftar Penumpang\n";
    cout << "4. Cari data Penumpang\n";
    cout << "5. Hapus data Penumpang\n";
    cout << "6. Keluar\n\n";
    cout << "+ ==================================================== +\n";
    cout << "Silakan Masukkan Pilihan : "; cin >> pilih;
    system ("CLS");
}
void input (fstream &file, int count){

    penumpang input[100];
    int jumlah, kelas,total=0,berangkat,totalBayar=0;
    int njurusan,banyaknya,harga=0;
    string status;
    cout << "               Pembelian Tiket Kereta Api\n";
    cout << "+ ==================================================== +\n\n";
    cout << "1. Kelas Ekonomi\n";
    cout << "2. Kelas Bisnis\n";
    cout << "3. Kelas Eksekutif\n";
    cout << "Pilih Kelas : "; cin >> kelas;
    system("CLS");
    switch (kelas){
        case 1 :

        ekonomi();
        break;
        case 2 :
        bisnis();
        break;
        case 3 :
        eksekutif();
        break;

    }
    cout << "-------------------- Waktu Keberangkatan ---------------------\n";
    cout << "1. Pagi\n";
    cout << "2. Siang\n";
    cout << "3. Malam\n";
    cout << "--------------------------------------------------------------\n\n";

    cout << "Jumlah transaksi : "; cin >> jumlah;
    cout << endl;

    for (int i = 0; i < jumlah; i++){
        cin.ignore();
        cout << "Transaksi ke " << i+1 << endl;
        cout << "Nama Penumpang : "; getline(cin,input[i].nama);
        cout << "NIK : "; getline(cin,input[i].nik);
        cout << "Nomor Tempat Duduk : "; getline(cin,input[i].no_tempatduduk);
        cout << "Masukkan Nomor Jurusan (1-3) : "; cin >> njurusan;
        cout << "Jumlah Tiket : "; cin >> banyaknya;
        cout << "Nomor Waktu Keberangkatan (1-3): "; cin >> berangkat;


        if (kelas == 1){
        if (njurusan == 1){
            input[i].jurusan = "Purwokerto - Bandung";
            harga = 125000;
            input[i].kelas = "Ekonomi";
            input[i].status = "Aktif";
            input[i].harga = "125.000";
            input[i].kode = "EKPB";
        }else if (njurusan == 2){
            input[i].jurusan = "Bandung - Purwokerto";
            harga = 175000;
            input[i].kelas = "Ekonomi";
            input[i].status = "Hangus";
            input[i].harga = "175.000";
            input[i].kode = "EKBP";
        } else if (njurusan == 3){
            input[i].jurusan = "Yogyakarta - Surabaya";
            harga = 150000;
            input[i].kelas = "Ekonomi";
            input[i].status = "Aktif";
            input[i].harga = "150.000";
            input[i].kode = "EKYS";
        }
    }else if (kelas == 2){
        if (njurusan == 1){
            input[i].jurusan = "Purwokerto - Bandung";
            harga = 175000;
            input[i].kelas = "Bisnis";
            input[i].status = "Aktif";
            input[i].harga = "175.000";
            input[i].kode = "BSPB";
        }else if (njurusan == 2){
            input[i].jurusan = "Bandung - Purwokerto";
            harga = 225000;
            input[i].kelas = "Bisnis";
            input[i].status = "Aktif";
            input[i].harga = "225.000";
            input[i].kode = "BSBP";
        } else if (njurusan == 3){
            input[i].jurusan = "Yogyakarta - Surabaya";
            harga = 200000;
            input[i].kelas = "Bisnis";
            input[i].status = "Hangus";
            input[i].harga = "200.000";
            input[i].kode = "BSYS";
        }
    }
    else if (kelas == 3){
        if (njurusan == 1){
            input[i].jurusan = "Purwokerto - Bandung";
            harga = 215000;
            input[i].kelas = "Eksekutif";
            input[i].status = "Hangus";
            input[i].harga = "215.000";
            input[i].kode = "EXPB";
        }else if (njurusan == 2){
            input[i].jurusan = "Bandung - Purwokerto";
            harga = 300000;
            input[i].kelas = "Eksekutif";
            input[i].status = "Aktif";
            input[i].harga = "300.000";
            input[i].kode = "EXBP";
        } else if (njurusan == 3){
            input[i].jurusan = "Yogyakarta - Surabaya";
            harga = 250000;
            input[i].kelas = "Eksekutif";
            input[i].status = "Aktif";
            input[i].harga = "250.000";
            input[i].kode = "EXYS";
        }
    }
    if (berangkat == 1){
        input[i].waktu = "Pagi";
    }else if (berangkat == 2){
        input[i].waktu = "Siang";
    }else if (berangkat == 3){
        input[i].waktu = "Malam";
    }
    total = total + (banyaknya * harga);
    totalBayar = totalBayar + total;
    cout << endl;
    }
    system ("pause"); //menghentikan proses eksekusi sampai user menekan sembarang tombol

    bayar(file,totalBayar);

    file.open("penumpang.txt",ios::app | ios::out);
    for (int i = 0; i < jumlah; i++){
        file << input[i].nama << endl;
        file << input[i].nik << endl;
        file << input[i].no_tempatduduk << endl;
        file << input[i].jurusan << endl;
        file << input[i].kelas << endl;
        file << input[i].waktu << endl;
        file << input[i].status << endl;
        file << input[i].harga << endl;
        file << input[i].kode << endl;
    }file.close();

    cout << "Ingin kembali ke menu utama? (Y/N) ";
    cin >> kembali;

    if (kembali == 'Y' || kembali == 'y'){
        return;
    } else exit(0); //pengehentian program yg berhasil
}
void bayar(fstream &file, int totalBayar){

    int bayar,y = 1;
    int kembalian;
    while (y == 1){
        system ("CLS");
        cout << "------------------ Pembayaran Pesanan Tiket -----------------\n";
        cout << "+ ========================================================= +\n\n";
        cout << "Total Pembayaran : " << totalBayar << endl;
        cout << "Bayar\t: "; cin >> bayar;
        kembalian = bayar - totalBayar;
        cout << "Kembalian Anda : " << kembalian << endl << endl;
        if (kembalian >= 0) {
            cout << "------------------ Terima Kasih -----------------\n";
            cout << "        Semoga perjalanan anda Menyenangkan\n\n";
            y = 0;
        }
            system ("pause");
        }
    }
void ekonomi (){
    cout << "----------------------- Kelas Ekonomi -----------------------\n\n";
    cout << "-------------------------------------------------------------\n";
    cout << "  No. |               Jurusan              |   Harga Tiket  |\n";
    cout << "-------------------------------------------------------------\n";
    cout << "   1. |  Purwokerto - Bandung              |   Rp. 125.000  |\n";
    cout << "-------------------------------------------------------------\n";
    cout << "   2. |  Bandung    - Purwokerto           |   Rp. 175.000  |\n";
    cout << "-------------------------------------------------------------\n";
    cout << "   3. |  Yogyakarta - Surabaya             |   Rp. 150.000  |\n";
    cout << "-------------------------------------------------------------\n\n";
}
void bisnis (){
    cout << "----------------------- Kelas Bisnis -----------------------\n\n";
    cout << "-------------------------------------------------------------\n";
    cout << "  No. |               Jurusan              |   Harga Tiket  |\n";
    cout << "-------------------------------------------------------------\n";
    cout << "   1. |  Purwokerto - Bandung              |   Rp. 175.000  |\n";
    cout << "-------------------------------------------------------------\n";
    cout << "   2. |  Bandung    - Purwokerto           |   Rp. 225.000  |\n";
    cout << "-------------------------------------------------------------\n";
    cout << "   3. |  Yogyakarta - Surabaya             |   Rp. 200.000  |\n";
    cout << "-------------------------------------------------------------\n\n";
}
void eksekutif (){
    cout << "----------------------- Kelas Eksekutif -----------------------\n\n";
    cout << "-------------------------------------------------------------\n";
    cout << "  No. |               Jurusan              |   Harga Tiket  |\n";
    cout << "-------------------------------------------------------------\n";
    cout << "   1. |  Purwokerto - Bandung              |   Rp. 215.000  |\n";
    cout << "-------------------------------------------------------------\n";
    cout << "   2. |  Bandung    - Purwokerto           |   Rp. 300.000  |\n";
    cout << "-------------------------------------------------------------\n";
    cout << "   3. |  Yogyakarta - Surabaya             |   Rp. 250.000  |\n";
    cout << "-------------------------------------------------------------\n\n";
}
void daftar (){
    cout << "+ ========================================================= +\n";
    cout << "                Daftar Jurusan dan Harga Tiket\n";
    cout << "+ ========================================================= +\n\n";
    ekonomi ();
    bisnis ();
    eksekutif ();

    cout << "Anda ingin kembali ke menu utama? (Y/N) ";
        cin >> kembali;

        if (kembali == 'Y' || kembali == 'y'){
        return;
        } else exit(0);
}
void nama (fstream &file, int count){   //count == total angka/baris
    penumpang nama[count],temp;
    cout << "             ------ Output Berdasarkan Nama ------\n";
    cout << "+ ========================================================= +\n\n";
    file.open("penumpang.txt");
    for (int i = 0; i < count; i++){
        getline(file,nama[i].nama);
        getline(file,nama[i].nik);
        getline(file,nama[i].no_tempatduduk);
        getline(file,nama[i].jurusan);
        getline(file,nama[i].kelas);
        getline(file,nama[i].waktu);
        getline(file,nama[i].status);
        getline(file,nama[i].harga);
        getline(file,nama[i].kode);

    }file.close();
    //INSERTION SORT
    for (int i = 0; i < count; i++){
        for (int j = i+1; j < count; j++){
            if (nama[i].nama > nama[j].nama){
                temp = nama[i];
                nama[i] = nama[j];
                nama[j] = temp;
            }
        }
    }

    //IOS TRUNC == mengahpus data kalo berkasnya sudah ada
    // IOS out == mencetak data

    file.open("penumpang.txt", ios::trunc | ios::out);
    for (int i = 0; i < count; i++){
        file << nama[i].nama << endl;
        file << nama[i].nik << endl;
        file << nama[i].no_tempatduduk<< endl;
        file << nama[i].jurusan << endl;
        file << nama[i].kelas << endl;
        file << nama[i].waktu << endl;
        file << nama[i].status << endl;
        file << nama[i].harga << endl;
        file << nama[i].kode << endl;

    }file.close();

    cout << "Jumlah Penumpang : " << count << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "        Nama       |     NIK     | NOMOR TEMPAT DUDUK |        JURUSAN        |   KELAS   |  WAKTU | STATUS     |    HARGA   |  KODE  |\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i=0;i<count;i++){
        cout << setiosflags(ios::left) << setw(18) << nama[i].nama << " | ";
        cout << setiosflags(ios::left) << setw(11) << nama[i].nik << " | ";
        cout << setiosflags(ios::left) << setw(14) << nama[i].no_tempatduduk << "     | ";
        cout << setiosflags(ios::left) << setw(21) << nama[i].jurusan << " | ";
        cout << setiosflags(ios::left) << setw(9) << nama[i].kelas << " | ";
        cout << setiosflags(ios::left) << setw(6) << nama[i].waktu << " | ";
        cout << setiosflags(ios::left) << setw(10) << nama[i].status << " | ";
        cout << setiosflags(ios::left) << setw(10) << nama[i].harga << " | " ;
        cout << setiosflags(ios::left) << setw(6) << nama[i].kode << " | " << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------\n";
        }
}
void nik (fstream &file, int count){
    penumpang nik[count],temp;
    cout << "             ------ Output Berdasarkan NIK ------\n";
    cout << "+ ========================================================= +\n\n";
    file.open("penumpang.txt");

    //PAKAI INSERTION SORT
    for (int i = 0; i < count; i++){
        getline(file,nik[i].nama);
        getline(file,nik[i].nik);
        getline(file,nik[i].no_tempatduduk);
        getline(file,nik[i].jurusan);
        getline(file,nik[i].kelas);
        getline(file,nik[i].waktu);
        getline(file,nik[i].status);
        getline(file,nik[i].harga);
        getline(file,nik[i].kode);
    }file.close();
    for (int i = 0; i < count; i++){
        for (int j = i+1; j < count; j++){
            if (nik[i].nik > nik[j].nik){
                temp = nik[i];
                nik[i] = nik[j];
                nik[j] = temp;
            }
        }
    }

    file.open("penumpang.txt", ios::trunc | ios::out);
    for (int i = 0; i < count; i++){
        file << nik[i].nama << endl;
        file << nik[i].nik << endl;
        file << nik[i].no_tempatduduk << endl;
        file << nik[i].jurusan << endl;
        file << nik[i].kelas << endl;
        file << nik[i].waktu << endl;
        file << nik[i].status << endl;
        file << nik[i].harga << endl;
        file << nik[i].kode << endl;
    }file.close();

    cout << "Jumlah Penumpang : " << count << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "     NIK    |        Nama        | NOMOR TEMPAT DUDUK |        JURUSAN        |   KELAS   |  WAKTU |  STATUS |    HARGA    |  KODE  |\n";
    cout << "------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i=0;i<count;i++){
        cout << setiosflags(ios::left) << setw(11) << nik[i].nik << " | ";
        cout << setiosflags(ios::left) << setw(18) << nik[i].nama << " | ";
        cout << setiosflags(ios::left) << setw(18) << nik[i].no_tempatduduk << " | ";
        cout << setiosflags(ios::left) << setw(21) << nik[i].jurusan << " | ";
        cout << setiosflags(ios::left) << setw(8) << nik[i].kelas << "  | ";
        cout << setiosflags(ios::left) << setw(6) << nik[i].waktu << " | ";
        cout << setiosflags(ios::left) << setw(7) << nik[i].status << " | ";
        cout << setiosflags(ios::left) << setw(11) << nik[i].harga << " | " ;
        cout << setiosflags(ios::left) << setw(6) << nik [i].kode << " | " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------\n";
        }
}
void output (fstream &file, int count){
    penumpang output[count],temp;
    int pilihan;
    cout << "                ------ Daftar Penumpang ------\n";
    cout << "                 Stasiun Kereta Api Purwokerto\n";
    cout << "+ ========================================================= +\n\n";
    cout << "1. Output Berdasarkan Nama\n";
    cout << "2. Output Berdasarkan NIK\n";
    cout << "-------------------------------------------------------------\n";
    cout << "Masukkan Pilihan : "; cin >> pilihan;
    cout << endl;
    switch (pilihan){
        case 1 :
        nama(file,count);
        break;
        case 2 :
        nik(file,count);
        break;
    }
    cout << "Anda ingin kembali ke menu utama? (Y/N) ";
        cin >> kembali;

        if (kembali == 'Y' || kembali == 'y'){
        return;
        } else exit(0);
}
void searching (fstream &file, int count){
    //sequential search
    penumpang searching[count],temp;
    string cari;
    //
    bool p = false;
    cout << "                   Mencari Data Penumpang\n";
    cout << "           ---- Stasiun Kereta Api Yogyakarta ----\n";
    cout << "+ ========================================================= +\n\n";
    cout << "Cari NIK Penumpang : ";
    cin.ignore(); //menghapus enter
    cin >> cari;

    file.open("penumpang.txt",ios::in);
    for (int i = 0; i < count; i++){
        getline(file,searching[i].nama);
        getline(file,searching[i].nik);
        getline(file,searching[i].no_tempatduduk);
        getline(file,searching[i].jurusan);
        getline(file,searching[i].kelas);
        getline(file,searching[i].waktu);
        getline(file,searching[i].status);
        getline(file,searching[i].harga);
        getline(file,searching[i].kode);
    }file.close();
    cout << endl;
    cout << "                   Informasi data Penumpang\n";
    cout << "+ ========================================================= +\n\n";
    for (int i = 0; i < count; i++){
        if (cari == searching[i].nik){
            p = true;
            cout << "Data ditemukan!\n";
            cout << "Penumpang dengan data berikut :\n";
            cout << "Nama\t\t\t: " << searching[i].nama << endl;
            cout << "NIK\t\t\t: " << searching[i].nik << endl;
            cout << "Nomer Tempat duduk\t: " << searching[i].no_tempatduduk << endl;
            cout << "Berada di Jurusan " << searching[i].jurusan << " dengan kelas " << searching[i].kelas << endl;
            cout << "Pada waktu\t\t: " << searching[i].waktu << endl;
            cout << "Status\t\t\t: " << searching[i].status << endl;
            cout << "-------------------------------------------------------------\n";
        }
    }
    if (p == false){
        cout << "Data yang Anda Cari tidak ditemukan!\n";
    }
    cout << endl;
    cout << "Ingin kembali ke menu utama? (Y/N) ";
    cin >> kembali;
    if (kembali == 'Y' || kembali == 'y'){
         return;
    } else exit(0);
}
void hapus (fstream &file, int count){
    penumpang hapus[count];
    string namaa;
    bool y = false;
    cout << "                 --- Hapus data Penumpang ---\n";
    cout << "+ ========================================================= +\n\n";

    file.open("penumpang.txt");
    for (int i = 0; i < count; i++){
        getline(file,hapus[i].nama);
        getline(file,hapus[i].nik);
        getline(file,hapus[i].no_tempatduduk);
        getline(file,hapus[i].jurusan);
        getline(file,hapus[i].kelas);
        getline(file,hapus[i].waktu);
        getline(file,hapus[i].status);
        getline(file,hapus[i].harga);
        getline(file,hapus[i].kode);
    }file.close();
    cout << "Masukkan Nama Penumpang yang ingin dihapus : ";
    cin.ignore();
    getline(cin,namaa);
    for (int i = 0; i < count; i++)
    {
        if (namaa == hapus[i].nama)
        {
            for (int j = i; j < count-1; j++)
            {
                hapus[j].nama = hapus[j+1].nama;
                hapus[j].nik = hapus[j+1].nik;
                hapus[j].no_tempatduduk = hapus[j+1].no_tempatduduk;
                hapus[j].jurusan = hapus[j+1].jurusan;
                hapus[j].kelas = hapus[j+1].kelas;
                hapus[j].waktu = hapus[j+1].waktu;
                hapus[j].waktu = hapus[j+1].status;
                hapus[j].waktu = hapus[j+1].harga;
                hapus[j].waktu = hapus[j+1].kode;
            }
            count--;
            y = true;
            break;
        }
    }
    if ( y == true){
        cout << "\n------- Data berhasil dihapus -------\n\n";
        file.open("penumpang.txt",ios::trunc | ios:: out);
    for (int i = 0; i < count; i++){
        file << hapus[i].nama << endl;
        file << hapus[i].nik << endl;
        file << hapus[i].no_tempatduduk << endl;
        file << hapus[i].jurusan << endl;
        file << hapus[i].kelas << endl;
        file << hapus[i].waktu << endl;
        file << hapus[i].status << endl;
        file << hapus[i].harga << endl;
        file << hapus[i].kode << endl;
    }file.close();
    file.open("penumpang.txt");
    cout << "Jumlah Penumpang Sebelumnya : " << count+1 << endl;
    cout << "Jumlah Penumpang Setelah dihapus : " << count << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "        Nama       |     NIK     | NOMOR TEMPAT DUDUK |        JURUSAN        |   KELAS   |  WAKTU |  STATUS |    HARGA   |  KODE  |\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i=0;i<count;i++){
        cout << setiosflags(ios::left) << setw(18) << hapus[i].nama << " | ";
        cout << setiosflags(ios::left) << setw(11) << hapus[i].nik << " | ";
        cout << setiosflags(ios::left) << setw(18) << hapus[i].no_tempatduduk << " | ";
        cout << setiosflags(ios::left) << setw(21) << hapus[i].jurusan << " | ";
        cout << setiosflags(ios::left) << setw(9) << hapus[i].kelas << " | ";
        cout << setiosflags(ios::left) << setw(6) << hapus[i].waktu << " | " ;
        cout << setiosflags(ios::left) << setw(7) << hapus[i].status << " | ";
        cout << setiosflags(ios::left) << setw(10) << hapus[i].harga << " | ";
        cout << setiosflags(ios::left) << setw(6) << hapus[i].kode << " | " << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";
        }file.close();

    }else cout << "\nData tidak ditemukan, Nama yang Anda masukkan salah!\n\n";
    cout << "Ingin kembali ke menu utama? (Y/N) ";
    cin >> kembali;
    if (kembali == 'Y' || kembali == 'y'){
         return ;
    } else exit(0);
}
