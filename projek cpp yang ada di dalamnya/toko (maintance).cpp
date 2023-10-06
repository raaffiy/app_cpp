#include <iostream>
#include <windows.h>
using namespace std;

void setcolor (unsigned short color) {
	HANDLE hCon= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

int main () {

// Tipe data dll
menuinput:
string menuinput, menubeli, editbarang, kodenamabarang, belibarang;      
long long int jumlahbarang;

// tipe data 
struct {

// tipe data input 
    string kodebarang;
    string namabarang;
    string deskripsibarang;
    string kategoribarang;
    long long int hargabarang;
    long long int stokbarang;

// Tipe data beli
    long long int jb;
    long long int by;
    string ctt;
    string alm;
} input;


// Pembuka 
    system ("cls");
    setcolor (15);
	cout << "          ALFAMART RAWA LUMBU / 085714713706\n";
	cout << "             PT.SUMBER ALFARIA TRIJAYA,TBK\n";
	cout << endl;
	cout << "        ALFA TOWER LT.12, ALAM SUTERA, TANGGERANG\n";
	cout << "             HPWP : 01.226.238.0-054.000\n";
	cout << "        JL.RAYA JEMBATAN NO.9 RT.06/R RAWALUMBU\n";
	cout << endl;
	setcolor (10);
	cout << "=========================================================\n\n";
	setcolor (15);
	cout <<"        1. Input Barang            2. Edit Barang\n";
    cout <<"        3. Beli Barang             4. Hapus Barang\n";
    cout <<"        5. Exit\n\n";
    cout << "Masukkan Pilihan anda [ 1 s.d 5 ] = ";
    cin >> menuinput;

// Input barang
if (menuinput == "1") {
    system ("cls");

// Jumlah barang yang ingin di masukkan 
cout << "Jumlah barang yang akan input : ";
cin >> jumlahbarang;

// Input data barang
    for (int i = 1; i <= jumlahbarang; i++) {
        cout << "Kategori barang : ";
        cin >> input.kategoribarang;
        cout << "Input Kode Barang : ";
        cin >> input.kodebarang;
        cout << "Nama Barang : ";
        cin >> input.namabarang;
        cout << "Harga Barang : ";
        cin >> input.hargabarang;
        cout << "Stok Barang : ";
        cin >> input.stokbarang;
        cout << "Deskripsi Barang : ";
        cin >> input.deskripsibarang;
    }

// Data telah di simpan
setcolor (267);
cout<<"\nData telah di simpan\n";
setcolor (15);
system ("pause");
system ("cls");
goto menuinput;

// Edit barang
} else if (menuinput == "2"){
    system ("cls");

// Input Kategori barang
cout << "Kategori barang : ";
cin >> input.kategoribarang;

// Menampilkan data berdasarkan kategorinya

// input kode/nama barang
cout << "Input kode barang / nama barang : ";
cin >> kodenamabarang;

// Menampilkan data di database sesuai input/nama yang diinputkan 

// Ingin mengedit barang ?? 
cout << "Apakah anda ingin mengedit barang [ Y / T ] : ";
cin >> editbarang;

// Memasukkan kembali data barang
        cout << "Kategori barang : ";
        cin >> input.kategoribarang;
        cout << "Input Kode Barang : ";
        cin >> input.kodebarang;
        cout << "Nama Barang : ";
        cin >> input.namabarang;
        cout << "Harga Barang : ";
        cin >> input.hargabarang;
        cout << "Stok Barang : ";
        cin >> input.stokbarang;
        cout << "Deskripsi Barang : ";
        cin >> input.deskripsibarang;

// barang berhasil di edit 
setcolor (267);
cout<<"\nBarang berhasil di Edit\n";
setcolor (15);
system ("pause");
system ("cls");
goto menuinput;

// Beli Barang
} else if (menuinput == "3"){
    system ("cls");

// Menu bali barang
menubeli:
    setcolor (14);
    cout << "-- Menu Beli Barang --\n";
    setcolor (15);
    cout << "1. Search\n";
    cout << "2. search in categories\n";
    cout << "3. Exit\n";
    cout << "Masukkan Pilihan anda [ 1 s.d 3 ] = ";
    cin >> menubeli;

// Menu beli
if (menubeli == "1"){
    system ("cls");

// Menampilkan semua data di database 

// input kode/nama barang 
cout << "Input kode barang / nama barang : ";
cin >> kodenamabarang;

// menampilkan data yang dipilih 

// Ingin membeli ?? 
cout << "Apakah anda ingin membeli [ Y / T ] : ";
cin >> belibarang;

// Input
if (belibarang == "Y" || belibarang == "y"){
    system ("cls");

// Struck Belanja 

// beli barang
    cout << "Jumlah barang yang ingin di beli : ";
    cin >> input.jb;
    cout << "Catatan untuk admin : ";
    cin >> input.ctt;
    cout << "Alamat : ";
    cin >> input.alm;
    cout << "Total bayar : ";
    cout << "Bayar : ";
    cin >> input.by;
    cout << "Kembali";

// Penutup
cout << endl;
setcolor (10);
cout << "=========================================================\n\n";
setcolor (15);
cout << "Terimakasih telah berbelanja di toko kami :) semoga kamu senang belanja di toko kami\n";
system ("pause");
system ("cls");
goto menubeli;

} else {
    system ("cls");
    goto menubeli;
}

} else if (menubeli == "2"){
    system ("cls");

// Input Kategori barang
cout << "Kategori barang : ";
cin >> input.kategoribarang;

// Menampilkan data berdasarkan kategorinya

// input kode/nama barang
cout << "Input kode barang / nama barang : ";
cin >> kodenamabarang;

// Menampilkan data di database sesuai input/nama yang diinputkan 

// Ingin membeli ?? 
cout << "Apakah anda ingin membeli [ Y / T ] : ";
cin >> belibarang;

// Input
if (belibarang == "Y" || belibarang == "y"){
    system ("cls");

// Struck Belanja 

// beli barang
    cout << "Jumlah barang yang ingin di beli : ";
    cin >> input.jb;
    cout << "Catatan untuk admin : ";
    cin >> input.ctt;
    cout << "Alamat : ";
    cin >> input.alm;
    cout << "Total bayar : ";
    cout << "Bayar : ";
    cin >> input.by;
    cout << "Kembali";

// Penutup
cout << endl;
setcolor (10);
cout << "=========================================================\n\n";
setcolor (15);
cout << "Terimakasih telah berbelanja di toko kami :) semoga kamu senang belanja di toko kami\n";
system ("pause");
system ("cls");
goto menubeli;

} else {
    system ("cls");
    goto menubeli;
}

} else if (menubeli == "3"){
    system ("cls");
    goto menuinput;

} else {
    system ("cls");
    goto menubeli;
}

// Hapus Barang
} else if (menuinput == "4"){
    system ("cls");

// Input Kategori barang
cout << "Kategori barang : ";
cin >> input.kategoribarang;

// Menampilkan data berdasarkan kategorinya

// input kode/nama barang
cout << "Input kode barang / nama barang : ";
cin >> kodenamabarang;

// Menampilkan data di database sesuai input/nama yang diinputkan 

// Ingin mengedit barang ?? 
cout << "Apakah anda ingin menghapus barang [ Y / T ] : ";
cin >> editbarang;

// Berhasil di hapus
setcolor (12);
cout << "\nBarang berhasil di hapus\n";
setcolor(15);
system ("pause");
system ("cls");
goto menuinput;

// Exit
} else if (menuinput == "5"){
    return 0;

// Input menu barang apabila salah
} else {
    system ("cls");
    goto menuinput;
}
}