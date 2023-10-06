// selesaikan datanya
#include <iostream>
#include <windows.h>
#include <iomanip> 
#include <fstream>

void setcolor (unsigned short color) {
	HANDLE hCon= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

using namespace std;
int main () {

///////////////////////
/////// Tipe Data /////
///////////////////////
setcolor(15);
menud:
system ("cls");
string pill, kl1, kl2;      // kelas
string jur1x, jur1xi, jur1xii, jur2x, jur2xi, jur2xii;      //jurusan
string ktxrpl, ktxtkj, ktxtei, ktxtet, ktxak, ktxto;        // keterangan kelas x (input data)
string ktxirpl, ktxitkj, ktxitei, ktxitet, ktxiak, ktxito;      // keterangan kelas xi (input data)
string ktxiirpl, ktxiitkj, ktxiitei, ktxiitet, ktxiiak, ktxiito;        // keterangan kelas xii (input data)
string ktxrpl2, ktxtkj2, ktxtei2, ktxtet2, ktxak2, ktxto2;        // keterangan kelas x (Lihat data)
string ktxirpl2, ktxitkj2, ktxitei2, ktxitet2, ktxiak2, ktxito2;      // keterangan kelas xi (Lihat data)
string ktxiirpl2, ktxiitkj2, ktxiitei2, ktxiitet2, ktxiiak2, ktxiito2;        // keterangan kelas xii (Lihat data)
string ynd;     //kembali ke menu

// Pengecekan dan input data
string namacek, niscek, ttlcek, jkcek, almtcek;     // untuk melakukan pengecekan data apabila ada yang sama
string namainput, nisinput, ttlinput, jkinput, alamatinput;   // untuk menginput data 

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    string fileNames[] = {"x_rpl_1.txt", "x_rpl_2.txt", "x_rpl_3.txt", "x_rpl_ki.txt",           // pengecekan x
                            "x_tkj_1.txt", "x_tkj_2.txt", "x_tkj_3.txt", "x_tkj_ki.txt",
                            "x_tei_1.txt", "x_tei_2.txt", "x_tei_3.txt", "x_tei_ki.txt",
                            "x_tet_1.txt", "x_tet_2.txt", "x_tet_3.txt", "x_tet_ki.txt",
                            "x_ak_1.txt", "x_ak_2.txt", "x_ak_3.txt", "x_ak_ki.txt",
                            "x_to_1.txt", "x_to_2.txt", "x_to_3.txt", "x_to_ki.txt",    
                            "xi_rpl_1.txt", "xi_rpl_2.txt", "xi_rpl_3.txt", "xi_rpl_ki.txt",     // pengecekan xi
                            "xi_tkj_1.txt", "xi_tkj_2.txt", "xi_tkj_3.txt", "xi_tkj_ki.txt",
                            "xi_tei_1.txt", "xi_tei_2.txt", "xi_tei_3.txt", "xi_tei_ki.txt",
                            "xi_tet_1.txt", "xi_tet_2.txt", "xi_tet_3.txt", "xi_tet_ki.txt",
                            "xi_ak_1.txt", "xi_ak_2.txt", "xi_ak_3.txt", "xi_ak_ki.txt",
                            "xi_to_1.txt", "xi_to_2.txt", "xi_to_3.txt", "xi_to_ki.txt",
                            "xii_rpl_1.txt", "xii_rpl_2.txt", "xii_rpl_3.txt", "xii_rpl_ki.txt",  // pengecekan xii
                            "xii_tkj_1.txt", "xii_tkj_2.txt", "xii_tkj_3.txt", "xii_tkj_ki.txt",
                            "xii_tei_1.txt", "xii_tei_2.txt", "xii_tei_3.txt", "xii_tei_ki.txt",
                            "xii_tet_1.txt", "xii_tet_2.txt", "xii_tet_3.txt", "xii_tet_ki.txt",
                            "xii_ak_1.txt", "xii_ak_2.txt", "xii_ak_3.txt", "xii_ak_ki.txt",
                            "xii_to_1.txt", "xii_to_2.txt", "xii_to_3.txt", "xii_to_ki.txt",                            
                            };

////////////////
///// Menu /////
////////////////
setcolor (10);
cout<<"------------------------------------------------------------------\n";
setcolor (11);
cout<<"                   Database Kartu Pelajar Siswa                   \n";
setcolor (10);
cout<<"------------------------------------------------------------------\n\n";
setcolor (15);
cout << "1. Input Data\n";
cout << "2. Lihat Data\n";
cout << "3. Keluar\n";
setcolor(14);
cout << "Masukkan Pilihan Anda [ 1 s.d 3 ] : ";
cin >> pill;
cout << "\n";
setcolor(15);


// Pilih 1
if (pill == "1"){

// Input Kelas
    kel1:
    cout << "Kelas [ X, XI, XII ] : ";
    cin >> kl1;

// Pilih X 
    if (kl1 == "X" || kl1 == "x" || kl1 == "Sepuluh" || kl1 == "sepuluh" || kl1 == "SEPULUH"){

// Input Jurusan
    jur1x:
    cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
    cin >> jur1x;

// Pilih RPL
    if (jur1x == "RPL" || jur1x == "rpl" || jur1x == "Rpl"){

// keterangan 
    ktxrpl:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxrpl;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxrpl == "1"){

//////////////////////////////
///// Input Data x rpl 1 /////
//////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X RPL 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;

// input NIS X RPL 1
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data1("x_rpl_1.txt",ios::app);
        data1<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;
        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxrpl == "2"){

//////////////////////////////
///// Input Data x rpl 2 /////
//////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X RPL 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;

// input NIS X RPL 2
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data2("x_rpl_2.txt",ios::app);
        data2<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxrpl == "3"){

//////////////////////////////
///// Input Data x rpl 3 /////
//////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X RPL 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data3("x_rpl_3.txt",ios::app);
        data3<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxrpl == "K.I" || ktxrpl == "k.i" || ktxrpl == "KI" || ktxrpl == "ki"){

////////////////////////////////
///// Input Data x rpl K.I /////
//////////////////////////////// 

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X RPL K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_rpl_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxrpl;
    }

// Pilih TKJ
    } else if (jur1x == "TKJ" || jur1x == "tkj" || jur1x == "Tkj"){

// keterangan 
    ktxtkj:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxtkj;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 1
    if (ktxtkj == "1"){

//////////////////////////////
///// Input Data x tkj 1 /////
//////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TKJ 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tkj_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
                system ("cls");
                goto menud;
    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxtkj == "2"){

//////////////////////////////
///// Input Data x tkj 2 /////
//////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TKJ 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tkj_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxtkj == "3"){

//////////////////////////////
///// Input Data x tkj 3 /////
//////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TKJ 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tkj_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxtkj == "K.I" || ktxtkj == "k.i" || ktxtkj == "KI" || ktxtkj == "ki"){

////////////////////////////////
///// Input Data x tkj k.i /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TKJ K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tkj_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxtkj;
    }

// Pilih TEI
    } else if (jur1x == "TEI" || jur1x == "tei" || jur1x == "Tei"){

// keterangan 
    ktxtei:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxtei;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxtei == "1"){

//////////////////////////////
///// Input Data x tei 1 /////
//////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TEI 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tei_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxtei == "2"){

////////////////////////////////
///// Input Data X TEI 2   /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TEI 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tei_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxtei == "3"){

////////////////////////////////
///// Input Data x tei 3   /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data x tei 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tei_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxtei == "K.I" || ktxtei == "k.i" || ktxtei == "KI" || ktxtei == "ki"){

////////////////////////////////
///// Input Data X TEI K.I /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TEI K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tei_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxtei;
    }

// Pilih TET
    } else if (jur1x == "TET" || jur1x == "tet" || jur1x == "Tet"){

// keterangan 
    ktxtet:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxtet;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxtet == "1"){

////////////////////////////////
///// Input Data X TET 1   /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TET 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tet_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxtet == "2"){

////////////////////////////////
///// Input Data X TET 2   /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TET 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tet_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxtet == "3"){

////////////////////////////////
///// Input Data X TET 3   /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TET 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tet_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxtet == "K.I" || ktxtet == "k.i" || ktxtet == "KI" || ktxtet == "ki"){

////////////////////////////////
///// Input Data X TET k.i /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TET K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_tet_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
// output apabila input tidak sesuai
    } else {
        goto ktxtet;
    }

// Pilih AK
    } else if (jur1x == "AK" || jur1x == "Ak" || jur1x == "ak"){

// keterangan 
    ktxak:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxak;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxak == "1"){

////////////////////////////////
///// Input Data X AK 1    /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X AK 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_ak_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxak == "2"){

////////////////////////////////
///// Input Data X AK 2    /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X AK 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_ak_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxak == "3"){

////////////////////////////////
///// Input Data X AK 3    /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X AK 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_ak_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxak == "K.I" || ktxak == "k.i" || ktxak == "KI" || ktxak == "ki"){

////////////////////////////////
///// Input Data X AK K.I  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X AK K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_ak_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxak;
    }
    
// Pilih TO
    } else if (jur1x == "TO" || jur1x == "to" || jur1x == "To"){

// keterangan 
    ktxto:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxto;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxto == "1"){

////////////////////////////////
///// Input Data X TO 1    /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TO 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_to_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxto == "2"){

////////////////////////////////
///// Input Data X TO 2    /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TO 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_to_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxto == "3"){

////////////////////////////////
///// Input Data X TO 3    /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TO 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_to_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxto == "K.I" || ktxto == "k.i" || ktxto == "KI" || ktxto == "ki"){

////////////////////////////////
///// Input Data X TO k.i  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data X TO K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("x_to_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxto;
    }

