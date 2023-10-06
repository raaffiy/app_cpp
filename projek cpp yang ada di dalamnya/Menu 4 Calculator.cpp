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
#include <limits>

using namespace std;

void setcolor (unsigned short color) {
	HANDLE hCon= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

int main() {

// tipe data jumlah bilangan 
string yn1;
menu4:
long long int jumlahBilangan;           // untuk menghitung jumlah bilangan lebih dari ratusan juta

// judul program
system ("cls");
setcolor (14);
cout << "-------- Calculator --------\n\n\n";
setcolor (15);

// Input jumlah bilangan
bool validInput = false;     
    while (!validInput) {
        setcolor(15);
        cout << "Masukkan jumlah bilangan yang ingin diinputkan : ";
        string input;
        cin >> input;

// pengecekan apakah input hanya terdiri dari angka
        bool isNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

// melakukan pengecekan ulang
        if (isNumber) {
            // konversi input ke integer
            jumlahBilangan = stoi(input);
            validInput = true;
        } else {                        // output yang dihasilkan apabila input nya tidak sesuai dan melakukan input lagi
            system ("cls");
            setcolor (14);
            cout << "-------- Calculator --------\n\n\n";
            setcolor (15);
        }
    }

// tipe data dari input bilangan
cout << endl;
long double bilangan[jumlahBilangan];           // untuk menghitung jumlah bilangan lebih dari ratusan juta
string input;

// input data
for (int i = 0; i < jumlahBilangan; i++) {
    cout << "Masukkan bilangan ke-" << i + 1 << ": ";
    cin >> input;

// Pengecekan data
        try {
            bilangan[i] = stod(input);
        } catch(exception& e) {                         // output apabila input tidak sesuai
            setcolor (12);  
            cout << "Input tidak valid !!" << endl;
            setcolor (15);
            i--;
        }
    }
cout << endl;
menu4salah: // kembali ke sini apabila input operator nya salah

// menentukan apakah (+,-,*, atau /)
long double hasil = bilangan[0];
string operasi;
cout << "Masukkan operasi yang ingin dilakukan (";
setcolor (2);
cout << " +, -, *, atau / ";
setcolor (15);
cout << "): ";
cin >> operasi;

// dihitung
for (int i = 1; i < jumlahBilangan; i++) {
    if (operasi == "+") {
        hasil += bilangan[i];
    } else if (operasi == "-") {
        hasil -= bilangan[i];
    } else if (operasi == "*") {
        hasil *= bilangan[i];
    } else if (operasi == "/") {
        hasil /= bilangan[i];
    } else {
        goto menu4salah; // kembali ke memilih apabila input yang dimasukkan salah
    }
}

// output
cout << "\n\n";
setcolor (10);
cout << "Hasil dari operasi tersebut adalah: " << hasil << endl;
setcolor (15);

// pengulang penjumlah menu 4
cout << "\n\n";
setcolor (14);
cout << "Apakah Anda Ingin Kembali Ke Menu (y/n) : ";
cin >> yn1;
setcolor (15);
    if (yn1 =="y"||yn1 =="Y"){
        system ("cls");
        goto menu4;
    } else {
        system ("cls");
        goto menu4;
    }
}