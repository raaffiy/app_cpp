#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;
void setcolor (unsigned short color) {
	HANDLE hCon= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

///////////////////////////////
// Variabel kehadiran menu 3 //
//////////////////////////////
const int MAX_N = 100;
const int MAX_HT = 100;		// untuk menggunakan getline di dalam array
const int MAX_K = 100;

/////////////////////////////////
//// Menu 3 sistem kehadiran ////
/////////////////////////////////
int main () {
menu3:	
string cls, yn1, outputhilang;
string nama[MAX_N]; 		//array untuk menyimpan nama
string hadir[MAX_HT];		 //array untuk menyimpan jumlah hadir
string keterangan[MAX_K];	 //array untuk menyimpan keterangan hadir
long long int jumlah_mahasiswa; 		//variabel untuk menyimpan jumlah mahasiswa
int jumlah_tidak_hadir = 0;	// variabel untuk menghitung jumlah siswa yang tidak hadir
int jumlah_hadir = 0;		// variabel untuk menghitung jumlah siswa yang hadir

//Judul Program
system ("cls");
setcolor (15);
cout << "\n";
cout << " Sistem Kehadiran Siswa SMK Negeri 2 Kota Bekasi\n";
cout << "          Program Kelas X RPL Industri           \n";
setcolor (2);
cout << "--------------------------------------------------\n";
setcolor (15);
cout << "\n";

// input jumlah siswa
bool validInput = false;     
    while (!validInput) {
        setcolor(15);
        cout << "Masukkan Jumlah Siswa : ";
        string masuk;
        cin >> masuk;

// pengecekan apakah input hanya terdiri dari angka
        bool isNumber = true;
        for (char c : masuk) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

// melakukan pengecekan ulang
        if (isNumber) {
            // konversi input ke integer
            jumlah_mahasiswa = stoi(masuk);
            validInput = true;
        } else {                        // output yang dihasilkan apabila input nya tidak sesuai dan melakukan input lagi
			system ("cls");
            setcolor (15);
			cout << "\n";
			cout << " Sistem Kehadiran Siswa SMK Negeri 2 Kota Bekasi\n";
			cout << "          Program Kelas X RPL Industri           \n";
			setcolor (2);
			cout << "--------------------------------------------------\n";
			setcolor (15);
			cout << "\n";
        }
    }

cout << "";								// ini gak masukkan apa apa cuman ngecohin getline nya
getline (cin, outputhilang);			// 
cout << "Kelas : ";						// ini baru masukkan nama kelas nya
getline (cin, cls);						//  
setcolor (2);
cout << "\n--------------------------------------------------\n\n";
setcolor (15);

//input nama dan jumlah hadir setiap mahasiswa
for(int i=0; i<jumlah_mahasiswa; i++){
    	cout << i+1 << "." << " Masukkan nama siswa : ";
    	getline (cin, nama[i]);
	ht:
    	cout << "   Hadir / Tidak (H/T) : "; 
    	getline (cin, hadir[i]);
    
	if (hadir[i] == "T" || hadir[i] == "t" || hadir[i] == "Tidak" || hadir[i] == "tidak" || hadir[i] == "TIDAK"){
		jumlah_tidak_hadir++;
		cout << "   Keterangan (S/I/A) : ";
    	getline (cin, keterangan [i]);
	} else if (hadir[i] == "H" || hadir[i] == "h" || hadir[i] == "Hadir" || hadir[i] == "hadir" || hadir[i] == "HADIR"){
		jumlah_hadir++;
	} else {					// else ini digunakan untuk (saat input y dia akan masuk ke sini kalau tidak dia akan masuk ke atas itu)
	goto ht;
	}
	cout << endl;
}

// data di simpan
setcolor (11);
cout << "``Data Disimpan``\n\n\n";
setcolor (15);
system ("pause");
system ("cls");

//judul output
cout << "\n";
cout << " Sistem Kehadiran Siswa SMK Negeri 2 Kota Bekasi\n";
cout << "          Proram Kelas X RPL Industri           \n";
setcolor (2);
cout << "--------------------------------------------------\n";
setcolor (15);
cout << "\n\n\n";

// judul output 2
cout << "  No                Nama Siswa                  Hadir/Tidak         Keterangan (S/A/I)\n";
setcolor (11);
cout << "-----------------------------------------------------------------------------------------------------------\n";
setcolor (15);

// output
for(int i=0; i<jumlah_mahasiswa; i++){
    cout << setw(3) << i+1 << ". " << setw(30) << nama[i] << setw(20) << hadir[i] << setw(25) << keterangan[i] << endl;
}

// output kelas, jumlah siswa dan hadir / tidaknya siswa
cout << "\n\n";
cout << "Kelas : " << cls << endl;						// output kelas yang tadi diinput
cout << "Jumlah Siswa : " << jumlah_mahasiswa << endl;	// output jumlah siswa yang tadi diinput
cout << "Jumlah siswa yang hadir : " << jumlah_hadir << endl;	// output jumlah siswa yang di input hadir
cout << "Jumlah siswa yang tidak hadir : " << jumlah_tidak_hadir << endl;		// output jumlah siswa yang di input tidak hadir
setcolor (10);
cout << "-----------------------------\n\n";
setcolor (15);

// perulangan menu3		
cout << "\n\n";
setcolor (14);
cout<<"Apakah Anda Ingin Kembali Ke Menu ? (y/n) : ";
cin>>yn1;
setcolor (15);
			if (yn1 =="y"||yn1 =="Y"){
				system ("cls");
				goto menu3;		// kembali ke menu
			} else {
				return 0;
			}
}