// Output apabila input tidak sesuai
    } else {
        goto jur1x;
    }

// Pilih XI
    } else if (kl1 == "XI" || kl1 == "xi" || kl1 == "Xi" || kl1 == "Sebelas" || kl1 == "SEBELAS" || kl1 == "sebelas"){
        
// Input Jurusan
    jur1xi:
    cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
    cin >> jur1xi;

// Pilih RPL
    if (jur1xi == "RPL" || jur1xi == "rpl" || jur1xi == "Rpl"){

// keterangan 
    ktxirpl:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxirpl;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxirpl == "1"){

////////////////////////////////
///// Input Data XI RPL 1  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI RPL 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_rpl_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxirpl == "2"){

////////////////////////////////
///// Input Data XI RPL 2  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI RPL 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_rpl_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxirpl == "3"){

////////////////////////////////
///// Input Data XI RPL 3  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI RPL 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_rpl_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxirpl == "K.I" || ktxirpl == "k.i" || ktxirpl == "KI" || ktxirpl == "ki"){

/////////////////////////////////
///// Input Data XI RPL K.I /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI RPL K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_rpl_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxirpl;
    }

// Pilih TKJ
    } else if (jur1xi == "TKJ" || jur1xi == "tkj" || jur1xi == "Tkj"){

// keterangan 
    ktxitkj:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxitkj;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxitkj == "1"){

////////////////////////////////
///// Input Data XI TKJ 1  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TKJ 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tkj_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxitkj == "2"){

////////////////////////////////
///// Input Data XI TKJ 2  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TKJ 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tkj_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxitkj == "3"){

////////////////////////////////
///// Input Data XI TKJ 3  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TKJ 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tkj_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxitkj == "K.I" || ktxitkj == "k.i" || ktxitkj == "KI" || ktxitkj == "ki"){

//////////////////////////////////
///// Input Data XI TKJ K.I  /////
//////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TKJ K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tkj_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxitkj;
    }

