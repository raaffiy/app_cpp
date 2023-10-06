#include <iostream>
#include <windows.h>
#include <iomanip>
#include <limits>

using namespace std;
void setcolor (unsigned short color) {
	HANDLE hCon= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

/////////////////////////////////////
// Variabel sistem belanja menu 5 //
////////////////////////////////////
const int MAX_B = 100;		// untuk menggunakan getline di dalam array

//////////////////////////////////////////////
//// menu 5 sistem pembelian di alfamart ////
////////////////////////////////////////////
int main (){
string yn1;
menu5:
//Inisialisasi atau deklarasi variabel
	long int tot,jum_beli,jumlah[50], harga[50], sub_tot[50], diskon, bayar;
	string nama_barang[MAX_B];
	string hilang;

// pembuka
	cout << "          ALFAMART RAWA LUMBU / 085714713706\n";
	cout << "             PT.SUMBER ALFARIA TRIJAYA,TBK\n";
	cout << endl;
	cout << "        ALFA TOWER LT.12, ALAM SUTERA, TANGGERANG\n";
	cout << "             HPWP : 01.226.238.0-054.000\n";
	cout << "        JL.RAYA JEMBATAN NO.9 RT.06/R RAWALUMBU\n";
	cout << endl;
	setcolor (10);
	cout << "=========================================================\n";
	setcolor (15);
	cout << endl;

// Input jumlah barang
bool validInput = false;     
    while (!validInput) {
        setcolor(15);
        cout << "Masukkan jumlah Beli Barang : ";
        string input1;
        cin >> input1;

// pengecekan apakah input hanya terdiri dari angka
        bool isNumber = true;
        for (char c : input1) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

// melakukan pengecekan ulang
        if (isNumber) {
            // konversi input ke integer
            jum_beli = stoi(input1);
            validInput = true;
        } else {                        // output yang dihasilkan apabila input nya tidak sesuai dan melakukan input lagi
				system ("cls");
            	cout << "          ALFAMART RAWA LUMBU / 085714713706\n";
				cout << "             PT.SUMBER ALFARIA TRIJAYA,TBK\n";
				cout << endl;
				cout << "        ALFA TOWER LT.12, ALAM SUTERA, TANGGERANG\n";
				cout << "             HPWP : 01.226.238.0-054.000\n";
				cout << "        JL.RAYA JEMBATAN NO.9 RT.06/R RAWALUMBU\n";
				cout << endl;
				setcolor (10);
				cout << "=========================================================\n";
				setcolor (15);
				cout << endl;
        }
    }


// memasukkan nama, harga, jumlah barang
	for (int i=0; i<jum_beli;i++){
		cout<<endl;
		cout<<"Masukan Barang Ke-"<<i+1<<endl;

		cout << "";					// buat mengecoh getlinenya ini gak di input apa apa alias kosong
		getline (cin, hilang);

		cout<<"Nama Barang : ";
		getline (cin,nama_barang[i]); //Pengguna input nama barang disimpan pada array nama_barang
			
// Input jumlah barang
bool validInput = false;     
    while (!validInput) {
        setcolor(15);
        cout << "Jumlah      : ";
        string input2;
        cin >> input2;

// pengecekan apakah input hanya terdiri dari angka
        bool isNumber = true;
        for (char c : input2) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

// melakukan pengecekan ulang
        if (isNumber) {
            // konversi input ke integer
            jumlah[i] = stoi(input2);
            validInput = true;
        } else {                        // output yang dihasilkan apabila input nya tidak sesuai dan melakukan input lagi
				setcolor (12);  
            	cout << "Input tidak valid !!\n" << endl;
            	setcolor (15);
        }
    }
			
		cout<<"Harga       : ";
		cin>>harga[i]; //Pengguna input harga disimpan pada array harga

		sub_tot[i]=jumlah[i]*harga[i]; // Menjumlahkan Harga sub total barang
		tot+=sub_tot[i]; //Menjumlahkan seluruh sub total barang
	}

	// ouput struk belanja
cout<<"\n";
system ("cls");
setcolor (2);
cout<<"----------------------------------------------------------------------------------"<<endl;
setcolor (15);
cout<<"No   Nama Barang              Jumlah               Harga                   Sub Total"<<"\n";
cout<<"------------------------------------------------------------------------------------\n\n";
for (int i=0;i<jum_beli;i++){
    cout<<i+1<<". "<<setw(10)<<nama_barang[i]<<setw(20)<<jumlah[i]<<setw(25)<<fixed<<setprecision(2)<<harga[i]<<setw(25)<<fixed<<setprecision(2)<<sub_tot[i]<<endl;
    //Menampilkan semua nilai array dengan format rapi dan menggunakan setprecision() agar nilai desimal ditampilkan dengan 2 angka di belakang koma
}
setcolor (2);
cout<<"----------------------------------------------------------------------------------\n"<<endl;
setcolor (15);

//Kondisi untuk menentukan diskon yang didapatkan berdasarkan total belanja
	if (tot==100000){
		diskon=0.06*tot;
	} else if (tot>=50000){
		diskon=0.04*tot;
	}else if (tot>=25000){
		diskon=0.02*tot;
	}else {
		diskon=0;
	}

//Menampilkan Keterangan
	cout<<"Jumlah Bayar : Rp."<<tot<<endl;//Menampilkan jumlah bayar (belum termasuk diskon)
	cout<<"Dikon        : Rp."<<diskon<<endl; //Menampilkan diskon
	cout<<"Total Bayar  : Rp."<<tot-diskon<<endl;//Menampilkan total harga yang harus dibayar
	cout<<"Bayar        : Rp.";
	cin>>bayar; // Input dari user untuk jumlah yang dibayar
	cout<<"Kembali      : Rp."<<(bayar-(tot-diskon))<<endl; // Menampilkan uang kembali

// penutup
	cout << endl;
	setcolor (10);
	cout << "=========================================================\n\n";
	setcolor (15);
	cout << "Terimakasih telah berbelanja di toko kami :) semoga kamu senang belanja di toko kami\n";


// pengulang menu 5 sistem belanja
cout << "\n\n";
setcolor (14);
cout << "Apakah Anda Ingin Kembali Ke Menu (y/n) : ";
cin >> yn1;
setcolor (15);
if (yn1 =="y"||yn1 =="Y"){
				system ("cls");
				goto menu5;
			} else {
				system ("cls");
				return 0;
			}
}