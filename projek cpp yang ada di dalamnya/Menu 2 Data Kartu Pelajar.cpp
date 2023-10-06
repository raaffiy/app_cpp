#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <time.h>
#include <dos.h>

using namespace std;
void setcolor (unsigned short color) {
	HANDLE hCon= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

//////////////////////////////////
//  input output Biodata menu 2 //
//////////////////////////////////
int main() {
menu2:
	string pilih,yn1;
	setcolor (10);
	cout<<"------------------------------------------------------------------\n";
	setcolor (11);
	cout<<"           Data Kartu Pelajar Siswa Kelas X RPL Industri                  \n";
	setcolor (10);
	cout<<"------------------------------------------------------------------\n\n";
	setcolor (15);
	cout << " 1.  AL MAS BALQIS KHAIRUNNISA          13. MOCHAMMAD HAZEL KAMIL\n";
	cout << " 2.  ALIF IKROM AKBAR                   14. MUHAMMAD ANDRY ALFARISI\n";
	cout << " 3.  ALYA SURYA NINGTIAS                15. MUHAMMAD RIDWAN\n";
	cout << " 4.  BANYU REKSA GHAISAN PRADIFA        16. NAILAH LEANI UTAMI\n";
	cout << " 5.  DIMAS AKBAR ASSHIDQI               17. NAJWAN RAIHAN AZHARI\n";
	cout << " 6.  DIMAS ALFIANSYAH PUTRA             18. RADEN MAKDUM\n";
	cout << " 7.  FELI ALTIFA MAHENDRA               19. RADITYA DAFFA PRATAMA\n";
	cout << " 8.  FERDIAN ABDILAH                    20. RAMA ANDERALDI FAJR\n";
	cout << " 9.  FITROH NOVIANTO WIDIATMOKO         21. RIFKY AHMAD PUTRA SUNDAWA\n";
	cout << " 10. IRFAN RAMADHAN TAUFIK              22. RONY WIJAYA\n";
	cout << " 11. KHALILA NAJLA                      23. SYAHRUL FITRA AGHFARI\n";
	cout << " 12. MAULANA RA'AFI                     24. TIARA NUR HAKIM\n\n";
	setcolor (12);
	cout << "Laki-Laki = 18\n";
	setcolor (13);
	cout << "Perempuan = 6\n";
	setcolor (15);
	
// input pemilihan data siswa 
	cout << endl;
	cout << "Pilih Angka Yang Ingin DI lihat Datanya\n";
	cout << "Masukkan Pilihan Anda [ 1 s.d 24 ] = ";
	cin >> pilih;
	cout << endl;
	
// output pemilihan data siswa
	if (pilih == "1"){
		setcolor (7);
		cout << " Nama            : Al Mas Balqis Khairunnisa\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Perempuan\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "2"){
		setcolor (7);
		cout << " Nama            : Alif Ikrom Akbar\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "3"){
		setcolor (7);
		cout << " Nama            : Alya Surya Ningtias\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Perempuan\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "4"){
		setcolor (7);
		cout << " Nama            : Banyu Reksa Ghaisan Pradifa\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "5"){
		setcolor (7);
		cout << " Nama            : Dimas Akbar Asshidqi\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "6"){
		setcolor (7);
		cout << " Nama            : Dimas Alfiansyah Putra\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "7"){
		setcolor (7);
		cout << " Nama            : Feli Altifa Mahendra\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Perempuan\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "8"){
		setcolor (7);
		cout << " Nama            : Ferdian Abdilah\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "9"){
		setcolor (7);
		cout << " Nama            : Fitroh Novianto Widiatmoko\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "10"){
		setcolor (7);
		cout << " Nama            : Irfan Ramadhan Taufik\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "11"){
		setcolor (7);
		cout << " Nama            : Khalila Najla\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Perempuan\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "12"){
		setcolor (7);
		cout << " Nama            : Maulana ra'afi\n";	cout << " Nis             : 222310403\n";	cout << " TTL             : Rembang, 06 Oktober 2006\n";
		cout << " Jenis Kelamin   : Laki-laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : Bojong Menteng, Rawa Lumbu, Rt 02 Rw 06, Kota Bekasi\n";
	}
	else if (pilih == "13"){
		setcolor (7);
		cout << " Nama            : Mochammad Hazel Kamil\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "14"){
		setcolor (7);
		cout << " Nama            : Muhammad Andry Alfarisi\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "15"){
		setcolor (7);
		cout << " Nama            : Muhammad Ridwan\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "16"){
		setcolor (7);
		cout << " Nama            : Nailah Leani Utami\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Perempuan\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "17"){
		setcolor (7);
		cout << " Nama            : Najwan Raihan Azhari\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "18"){
		setcolor (7);
		cout << " Nama            : Raden Makdum\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "19"){
		setcolor (7);
		cout << " Nama            : Raditya Daffa Pratama\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "20"){
		setcolor (7);
		cout << " Nama            : Rama Anderaldi Fajr\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "21"){
		setcolor (7);
		cout << " Nama            : Rifky Ahmad Putra Sundawa\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "22"){
		setcolor (7);
		cout << " Nama            : Rony Wijaya\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}
	else if (pilih == "23"){
		setcolor (7);
		cout << " Nama            : Syahrul Fitra Aghfari\n";	cout << " Nis             : 222310414\n";	cout << " TTL             : Magetan, 15 Oktober 2006\n";
		cout << " Jenis Kelamin   : Laki-Laki\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : Griya Alam Sentosa Blok P 20 No 4, Desa. Pasir Angin, Kec. Cileungsi, Kab. Bogor\n";
	}
	else if (pilih == "24"){
		setcolor (7);
		cout << " Nama            : Tiara Nur Hakim\n";	cout << " Nis             : \n";	cout << " TTL             : \n";
		cout << " Jenis Kelamin   : Perempuan\n";	cout << " Agama           : Islam\n";	cout << " Alamat          : \n";
	}else {
	system ("cls");   
    goto menu2;
}
	
// mengulagi absen sekolah menu 2
cout << "\n\n";
setcolor (14);
cout<<"Apakah Anda Ingin Kembali Ke Menu ? (y/n) : ";
cin>>yn1;
setcolor (15);
			if (yn1 =="y"||yn1 =="Y"){
				system ("cls");
				goto menu2;		// kembali ke menu
			} else {
				system ("cls");
				goto menu2;		// kembali ke menu 2
			}
}