// Pilih TEI
    } else if (jur1xi == "TEI" || jur1xi == "tei" || jur1xi == "Tei"){

// keterangan 
    ktxitei:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxitei;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxitei == "1"){

////////////////////////////////
///// Input Data XI TEI 1  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TEI 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tei_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxitei == "2"){

////////////////////////////////
///// Input Data XI TEI 2  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TEI 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tei_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxitei == "3"){

////////////////////////////////
///// Input Data XI TEI 3  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TEI 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tei_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxitei == "K.I" || ktxitei == "k.i" || ktxitei == "KI" || ktxitei == "ki"){

//////////////////////////////////
///// Input Data XI TEI K.I  /////
//////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TEI K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tei_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxitei;
    }

// Pilih TET
    } else if (jur1xi == "TET" || jur1xi == "tet" || jur1xi == "Tet"){

// keterangan 
    ktxitet:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxitet;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxitet == "1"){

////////////////////////////////
///// Input Data XI TET 1  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TET 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tet_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxitet == "2"){

////////////////////////////////
///// Input Data XI TET 2  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TET 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tet_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxitet == "3"){

////////////////////////////////
///// Input Data XI TET 3  /////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TET 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tet_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxitet == "K.I" || ktxitet == "k.i" || ktxitet == "KI" || ktxitet == "ki"){

//////////////////////////////////
///// Input Data XI TET K.I  /////
//////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TET K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_tet_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxitet;
    }

// Pilih AK
    } else if (jur1xi == "AK" || jur1xi == "Ak" || jur1xi == "ak"){

// keterangan 
    ktxiak:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiak;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiak == "1"){

////////////////////////////////
///// Input Data XI AK 1  //////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI AK 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_ak_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiak == "2"){

////////////////////////////////
///// Input Data XI AK 2  //////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI AK 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_ak_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiak == "3"){

////////////////////////////////
///// Input Data XI AK 3  //////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI AK 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_ak_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
                system ("cls");
                goto menud;
    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiak == "K.I" || ktxiak == "k.i" || ktxiak == "KI" || ktxiak == "ki"){

/////////////////////////////////
///// Input Data XI AK K.I  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI AK K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_ak_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiak;
    }

// Pilih TO
    } else if (jur1xi == "TO" || jur1xi == "to" || jur1xi == "To"){

// keterangan 
    ktxito:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxito;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxito == "1"){

////////////////////////////////
///// Input Data XI TO 1  //////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TO 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_to_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxito == "2"){

////////////////////////////////
///// Input Data XI TO 2  //////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TO 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_to_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxito == "3"){

////////////////////////////////
///// Input Data XI TO 3  //////
////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TO 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;

// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_to_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
                system ("cls");
                goto menud;
    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxito == "K.I" || ktxito == "k.i" || ktxito == "KI" || ktxito == "ki"){

/////////////////////////////////
///// Input Data XI TO K.I  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XI TO K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xi_to_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxito;
    }

// Output apabila input tidak sesuai
    } else {
        goto jur1xi;
    }

// Pilih XII
    } else if (kl1 == "XII" || kl1 == "xii" || kl1 == "Xii" || kl1 == "Dua Belas" || kl1 == "dua belas" || kl1 == "DUA BELAS" || kl1 == "Dua belas"){

// Input Jurusan
    jur1xii:
    cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
    cin >> jur1xii;

// Pilih RPL
    if (jur1xii == "RPL" || jur1xii == "rpl" || jur1xii == "Rpl"){

// keterangan 
    ktxiirpl:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiirpl;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiirpl == "1"){

/////////////////////////////////
///// Input Data XII RPL 1  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII RPL 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_rpl_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiirpl == "2"){

/////////////////////////////////
///// Input Data XII RPL 2  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII RPL 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_rpl_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiirpl == "3"){

/////////////////////////////////
///// Input Data XII RPL 3  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII RPL 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_rpl_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiirpl == "K.I" || ktxiirpl == "k.i" || ktxiirpl == "KI" || ktxiirpl == "ki"){

///////////////////////////////////
///// Input Data XII RPL K.I  /////
///////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII RPL K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_rpl_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiirpl;
    }

// Pilih TKJ
    } else if (jur1xii == "TKJ" || jur1xii == "tkj" || jur1xii == "Tkj"){

// keterangan 
    ktxiitkj:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiitkj;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiitkj == "1"){

/////////////////////////////////
///// Input Data XII TKJ 1  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TKJ 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tkj_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiitkj == "2"){

/////////////////////////////////
///// Input Data XII TKJ 2  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TKJ 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tkj_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiitkj == "3"){

/////////////////////////////////
///// Input Data XII TKJ 3  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TKJ 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tkj_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiitkj == "K.I" || ktxiitkj == "k.i" || ktxiitkj == "KI" || ktxiitkj == "ki"){

///////////////////////////////////
///// Input Data XII TKJ K.I  /////
///////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TKJ K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tkj_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiitkj;
    }

