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

/////////////////////////////////	
///// input hari dan menu 1 ///// 
/////////////////////////////////
int main () {
string hari, yn1;		// menentukan hari dan jadwal sekolah
menu1: cout << "\n";

// input nama hari
setcolor (10);
cout << "==============================================================\n";
setcolor (15);
cout << endl;
cout << "Jadwal Mata Pelajaran\n" << endl;
cout << "Senin, Selasa, Rabu, Kamis, Jum'at" << endl;
cout << "Hari : ";
cin >> hari;
cout << endl;
setcolor (10);
cout << "==============================================================\n"; 
setcolor (15);
cout << endl;
				
// output hari
if ( hari == "Senin" || hari == "senin" || hari == "SENIN" ) {
	cout << "Hari          : Senin" << endl;
	cout << endl;
	setcolor (12);
	cout << " 06.45 - 07.30 : UPACARA " << endl;
	setcolor (15);
	setcolor (10);
	cout << " 07.30 - 07.45 : TADARUS" << endl;
	setcolor (15);
	cout << " 07.45 - 08.30 : IPAS " << endl; 
	cout << " 08.30 - 09.15 : IPAS " << endl;
	cout << " 09.15 - 10.00 : IPAS " << endl;
	setcolor(9);
	cout << " 10.00 - 10.20 : ISTIRAHAT " << endl;
	setcolor (15);
	cout << " 10.20 - 11.05 : IPAS " << endl;
	cout << " 11.05 - 11.50 : IPAS " << endl;
	setcolor(9);
	cout << " 11.50 - 12.30 : ISTIRAHAT " << endl;
	setcolor (15);
	cout << " 12.30 - 13.05 : IPAS " << endl;
	cout << " 13.05 - 13.40 : B. INDO " << endl;
	cout << " 13.40 - 14.15 : B. INDO " << endl;
	cout << " 14.15 - 14.50 : MTK " << endl;
	cout << " 14.50 - 15.25 : MTK " << endl;
}
else if ( hari == "Selasa" || hari == "selasa" || hari == "SELASA" ) {
	cout << "Hari          : Selasa" << endl;
	cout << endl;
	setcolor (10);
	cout << " 06.45 - 07.00 : TADARUS " << endl;
	setcolor (15);
	cout << " 07.00 - 07.45 : MTK " << endl;
	cout << " 07.45 - 08.30 : MTK " << endl; 
	cout << " 08.30 - 09.15 : DASJUR " << endl;
	cout << " 09.15 - 10.00 : DASJUR " << endl;
	setcolor(9);
	cout << " 10.00 - 10.15 : ISTIRAHAT " << endl;
	setcolor (15);
	cout << " 10.15 - 11.00 : DASJUR " << endl;
	cout << " 11.00 - 11.45 : DASJUR " << endl;
	setcolor(9);
	cout << " 11.45 - 12.30 : ISTIRAHAT " << endl;
	setcolor (15);
	cout << " 12.30 - 13.15 : DASJUR " << endl;
	cout << " 13.15 - 14.00 : DASJUR " << endl;
	cout << " 14.00 - 14.45 : DASJUR " << endl;
	cout << " 14.45 - 15.30 : DASJUR " << endl;
}
else if ( hari == "Rabu" || hari == "rabu" || hari == "RABU" ) {
	cout << "Hari          : Rabu" << endl;
	cout << endl;
	setcolor (10);
	cout << " 06.45 - 07.00 : TADARUS " << endl;
	setcolor (15);
	cout << " 07.00 - 07.45 : DASJUR " << endl;
	cout << " 07.45 - 08.30 : DASJUR " << endl; 
	cout << " 08.30 - 09.15 : DASJUR " << endl;
	cout << " 09.15 - 10.00 : DASJUR " << endl;
	setcolor(9);
	cout << " 10.00 - 10.15 : ISTIRAHAT " << endl;
	setcolor (15);
	cout << " 10.15 - 11.00 : B. INDO " << endl;
	cout << " 11.00 - 11.45 : B. INDO " << endl;
	setcolor(9);
	cout << " 11.45 - 12.30 : ISTIRAHAT " << endl;
	setcolor (15);
	cout << " 12.30 - 13.15 : SBK " << endl;
	cout << " 13.15 - 14.00 : SBK " << endl;
	cout << " 14.00 - 14.45 : B. INGGRIS " << endl;
	cout << " 14.45 - 15.30 : B. INGGRIS " << endl;
}
else if ( hari == "Kamis" || hari == "kamis" || hari == "KAMIS" ) {
	cout << "Hari          : Kamis" << endl;
	cout << endl;
	setcolor (10);
	cout << " 06.45 - 07.00 : TADARUS " << endl;
	setcolor (15);
	cout << " 07.00 - 07.45 : PABP " << endl;
	cout << " 07.45 - 08.30 : PABP " << endl; 
	cout << " 08.30 - 09.15 : PABP " << endl;
	cout << " 09.15 - 10.00 : PJOK " << endl;
	setcolor(9);
	cout << " 10.00 - 10.15 : ISTIRAHAT " << endl;
	setcolor (15);
	cout << " 10.15 - 11.00 : PJOK " << endl;
	cout << " 11.00 - 11.45 : PJOK " << endl;
	setcolor(9);
	cout << " 11.45 - 12.30 : ISTIRAHAT " << endl;
	setcolor (15);
	cout << " 12.30 - 13.15 : PP " << endl;
	cout << " 13.15 - 14.00 : PP " << endl;
	cout << " 14.00 - 14.45 : B. SUNDA " << endl;
	cout << " 14.45 - 15.30 : B. SUNDA " << endl;
}
else if ( hari == "Jum'at" || hari == "jum'at" || hari == "JUM'AT" || hari == "JUMAT" || hari == "Jumat" || hari == "jumat" ) {
	cout << "Hari          : Jum'at" << endl;
	cout << endl;
	setcolor (10);
	cout << " 06.45 - 07.00 : TADARUS " << endl;
	setcolor (15);
	cout << " 07.00 - 07.45 : INFORMATIKA " << endl;
	cout << " 07.45 - 08.30 : INFORMATIKA " << endl; 
	cout << " 08.30 - 09.15 : INFORMATIKA " << endl;
	cout << " 09.15 - 10.00 : INFORMATIKA " << endl;
	setcolor(9);
	cout << " 10.00 - 10.15 : ISTIRAHAT " << endl;
	setcolor (15);
	cout << " 10.15 - 11.00 : SEJARAH " << endl;
	cout << " 11.00 - 11.45 : SEJARAH " << endl;
	setcolor(9);
	cout << " 11.45 - 12.30 : ISTIRAHAT " << endl;
	setcolor (15);
	cout << " 12.30 - 13.15 : B. INGGRIS " << endl;
	cout << " 13.15 - 14.00 : B. INGGRIS " << endl;
} else {
	system ("cls");   
    goto menu1;
}

// mengulagi jadwal sekolah menu 1
cout << "\n\n";
setcolor (14);
cout<<"Apakah Anda Ingin Kembali Ke Menu ? (y/n) : ";
cin>>yn1;
setcolor (15);
			if (yn1 =="y"||yn1 =="Y"){
				system ("cls");
				goto menu1;	// kembali ke menu 
			} else {
				system ("cls");
				goto menu1;		// kembali ke menu 1
			}

return 0;
}
