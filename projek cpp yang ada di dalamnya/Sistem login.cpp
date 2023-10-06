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
void login();
void registr();
void forgot();

void setcolor (unsigned short color) {
	HANDLE hCon= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

/////////////////////////
///// Judul Program /////
/////////////////////////
main() {
    system ("cls");
	  setcolor (15);
    string choice;	
	
// judul program	
        cout << "\n\n\n\n\n\n\n\n";
		    cout << "\t\t\t         SMK NEGERI 2 KOTA BEKASI \n";
		    cout << "\t\t\t  UNGGUL BERKARAKTER DAN BERWAWASAN GLOBAL \n";
		    cout << "\t\t ----------------------------------------------------------\n";
        cout << "\t\t\t1.Login" << endl;
        cout << "\t\t\t2.Register" << endl;
        cout << "\t\t\t3.Lupa Password atau Username" << endl;
        cout << "\t\t\t4.Exit" << endl;
        cout << "\nMasukkan Pilihan Anda [ 1 s.d 4 ] : ";
        cin >> choice;
        cout << endl;
        
// pemilihan menu 1,2,3, dan 4
        if (choice == "1") {
                        login();			// pergi ke void login
                        return 0;
                }
        else if (choice == "2") {
                        registr();			// pergi ke void registr
                        return 0;
            	}
        else if (choice == "3") {
                        forgot();			// pergi ke void forgot
                        return 0;
            	}
        else if (choice == "4") {						// sistem end
						system ("cls");
						cout<<"\n\n\n\n\n\n\n\n";
						setcolor (6);
                        cout<<"\t\t\t-- Terimakasih Telah Melihat Program Ini --\n";
                        setcolor (15);
                        cout << "\t\t\t    By Maulana ra'afi \n";
                        cout << "\t\t\t    Kelas : RPL K.I \n\n";
                        return 0;				// progra selesai
            	}
        	else {
                        system("cls"); 		// apabila input salah
                        main();				// kembali ke menu();
        } 
}

////////////////////////
///// Sistem Login /////
////////////////////////
void login() {
  string user, u, p;
  char pass[9999];
  string nam, kel, n, k;

// memasukkan username dan password
  cout << "Username : ";
  cin >> user;
  cout << "Password : ";

// percabangan apabila saat input password akan berupa bintang (*)
  int i = 0;
  while (i < 9999) {
    char ch = getch();
    if (ch == 13) {
      pass[i] = '\0';
      break;
    }
    else if (ch == 8) {
      if (i > 0) {
        cout << "\b \b";
        --i;
      }
    }
    else {
      pass[i++] = ch;
      cout << "*";
    }
  }
  cout << endl;

// Memeriksa apakah file sudah ada atau belum
  ifstream input("database.txt");			// Membuka file database
  if (!input.good()) {
    setcolor(4);
    cout << "\n-- Username or Password Invalid --\n";
    setcolor(15);
    cout << "Please check your username and password\n\n\n";
    system("pause");
    system("cls");
    main();
  }

// output login success
  while(input >> u >> p >> n >> k) {		//mencari data di database
    if (u == user && p == pass) {
      system("cls");
      cout << "\n\n\n\n\n\n\n\n";
      cout << "\t\t\t         SMK NEGERI 2 KOTA BEKASI \n";
      cout << "\t\t\t  UNGGUL BERKARAKTER DAN BERWAWASAN GLOBAL \n";
      cout << "\t\t ----------------------------------------------------------\n\n\n";
      setcolor(10);
      cout << "\n\t      Login Success\n";
      setcolor(15);

      cout << "\t --------------------------\n";
      cout << "\t Nama : " << n << endl;
      cout << "\t Kelas : " << k << endl;
      cout << "\t --------------------------\n\n\n";
      system("pause");
      system("cls");
      main();
      break;
    }
  }
  input.close();		// menutup file database

// apabila file ada di database dan saat memasukkan username dan password salah
  if (input.eof()) {
    setcolor(4);
    cout << "\n-- Username or Password Invalid --\n";
    setcolor(15);
    cout << "Please check your username and password\n\n\n";
    system("pause");
    system("cls");
    main();
  }
}


//////////////////////////////
///// Sistem pendaftaran /////
//////////////////////////////
void registr() {

// variabel sistem pendaftaran
    string reguser,ru,rp;
    string nama,kl,o,o2;

// memasukkan username
    while (true) {
        cout<<"Enter the username : ";
        cin>>reguser;

// pengecekan apakah data username sudah ada di database atau blm
        ifstream reg("database.txt");
        bool flag = false;
        while (reg >> ru >> rp >> nama >> kl) {
            if (ru == reguser) {
                flag = true;
                break;
            }
        }

// output apabila username sudah ada di database
        if (flag) {
            system("cls");
                setcolor (12);
                cout << "Username sudah terpakai, masukkan username lain" << endl;
                setcolor (15);
                cout << "\n\n\n\n\n\n\n\n";
		        cout << "\t\t\t         SMK NEGERI 2 KOTA BEKASI \n";
		        cout << "\t\t\t  UNGGUL BERKARAKTER DAN BERWAWASAN GLOBAL \n";
		        cout << "\t\t ----------------------------------------------------------\n";
                cout << "\t\t\t1.Login" << endl;
                cout << "\t\t\t2.Register" << endl;
                cout << "\t\t\t3.Lupa Password atau Username" << endl;
                cout << "\t\t\t4.Exit" << endl;
                cout << "\nMasukkan Pilihan Anda [ 1 s.d 4 ] : \n\n";
            continue;
        }
        else {
            break;
        }
    }

// Memasukkan Password
char regpass[9999]; // input akan berupa bintang (*)
cout << "\nEnter the password : ";

// percabangan apabila saat input password akan berupa bintang (*)
  int i = 0;
  while (i < 9999) {
  char ch = getch();

// if else
    if (ch == 13) { // karakter Enter
      regpass[i] = '\0';
      break;
    }
    else if (ch == 8) { // karakter Backspace
        if (i > 0) {
            cout << "\b \b";
            --i;
        }
    }
    else {
        regpass[i++] = ch;
        cout << "*";
    }
}

// memasukkan nama dan kelas
        cout<<"";
        getline(cin,o);
        cout << "";
        getline(cin,o2);
        cout << "\n\n";

	  setcolor (2);
    cout << "-- Data Diri --\t";
    setcolor (15);
    cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi\n";
    cout << "Nama : ";
    cin >> nama;
    cout << "Kelas : ";
    cin >> kl;

// data akan di simpan di database.txt
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<' '<<nama<<' '<<kl<<endl;
        system("cls");
        setcolor (10);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        main();
}


//////////////////////////////////
///// lupa password/username /////
//////////////////////////////////
void forgot() {

// judul / pembuka forgot
    string ch;
    system("cls");
    setcolor (14);
    cout<<"--- Lupa dengan Password atau Username ?? we will help you ---\n\n";
    setcolor (15);
    cout<<"1. Cari Password dengan Memasukkan Username" << endl;
    cout<<"2. Cari Username dengan Memasukkan Password"<<endl;
    cout<<"3. Back\n";
    cout<<"Masukkan Pilihan Anda [ 1 s.d 3 ] : ";
    cin>>ch;
        
// menu 1 cari password 
if (ch == "1"){

// variabel dan input username yang di ingat
    string searchuser,su,sp,n1,k1;
    cout<<"\nMasukkan Username yang anda ingat : ";		// memasukkan data yang diingat oleh pengguna
    cin>>searchuser;
                        
// Memeriksa apakah file sudah ada atau belum 
  ifstream searchu("database.txt");			// Membuka file database
  if (!searchu.good()) { 
    	setcolor (4);		
        cout<<"\nSorry, Your userID is not found in our database";
        setcolor (15);
        cout<<"\nPlease kindly contact your system administrator for more details \n";
        cout << "\n\n\n";
        system ("pause");
        system ("cls");
        forgot();				// kembali ke void forgot();
  }

// mencari data di database                
  while(searchu>>su>>sp>>n1>>k1) {
	if(su==searchuser) {
		
// output data apabila data ada di database
        setcolor (10);
        cout<<"\n\nHoree, your account found in the database";
        setcolor (15);
    	  cout<<"\nYour password is "<<sp;	// output password apabila ada datanya 
        cout << "\n\n\n";
        system ("pause");
        system("cls");
        forgot();				// kembali ke void forgot();
    	  break;
    	}
    }
    searchu.close();						// menutup file database.txt 

// output data apabila data yang diinputkan tidak ada di database
    if (searchu.eof()) {						
        setcolor (4);		
        cout<<"\nSorry, Your userID is not found in our database";
        setcolor (15);
        cout<<"\nPlease kindly contact your system administrator for more details \n";
        cout << "\n\n\n";
        system ("pause");
        system ("cls");
        forgot();				// kembali ke void forgot();
    }
}

// menu 2 cari username
else if (ch == "2"){
	
// variabel dan input username yang di ingat
    string searchpass,su2,sp2,n2,k2;
    cout<<"\nMasukkan Password yang anda ingat : ";		// memasukkan data yang diingat oleh pengguna
    cin>>searchpass;

// Memeriksa apakah file sudah ada atau belum 
  ifstream searchp("database.txt");			// Membuka file database
  if (!searchp.good()) { 
    	setcolor (4);
        cout<<"\nSorry, We cannot found your password in our database";
        setcolor (15);
        cout<<"\nPlease kindly contact your system administrator for more details \n";
        cout << "\n\n\n";
        system ("pause");
        system ("cls");
        forgot();				// kembali ke void forgot();
  }
  
// mencari data di database       
    while(searchp>>su2>>sp2>>n2>>k2) {
    if(sp2==searchpass) {

// output data apabila data ada di database
        setcolor (10);
        cout<<"\nsuccess, Your password is found in the database";
        setcolor (15);
        cout<<"\nYour Username is : "<<su2;		// output username apabila ada datanya
        cout << "\n\n\n";
        system ("pause");
        system("cls");
        forgot();				// kembali ke void forgot();
        break;
        }       
    }
    searchp.close();							// menutup file database.txt
    
// output data apabila data yang diinputkan tidak ada di database
	if (searchp.eof()) {								
        setcolor (4);
        cout<<"\nSorry, We cannot found your password in our database";
        setcolor (15);
        cout<<"\nPlease kindly contact your system administrator for more details \n";
        cout << "\n\n\n";
        system ("pause");
        system ("cls");
        forgot();				// kembali ke void forgot();
        }
    }    
    
// menu 3 exit
else if (ch == "3"){			
    system ("cls");
    main();				// kembali ke main / judul
}

// apabila input yang di masukan tidak sesuai 
else {					
    forgot();		// kembali ke void forgot();
    }
}