// Pilih TEI
    } else if (jur1xii == "TEI" || jur1xii == "tei" || jur1xii == "Tei"){

// keterangan 
    ktxiitei:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiitei;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiitei == "1"){

/////////////////////////////////
///// Input Data XII TEI 1  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TEI 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tei_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiitei == "2"){

/////////////////////////////////
///// Input Data XII TEI 2  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TEI 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tei_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiitei == "3"){

/////////////////////////////////
///// Input Data XII TEI 3  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TEI 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tei_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiitei == "K.I" || ktxiitei == "k.i" || ktxiitei == "KI" || ktxiitei == "ki"){

///////////////////////////////////
///// Input Data XII TEI K.I  /////
///////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TEI K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tei_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiitei;
    }

// Pilih TET
    } else if (jur1xii == "TET" || jur1xii == "tet" || jur1xii == "Tet"){

// keterangan 
    ktxiitet:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiitet;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiitet == "1"){

/////////////////////////////////
///// Input Data XII TET 1  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TET 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tet_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiitet == "2"){

/////////////////////////////////
///// Input Data XII TET 2  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TET 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tet_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiitet == "3"){

/////////////////////////////////
///// Input Data XII TET 3  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TET 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tet_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiitet == "K.I" || ktxiitet == "k.i" || ktxiitet == "KI" || ktxiitet == "ki"){

///////////////////////////////////
///// Input Data XII TET K.I  /////
///////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TET K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_tet_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiitet;
    }

// Pilih AK
    } else if (jur1xii == "AK" || jur1xii == "Ak" || jur1xii == "ak"){

// keterangan 
    ktxiiak:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiiak;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiiak == "1"){

/////////////////////////////////
///// Input Data XII AK 1  //////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII AK 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_ak_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiiak == "2"){

/////////////////////////////////
///// Input Data XII AK 2  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII AK 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_ak_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiiak == "3"){

/////////////////////////////////
///// Input Data XII AK 3  //////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII AK 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_ak_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiiak == "K.I" || ktxiiak == "k.i" || ktxiiak == "KI" || ktxiiak == "ki"){

//////////////////////////////////
///// Input Data XII AK K.I  /////
//////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII AK K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_ak_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiiak;
    }

// Pilih TO
    } else if (jur1xii == "TO" || jur1xii == "to" || jur1xii == "To"){

// keterangan 
    ktxiito:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiito;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiito == "1"){

/////////////////////////////////
///// Input Data XII TO 1  //////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TO 1 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_to_1.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiito == "2"){

/////////////////////////////////
///// Input Data XII TO 2  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TO 2 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_to_2.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiito == "3"){

/////////////////////////////////
///// Input Data XII TO 3  /////
/////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TO 3 --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_to_3.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiito == "K.I" || ktxiito == "k.i" || ktxiito == "KI" || ktxiito == "ki"){

//////////////////////////////////
///// Input Data XII TO K.I  /////
//////////////////////////////////

// Judul
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Input data XII TO K.I --\t";
setcolor (15);
cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

// Input Username X RPL
    cout << "Nama : ";
    cin >> namainput;


// input NIS X RPL 3
while (true) {
    cout << "NIS : ";
    cin >> nisinput;

// validasi NIS harus berupa angka
bool valid = true;
for (char c : nisinput) {
    if (!isdigit(c)) {
        valid = false;
        break;
    }
}
if (!valid) {
    setcolor(12);
    cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
    setcolor(15);
    continue;
}

// pengecekan apakah data sudah ada di salah satu dari beberapa file database
    bool flag = false;
    for (string fileName : fileNames) {
        ifstream data(fileName);
        while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek) {     // mengecek data yang berada di dalam file database txt
            if (niscek == nisinput) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

// output apabila data sudah ada di salah satu dari beberapa file database
    if (flag) {
        setcolor(12);
        cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
        setcolor(15);
        continue;
    } else {
        break;
    }
}

// input TTL X RPL 
    cout << "TTL : ";
    cin >> ttlinput;

// input JK
    cout << "Jenis Kelamin : ";
    cin >> jkinput;

// input alamat
    cout << "Alamat : ";
    cin >> alamatinput;

// data akan di simpan di database.txt
        ofstream data4("xii_to_ki.txt",ios::app);
        data4<<namainput<<' '<<nisinput<<' '<<ttlinput<<' '<<jkinput << ' ' << alamatinput<<endl;
        setcolor (267);
        cout<<"\nRegistration Sucessful\n";
        setcolor (15);
        cout << "\n";
        system ("pause");
        system ("cls");
        goto menud;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiito;
    }

// Output apabila input tidak sesuai
    } else {
        goto jur1xii;
    }

// Output apabila input tidak sesuai
    } else {
        goto kel1;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} else if (pill == "2"){

// output Kelas
    kl2:
    cout << "Kelas [ X, XI, XII ] : ";
    cin >> kl2;

// Pilih x
    if (kl2 == "X" || kl2 == "x" || kl2 == "Sepuluh" || kl2 == "sepuluh" || kl2 == "SEPULUH"){

// output Jurusan
    jur2x:
    cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
    cin >> jur2x;

// Pilih RPL
    if (jur2x == "RPL" || jur2x == "rpl" || jur2x == "Rpl"){

// keterangan 
    ktxrpl2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxrpl2;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxrpl2 == "1"){

/////////////////////////////////////
///// MENAMPILKAN Data X RPL 1  /////
/////////////////////////////////////

// Judul
ynd73:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X RPL 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_rpl_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_rpl_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd73;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxrpl2 == "2"){

/////////////////////////////////////
///// MENAMPILKAN Data X RPL 2  /////
/////////////////////////////////////

// Judul
ynd74:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X RPL 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_rpl_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_rpl_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd74;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxrpl2 == "3"){

/////////////////////////////////////
///// MENAMPILKAN Data X RPL 3  /////
/////////////////////////////////////

// Judul
ynd75:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X RPL 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_rpl_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_rpl_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd75;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxrpl2 == "K.I" || ktxrpl2 == "k.i" || ktxrpl2 == "KI" || ktxrpl2 == "ki"){

///////////////////////////////////////
///// MENAMPILKAN Data X RPL K.I  /////
///////////////////////////////////////

// Judul
ynd76:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X RPL K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_rpl_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_rpl_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd76;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxrpl2;
    }

// Pilih TKJ
    } else if (jur2x == "TKJ" || jur2x == "tkj" || jur2x == "Tkj"){

// keterangan 
    ktxtkj2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxtkj2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxtkj2 == "1"){

/////////////////////////////////////
///// MENAMPILKAN Data X TKJ 1  /////
/////////////////////////////////////

// Judul
ynd77:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TKJ 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tkj_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tkj_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd77;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxtkj2 == "2"){

/////////////////////////////////////
///// MENAMPILKAN Data X TKJ 2  /////
/////////////////////////////////////

// Judul
ynd78:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TKJ 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tkj_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tkj_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd78;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxtkj2 == "3"){

/////////////////////////////////////
///// MENAMPILKAN Data X TKJ 3  /////
/////////////////////////////////////

// Judul
ynd79:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TKJ 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tkj_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tkj_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd79;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxtkj2 == "K.I" || ktxtkj2 == "k.i" || ktxtkj2 == "KI" || ktxtkj2 == "ki"){

///////////////////////////////////////
///// MENAMPILKAN Data X TKJ K.I  /////
///////////////////////////////////////

// Judul
ynd80:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TKJ K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tkj_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tkj_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd80;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxtkj2;
    }

// Pilih TEI
    } else if (jur2x == "TEI" || jur2x == "tei" || jur2x == "Tei"){

// keterangan 
    ktxtei2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxtei2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxtei2 == "1"){

/////////////////////////////////////
///// MENAMPILKAN Data X TEI 1  /////
/////////////////////////////////////

// Judul
ynd81:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TEI 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tei_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tei_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd81;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxtei2 == "2"){

/////////////////////////////////////
///// MENAMPILKAN Data X TEI 2  /////
/////////////////////////////////////

// Judul
ynd82:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TEI 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tei_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tei_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd82;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxtei2 == "3"){

/////////////////////////////////////
///// MENAMPILKAN Data X TEI 3  /////
/////////////////////////////////////

// Judul
ynd83:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TEI 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tei_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tei_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd83;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxtei2 == "K.I" || ktxtei2 == "k.i" || ktxtei2 == "KI" || ktxtei2 == "ki"){

///////////////////////////////////////
///// MENAMPILKAN Data X TEI K.I  /////
///////////////////////////////////////

// Judul
ynd84:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TEI K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tei_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tei_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd84;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxtei2;
    }

// Pilih TET
    } else if (jur2x == "TET" || jur2x == "tet" || jur2x == "Tet"){

// keterangan 
    ktxtet2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxtet2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxtet2 == "1"){

/////////////////////////////////////
///// MENAMPILKAN Data X TET 1  /////
/////////////////////////////////////

// Judul
ynd85:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TET 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tet_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tet_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd85;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxtet2 == "2"){

/////////////////////////////////////
///// MENAMPILKAN Data X TET 2  /////
/////////////////////////////////////

// Judul
ynd86:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TET 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tet_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tet_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd86;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxtet2 == "3"){

/////////////////////////////////////
///// MENAMPILKAN Data X TET 3  /////
/////////////////////////////////////

// Judul
ynd87:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TET 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tet_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tet_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd87;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxtet2 == "K.I" || ktxtet2 == "k.i" || ktxtet2 == "KI" || ktxtet2 == "ki"){

///////////////////////////////////////
///// MENAMPILKAN Data X TET K.I  /////
///////////////////////////////////////

// Judul
ynd88:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TET K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_tet_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_tet_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd88;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxtet2;
    }

// Pilih AK
    } else if (jur2x == "AK" || jur2x == "Ak" || jur2x == "ak"){

// keterangan 
    ktxak2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxak2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxak2 == "1"){

////////////////////////////////////
///// MENAMPILKAN Data X AK 1  /////
////////////////////////////////////

// Judul
ynd89:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X AK 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_ak_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_ak_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd89;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxak2 == "2"){

////////////////////////////////////
///// MENAMPILKAN Data X AK 2  /////
////////////////////////////////////

// Judul
ynd90:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X AK 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_ak_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_ak_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd90;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxak2 == "3"){

////////////////////////////////////
///// MENAMPILKAN Data X AK 3  /////
////////////////////////////////////

// Judul
ynd91:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X AK 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_ak_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_ak_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd91;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxak2 == "K.I" || ktxak2 == "k.i" || ktxak2 == "KI" || ktxak2 == "ki"){

//////////////////////////////////////
///// MENAMPILKAN Data X AK K.I  /////
//////////////////////////////////////

// Judul
ynd92:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X AK K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_ak_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_ak_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd92;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxak2;
    }

// Pilih TO
    } else if (jur2x == "TO" || jur2x == "to" || jur2x == "To"){

// keterangan 
    ktxto2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxto2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxto2 == "1"){

////////////////////////////////////
///// MENAMPILKAN Data X TO 1  /////
////////////////////////////////////

// Judul
ynd93:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TO 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_to_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_to_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd93;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxto2 == "2"){

////////////////////////////////////
///// MENAMPILKAN Data X TO 2  /////
////////////////////////////////////

// Judul
ynd94:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TO 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_to_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_to_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd94;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxto2 == "3"){

////////////////////////////////////
///// MENAMPILKAN Data X TO 3  /////
////////////////////////////////////

// Judul
ynd95:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TO 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_to_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_to_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd95;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxto2 == "K.I" || ktxto2 == "k.i" || ktxto2 == "KI" || ktxto2 == "ki"){

//////////////////////////////////////
///// MENAMPILKAN Data X TO K.I  /////
//////////////////////////////////////

// Judul
ynd96:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database X TO K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("x_to_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("x_to_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd96;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxto2;
    }

//  Output apabila input tidak sesuai
    } else {
        goto jur2x;
    }

// Pilih XI
    } else if (kl2 == "XI" || kl2 == "xi" || kl2 == "Xi" || kl2 == "Sebelas" || kl2 == "SEBELAS" || kl2 == "sebelas"){

// output Jurusan
    jur2xi:
    cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
    cin >> jur2xi;

// Pilih RPL
    if (jur2xi == "RPL" || jur2xi == "rpl" || jur2xi == "Rpl"){

// keterangan 
    ktxirpl2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxirpl2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxirpl2 == "1"){

//////////////////////////////////////
///// MENAMPILKAN Data XI RPL 1  /////
//////////////////////////////////////

// Judul
ynd97:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI RPL 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_rpl_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_rpl_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd97;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxirpl2 == "2"){

//////////////////////////////////////
///// MENAMPILKAN Data XI RPL 2  /////
//////////////////////////////////////

// Judul
ynd98:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI RPL 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_rpl_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_rpl_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd98;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxirpl2 == "3"){

//////////////////////////////////////
///// MENAMPILKAN Data XI RPL 3  /////
//////////////////////////////////////

// Judul
ynd99:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI RPL 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_rpl_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_rpl_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd99;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxirpl2 == "K.I" || ktxirpl2 == "k.i" || ktxirpl2 == "KI" || ktxirpl2 == "ki"){

////////////////////////////////////////
///// MENAMPILKAN Data XI RPL K.I  /////
////////////////////////////////////////

// Judul
ynd100:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI RPL K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_rpl_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_rpl_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd100;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxirpl2;
    }

// Pilih TKJ
    } else if (jur2xi == "TKJ" || jur2xi == "tkj" || jur2xi == "Tkj"){

// keterangan 
    ktxitkj2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxitkj2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxitkj2 == "1"){
//////////////////////////////////////
///// MENAMPILKAN Data XI TKJ 1  /////
//////////////////////////////////////

// Judul
ynd101:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TKJ 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tkj_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tkj_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd101;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxitkj2 == "2"){

//////////////////////////////////////
///// MENAMPILKAN Data XI TKJ 2  /////
//////////////////////////////////////

// Judul
ynd102:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TKJ 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tkj_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tkj_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd102;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxitkj2 == "3"){

//////////////////////////////////////
///// MENAMPILKAN Data XI TKJ 3  /////
//////////////////////////////////////

// Judul
ynd103:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TKJ 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tkj_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tkj_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd103;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxitkj2 == "K.I" || ktxitkj2 == "k.i" || ktxitkj2 == "KI" || ktxitkj2 == "ki"){

////////////////////////////////////////
///// MENAMPILKAN Data XI TKJ K.I  /////
////////////////////////////////////////

// Judul
ynd104:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TKJ K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tkj_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tkj_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd104;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxitkj2;
    }

// Pilih TEI
    } else if (jur2xi == "TEI" || jur2xi == "tei" || jur2xi == "Tei"){

// keterangan 
    ktxitei2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxitei2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxitei2 == "1"){

//////////////////////////////////////
///// MENAMPILKAN Data XI TEI 1  /////
//////////////////////////////////////

// Judul
ynd105:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TEI 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tei_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tei_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd105;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxitei2 == "2"){

//////////////////////////////////////
///// MENAMPILKAN Data XI TEI 2  /////
//////////////////////////////////////

// Judul
ynd106:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TEI 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tei_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tei_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd106;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxitei2 == "3"){

//////////////////////////////////////
///// MENAMPILKAN Data XI TEI 3  /////
//////////////////////////////////////

// Judul
ynd107:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TEI 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tei_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tei_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd107;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxitei2 == "K.I" || ktxitei2 == "k.i" || ktxitei2 == "KI" || ktxitei2 == "ki"){

////////////////////////////////////////
///// MENAMPILKAN Data XI TEI K.I  /////
////////////////////////////////////////

// Judul
ynd108:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TEI K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tei_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tei_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd108;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxitei2;
    }

// Pilih TET
    } else if (jur2xi == "TET" || jur2xi == "tet" || jur2xi == "Tet"){

// keterangan 
    ktxitet2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxitet2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxitet2 == "1"){

//////////////////////////////////////
///// MENAMPILKAN Data XI TET 1  /////
//////////////////////////////////////

// Judul
ynd109:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TET 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tet_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tet_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd109;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxitet2 == "2"){

//////////////////////////////////////
///// MENAMPILKAN Data XI TET 2  /////
//////////////////////////////////////

// Judul
ynd110:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TET 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tet_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tet_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd110;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxitet2 == "3"){

//////////////////////////////////////
///// MENAMPILKAN Data XI TET 3  /////
//////////////////////////////////////

// Judul
ynd111:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TET 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tet_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tet_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd111;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxitet2 == "K.I" || ktxitet2 == "k.i" || ktxitet2 == "KI" || ktxitet2 == "ki"){

////////////////////////////////////////
///// MENAMPILKAN Data XI TET K.I  /////
////////////////////////////////////////

// Judul
ynd112:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TET K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_tet_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_tet_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd112;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxitet2;
    }

// Pilih AK
    } else if (jur2xi == "AK" || jur2xi == "Ak" || jur2xi == "ak"){

// keterangan 
    ktxiak2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiak2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiak2 == "1"){

//////////////////////////////////////
///// MENAMPILKAN Data XI AK 1  //////
//////////////////////////////////////

// Judul
ynd113:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI AK 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_ak_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_ak_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd113;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiak2 == "2"){

//////////////////////////////////////
///// MENAMPILKAN Data XI AK 2  //////
//////////////////////////////////////

// Judul
ynd114:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI AK 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_ak_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_ak_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd114;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiak2 == "3"){

//////////////////////////////////////
///// MENAMPILKAN Data XI AK 3  //////
//////////////////////////////////////

// Judul
ynd115:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI AK 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_ak_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_ak_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd115;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiak2 == "K.I" || ktxiak2 == "k.i" || ktxiak2 == "KI" || ktxiak2 == "ki"){

///////////////////////////////////////
///// MENAMPILKAN Data XI AK K.I  /////
///////////////////////////////////////

// Judul
ynd116:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI AK K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_ak_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_ak_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd116;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiak2;
    }

// Pilih TO
    } else if (jur2xi == "TO" || jur2xi == "to" || jur2xi == "To"){

// keterangan 
    ktxito2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxito2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxito2 == "1"){

//////////////////////////////////////
///// MENAMPILKAN Data XI TO 1  //////
//////////////////////////////////////

// Judul
ynd117:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TO 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_to_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_to_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd117;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxito2 == "2"){

//////////////////////////////////////
///// MENAMPILKAN Data XI TO 2  //////
//////////////////////////////////////

// Judul
ynd118:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TO 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_to_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_to_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd118;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxito2 == "3"){

//////////////////////////////////////
///// MENAMPILKAN Data XI TO 3  //////
//////////////////////////////////////

// Judul
ynd119:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TO 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_to_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_to_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd119;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxito2 == "K.I" || ktxito2 == "k.i" || ktxito2 == "KI" || ktxito2 == "ki"){

///////////////////////////////////////
///// MENAMPILKAN Data XI TO K.I  /////
///////////////////////////////////////

// Judul
ynd120:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XI TO K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xi_to_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xi_to_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd120;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxito2;
    }

//  Output apabila input tidak sesuai
    } else {
        goto jur2xi;
    }

// Pilih XII
    } else if (kl2 == "XII" || kl2 == "xii" || kl2 == "Xii" || kl2 == "Dua Belas" || kl2 == "dua belas" || kl2 == "DUA BELAS" || kl2 == "Dua belas"){

// output Jurusan
    jur2xii:
    cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
    cin >> jur2xii;

// Pilih RPL
    if (jur2xii == "RPL" || jur2xii == "rpl" || jur2xii == "Rpl"){

// keterangan 
    ktxiirpl2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiirpl2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiirpl2 == "1"){

///////////////////////////////////////
///// MENAMPILKAN Data XII RPL 1  /////
///////////////////////////////////////

// Judul
ynd121:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII RPL 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_rpl_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_rpl_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd121;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiirpl2 == "2"){

///////////////////////////////////////
///// MENAMPILKAN Data XII RPL 2  /////
///////////////////////////////////////

// Judul
ynd122:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII RPL 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_rpl_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_rpl_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd122;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiirpl2 == "3"){

///////////////////////////////////////
///// MENAMPILKAN Data XII RPL 3  /////
///////////////////////////////////////

// Judul
ynd123:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII RPL 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_rpl_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_rpl_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd123;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiirpl2 == "K.I" || ktxiirpl2 == "k.i" || ktxiirpl2 == "KI" || ktxiirpl2 == "ki"){

/////////////////////////////////////////
///// MENAMPILKAN Data XII RPL K.I  /////
/////////////////////////////////////////

// Judul
ynd124:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII RPL K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_rpl_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_rpl_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd124;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiirpl2;
    }

// Pilih TKJ
    } else if (jur2xii == "TKJ" || jur2xii == "tkj" || jur2xii == "Tkj"){

// keterangan 
    ktxiitkj2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiitkj2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiitkj2 == "1"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TKJ 1  /////
///////////////////////////////////////

// Judul
ynd125:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TKJ 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tkj_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tkj_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd125;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiitkj2 == "2"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TKJ 2  /////
///////////////////////////////////////

// Judul
ynd126:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TKJ 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tkj_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tkj_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd126;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiitkj2 == "3"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TKJ 3  /////
///////////////////////////////////////

// Judul
ynd127:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TKJ 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tkj_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tkj_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd127;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiitkj2 == "K.I" || ktxiitkj2 == "k.i" || ktxiitkj2 == "KI" || ktxiitkj2 == "ki"){

/////////////////////////////////////////
///// MENAMPILKAN Data XII TKJ K.I  /////
/////////////////////////////////////////

// Judul
ynd128:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TKJ K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tkj_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tkj_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd128;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiitkj2;
    }

// Pilih TEI
    } else if (jur2xii == "TEI" || jur2xii == "tei" || jur2xii == "Tei"){

// keterangan 
    ktxiitei2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiitei2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiitei2 == "1"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TEI 1  /////
///////////////////////////////////////

// Judul
ynd129:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TEI 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tei_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tei_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd129;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiitei2 == "2"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TEI 2  /////
///////////////////////////////////////

// Judul
ynd130:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TEI 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tei_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tei_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd130;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiitei2 == "3"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TEI 3  /////
///////////////////////////////////////

// Judul
ynd131:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TEI 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tei_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tei_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd131;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiitei2 == "K.I" || ktxiitei2 == "k.i" || ktxiitei2 == "KI" || ktxiitei2 == "ki"){

/////////////////////////////////////////
///// MENAMPILKAN Data XII TEI K.I  /////
/////////////////////////////////////////

// Judul
ynd132:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TEI K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tei_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tei_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd132;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiitei2;
    }

// Pilih TET
    } else if (jur2xii == "TET" || jur2xii == "tet" || jur2xii == "Tet"){

// keterangan 
    ktxiitet2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiitet2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiitet2 == "1"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TET 1  /////
///////////////////////////////////////

// Judul
ynd133:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TET 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tet_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tet_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd133;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiitet2 == "2"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TET 2  /////
///////////////////////////////////////

// Judul
ynd134:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TET 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tet_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tet_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd134;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiitet2 == "3"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TET 3  /////
///////////////////////////////////////

// Judul
ynd135:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TET 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tet_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tet_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd135;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiitet2 == "K.I" || ktxiitet2 == "k.i" || ktxiitet2 == "KI" || ktxiitet2 == "ki"){

/////////////////////////////////////////
///// MENAMPILKAN Data XII TET K.I  /////
/////////////////////////////////////////

// Judul
ynd136:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TET K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_tet_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_tet_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd136;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiitet2;
    }

// Pilih AK
    } else if (jur2xii == "AK" || jur2xii == "Ak" || jur2xii == "ak"){

// keterangan 
    ktxiiak2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiiak2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiiak2 == "1"){

///////////////////////////////////////
///// MENAMPILKAN Data XII AK 1  //////
///////////////////////////////////////

// Judul
ynd137:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII AK 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_ak_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_ak_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd137;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiiak2 == "2"){

///////////////////////////////////////
///// MENAMPILKAN Data XII AK 2  //////
///////////////////////////////////////

// Judul
ynd138:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII AK 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_ak_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_ak_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd138;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiiak2 == "3"){

///////////////////////////////////////
///// MENAMPILKAN Data XII AK 3  //////
///////////////////////////////////////

// Judul
ynd:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII AK 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_ak_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_ak_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiiak2 == "K.I" || ktxiiak2 == "k.i" || ktxiiak2 == "KI" || ktxiiak2 == "ki"){

/////////////////////////////////////////
///// MENAMPILKAN Data XII AK K.I  //////
/////////////////////////////////////////

// Judul
ynd139:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII AK K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_ak_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_ak_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd139;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiiak2;
    }

// Pilih TO
    } else if (jur2xii == "TO" || jur2xii == "to" || jur2xii == "To"){

// keterangan 
    ktxiito2:
    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
    cin >> ktxiito2;    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pilih 1
    if (ktxiito2 == "1"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TO 1  //////
///////////////////////////////////////

// Judul
ynd140:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TO 1 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_to_1.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_to_1.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);  
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd140;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 2
    } else if (ktxiito2 == "2"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TO 2  //////
///////////////////////////////////////

// Judul
ynd141:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TO 2 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_to_2.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_to_2.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd141;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih 3
    } else if (ktxiito2 == "3"){

///////////////////////////////////////
///// MENAMPILKAN Data XII TO 3  //////
///////////////////////////////////////

// Judul
ynd142:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TO 3 --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_to_3.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_to_3.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd142;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilih k.i
    } else if (ktxiito2 == "K.I" || ktxiito2 == "k.i" || ktxiito2 == "KI" || ktxiito2 == "ki"){

/////////////////////////////////////////
///// MENAMPILKAN Data XII TO K.I  //////
/////////////////////////////////////////

// Judul
ynd143:
system ("cls");
cout << "\n";
setcolor(2);
cout << "-- Database XII TO K.I --\t\n\n";
setcolor (15);

// tipe data dan memanggil file database 
string line;
ifstream in("xii_to_ki.txt");

// Judul output
if (in.is_open()) {
    cout << "===================================================================================================================" << endl;
    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
    cout << "===================================================================================================================" << endl;
    
// Menampilkan data yang ada di database
    int count = 0;
    while (getline(in, line)) {
        stringstream ss(line);
        string nama, nis, ttl, jk, alamat;
        ss >> nama >> nis >> ttl >> jk >> alamat;
        if (count > 0) {
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
        count++;
    }
    cout << "===================================================================================================================" << endl;
    in.close();

// Mencari data dengan memasukkan NIS
    string nis_input;
    while (true) {
        cout << "\nMasukkan NIS untuk mencari data: ";
        cin >> nis_input;

        ifstream in2("xii_to_ki.txt");
        if (in2.is_open()) {
            bool found = false;
            while (getline(in2, line)) {
                stringstream ss(line);
                string nama, nis, ttl, jk, alamat;
                ss >> nama >> nis >> ttl >> jk >> alamat;
                if (nis == nis_input) {
                    cout << "===================================================================================================================" << endl;
                    cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                    cout << "===================================================================================================================" << endl;
                    cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                    cout << "===================================================================================================================" << endl;
                    found = true;
                    break;
                }
            }
            in2.close();
            if (found) {
                break;
            } else {
                setcolor (12);
                cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                setcolor (15);
            }
        } else {
            cout << "File tidak ditemukan" << endl;
            break;
        }
    }
} else {
    cout << "File tidak ditemukan" << endl;
}

// kembali ke menu ?
    cout << "\n";
    setcolor(14);
    cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
    setcolor (15);
    cin >>ynd;

    if (ynd == "y" || ynd == "Y"){
        system ("cls");
        goto menud;
    } else {
        goto ynd143;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// output apabila input tidak sesuai
    } else {
        goto ktxiito2;
    }

// Output apabila input tidak sesuai
    } else {
        goto jur2xii;
    }

// Output apabila input tidak sesuai
    } else {
        goto kl2;
    }

// output apabila input tidak sesuai
} else if (pill == "3") {
    return 0;

}else {
    system ("cls");
    goto menud;
}
}