/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Wajib	= Menu 6 (apabila memasukkan tahun tapi berupa huruf tidak berupa angka, tidak akan terjadi eror (tetapi data 0))											            /////
////		= Menu 6 (apabila memasukkan bulan tetapi berupa huruf akan mengulang lagi tetapi apabila sudah berkali kali, akan eror ketika memasukkan dengan huruf)		            /////
////		= Menu 5 (input bayarnya tidak bisa menggunakan koma/titik)																									            /////
////		= Menu 5 (input harganya tidak bisa menggunakan koma/titik)																									            /////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// ADD MySQL	= Menu 1 input jadwal pelajarannya, lalu di simpan di database (seperti sistem login) lalu ketika output data, sesuai apa yang di cari						        /////
////            = Menu 2 input data nya bisa menggunakan spasi, dan tambahkan fiture hapus data dan edit data dengan menggunakan MySQL                                              /////
////            = Menu 3 tambahkan input tanggal lalu setelah mengisi semua informasi maka akan di simpan ke dalam database sesuai tanggalnya                                       /////
////            = Menu 5 Input Barang dan Membeli barang. Input = (kategori, kode, nama, harga, stok, keterangan ), Beli = (input kode, jumlah beli, Alamat, bayar, struk belanja), /////
////            = Menu 5 tambahkan fiture hapus barang dan edit barang                                                                                                              /////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////                      MySQL                     /////
/////////////////////////////////////////////////////////
//// Sistem Login                       => MySQL    /////
//// Menu 1 = Jadwal Mata Pelajaran     => MySQ		/////
//// Menu 2 = Data Siswa X RPL K.I 		=> MySQL   	/////
//// Menu 3 = Sistem Kehadiran Siswa	=> MySQL   	/////
//// Menu 4 = Calculator					        /////
//// Menu 5 = Sistem Belanja 			=> MySQL    /////
//// Menu 6 = Calender					            /////
//// Menu 7 = Game 							        /////
//// Menu 8 = Exit 							        /////
/////////////////////////////////////////////////////////

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

// perpustakaan menu 7 (Game)
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 20
#define GAP_SIZE 7
#define PIPE_DIF 45

using namespace std;
void login();
void registr();
void forgot();

void setcolor(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, color);
}

/////////////////////////
///// Judul Program /////
/////////////////////////
main()
{
    system("cls");
    setcolor(15);
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
    if (choice == "1")
    {
        login(); // pergi ke void login
        return 0;
    }
    else if (choice == "2")
    {
        registr(); // pergi ke void registr
        return 0;
    }
    else if (choice == "3")
    {
        forgot(); // pergi ke void forgot
        return 0;
    }
    else if (choice == "4")
    { // sistem end
        system("cls");
        cout << "\n\n\n\n\n\n\n\n";
        setcolor(6);
        cout << "\t\t\t-- Terimakasih Telah Melihat Program Ini --\n";
        setcolor(15);
        cout << "\t\t\t    By Maulana ra'afi \n";
        cout << "\t\t\t    Kelas : X RPL K.I \n\n";
        return 0; // progra selesai
    }
    else
    {
        system("cls"); // apabila input salah
        main();        // kembali ke menu();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////
// Variabel menu 7 (game) //
///////////////////////////
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int pipePos[3];
int gapPos[3];
int pipeFlag[3];
char bird[2][6] = {'/', '-', '-', 'o', '\\', ' ',
                   '|', '_', '_', '_', ' ', '>'};
int birdPos = 6;
int score = 0;

void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size)
{
    if (size == 0)
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void drawBorder()
{

    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        gotoxy(i, 0);
        cout << "_";
        gotoxy(i, SCREEN_HEIGHT);
        cout << "_";
    }

    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        gotoxy(0, i);
        cout << "|";
        gotoxy(SCREEN_WIDTH, i);
        cout << "|";
    }
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        gotoxy(WIN_WIDTH, i);
        cout << "|";
    }
}
void genPipe(int ind)
{
    gapPos[ind] = 3 + rand() % 14;
}
void drawPipe(int ind)
{
    if (pipeFlag[ind] == true)
    {
        for (int i = 0; i < gapPos[ind]; i++)
        {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1);
            cout << "***";
        }
        for (int i = gapPos[ind] + GAP_SIZE; i < SCREEN_HEIGHT - 1; i++)
        {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1);
            cout << "***";
        }
    }
}
void erasePipe(int ind)
{
    if (pipeFlag[ind] == true)
    {
        for (int i = 0; i < gapPos[ind]; i++)
        {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1);
            cout << "   ";
        }
        for (int i = gapPos[ind] + GAP_SIZE; i < SCREEN_HEIGHT - 1; i++)
        {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1);
            cout << "   ";
        }
    }
}

void drawBird()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            gotoxy(j + 2, i + birdPos);
            cout << bird[i][j];
        }
    }
}
void eraseBird()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            gotoxy(j + 2, i + birdPos);
            cout << " ";
        }
    }
}

int collision()
{
    if (pipePos[0] >= 61)
    {
        if (birdPos < gapPos[0] || birdPos > gapPos[0] + GAP_SIZE)
        {
            cout << "    HIT ";
            getch();
            return 1;
        }
    }
    return 0;
}
void debug()
{
    gotoxy(SCREEN_WIDTH + 3, 4);
    cout << "FPS: " << pipePos[0];
}
void gameover()
{
    system("cls");
    cout << endl;
    cout << "\t\t--------------------------" << endl;
    cout << "\t\t-------- Game Over -------" << endl;
    cout << "\t\t--------------------------" << endl
         << endl;
    cout << "\t\tPress any key to go back to menu.";
    getch();
}
void updateScore()
{
    gotoxy(WIN_WIDTH + 7, 5);
    cout << "Score: " << score << endl;
}

void instructions()
{

    system("cls");
    cout << "Instructions";
    cout << "\n----------------\n";
    cout << "\n Press spacebar to make bird fly";
    cout << "\n\nPress any key to go back to menu";
    getch();
}

void play()
{

    birdPos = 6;
    score = 0;
    pipeFlag[0] = 1;
    pipeFlag[1] = 0;
    pipePos[0] = pipePos[1] = 4;

    system("cls");
    drawBorder();
    genPipe(0);
    updateScore();

    gotoxy(WIN_WIDTH + 5, 2);
    cout << "FLAPPY BIRD";
    gotoxy(WIN_WIDTH + 6, 4);
    cout << "----------";
    gotoxy(WIN_WIDTH + 6, 6);
    cout << "----------";
    gotoxy(WIN_WIDTH + 7, 12);
    cout << "Control ";
    gotoxy(WIN_WIDTH + 7, 13);
    cout << "-------- ";
    gotoxy(WIN_WIDTH + 2, 14);
    cout << " Spacebar = jump";

    gotoxy(10, 5);
    cout << "Press any key to start";
    getch();
    gotoxy(10, 5);
    cout << "                      ";

    while (1)
    {

        if (kbhit())
        {
            char ch = getch();
            if (ch == 32)
            {
                if (birdPos > 3)
                    birdPos -= 3;
            }
            if (ch == 27)
            {
                break;
            }
        }

        drawBird();
        drawPipe(0);
        drawPipe(1);
        debug();
        if (collision() == 1)
        {
            gameover();
            return;
        }
        Sleep(100);
        eraseBird();
        erasePipe(0);
        erasePipe(1);
        birdPos += 1;

        if (birdPos > SCREEN_HEIGHT - 2)
        {
            gameover();
            return;
        }

        if (pipeFlag[0] == 1)
            pipePos[0] += 2;

        if (pipeFlag[1] == 1)
            pipePos[1] += 2;

        if (pipePos[0] >= 40 && pipePos[0] < 42)
        {
            pipeFlag[1] = 1;
            pipePos[1] = 4;
            genPipe(1);
        }
        if (pipePos[0] > 68)
        {
            score++;
            updateScore();
            pipeFlag[1] = 0;
            pipePos[0] = pipePos[1];
            gapPos[0] = gapPos[1];
        }
    }
}

/////////////////////////////////
// variabel menu 6 (calender) //
///////////////////////////////
int hitung_Year(int thn);
int hitung_Month(int thn, int bln);
int cek_Day(int jmlDay);
int hitung_Day(int bln, int thn);
// variabel perhitungan calender menu 6
int hitung_Year(int thn)
{
    int jmlDay = 0, year;
    for (year = 1900; year < thn; year++)
    {
        if (year % 4 == 0)
        {
            jmlDay += 366;
        }
        else
        {
            jmlDay += 365;
        }
    }
    return (jmlDay);
}
// variabel perhitungan calender menu 6
int hitung_Month(int thn, int bln)
{
    int jmlDay = 0, Month;
    for (Month = 1; Month < bln; Month++)
    {
        if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
        {
            jmlDay += 31;
        }
        else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
        {
            jmlDay += 30;
        }
        else
        {
            if (thn % 4 == 0)
            {
                jmlDay += 29;
            }
            else
                jmlDay += 28;
        }
    }
    return (jmlDay);
}
// variabel perhitungan calender menu 6
int cek_Day(int jmlDay)
{
    int Day = jmlDay % 7;
    return (Day);
}
// variabel perhitungan calender menu 6
int hitung_Day(int Month, int thn)
{
    int jmlDay = 0;
    if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
    {
        jmlDay += 31;
    }
    else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
    {
        jmlDay += 30;
    }
    else
    {
        if (thn % 4 == 0)
            jmlDay += 29;
        else
            jmlDay += 28;
    }
    return (jmlDay);
}

///////////////////////////////
// Variabel kehadiran menu 3 //
//////////////////////////////
const int MAX_N = 100;
const int MAX_HT = 100; // untuk menggunakan getline di dalam array
const int MAX_K = 100;

/////////////////////////////////////
// Variabel sistem belanja menu 5 //
////////////////////////////////////
const int MAX_B = 100; // untuk menggunakan getline di dalam array

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu()
{
    ////////////////////////////////
    ///////////// menu /////////////
    ////////////////////////////////
    string pil, yn1;
    system("cls");
    setcolor(14);
    cout << "\t------------ Menu ------------\n";
    setcolor(15);
    cout << " 1. Jadwal Mata Pelajaran                    5. Sistem Belanja\n";
    cout << " 2. Database Kartu Pelajar Siswa             6. Calender\n";
    cout << " 3. Sistem Kehadiran Siswa                   7. Game\n";
    cout << " 4. Calculator                               8. Exit\n";
    cout << endl;
    cout << "Masukan Pilihan anda [ 1 s.d. 8 ] = ";
    cin >> pil;
    system("cls");

    /////////////////////////////////
    ///// input hari dan menu 1 /////
    /////////////////////////////////
    if (pil == "1")
    {
    jadwal2:
        // input nama kelas
        string ynd;
        string pilih, klj2, klj1;                                        // memilih menu dan kelas
        string ju2x, ju2xi, ju2xii;                                      // memilih jurusan menu 1
        string jul2x, jul2xi, jul2xii;                                   // memilih jurusan menu 2
        string kxrpl, kxtkj, kxtei, kxtet, kxak, kxto;                   // memilih kelas x  menu 1
        string kxirpl, kxitkj, kxitei, kxitet, kxiak, kxito;             // memilih kelas xi menu 1
        string kxiirpl, kxiitkj, kxiitei, kxiitet, kxiiak, kxiito;       // memilih kelas xii menu 1
        string kxrpl2, kxtkj2, kxtei2, kxtet2, kxak2, kxto2;             // memilih kelas x menu 2
        string kxirpl2, kxitkj2, kxitei2, kxitet2, kxiak2, kxito2;       // memilih kelas xi menu 2
        string kxiirpl2, kxiitkj2, kxiitei2, kxiitet2, kxiiak2, kxiito2; // memilih kelas xii menu 2

        setcolor(10);
        cout << "------------------------------------------------------------------\n";
        setcolor(11);
        cout << "             Jadwal Pelajaran SMK Negeri 2 Kota Bekasi            \n";
        setcolor(10);
        cout << "------------------------------------------------------------------\n\n";
        setcolor(15);
        cout << "1. Input Data\n";
        cout << "2. Lihat Data\n";
        cout << "3. Keluar\n";
        setcolor(14);
        cout << "Masukkan Pilihan Anda [ 1 s.d 3 ] : ";
        cin >> pilih;
        cout << "\n";
        setcolor(15);

        if (pilih == "1")
        {
        klj1:
            cout << "Kelas [ X, XI, XII ] : ";
            cin >> klj1;
            if (klj1 == "X" || klj1 == "x" || klj1 == "SEPULUH" || klj1 == "sepuluh" || klj1 == "Sepuluh")
            {
            ju2x:
                cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
                cin >> ju2x;
                if (ju2x == "RPL" || ju2x == "rpl" || ju2x == "Rpl")
                {
                kxrpl:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxrpl;
                    if (kxrpl == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxrpl == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxrpl == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxrpl == "K.I" || kxrpl == "k.i" || kxrpl == "KI" || kxrpl == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxrpl;
                    }
                }
                else if (ju2x == "TKJ" || ju2x == "tkj" || ju2x == "Tkj")
                {
                kxtkj:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxtkj;
                    if (kxtkj == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxtkj == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxtkj == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxtkj == "K.I" || kxtkj == "k.i" || kxtkj == "KI" || kxtkj == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxtkj;
                    }
                }
                else if (ju2x == "TEI" || ju2x == "tei" || ju2x == "Tei")
                {
                kxtei:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxtei;
                    if (kxtei == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxtei == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxtei == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxtei == "K.I" || kxtei == "k.i" || kxtei == "KI" || kxtei == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxtei;
                    }
                }
                else if (ju2x == "TET" || ju2x == "tet" || ju2x == "Tet")
                {
                kxtet:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxtet;
                    if (kxtet == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxtet == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxtet == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxtet == "K.I" || kxtet == "k.i" || kxtet == "KI" || kxtet == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxtet;
                    }
                }
                else if (ju2x == "AK" || ju2x == "ak" || ju2x == "Ak")
                {
                kxak:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxak;
                    if (kxak == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxak == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxak == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxak == "K.I" || kxak == "k.i" || kxak == "KI" || kxak == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxak;
                    }
                }
                else if (ju2x == "TO" || ju2x == "to" || ju2x == "To")
                {
                kxto:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxto;
                    if (kxto == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxto == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxto == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxto == "K.I" || kxto == "k.i" || kxto == "KI" || kxto == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxto;
                    }
                }
                else
                {
                    goto ju2x;
                }
            }
            else if (klj1 == "XI" || klj1 == "xi" || klj1 == "Xi" || klj1 == "Sebelas" || klj1 == "SEBELAS" || klj1 == "sebelas")
            {
            ju2xi:
                cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
                cin >> ju2xi;
                if (ju2xi == "RPL" || ju2xi == "rpl" || ju2xi == "Rpl")
                {
                kxirpl:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxirpl;
                    if (kxirpl == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxirpl == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxirpl == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxirpl == "K.I" || kxirpl == "k.i" || kxirpl == "KI" || kxirpl == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxirpl;
                    }
                }
                else if (ju2xi == "TKJ" || ju2xi == "tkj" || ju2xi == "Tkj")
                {
                kxitkj:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxitkj;
                    if (kxitkj == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxitkj == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxitkj == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxitkj == "K.I" || kxitkj == "k.i" || kxitkj == "KI" || kxitkj == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxitkj;
                    }
                }
                else if (ju2xi == "TEI" || ju2xi == "tei" || ju2xi == "Tei")
                {
                kxitei:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxitei;
                    if (kxitei == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxitei == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxitei == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxitei == "K.I" || kxitei == "k.i" || kxitei == "KI" || kxitei == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxitei;
                    }
                }
                else if (ju2xi == "TET" || ju2xi == "tet" || ju2xi == "Tet")
                {
                kxitet:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxitet;
                    if (kxitet == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxitet == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxitet == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxitet == "K.I" || kxitet == "k.i" || kxitet == "KI" || kxitet == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxitet;
                    }
                }
                else if (ju2xi == "AK" || ju2xi == "ak" || ju2xi == "Ak")
                {
                kxiak:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiak;
                    if (kxiak == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiak == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiak == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiak == "K.I" || kxiak == "k.i" || kxiak == "KI" || kxiak == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxiak;
                    }
                }
                else if (ju2xi == "TO " || ju2xi == "to" || ju2xi == "To")
                {
                kxito:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxito;
                    if (kxito == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxito == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxito == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxito == "K.I" || kxito == "k.i" || kxito == "KI" || kxito == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxito;
                    }
                }
                else
                {
                    goto ju2xi;
                }
            }
            else if (klj1 == "XII" || klj1 == "Xii" || klj1 == "DUA BELAS" || klj1 == "Dua Belas" || klj1 == "dua belas" || klj1 == "xii")
            {
            ju2xii:
                cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
                cin >> ju2xii;
                if (ju2xii == "RPL" || ju2xii == "rpl" || ju2xii == "Rpl")
                {
                kxiirpl:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiirpl;
                    if (kxiirpl == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiirpl == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiirpl == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiirpl == "K.I" || kxiirpl == "k.i" || kxiirpl == "KI" || kxiirpl == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxiirpl;
                    }
                }
                else if (ju2xii == "TKJ" || ju2xii == "tkj" || ju2xii == "Tkj")
                {
                kxiitkj:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiitkj;
                    if (kxiitkj == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiitkj == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiitkj == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiitkj == "K.I" || kxiitkj == "k.i" || kxiitkj == "KI" || kxiitkj == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxiitkj;
                    }
                }
                else if (ju2xii == "TEI" || ju2xii == "tei" || ju2xii == "Tei")
                {
                kxiitei:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiitei;
                    if (kxiitei == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiitei == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiitei == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiitei == "K.I" || kxiitei == "k.i" || kxiitei == "KI" || kxiitei == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxiitei;
                    }
                }
                else if (ju2xii == "TET" || ju2xii == "tet" || ju2xii == "Tet")
                {
                kxiitet:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiitet;
                    if (kxiitet == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiitet == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiitet == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiitet == "K.I" || kxiitet == "k.i" || kxiitet == "KI" || kxiitet == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxiitet;
                    }
                }
                else if (ju2xii == "AK" || ju2xii == "ak" || ju2xii == "Ak")
                {
                kxiiak:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiiak;
                    if (kxiiak == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiiak == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiiak == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiiak == "K.I" || kxiiak == "k.i" || kxiiak == "KI" || kxiiak == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxiiak;
                    }
                }
                else if (ju2xii == "TO" || ju2xii == "to" || ju2xii == "To")
                {
                kxiito:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiito;
                    if (kxiito == "1")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiito == "2")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiito == "3")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else if (kxiito == "K.I" || kxiito == "k.i" || kxiito == "KI" || kxiito == "ki")
                    {
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto jadwal2;
                    }
                    else
                    {
                        goto kxiito;
                    }
                }
                else
                {
                    goto ju2xii;
                }
            }
            else
            {
                goto klj1;
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
        }
        else if (pilih == "2")
        {
        klj2:
            cout << "Kelas [ X, XI, XII ] : ";
            cin >> klj2;
            if (klj2 == "X" || klj2 == "x" || klj2 == "Sepuluh" || klj2 == "SEPULUH" || klj2 == "sepuluh")
            {
            jul2x:
                cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
                cin >> jul2x;
                if (jul2x == "RPL" || jul2x == "rpl" || jul2x == "Rpl")
                {
                kxrpl2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxrpl2;
                    if (kxrpl2 == "1")
                    {
                    back1:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back1;
                        }
                    }
                    else if (kxrpl2 == "2")
                    {
                    back2:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back2;
                        }
                    }
                    else if (kxrpl2 == "3")
                    {
                    back3:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back3;
                        }
                    }
                    else if (kxrpl2 == "K.I" || kxrpl2 == "k.i" || kxrpl2 == "KI" || kxrpl2 == "ki")
                    {
                    back4:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back4;
                        }
                    }
                    else
                    {
                        goto kxrpl2;
                    }
                }
                else if (jul2x == "TKJ" || jul2x == "tkj" || jul2x == "Tkj")
                {
                kxtkj2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxtkj2;
                    if (kxtkj2 == "1")
                    {
                    back5:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back5;
                        }
                    }
                    else if (kxtkj2 == "2")
                    {
                    back6:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back6;
                        }
                    }
                    else if (kxtkj2 == "3")
                    {
                    back7:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back7;
                        }
                    }
                    else if (kxtkj2 == "K.I" || kxtkj2 == "k.i" || kxtkj2 == "KI" || kxtkj2 == "ki")
                    {
                    back8:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back8;
                        }
                    }
                    else
                    {
                        goto kxtkj2;
                    }
                }
                else if (jul2x == "TEI" || jul2x == "tei" || jul2x == "Tei")
                {
                kxtei2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxtei2;
                    if (kxtei2 == "1")
                    {
                    back9:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back9;
                        }
                    }
                    else if (kxtei2 == "2")
                    {
                    back10:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back10;
                        }
                    }
                    else if (kxtei2 == "3")
                    {
                    back11:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back11;
                        }
                    }
                    else if (kxtei2 == "K.I" || kxtei2 == "k.i" || kxtei2 == "KI" || kxtei2 == "ki")
                    {
                    back12:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back12;
                        }
                    }
                    else
                    {
                        goto kxtei2;
                    }
                }
                else if (jul2x == "TET" || jul2x == "tet" || jul2x == "Tet")
                {
                kxtet2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxtet2;
                    if (kxtet2 == "1")
                    {
                    back13:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back13;
                        }
                    }
                    else if (kxtet2 == "2")
                    {
                    back14:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back14;
                        }
                    }
                    else if (kxtet2 == "3")
                    {
                    back15:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back15;
                        }
                    }
                    else if (kxtet2 == "K.I" || kxtet2 == "k.i" || kxtet2 == "KI" || kxtet2 == "ki")
                    {
                    back16:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back16;
                        }
                    }
                    else
                    {
                        goto kxtet2;
                    }
                }
                else if (jul2x == "AK" || jul2x == "ak" || jul2x == "Ak")
                {
                kxak2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxak2;
                    if (kxak2 == "1")
                    {
                    back17:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back17;
                        }
                    }
                    else if (kxak2 == "2")
                    {
                    back18:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back18;
                        }
                    }
                    else if (kxak2 == "3")
                    {
                    back19:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back19;
                        }
                    }
                    else if (kxak2 == "K.I" || kxak2 == "k.i" || kxak2 == "KI" || kxak2 == "ki")
                    {
                    back20:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back20;
                        }
                    }
                    else
                    {
                        goto kxak2;
                    }
                }
                else if (jul2x == "TO" || jul2x == "To" || jul2x == "to")
                {
                kxto2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxto2;
                    if (kxto2 == "1")
                    {
                    back21:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back21;
                        }
                    }
                    else if (kxto2 == "2")
                    {
                    back22:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back22;
                        }
                    }
                    else if (kxto2 == "3")
                    {
                    back23:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back23;
                        }
                    }
                    else if (kxto2 == "K.I" || kxto2 == "k.i" || kxto2 == "KI" || kxto2 == "ki")
                    {
                    back24:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back24;
                        }
                    }
                    else
                    {
                        goto kxto2;
                    }
                }
                else
                {
                    goto jul2x;
                }
            }
            else if (klj2 == "XI" || klj2 == "xi" || klj2 == "Xi" || klj2 == "SEBELAS" || klj2 == "sebelas" || klj2 == "Sebelas")
            {
            jul2xi:
                cout << "Jurusan [ RPL, TEKJ, TEI, TET, AK, TO ] : ";
                cin >> jul2xi;
                if (jul2xi == "RPL" || jul2xi == "rpl" || jul2xi == "Rpl")
                {
                kxirpl2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxirpl2;
                    if (kxirpl2 == "1")
                    {
                    back25:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back25;
                        }
                    }
                    else if (kxirpl2 == "2")
                    {
                    back26:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back26;
                        }
                    }
                    else if (kxirpl2 == "3")
                    {
                    back27:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back27;
                        }
                    }
                    else if (kxirpl2 == "K.I" || kxirpl2 == "k.i" || kxirpl2 == "KI" || kxirpl2 == "ki")
                    {
                    back28:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back28;
                        }
                    }
                    else
                    {
                        goto kxirpl2;
                    }
                }
                else if (jul2xi == "TKJ" || jul2xi == "tkj" || jul2xi == "Tkj")
                {
                kxitkj2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxitkj2;
                    if (kxitkj2 == "1")
                    {
                    back29:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back29;
                        }
                    }
                    else if (kxitkj2 == "2")
                    {
                    back30:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back30;
                        }
                    }
                    else if (kxitkj2 == "3")
                    {
                    back31:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back31;
                        }
                    }
                    else if (kxitkj2 == "K.I" || kxitkj2 == "k.i" || kxitkj2 == "KI" || kxitkj2 == "ki")
                    {
                    back32:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back32;
                        }
                    }
                    else
                    {
                        goto kxitkj2;
                    }
                }
                else if (jul2xi == "TEI" || jul2xi == "tei" || jul2xi == "Tei")
                {
                kxitei2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxitei2;
                    if (kxitei2 == "1")
                    {
                    back33:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back33;
                        }
                    }
                    else if (kxitei2 == "2")
                    {
                    back34:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back34;
                        }
                    }
                    else if (kxitei2 == "3")
                    {
                    back35:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back35;
                        }
                    }
                    else if (kxitei2 == "K.I" || kxitei2 == "k.i" || kxitei2 == "KI" || kxitei2 == "ki")
                    {
                    back36:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back36;
                        }
                    }
                    else
                    {
                        goto kxitei2;
                    }
                }
                else if (jul2xi == "TET" || jul2xi == "tet" || jul2xi == "Tet")
                {
                kxitet2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxitet2;
                    if (kxitet2 == "1")
                    {
                    back37:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back37;
                        }
                    }
                    else if (kxitet2 == "2")
                    {
                    back38:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back38;
                        }
                    }
                    else if (kxitet2 == "3")
                    {
                    back39:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back39;
                        }
                    }
                    else if (kxitet2 == "K.I" || kxitet2 == "k.i" || kxitet2 == "KI" || kxitet2 == "ki")
                    {
                    back40:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back40;
                        }
                    }
                    else
                    {
                        goto kxitet2;
                    }
                }
                else if (jul2xi == "AK" || jul2xi == "ak" || jul2xi == "Ak")
                {
                kxiak2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiak2;
                    if (kxiak2 == "1")
                    {
                    back41:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back41;
                        }
                    }
                    else if (kxiak2 == "2")
                    {
                    back42:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back42;
                        }
                    }
                    else if (kxiak2 == "3")
                    {
                    back43:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back43;
                        }
                    }
                    else if (kxiak2 == "K.I" || kxiak2 == "k.i" || kxiak2 == "KI" || kxiak2 == "ki")
                    {
                    back44:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back44;
                        }
                    }
                    else
                    {
                        goto kxiak2;
                    }
                }
                else if (jul2xi == "TO" || jul2xi == "to" || jul2xi == "Xi")
                {
                kxito2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxito2;
                    if (kxito2 == "1")
                    {
                    back45:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back45;
                        }
                    }
                    else if (kxito2 == "2")
                    {
                    back46:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back46;
                        }
                    }
                    else if (kxito2 == "3")
                    {
                    back47:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back47;
                        }
                    }
                    else if (kxito2 == "K.I" || kxito2 == "k.i" || kxito2 == "KI" || kxito2 == "ki")
                    {
                    back48:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back48;
                        }
                    }
                    else
                    {
                        goto kxito2;
                    }
                }
                else
                {
                    goto jul2xi;
                }
            }
            else if (klj2 == "XII" || klj2 == "Xii" || klj2 == "DUA BELAS" || klj2 == "Dua Belas" || klj2 == "dua belas" || klj2 == "xii")
            {
            jul2xii:
                cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
                cin >> jul2xii;
                if (jul2xii == "RPL" || jul2xii == "rpl" || jul2xii == "Rpl")
                {
                kxiirpl2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiirpl2;
                    if (kxiirpl2 == "1")
                    {
                    back49:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back49;
                        }
                    }
                    else if (kxiirpl2 == "2")
                    {
                    back50:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back50;
                        }
                    }
                    else if (kxiirpl2 == "3")
                    {
                    back51:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back51;
                        }
                    }
                    else if (kxiirpl2 == "K.I" || kxiirpl2 == "k.i" || kxiirpl2 == "KI" || kxiirpl2 == "ki")
                    {
                    back52:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back52;
                        }
                    }
                    else
                    {
                        goto kxiirpl2;
                    }
                }
                else if (jul2xii == "TKJ" || jul2xii == "tkj" || jul2xii == "Tkj")
                {
                kxiitkj2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiitkj2;
                    if (kxiitkj2 == "1")
                    {
                    back53:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back53;
                        }
                    }
                    else if (kxiitkj2 == "2")
                    {
                    back54:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back54;
                        }
                    }
                    else if (kxiitkj2 == "3")
                    {
                    back55:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back55;
                        }
                    }
                    else if (kxiitkj2 == "K.I" || kxiitkj2 == "k.i" || kxiitkj2 == "KI" || kxiitkj2 == "ki")
                    {
                    back56:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back56;
                        }
                    }
                    else
                    {
                        goto kxiitkj2;
                    }
                }
                else if (jul2xii == "TEI" || jul2xii == "tei" || jul2xii == "Tei")
                {
                kxiitei2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiitei2;
                    if (kxiitei2 == "1")
                    {
                    back57:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back57;
                        }
                    }
                    else if (kxiitei2 == "2")
                    {
                    back58:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back58;
                        }
                    }
                    else if (kxiitei2 == "3")
                    {
                    back59:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back59;
                        }
                    }
                    else if (kxiitei2 == "K.I" || kxiitei2 == "k.i" || kxiitei2 == "KI" || kxiitei2 == "ki")
                    {
                    back60:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back60;
                        }
                    }
                    else
                    {
                        goto kxiitei2;
                    }
                }
                else if (jul2xii == "TET" || jul2xii == "tet" || jul2xii == "Tet")
                {
                kxiitet2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiitet2;
                    if (kxiitet2 == "1")
                    {
                    back61:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back61;
                        }
                    }
                    else if (kxiitet2 == "2")
                    {
                    back62:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back62;
                        }
                    }
                    else if (kxiitet2 == "3")
                    {
                    back63:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back63;
                        }
                    }
                    else if (kxiitet2 == "K.I" || kxiitet2 == "k.i" || kxiitet2 == "KI" || kxiitet2 == "ki")
                    {
                    back64:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back64;
                        }
                    }
                    else
                    {
                        goto kxiitet2;
                    }
                }
                else if (jul2xii == "AK" || jul2xii == "ak" || jul2xii == "Ak")
                {
                kxiiak2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiiak2;
                    if (kxiiak2 == "1")
                    {
                    back65:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back65;
                        }
                    }
                    else if (kxiiak2 == "2")
                    {
                    back66:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back66;
                        }
                    }
                    else if (kxiiak2 == "3")
                    {
                    back67:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back67;
                        }
                    }
                    else if (kxiiak2 == "K.I" || kxiiak2 == "k.i" || kxiiak2 == "KI" || kxiiak2 == "ki")
                    {
                    back68:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back68;
                        }
                    }
                    else
                    {
                        goto kxiiak2;
                    }
                }
                else if (jul2xii == "TO" || jul2xii == "To" || jul2xii == "to")
                {
                kxiito2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> kxiito2;
                    if (kxiito2 == "1")
                    {
                    back69:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back69;
                        }
                    }
                    else if (kxiito2 == "2")
                    {
                    back70:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back70;
                        }
                    }
                    else if (kxiito2 == "3")
                    {
                    back71:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back71;
                        }
                    }
                    else if (kxiito2 == "K.I" || kxiito2 == "k.i" || kxiito2 == "KI" || kxiito2 == "ki")
                    {
                    back72:
                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto jadwal2;
                        }
                        else
                        {
                            goto back72;
                        }
                    }
                    else
                    {
                        goto kxiito2;
                    }
                }
                else
                {
                    goto jul2xii;
                }
            }
            else
            {
                goto klj2;
            }
        }

        else if (pilih == "3")
        {
            system("cls");
            menu();
        }
        else
        {
            system("cls");
            goto jadwal2;
        }
    }

    /////////////////////////////////////////
    ////  Menu 2 = Sistem Database Siswa ////
    /////////////////////////////////////////
    else if (pil == "2")
    {

        ///////////////////////
        /////// Tipe Data /////
        ///////////////////////
        setcolor(15);
    menud:
        system("cls");
        string pill, kl1, kl2;                                                 // kelas
        string jur1x, jur1xi, jur1xii, jur2x, jur2xi, jur2xii;                 // jurusan
        string ktxrpl, ktxtkj, ktxtei, ktxtet, ktxak, ktxto;                   // keterangan kelas x (input data)
        string ktxirpl, ktxitkj, ktxitei, ktxitet, ktxiak, ktxito;             // keterangan kelas xi (input data)
        string ktxiirpl, ktxiitkj, ktxiitei, ktxiitet, ktxiiak, ktxiito;       // keterangan kelas xii (input data)
        string ktxrpl2, ktxtkj2, ktxtei2, ktxtet2, ktxak2, ktxto2;             // keterangan kelas x (Lihat data)
        string ktxirpl2, ktxitkj2, ktxitei2, ktxitet2, ktxiak2, ktxito2;       // keterangan kelas xi (Lihat data)
        string ktxiirpl2, ktxiitkj2, ktxiitei2, ktxiitet2, ktxiiak2, ktxiito2; // keterangan kelas xii (Lihat data)
        string ynd;                                                            // kembali ke menu

        // Pengecekan dan input data
        string namacek, niscek, ttlcek, jkcek, almtcek;             // untuk melakukan pengecekan data apabila ada yang sama
        string namainput, nisinput, ttlinput, jkinput, alamatinput; // untuk menginput data

        // pengecekan apakah data sudah ada di salah satu dari beberapa file database
        string fileNames[] = {
            "x_rpl_1.txt", "x_rpl_2.txt", "x_rpl_3.txt", "x_rpl_ki.txt",         // pengecekan kelas x rpl
            "x_tkj_1.txt", "x_tkj_2.txt", "x_tkj_3.txt", "x_tkj_ki.txt",         // pengecekan kelas x tkj
            "x_tei_1.txt", "x_tei_2.txt", "x_tei_3.txt", "x_tei_ki.txt",         // pengecekan kelas x tei
            "x_tet_1.txt", "x_tet_2.txt", "x_tet_3.txt", "x_tet_ki.txt",         // pengecekan kelas x tet
            "x_ak_1.txt", "x_ak_2.txt", "x_ak_3.txt", "x_ak_ki.txt",             // pengecekan kelas x ak
            "x_to_1.txt", "x_to_2.txt", "x_to_3.txt", "x_to_ki.txt",             // pengecekan kelas x to
            "xi_rpl_1.txt", "xi_rpl_2.txt", "xi_rpl_3.txt", "xi_rpl_ki.txt",     // pengecekan xi rpl
            "xi_tkj_1.txt", "xi_tkj_2.txt", "xi_tkj_3.txt", "xi_tkj_ki.txt",     // pengecekan xi tkj
            "xi_tei_1.txt", "xi_tei_2.txt", "xi_tei_3.txt", "xi_tei_ki.txt",     // pengecekan xi tei
            "xi_tet_1.txt", "xi_tet_2.txt", "xi_tet_3.txt", "xi_tet_ki.txt",     // pengecekan xi tet
            "xi_ak_1.txt", "xi_ak_2.txt", "xi_ak_3.txt", "xi_ak_ki.txt",         // pengecekan xi ak
            "xi_to_1.txt", "xi_to_2.txt", "xi_to_3.txt", "xi_to_ki.txt",         // pengecekan xi to
            "xii_rpl_1.txt", "xii_rpl_2.txt", "xii_rpl_3.txt", "xii_rpl_ki.txt", // pengecekan xii rpl
            "xii_tkj_1.txt", "xii_tkj_2.txt", "xii_tkj_3.txt", "xii_tkj_ki.txt", // pengecekan xii tkj
            "xii_tei_1.txt", "xii_tei_2.txt", "xii_tei_3.txt", "xii_tei_ki.txt", // pengecekan xii tei
            "xii_tet_1.txt", "xii_tet_2.txt", "xii_tet_3.txt", "xii_tet_ki.txt", // pengecekan xii tet
            "xii_ak_1.txt", "xii_ak_2.txt", "xii_ak_3.txt", "xii_ak_ki.txt",     // pengecekan xii ak
            "xii_to_1.txt", "xii_to_2.txt", "xii_to_3.txt", "xii_to_ki.txt",     // pengecekan xii to
        };

        ////////////////
        ///// Menu /////
        ////////////////
        setcolor(10);
        cout << "------------------------------------------------------------------\n";
        setcolor(11);
        cout << "                   Database Kartu Pelajar Siswa                   \n";
        setcolor(10);
        cout << "------------------------------------------------------------------\n\n";
        setcolor(15);
        cout << "1. Input Data\n";
        cout << "2. Lihat Data\n";
        cout << "3. Keluar\n";
        setcolor(14);
        cout << "Masukkan Pilihan Anda [ 1 s.d 3 ] : ";
        cin >> pill;
        cout << "\n";
        setcolor(15);

        // Pilih 1
        if (pill == "1")
        {

            // Input Kelas
        kel1:
            cout << "Kelas [ X, XI, XII ] : ";
            cin >> kl1;

            // Pilih X
            if (kl1 == "X" || kl1 == "x" || kl1 == "Sepuluh" || kl1 == "sepuluh" || kl1 == "SEPULUH")
            {

                // Input Jurusan
            jur1x:
                cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
                cin >> jur1x;

                // Pilih RPL
                if (jur1x == "RPL" || jur1x == "rpl" || jur1x == "Rpl")
                {

                    // keterangan
                ktxrpl:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxrpl;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxrpl == "1")
                    {

                        //////////////////////////////
                        ///// Input Data x rpl 1 /////
                        //////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X RPL 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 1
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data1("x_rpl_1.txt", ios::app);
                        data1 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxrpl == "2")
                    {

                        //////////////////////////////
                        ///// Input Data x rpl 2 /////
                        //////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X RPL 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 2
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data2("x_rpl_2.txt", ios::app);
                        data2 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxrpl == "3")
                    {

                        //////////////////////////////
                        ///// Input Data x rpl 3 /////
                        //////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X RPL 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data3("x_rpl_3.txt", ios::app);
                        data3 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxrpl == "K.I" || ktxrpl == "k.i" || ktxrpl == "KI" || ktxrpl == "ki")
                    {

                        ////////////////////////////////
                        ///// Input Data x rpl K.I /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X RPL K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_rpl_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxrpl;
                    }

                    // Pilih TKJ
                }
                else if (jur1x == "TKJ" || jur1x == "tkj" || jur1x == "Tkj")
                {

                    // keterangan
                ktxtkj:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxtkj;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // Pilih 1
                    if (ktxtkj == "1")
                    {

                        //////////////////////////////
                        ///// Input Data x tkj 1 /////
                        //////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TKJ 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tkj_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxtkj == "2")
                    {

                        //////////////////////////////
                        ///// Input Data x tkj 2 /////
                        //////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TKJ 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tkj_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxtkj == "3")
                    {

                        //////////////////////////////
                        ///// Input Data x tkj 3 /////
                        //////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TKJ 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tkj_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxtkj == "K.I" || ktxtkj == "k.i" || ktxtkj == "KI" || ktxtkj == "ki")
                    {

                        ////////////////////////////////
                        ///// Input Data x tkj k.i /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TKJ K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tkj_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxtkj;
                    }

                    // Pilih TEI
                }
                else if (jur1x == "TEI" || jur1x == "tei" || jur1x == "Tei")
                {

                    // keterangan
                ktxtei:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxtei;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxtei == "1")
                    {

                        //////////////////////////////
                        ///// Input Data x tei 1 /////
                        //////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TEI 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tei_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxtei == "2")
                    {

                        ////////////////////////////////
                        ///// Input Data X TEI 2   /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TEI 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tei_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxtei == "3")
                    {

                        ////////////////////////////////
                        ///// Input Data x tei 3   /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data x tei 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tei_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxtei == "K.I" || ktxtei == "k.i" || ktxtei == "KI" || ktxtei == "ki")
                    {

                        ////////////////////////////////
                        ///// Input Data X TEI K.I /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TEI K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tei_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxtei;
                    }

                    // Pilih TET
                }
                else if (jur1x == "TET" || jur1x == "tet" || jur1x == "Tet")
                {

                    // keterangan
                ktxtet:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxtet;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxtet == "1")
                    {

                        ////////////////////////////////
                        ///// Input Data X TET 1   /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TET 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tet_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxtet == "2")
                    {

                        ////////////////////////////////
                        ///// Input Data X TET 2   /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TET 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tet_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxtet == "3")
                    {

                        ////////////////////////////////
                        ///// Input Data X TET 3   /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TET 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tet_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxtet == "K.I" || ktxtet == "k.i" || ktxtet == "KI" || ktxtet == "ki")
                    {

                        ////////////////////////////////
                        ///// Input Data X TET k.i /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TET K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_tet_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxtet;
                    }

                    // Pilih AK
                }
                else if (jur1x == "AK" || jur1x == "Ak" || jur1x == "ak")
                {

                    // keterangan
                ktxak:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxak;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxak == "1")
                    {

                        ////////////////////////////////
                        ///// Input Data X AK 1    /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X AK 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_ak_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxak == "2")
                    {

                        ////////////////////////////////
                        ///// Input Data X AK 2    /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X AK 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_ak_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxak == "3")
                    {

                        ////////////////////////////////
                        ///// Input Data X AK 3    /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X AK 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_ak_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxak == "K.I" || ktxak == "k.i" || ktxak == "KI" || ktxak == "ki")
                    {

                        ////////////////////////////////
                        ///// Input Data X AK K.I  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X AK K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_ak_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxak;
                    }

                    // Pilih TO
                }
                else if (jur1x == "TO" || jur1x == "to" || jur1x == "To")
                {

                    // keterangan
                ktxto:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxto;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxto == "1")
                    {

                        ////////////////////////////////
                        ///// Input Data X TO 1    /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TO 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_to_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxto == "2")
                    {

                        ////////////////////////////////
                        ///// Input Data X TO 2    /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TO 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_to_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxto == "3")
                    {

                        ////////////////////////////////
                        ///// Input Data X TO 3    /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TO 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_to_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxto == "K.I" || ktxto == "k.i" || ktxto == "KI" || ktxto == "ki")
                    {

                        ////////////////////////////////
                        ///// Input Data X TO k.i  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data X TO K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("x_to_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxto;
                    }

                    // Output apabila input tidak sesuai
                }
                else
                {
                    goto jur1x;
                }

                // Pilih XI
            }
            else if (kl1 == "XI" || kl1 == "xi" || kl1 == "Xi" || kl1 == "Sebelas" || kl1 == "SEBELAS" || kl1 == "sebelas")
            {

                // Input Jurusan
            jur1xi:
                cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
                cin >> jur1xi;

                // Pilih RPL
                if (jur1xi == "RPL" || jur1xi == "rpl" || jur1xi == "Rpl")
                {

                    // keterangan
                ktxirpl:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxirpl;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxirpl == "1")
                    {

                        ////////////////////////////////
                        ///// Input Data XI RPL 1  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI RPL 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_rpl_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxirpl == "2")
                    {

                        ////////////////////////////////
                        ///// Input Data XI RPL 2  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI RPL 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_rpl_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxirpl == "3")
                    {

                        ////////////////////////////////
                        ///// Input Data XI RPL 3  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI RPL 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_rpl_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxirpl == "K.I" || ktxirpl == "k.i" || ktxirpl == "KI" || ktxirpl == "ki")
                    {

                        /////////////////////////////////
                        ///// Input Data XI RPL K.I /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI RPL K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_rpl_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxirpl;
                    }

                    // Pilih TKJ
                }
                else if (jur1xi == "TKJ" || jur1xi == "tkj" || jur1xi == "Tkj")
                {

                    // keterangan
                ktxitkj:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxitkj;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxitkj == "1")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TKJ 1  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TKJ 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tkj_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxitkj == "2")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TKJ 2  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TKJ 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tkj_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxitkj == "3")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TKJ 3  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TKJ 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tkj_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxitkj == "K.I" || ktxitkj == "k.i" || ktxitkj == "KI" || ktxitkj == "ki")
                    {

                        //////////////////////////////////
                        ///// Input Data XI TKJ K.I  /////
                        //////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TKJ K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tkj_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxitkj;
                    }

                    // Pilih TEI
                }
                else if (jur1xi == "TEI" || jur1xi == "tei" || jur1xi == "Tei")
                {

                    // keterangan
                ktxitei:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxitei;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxitei == "1")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TEI 1  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TEI 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tei_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxitei == "2")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TEI 2  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TEI 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tei_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxitei == "3")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TEI 3  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TEI 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tei_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxitei == "K.I" || ktxitei == "k.i" || ktxitei == "KI" || ktxitei == "ki")
                    {

                        //////////////////////////////////
                        ///// Input Data XI TEI K.I  /////
                        //////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TEI K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tei_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxitei;
                    }

                    // Pilih TET
                }
                else if (jur1xi == "TET" || jur1xi == "tet" || jur1xi == "Tet")
                {

                    // keterangan
                ktxitet:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxitet;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxitet == "1")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TET 1  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TET 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tet_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxitet == "2")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TET 2  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TET 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tet_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxitet == "3")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TET 3  /////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TET 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tet_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxitet == "K.I" || ktxitet == "k.i" || ktxitet == "KI" || ktxitet == "ki")
                    {

                        //////////////////////////////////
                        ///// Input Data XI TET K.I  /////
                        //////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TET K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_tet_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxitet;
                    }

                    // Pilih AK
                }
                else if (jur1xi == "AK" || jur1xi == "Ak" || jur1xi == "ak")
                {

                    // keterangan
                ktxiak:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiak;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiak == "1")
                    {

                        ////////////////////////////////
                        ///// Input Data XI AK 1  //////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI AK 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_ak_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiak == "2")
                    {

                        ////////////////////////////////
                        ///// Input Data XI AK 2  //////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI AK 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_ak_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiak == "3")
                    {

                        ////////////////////////////////
                        ///// Input Data XI AK 3  //////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI AK 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_ak_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiak == "K.I" || ktxiak == "k.i" || ktxiak == "KI" || ktxiak == "ki")
                    {

                        /////////////////////////////////
                        ///// Input Data XI AK K.I  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI AK K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_ak_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiak;
                    }

                    // Pilih TO
                }
                else if (jur1xi == "TO" || jur1xi == "to" || jur1xi == "To")
                {

                    // keterangan
                ktxito:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxito;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxito == "1")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TO 1  //////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TO 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_to_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxito == "2")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TO 2  //////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TO 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_to_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxito == "3")
                    {

                        ////////////////////////////////
                        ///// Input Data XI TO 3  //////
                        ////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TO 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_to_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxito == "K.I" || ktxito == "k.i" || ktxito == "KI" || ktxito == "ki")
                    {

                        /////////////////////////////////
                        ///// Input Data XI TO K.I  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XI TO K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xi_to_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxito;
                    }

                    // Output apabila input tidak sesuai
                }
                else
                {
                    goto jur1xi;
                }

                // Pilih XII
            }
            else if (kl1 == "XII" || kl1 == "xii" || kl1 == "Xii" || kl1 == "Dua Belas" || kl1 == "dua belas" || kl1 == "DUA BELAS" || kl1 == "Dua belas")
            {

                // Input Jurusan
            jur1xii:
                cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
                cin >> jur1xii;

                // Pilih RPL
                if (jur1xii == "RPL" || jur1xii == "rpl" || jur1xii == "Rpl")
                {

                    // keterangan
                ktxiirpl:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiirpl;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiirpl == "1")
                    {

                        /////////////////////////////////
                        ///// Input Data XII RPL 1  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII RPL 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_rpl_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiirpl == "2")
                    {

                        /////////////////////////////////
                        ///// Input Data XII RPL 2  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII RPL 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_rpl_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiirpl == "3")
                    {

                        /////////////////////////////////
                        ///// Input Data XII RPL 3  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII RPL 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_rpl_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiirpl == "K.I" || ktxiirpl == "k.i" || ktxiirpl == "KI" || ktxiirpl == "ki")
                    {

                        ///////////////////////////////////
                        ///// Input Data XII RPL K.I  /////
                        ///////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII RPL K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_rpl_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiirpl;
                    }

                    // Pilih TKJ
                }
                else if (jur1xii == "TKJ" || jur1xii == "tkj" || jur1xii == "Tkj")
                {

                    // keterangan
                ktxiitkj:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiitkj;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiitkj == "1")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TKJ 1  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TKJ 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tkj_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiitkj == "2")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TKJ 2  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TKJ 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tkj_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiitkj == "3")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TKJ 3  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TKJ 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tkj_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiitkj == "K.I" || ktxiitkj == "k.i" || ktxiitkj == "KI" || ktxiitkj == "ki")
                    {

                        ///////////////////////////////////
                        ///// Input Data XII TKJ K.I  /////
                        ///////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TKJ K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tkj_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiitkj;
                    }

                    // Pilih TEI
                }
                else if (jur1xii == "TEI" || jur1xii == "tei" || jur1xii == "Tei")
                {

                    // keterangan
                ktxiitei:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiitei;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiitei == "1")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TEI 1  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TEI 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tei_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiitei == "2")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TEI 2  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TEI 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tei_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiitei == "3")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TEI 3  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TEI 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tei_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiitei == "K.I" || ktxiitei == "k.i" || ktxiitei == "KI" || ktxiitei == "ki")
                    {

                        ///////////////////////////////////
                        ///// Input Data XII TEI K.I  /////
                        ///////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TEI K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tei_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiitei;
                    }

                    // Pilih TET
                }
                else if (jur1xii == "TET" || jur1xii == "tet" || jur1xii == "Tet")
                {

                    // keterangan
                ktxiitet:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiitet;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiitet == "1")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TET 1  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TET 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tet_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiitet == "2")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TET 2  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TET 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tet_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiitet == "3")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TET 3  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TET 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tet_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiitet == "K.I" || ktxiitet == "k.i" || ktxiitet == "KI" || ktxiitet == "ki")
                    {

                        ///////////////////////////////////
                        ///// Input Data XII TET K.I  /////
                        ///////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TET K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_tet_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiitet;
                    }

                    // Pilih AK
                }
                else if (jur1xii == "AK" || jur1xii == "Ak" || jur1xii == "ak")
                {

                    // keterangan
                ktxiiak:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiiak;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiiak == "1")
                    {

                        /////////////////////////////////
                        ///// Input Data XII AK 1  //////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII AK 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_ak_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiiak == "2")
                    {

                        /////////////////////////////////
                        ///// Input Data XII AK 2  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII AK 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_ak_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiiak == "3")
                    {

                        /////////////////////////////////
                        ///// Input Data XII AK 3  //////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII AK 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_ak_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiiak == "K.I" || ktxiiak == "k.i" || ktxiiak == "KI" || ktxiiak == "ki")
                    {

                        //////////////////////////////////
                        ///// Input Data XII AK K.I  /////
                        //////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII AK K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_ak_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiiak;
                    }

                    // Pilih TO
                }
                else if (jur1xii == "TO" || jur1xii == "to" || jur1xii == "To")
                {

                    // keterangan
                ktxiito:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiito;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiito == "1")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TO 1  //////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TO 1 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_to_1.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiito == "2")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TO 2  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TO 2 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_to_2.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiito == "3")
                    {

                        /////////////////////////////////
                        ///// Input Data XII TO 3  /////
                        /////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TO 3 --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_to_3.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiito == "K.I" || ktxiito == "k.i" || ktxiito == "KI" || ktxiito == "ki")
                    {

                        //////////////////////////////////
                        ///// Input Data XII TO K.I  /////
                        //////////////////////////////////

                        // Judul
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Input data XII TO K.I --\t";
                        setcolor(15);
                        cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi dan koma\n";

                        // Input Username X RPL
                        cout << "Nama : ";
                        cin >> namainput;

                        // input NIS X RPL 3
                        while (true)
                        {
                            cout << "NIS : ";
                            cin >> nisinput;

                            // validasi NIS harus berupa angka
                            bool valid = true;
                            for (char c : nisinput)
                            {
                                if (!isdigit(c))
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                            {
                                setcolor(12);
                                cout << "NIS harus berupa angka, masukkan NIS dengan benar !!" << endl;
                                setcolor(15);
                                continue;
                            }

                            // pengecekan apakah data sudah ada di salah satu dari beberapa file database
                            bool flag = false;
                            for (string fileName : fileNames)
                            {
                                ifstream data(fileName);
                                while (data >> namacek >> niscek >> ttlcek >> jkcek >> almtcek)
                                { // mengecek data yang berada di dalam file database txt
                                    if (niscek == nisinput)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag)
                                {
                                    break;
                                }
                            }

                            // output apabila data sudah ada di salah satu dari beberapa file database
                            if (flag)
                            {
                                setcolor(12);
                                cout << "NIS sudah terpakai, masukkan NIS lain" << endl;
                                setcolor(15);
                                continue;
                            }
                            else
                            {
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
                        ofstream data4("xii_to_ki.txt", ios::app);
                        data4 << namainput << ' ' << nisinput << ' ' << ttlinput << ' ' << jkinput << ' ' << alamatinput << endl;
                        setcolor(267);
                        cout << "\nRegistration Sucessful\n";
                        setcolor(15);
                        cout << "\n";
                        system("pause");
                        system("cls");
                        goto menud;

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiito;
                    }

                    // Output apabila input tidak sesuai
                }
                else
                {
                    goto jur1xii;
                }

                // Output apabila input tidak sesuai
            }
            else
            {
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
        }
        else if (pill == "2")
        {

            // output Kelas
        kl2:
            cout << "Kelas [ X, XI, XII ] : ";
            cin >> kl2;

            // Pilih x
            if (kl2 == "X" || kl2 == "x" || kl2 == "Sepuluh" || kl2 == "sepuluh" || kl2 == "SEPULUH")
            {

                // output Jurusan
            jur2x:
                cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
                cin >> jur2x;

                // Pilih RPL
                if (jur2x == "RPL" || jur2x == "rpl" || jur2x == "Rpl")
                {

                    // keterangan
                ktxrpl2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxrpl2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxrpl2 == "1")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X RPL 1  /////
                    /////////////////////////////////////

                    // Judul
                    ynd73:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X RPL 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_rpl_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_rpl_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd73;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxrpl2 == "2")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X RPL 2  /////
                    /////////////////////////////////////

                    // Judul
                    ynd74:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X RPL 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_rpl_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_rpl_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd74;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxrpl2 == "3")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X RPL 3  /////
                    /////////////////////////////////////

                    // Judul
                    ynd75:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X RPL 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_rpl_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_rpl_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd75;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxrpl2 == "K.I" || ktxrpl2 == "k.i" || ktxrpl2 == "KI" || ktxrpl2 == "ki")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data X RPL K.I  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd76:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X RPL K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_rpl_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_rpl_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd76;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxrpl2;
                    }

                    // Pilih TKJ
                }
                else if (jur2x == "TKJ" || jur2x == "tkj" || jur2x == "Tkj")
                {

                    // keterangan
                ktxtkj2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxtkj2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxtkj2 == "1")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X TKJ 1  /////
                    /////////////////////////////////////

                    // Judul
                    ynd77:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TKJ 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tkj_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tkj_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd77;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxtkj2 == "2")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X TKJ 2  /////
                    /////////////////////////////////////

                    // Judul
                    ynd78:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TKJ 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tkj_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tkj_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd78;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxtkj2 == "3")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X TKJ 3  /////
                    /////////////////////////////////////

                    // Judul
                    ynd79:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TKJ 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tkj_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tkj_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd79;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxtkj2 == "K.I" || ktxtkj2 == "k.i" || ktxtkj2 == "KI" || ktxtkj2 == "ki")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data X TKJ K.I  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd80:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TKJ K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tkj_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tkj_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd80;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxtkj2;
                    }

                    // Pilih TEI
                }
                else if (jur2x == "TEI" || jur2x == "tei" || jur2x == "Tei")
                {

                    // keterangan
                ktxtei2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxtei2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxtei2 == "1")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X TEI 1  /////
                    /////////////////////////////////////

                    // Judul
                    ynd81:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TEI 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tei_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tei_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd81;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxtei2 == "2")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X TEI 2  /////
                    /////////////////////////////////////

                    // Judul
                    ynd82:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TEI 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tei_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tei_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd82;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxtei2 == "3")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X TEI 3  /////
                    /////////////////////////////////////

                    // Judul
                    ynd83:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TEI 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tei_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tei_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd83;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxtei2 == "K.I" || ktxtei2 == "k.i" || ktxtei2 == "KI" || ktxtei2 == "ki")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data X TEI K.I  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd84:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TEI K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tei_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tei_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd84;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxtei2;
                    }

                    // Pilih TET
                }
                else if (jur2x == "TET" || jur2x == "tet" || jur2x == "Tet")
                {

                    // keterangan
                ktxtet2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxtet2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxtet2 == "1")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X TET 1  /////
                    /////////////////////////////////////

                    // Judul
                    ynd85:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TET 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tet_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tet_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd85;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxtet2 == "2")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X TET 2  /////
                    /////////////////////////////////////

                    // Judul
                    ynd86:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TET 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tet_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tet_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd86;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxtet2 == "3")
                    {

                    /////////////////////////////////////
                    ///// MENAMPILKAN Data X TET 3  /////
                    /////////////////////////////////////

                    // Judul
                    ynd87:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TET 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tet_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tet_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd87;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxtet2 == "K.I" || ktxtet2 == "k.i" || ktxtet2 == "KI" || ktxtet2 == "ki")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data X TET K.I  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd88:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TET K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_tet_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_tet_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd88;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxtet2;
                    }

                    // Pilih AK
                }
                else if (jur2x == "AK" || jur2x == "Ak" || jur2x == "ak")
                {

                    // keterangan
                ktxak2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxak2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxak2 == "1")
                    {

                    ////////////////////////////////////
                    ///// MENAMPILKAN Data X AK 1  /////
                    ////////////////////////////////////

                    // Judul
                    ynd89:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X AK 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_ak_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_ak_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd89;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxak2 == "2")
                    {

                    ////////////////////////////////////
                    ///// MENAMPILKAN Data X AK 2  /////
                    ////////////////////////////////////

                    // Judul
                    ynd90:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X AK 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_ak_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_ak_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd90;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxak2 == "3")
                    {

                    ////////////////////////////////////
                    ///// MENAMPILKAN Data X AK 3  /////
                    ////////////////////////////////////

                    // Judul
                    ynd91:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X AK 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_ak_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_ak_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd91;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxak2 == "K.I" || ktxak2 == "k.i" || ktxak2 == "KI" || ktxak2 == "ki")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data X AK K.I  /////
                    //////////////////////////////////////

                    // Judul
                    ynd92:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X AK K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_ak_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_ak_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd92;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxak2;
                    }

                    // Pilih TO
                }
                else if (jur2x == "TO" || jur2x == "to" || jur2x == "To")
                {

                    // keterangan
                ktxto2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxto2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxto2 == "1")
                    {

                    ////////////////////////////////////
                    ///// MENAMPILKAN Data X TO 1  /////
                    ////////////////////////////////////

                    // Judul
                    ynd93:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TO 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_to_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_to_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd93;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxto2 == "2")
                    {

                    ////////////////////////////////////
                    ///// MENAMPILKAN Data X TO 2  /////
                    ////////////////////////////////////

                    // Judul
                    ynd94:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TO 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_to_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_to_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd94;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxto2 == "3")
                    {

                    ////////////////////////////////////
                    ///// MENAMPILKAN Data X TO 3  /////
                    ////////////////////////////////////

                    // Judul
                    ynd95:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TO 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_to_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_to_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd95;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxto2 == "K.I" || ktxto2 == "k.i" || ktxto2 == "KI" || ktxto2 == "ki")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data X TO K.I  /////
                    //////////////////////////////////////

                    // Judul
                    ynd96:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database X TO K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("x_to_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("x_to_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd96;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxto2;
                    }

                    //  Output apabila input tidak sesuai
                }
                else
                {
                    goto jur2x;
                }

                // Pilih XI
            }
            else if (kl2 == "XI" || kl2 == "xi" || kl2 == "Xi" || kl2 == "Sebelas" || kl2 == "SEBELAS" || kl2 == "sebelas")
            {

                // output Jurusan
            jur2xi:
                cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
                cin >> jur2xi;

                // Pilih RPL
                if (jur2xi == "RPL" || jur2xi == "rpl" || jur2xi == "Rpl")
                {

                    // keterangan
                ktxirpl2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxirpl2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxirpl2 == "1")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI RPL 1  /////
                    //////////////////////////////////////

                    // Judul
                    ynd97:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI RPL 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_rpl_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_rpl_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd97;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxirpl2 == "2")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI RPL 2  /////
                    //////////////////////////////////////

                    // Judul
                    ynd98:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI RPL 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_rpl_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_rpl_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd98;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxirpl2 == "3")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI RPL 3  /////
                    //////////////////////////////////////

                    // Judul
                    ynd99:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI RPL 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_rpl_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_rpl_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd99;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxirpl2 == "K.I" || ktxirpl2 == "k.i" || ktxirpl2 == "KI" || ktxirpl2 == "ki")
                    {

                    ////////////////////////////////////////
                    ///// MENAMPILKAN Data XI RPL K.I  /////
                    ////////////////////////////////////////

                    // Judul
                    ynd100:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI RPL K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_rpl_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_rpl_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd100;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxirpl2;
                    }

                    // Pilih TKJ
                }
                else if (jur2xi == "TKJ" || jur2xi == "tkj" || jur2xi == "Tkj")
                {

                    // keterangan
                ktxitkj2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxitkj2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxitkj2 == "1")
                    {
                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TKJ 1  /////
                    //////////////////////////////////////

                    // Judul
                    ynd101:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TKJ 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tkj_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tkj_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd101;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxitkj2 == "2")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TKJ 2  /////
                    //////////////////////////////////////

                    // Judul
                    ynd102:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TKJ 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tkj_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tkj_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd102;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxitkj2 == "3")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TKJ 3  /////
                    //////////////////////////////////////

                    // Judul
                    ynd103:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TKJ 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tkj_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tkj_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd103;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxitkj2 == "K.I" || ktxitkj2 == "k.i" || ktxitkj2 == "KI" || ktxitkj2 == "ki")
                    {

                    ////////////////////////////////////////
                    ///// MENAMPILKAN Data XI TKJ K.I  /////
                    ////////////////////////////////////////

                    // Judul
                    ynd104:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TKJ K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tkj_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tkj_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd104;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxitkj2;
                    }

                    // Pilih TEI
                }
                else if (jur2xi == "TEI" || jur2xi == "tei" || jur2xi == "Tei")
                {

                    // keterangan
                ktxitei2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxitei2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxitei2 == "1")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TEI 1  /////
                    //////////////////////////////////////

                    // Judul
                    ynd105:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TEI 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tei_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tei_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd105;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxitei2 == "2")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TEI 2  /////
                    //////////////////////////////////////

                    // Judul
                    ynd106:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TEI 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tei_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tei_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd106;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxitei2 == "3")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TEI 3  /////
                    //////////////////////////////////////

                    // Judul
                    ynd107:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TEI 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tei_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tei_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd107;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxitei2 == "K.I" || ktxitei2 == "k.i" || ktxitei2 == "KI" || ktxitei2 == "ki")
                    {

                    ////////////////////////////////////////
                    ///// MENAMPILKAN Data XI TEI K.I  /////
                    ////////////////////////////////////////

                    // Judul
                    ynd108:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TEI K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tei_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tei_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd108;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxitei2;
                    }

                    // Pilih TET
                }
                else if (jur2xi == "TET" || jur2xi == "tet" || jur2xi == "Tet")
                {

                    // keterangan
                ktxitet2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxitet2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxitet2 == "1")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TET 1  /////
                    //////////////////////////////////////

                    // Judul
                    ynd109:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TET 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tet_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tet_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd109;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxitet2 == "2")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TET 2  /////
                    //////////////////////////////////////

                    // Judul
                    ynd110:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TET 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tet_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tet_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd110;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxitet2 == "3")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TET 3  /////
                    //////////////////////////////////////

                    // Judul
                    ynd111:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TET 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tet_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tet_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd111;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxitet2 == "K.I" || ktxitet2 == "k.i" || ktxitet2 == "KI" || ktxitet2 == "ki")
                    {

                    ////////////////////////////////////////
                    ///// MENAMPILKAN Data XI TET K.I  /////
                    ////////////////////////////////////////

                    // Judul
                    ynd112:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TET K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_tet_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_tet_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd112;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxitet2;
                    }

                    // Pilih AK
                }
                else if (jur2xi == "AK" || jur2xi == "Ak" || jur2xi == "ak")
                {

                    // keterangan
                ktxiak2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiak2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiak2 == "1")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI AK 1  //////
                    //////////////////////////////////////

                    // Judul
                    ynd113:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI AK 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_ak_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_ak_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd113;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiak2 == "2")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI AK 2  //////
                    //////////////////////////////////////

                    // Judul
                    ynd114:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI AK 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_ak_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_ak_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd114;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiak2 == "3")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI AK 3  //////
                    //////////////////////////////////////

                    // Judul
                    ynd115:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI AK 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_ak_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_ak_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd115;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiak2 == "K.I" || ktxiak2 == "k.i" || ktxiak2 == "KI" || ktxiak2 == "ki")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XI AK K.I  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd116:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI AK K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_ak_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_ak_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd116;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiak2;
                    }

                    // Pilih TO
                }
                else if (jur2xi == "TO" || jur2xi == "to" || jur2xi == "To")
                {

                    // keterangan
                ktxito2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxito2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxito2 == "1")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TO 1  //////
                    //////////////////////////////////////

                    // Judul
                    ynd117:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TO 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_to_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_to_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd117;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxito2 == "2")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TO 2  //////
                    //////////////////////////////////////

                    // Judul
                    ynd118:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TO 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_to_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_to_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd118;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxito2 == "3")
                    {

                    //////////////////////////////////////
                    ///// MENAMPILKAN Data XI TO 3  //////
                    //////////////////////////////////////

                    // Judul
                    ynd119:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TO 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_to_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_to_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd119;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxito2 == "K.I" || ktxito2 == "k.i" || ktxito2 == "KI" || ktxito2 == "ki")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XI TO K.I  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd120:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XI TO K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xi_to_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xi_to_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd120;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxito2;
                    }

                    //  Output apabila input tidak sesuai
                }
                else
                {
                    goto jur2xi;
                }

                // Pilih XII
            }
            else if (kl2 == "XII" || kl2 == "xii" || kl2 == "Xii" || kl2 == "Dua Belas" || kl2 == "dua belas" || kl2 == "DUA BELAS" || kl2 == "Dua belas")
            {

                // output Jurusan
            jur2xii:
                cout << "Jurusan [ RPL, TKJ, TEI, TET, AK, TO ] : ";
                cin >> jur2xii;

                // Pilih RPL
                if (jur2xii == "RPL" || jur2xii == "rpl" || jur2xii == "Rpl")
                {

                    // keterangan
                ktxiirpl2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiirpl2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiirpl2 == "1")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII RPL 1  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd121:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII RPL 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_rpl_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_rpl_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd121;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiirpl2 == "2")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII RPL 2  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd122:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII RPL 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_rpl_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_rpl_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd122;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiirpl2 == "3")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII RPL 3  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd123:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII RPL 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_rpl_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_rpl_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd123;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiirpl2 == "K.I" || ktxiirpl2 == "k.i" || ktxiirpl2 == "KI" || ktxiirpl2 == "ki")
                    {

                    /////////////////////////////////////////
                    ///// MENAMPILKAN Data XII RPL K.I  /////
                    /////////////////////////////////////////

                    // Judul
                    ynd124:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII RPL K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_rpl_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_rpl_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd124;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiirpl2;
                    }

                    // Pilih TKJ
                }
                else if (jur2xii == "TKJ" || jur2xii == "tkj" || jur2xii == "Tkj")
                {

                    // keterangan
                ktxiitkj2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiitkj2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiitkj2 == "1")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TKJ 1  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd125:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TKJ 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tkj_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tkj_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd125;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiitkj2 == "2")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TKJ 2  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd126:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TKJ 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tkj_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tkj_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd126;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiitkj2 == "3")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TKJ 3  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd127:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TKJ 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tkj_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tkj_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd127;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiitkj2 == "K.I" || ktxiitkj2 == "k.i" || ktxiitkj2 == "KI" || ktxiitkj2 == "ki")
                    {

                    /////////////////////////////////////////
                    ///// MENAMPILKAN Data XII TKJ K.I  /////
                    /////////////////////////////////////////

                    // Judul
                    ynd128:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TKJ K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tkj_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tkj_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd128;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiitkj2;
                    }

                    // Pilih TEI
                }
                else if (jur2xii == "TEI" || jur2xii == "tei" || jur2xii == "Tei")
                {

                    // keterangan
                ktxiitei2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiitei2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiitei2 == "1")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TEI 1  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd129:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TEI 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tei_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tei_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd129;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiitei2 == "2")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TEI 2  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd130:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TEI 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tei_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tei_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd130;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiitei2 == "3")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TEI 3  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd131:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TEI 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tei_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tei_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd131;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiitei2 == "K.I" || ktxiitei2 == "k.i" || ktxiitei2 == "KI" || ktxiitei2 == "ki")
                    {

                    /////////////////////////////////////////
                    ///// MENAMPILKAN Data XII TEI K.I  /////
                    /////////////////////////////////////////

                    // Judul
                    ynd132:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TEI K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tei_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tei_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd132;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiitei2;
                    }

                    // Pilih TET
                }
                else if (jur2xii == "TET" || jur2xii == "tet" || jur2xii == "Tet")
                {

                    // keterangan
                ktxiitet2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiitet2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiitet2 == "1")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TET 1  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd133:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TET 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tet_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tet_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd133;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiitet2 == "2")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TET 2  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd134:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TET 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tet_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tet_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd134;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiitet2 == "3")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TET 3  /////
                    ///////////////////////////////////////

                    // Judul
                    ynd135:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TET 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tet_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tet_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd135;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiitet2 == "K.I" || ktxiitet2 == "k.i" || ktxiitet2 == "KI" || ktxiitet2 == "ki")
                    {

                    /////////////////////////////////////////
                    ///// MENAMPILKAN Data XII TET K.I  /////
                    /////////////////////////////////////////

                    // Judul
                    ynd136:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TET K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_tet_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_tet_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd136;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiitet2;
                    }

                    // Pilih AK
                }
                else if (jur2xii == "AK" || jur2xii == "Ak" || jur2xii == "ak")
                {

                    // keterangan
                ktxiiak2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiiak2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiiak2 == "1")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII AK 1  //////
                    ///////////////////////////////////////

                    // Judul
                    ynd137:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII AK 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_ak_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_ak_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd137;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiiak2 == "2")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII AK 2  //////
                    ///////////////////////////////////////

                    // Judul
                    ynd138:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII AK 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_ak_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_ak_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd138;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiiak2 == "3")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII AK 3  //////
                    ///////////////////////////////////////

                    // Judul
                    ynd:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII AK 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_ak_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_ak_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiiak2 == "K.I" || ktxiiak2 == "k.i" || ktxiiak2 == "KI" || ktxiiak2 == "ki")
                    {

                    /////////////////////////////////////////
                    ///// MENAMPILKAN Data XII AK K.I  //////
                    /////////////////////////////////////////

                    // Judul
                    ynd139:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII AK K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_ak_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_ak_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd139;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiiak2;
                    }

                    // Pilih TO
                }
                else if (jur2xii == "TO" || jur2xii == "to" || jur2xii == "To")
                {

                    // keterangan
                ktxiito2:
                    cout << "Keterangan [ 1 | 2 | 3 | K.I ] : ";
                    cin >> ktxiito2;

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    // pilih 1
                    if (ktxiito2 == "1")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TO 1  //////
                    ///////////////////////////////////////

                    // Judul
                    ynd140:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TO 1 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_to_1.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_to_1.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd140;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 2
                    }
                    else if (ktxiito2 == "2")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TO 2  //////
                    ///////////////////////////////////////

                    // Judul
                    ynd141:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TO 2 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_to_2.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_to_2.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd141;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih 3
                    }
                    else if (ktxiito2 == "3")
                    {

                    ///////////////////////////////////////
                    ///// MENAMPILKAN Data XII TO 3  //////
                    ///////////////////////////////////////

                    // Judul
                    ynd142:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TO 3 --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_to_3.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_to_3.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd142;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // Pilih k.i
                    }
                    else if (ktxiito2 == "K.I" || ktxiito2 == "k.i" || ktxiito2 == "KI" || ktxiito2 == "ki")
                    {

                    /////////////////////////////////////////
                    ///// MENAMPILKAN Data XII TO K.I  //////
                    /////////////////////////////////////////

                    // Judul
                    ynd143:
                        system("cls");
                        cout << "\n";
                        setcolor(2);
                        cout << "-- Database XII TO K.I --\t\n\n";
                        setcolor(15);

                        // tipe data dan memanggil file database
                        string line;
                        ifstream in("xii_to_ki.txt");

                        // Judul output
                        if (in.is_open())
                        {
                            cout << "===================================================================================================================" << endl;
                            cout << "|\tNama\t|\tNIS\t|\tTTL\t\t|\tJenis Kelamin\t|\tAlamat\t|" << endl;
                            cout << "===================================================================================================================" << endl;

                            // Menampilkan data yang ada di database
                            int count = 0;
                            while (getline(in, line))
                            {
                                stringstream ss(line);
                                string nama, nis, ttl, jk, alamat;
                                ss >> nama >> nis >> ttl >> jk >> alamat;
                                if (count > 0)
                                {
                                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                                }
                                cout << "| " << setw(15) << nama << " | " << setw(10) << nis << " | " << setw(20) << ttl << " | " << setw(15) << jk << " | " << setw(20) << alamat << " |" << endl;
                                count++;
                            }
                            cout << "===================================================================================================================" << endl;
                            in.close();

                            // Mencari data dengan memasukkan NIS
                            string nis_input;
                            while (true)
                            {
                                cout << "\nMasukkan NIS untuk mencari data: ";
                                cin >> nis_input;

                                ifstream in2("xii_to_ki.txt");
                                if (in2.is_open())
                                {
                                    bool found = false;
                                    while (getline(in2, line))
                                    {
                                        stringstream ss(line);
                                        string nama, nis, ttl, jk, alamat;
                                        ss >> nama >> nis >> ttl >> jk >> alamat;
                                        if (nis == nis_input)
                                        {
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
                                    if (found)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setcolor(12);
                                        cout << "NIS tidak ditemukan. Silakan coba lagi." << endl;
                                        setcolor(15);
                                    }
                                }
                                else
                                {
                                    cout << "File tidak ditemukan" << endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "File tidak ditemukan" << endl;
                        }

                        // kembali ke menu ?
                        cout << "\n";
                        setcolor(14);
                        cout << "Apakah anda ingin kembali ke menu [Y/N] : ";
                        setcolor(15);
                        cin >> ynd;

                        if (ynd == "y" || ynd == "Y")
                        {
                            system("cls");
                            goto menud;
                        }
                        else
                        {
                            goto ynd143;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        // output apabila input tidak sesuai
                    }
                    else
                    {
                        goto ktxiito2;
                    }

                    // Output apabila input tidak sesuai
                }
                else
                {
                    goto jur2xii;
                }

                // Output apabila input tidak sesuai
            }
            else
            {
                goto kl2;
            }

            // output apabila input tidak sesuai
        }
        else if (pill == "3")
        {
            system("cls");
            menu();
        }
        else
        {
            system("cls");
            goto menud;
        }
    }

    /////////////////////////////////
    //// Menu 3 sistem kehadiran ////
    /////////////////////////////////
    else if (pil == "3")
    {
    menu3:
        string cls, yn1, outputhilang;
        string nama[MAX_N];             // array untuk menyimpan nama
        string hadir[MAX_HT];           // array untuk menyimpan jumlah hadir
        string keterangan[MAX_K];       // array untuk menyimpan keterangan hadir
        long long int jumlah_mahasiswa; // variabel untuk menyimpan jumlah mahasiswa
        int jumlah_tidak_hadir = 0;     // variabel untuk menghitung jumlah siswa yang tidak hadir
        int jumlah_hadir = 0;           // variabel untuk menghitung jumlah siswa yang hadir

        // Judul Program
        setcolor(15);
        cout << "\n";
        cout << " Sistem Kehadiran Siswa SMK Negeri 2 Kota Bekasi\n";
        cout << "          Program Kelas X RPL Industri           \n";
        setcolor(2);
        cout << "--------------------------------------------------\n";
        setcolor(15);
        cout << "\n";

        // input jumlah siswa
        bool validInput = false;
        while (!validInput)
        {
            setcolor(15);
            cout << "Masukkan Jumlah Siswa : ";
            string masuk;
            cin >> masuk;

            // pengecekan apakah input hanya terdiri dari angka
            bool isNumber = true;
            for (char c : masuk)
            {
                if (!isdigit(c))
                {
                    isNumber = false;
                    break;
                }
            }

            // melakukan pengecekan ulang
            if (isNumber)
            {
                // konversi input ke integer
                jumlah_mahasiswa = stoi(masuk);
                validInput = true;
            }
            else
            { // output yang dihasilkan apabila input nya tidak sesuai dan melakukan input lagi
                system("cls");
                setcolor(15);
                cout << "\n";
                cout << " Sistem Kehadiran Siswa SMK Negeri 2 Kota Bekasi\n";
                cout << "          Program Kelas X RPL Industri           \n";
                setcolor(2);
                cout << "--------------------------------------------------\n";
                setcolor(15);
                cout << "\n";
            }
        }

        cout << "";                 // ini gak masukkan apa apa cuman ngecohin getline nya
        getline(cin, outputhilang); //
        cout << "Kelas : ";         // ini baru masukkan nama kelas nya
        getline(cin, cls);          //
        setcolor(2);
        cout << "\n--------------------------------------------------\n\n";
        setcolor(15);

        // input nama dan jumlah hadir setiap mahasiswa
        for (int i = 0; i < jumlah_mahasiswa; i++)
        {
            cout << i + 1 << "."
                 << " Masukkan nama siswa : ";
            getline(cin, nama[i]);
        ht:
            cout << "   Hadir / Tidak (H/T) : ";
            getline(cin, hadir[i]);

            if (hadir[i] == "T" || hadir[i] == "t" || hadir[i] == "Tidak" || hadir[i] == "tidak" || hadir[i] == "TIDAK")
            {
                jumlah_tidak_hadir++;
                cout << "   Keterangan (S/I/A) : ";
                getline(cin, keterangan[i]);
            }
            else if (hadir[i] == "H" || hadir[i] == "h" || hadir[i] == "Hadir" || hadir[i] == "hadir" || hadir[i] == "HADIR")
            {
                jumlah_hadir++;
            }
            else
            { // else ini digunakan untuk (saat input y dia akan masuk ke sini kalau tidak dia akan masuk ke atas itu)
                goto ht;
            }
            cout << endl;
        }

        // data di simpan
        setcolor(11);
        cout << "``Data Disimpan``\n\n\n";
        setcolor(15);
        system("pause");
        system("cls");

        // judul output
        cout << "\n";
        cout << " Sistem Kehadiran Siswa SMK Negeri 2 Kota Bekasi\n";
        cout << "          Proram Kelas X RPL Industri           \n";
        setcolor(2);
        cout << "--------------------------------------------------\n";
        setcolor(15);
        cout << "\n\n\n";

        // judul output 2
        cout << "  No                Nama Siswa                  Hadir/Tidak         Keterangan (S/A/I)\n";
        setcolor(11);
        cout << "-----------------------------------------------------------------------------------------------------------\n";
        setcolor(15);

        // output
        for (int i = 0; i < jumlah_mahasiswa; i++)
        {
            cout << setw(3) << i + 1 << ". " << setw(30) << nama[i] << setw(20) << hadir[i] << setw(25) << keterangan[i] << endl;
        }

        // output kelas, jumlah siswa dan hadir / tidaknya siswa
        cout << "\n\n";
        cout << "Kelas : " << cls << endl;                                        // output kelas yang tadi diinput
        cout << "Jumlah Siswa : " << jumlah_mahasiswa << endl;                    // output jumlah siswa yang tadi diinput
        cout << "Jumlah siswa yang hadir : " << jumlah_hadir << endl;             // output jumlah siswa yang di input hadir
        cout << "Jumlah siswa yang tidak hadir : " << jumlah_tidak_hadir << endl; // output jumlah siswa yang di input tidak hadir
        setcolor(10);
        cout << "-----------------------------\n\n";
        setcolor(15);

        // perulangan menu3
        cout << "\n\n";
        setcolor(14);
        cout << "Apakah Anda Ingin Kembali Ke Menu ? (y/n) : ";
        cin >> yn1;
        setcolor(15);
        if (yn1 == "y" || yn1 == "Y")
        {
            system("cls");
            menu(); // kembali ke menu
        }
        else
        {
            system("cls");
            goto menu3; // kembali ke menu 3
        }
    }

    ////////////////////////////////
    /////   menu 4 calculator  /////
    ////////////////////////////////
    else if (pil == "4")
    {

        // tipe data jumlah bilangan
        string yn1;
    menu4:
        long long int jumlahBilangan; // untuk menghitung jumlah bilangan lebih dari ratusan juta

        // judul program
        setcolor(14);
        cout << "-------- Calculator --------\n\n\n";
        setcolor(15);

        // Input jumlah bilangan
        bool validInput = false;
        while (!validInput)
        {
            setcolor(15);
            cout << "Masukkan jumlah bilangan yang ingin diinputkan : ";
            string input;
            cin >> input;

            // pengecekan apakah input hanya terdiri dari angka
            bool isNumber = true;
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    isNumber = false;
                    break;
                }
            }

            // melakukan pengecekan ulang
            if (isNumber)
            {
                // konversi input ke integer
                jumlahBilangan = stoi(input);
                validInput = true;
            }
            else
            { // output yang dihasilkan apabila input nya tidak sesuai dan melakukan input lagi
                system("cls");
                setcolor(14);
                cout << "-------- Calculator --------\n\n\n";
                setcolor(15);
            }
        }

        // tipe data dari input bilangan
        cout << endl;
        long double bilangan[jumlahBilangan]; // untuk menghitung jumlah bilangan lebih dari ratusan juta
        string input;

        // input data
        for (int i = 0; i < jumlahBilangan; i++)
        {
            cout << "Masukkan bilangan ke-" << i + 1 << ": ";
            cin >> input;

            // Pengecekan data
            try
            {
                bilangan[i] = stod(input);
            }
            catch (exception &e)
            { // output apabila input tidak sesuai
                setcolor(12);
                cout << "Input tidak valid !!" << endl;
                setcolor(15);
                i--;
            }
        }
        cout << endl;
    menu4salah: // kembali ke sini apabila input operator nya salah

        // menentukan apakah (+,-,*, atau /)
        long double hasil = bilangan[0];
        string operasi;
        cout << "Masukkan operasi yang ingin dilakukan (";
        setcolor(2);
        cout << " +, -, *, atau / ";
        setcolor(15);
        cout << "): ";
        cin >> operasi;

        // dihitung
        for (int i = 1; i < jumlahBilangan; i++)
        {
            if (operasi == "+")
            {
                hasil += bilangan[i];
            }
            else if (operasi == "-")
            {
                hasil -= bilangan[i];
            }
            else if (operasi == "*")
            {
                hasil *= bilangan[i];
            }
            else if (operasi == "/")
            {
                hasil /= bilangan[i];
            }
            else
            {
                goto menu4salah; // kembali ke memilih apabila input yang dimasukkan salah
            }
        }

        // output
        cout << "\n\n";
        setcolor(10);
        cout << "Hasil dari operasi tersebut adalah: " << hasil << endl;
        setcolor(15);

        // pengulang penjumlah menu 4
        cout << "\n\n";
        setcolor(14);
        cout << "Apakah Anda Ingin Kembali Ke Menu (y/n) : ";
        cin >> yn1;
        setcolor(15);
        if (yn1 == "y" || yn1 == "Y")
        {
            system("cls");
            menu(); // kembali ke menu
        }
        else
        {
            system("cls");
            goto menu4; // kembali ke menu 4
        }
    }

    //////////////////////////////////////////////
    //// menu 5 sistem pembelian di alfamart ////
    ////////////////////////////////////////////
    else if (pil == "5")
    {
        string yn1;
    menu5:
        // Inisialisasi atau deklarasi variabel
        long int tot, jum_beli, jumlah[50], harga[50], sub_tot[50], diskon, bayar;
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
        setcolor(10);
        cout << "=========================================================\n";
        setcolor(15);
        cout << endl;

        // Input jumlah barang
        bool validInput = false;
        while (!validInput)
        {
            setcolor(15);
            cout << "Masukkan jumlah Beli Barang : ";
            string input1;
            cin >> input1;

            // pengecekan apakah input hanya terdiri dari angka
            bool isNumber = true;
            for (char c : input1)
            {
                if (!isdigit(c))
                {
                    isNumber = false;
                    break;
                }
            }

            // melakukan pengecekan ulang
            if (isNumber)
            {
                // konversi input ke integer
                jum_beli = stoi(input1);
                validInput = true;
            }
            else
            { // output yang dihasilkan apabila input nya tidak sesuai dan melakukan input lagi
                system("cls");
                cout << "          ALFAMART RAWA LUMBU / 085714713706\n";
                cout << "             PT.SUMBER ALFARIA TRIJAYA,TBK\n";
                cout << endl;
                cout << "        ALFA TOWER LT.12, ALAM SUTERA, TANGGERANG\n";
                cout << "             HPWP : 01.226.238.0-054.000\n";
                cout << "        JL.RAYA JEMBATAN NO.9 RT.06/R RAWALUMBU\n";
                cout << endl;
                setcolor(10);
                cout << "=========================================================\n";
                setcolor(15);
                cout << endl;
            }
        }

        // memasukkan nama, harga, jumlah barang
        for (int i = 0; i < jum_beli; i++)
        {
            cout << endl;
            cout << "Masukan Barang Ke-" << i + 1 << endl;

            cout << ""; // buat mengecoh getlinenya ini gak di input apa apa alias kosong
            getline(cin, hilang);

            cout << "Nama Barang : ";
            getline(cin, nama_barang[i]); // Pengguna input nama barang disimpan pada array nama_barang

            // Input jumlah barang
            bool validInput = false;
            while (!validInput)
            {
                setcolor(15);
                cout << "Jumlah      : ";
                string input2;
                cin >> input2;

                // pengecekan apakah input hanya terdiri dari angka
                bool isNumber = true;
                for (char c : input2)
                {
                    if (!isdigit(c))
                    {
                        isNumber = false;
                        break;
                    }
                }

                // melakukan pengecekan ulang
                if (isNumber)
                {
                    // konversi input ke integer
                    jumlah[i] = stoi(input2);
                    validInput = true;
                }
                else
                { // output yang dihasilkan apabila input nya tidak sesuai dan melakukan input lagi
                    setcolor(12);
                    cout << "Input tidak valid !!\n"
                         << endl;
                    setcolor(15);
                }
            }

            cout << "Harga       : ";
            cin >> harga[i]; // Pengguna input harga disimpan pada array harga

            sub_tot[i] = jumlah[i] * harga[i]; // Menjumlahkan Harga sub total barang
            tot += sub_tot[i];                 // Menjumlahkan seluruh sub total barang
        }

        // ouput struk belanja
        cout << "\n";
        setcolor(2);
        cout << "----------------------------------------------------------------------------------" << endl;
        setcolor(15);
        cout << "No   Nama Barang              Jumlah               Harga                   Sub Total"
             << "\n";
        cout << "------------------------------------------------------------------------------------\n\n";
        for (int i = 0; i < jum_beli; i++)
        {
            cout << i + 1 << ". " << setw(10) << nama_barang[i] << setw(20) << jumlah[i] << setw(25) << fixed << setprecision(2) << harga[i] << setw(25) << fixed << setprecision(2) << sub_tot[i] << endl;
            // Menampilkan semua nilai array dengan format rapi dan menggunakan setprecision() agar nilai desimal ditampilkan dengan 2 angka di belakang koma
        }
        setcolor(2);
        cout << "----------------------------------------------------------------------------------\n"
             << endl;
        setcolor(15);

        // Kondisi untuk menentukan diskon yang didapatkan berdasarkan total belanja
        if (tot == 100000)
        {
            diskon = 0.06 * tot;
        }
        else if (tot >= 50000)
        {
            diskon = 0.04 * tot;
        }
        else if (tot >= 25000)
        {
            diskon = 0.02 * tot;
        }
        else
        {
            diskon = 0;
        }

        // Menampilkan Keterangan
        cout << "Jumlah Bayar : Rp." << tot << endl;          // Menampilkan jumlah bayar (belum termasuk diskon)
        cout << "Dikon        : Rp." << diskon << endl;       // Menampilkan diskon
        cout << "Total Bayar  : Rp." << tot - diskon << endl; // Menampilkan total harga yang harus dibayar
        cout << "Bayar        : Rp.";
        cin >> bayar;                                                     // Input dari user untuk jumlah yang dibayar
        cout << "Kembali      : Rp." << (bayar - (tot - diskon)) << endl; // Menampilkan uang kembali

        // penutup
        cout << endl;
        setcolor(10);
        cout << "=========================================================\n\n";
        setcolor(15);
        cout << "Terimakasih telah berbelanja di toko kami :) semoga kamu senang belanja di toko kami\n";

        // pengulang menu 5 sistem belanja
        cout << "\n\n";
        setcolor(14);
        cout << "Apakah Anda Ingin Kembali Ke Menu (y/n) : ";
        cin >> yn1;
        setcolor(15);
        if (yn1 == "y" || yn1 == "Y")
        {
            system("cls");
            menu(); // kembali ke menu
        }
        else
        {
            system("cls");
            goto menu5; // kembali ke menu 5
        }
    }

    ////////////////////////////////
    /////  menu 6 calender     /////
    ////////////////////////////////
    else if (pil == "6")
    {

    // tipe data menu 6
    menu6:
        int thn, bln, jmlDay, jumlah_Day, Day;

        // judul program menu 6
        setcolor(14);
        cout << "-------- Calender --------\n";
        setcolor(15);

        // Note
        setcolor(14);
        cout << "\n\n-- Note --\n";
        setcolor(15);
        cout << "Input : Berupa angka tidak menggunakan huruf \n\n\n";

        // input tahun dan bulan
        printf("Masukkan Tahun : ");
        scanf("%d", &thn);
        fflush(stdin);
        do
        {
            printf("Masukkan Bulan : ");
            scanf("%d", &bln);
            fflush(stdin);
        }

        // output calender
        while (bln < 1 || bln > 12);
        cout << endl;
        if (bln == 1)
        {
            printf("Calender : January %d", thn);
        }
        else if (bln == 2)
        {
            printf("Calender : February %d", thn);
        }
        else if (bln == 3)
        {
            printf("Calender : March %d", thn);
        }
        else if (bln == 4)
        {
            printf("Calender : April %d", thn);
        }
        else if (bln == 5)
        {
            printf("Calender : May %d", thn);
        }
        else if (bln == 6)
        {
            printf("Calender : June %d", thn);
        }
        else if (bln == 7)
        {
            printf("Calender : July %d", thn);
        }
        else if (bln == 8)
        {
            printf("Calender : August %d", thn);
        }
        else if (bln == 9)
        {
            printf("Calender : September %d", thn);
        }
        else if (bln == 10)
        {
            printf("Calender : October %d", thn);
        }
        else if (bln == 11)
        {
            printf("Calender : November %d", thn);
        }
        else if (bln == 12)
        {
            printf("Calender : Desember %d", thn);
        }

        // operasi perhitungan
        jmlDay = hitung_Year(thn) + hitung_Month(thn, bln);
        Day = cek_Day(jmlDay);
        jumlah_Day = hitung_Day(bln, thn);

        // judul output
        setcolor(10);
        printf("\n=====================================================\n");
        setcolor(11);
        printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
        setcolor(10);
        printf("=====================================================\n");
        setcolor(15);

        // output
        for (int i = 0; i < Day; i++)
        {
            printf("\t");
        }
        for (int i = 1; i <= jumlah_Day; i++)
        {
            printf("%d\t", i);
            if (Day % 7 == 6)
                printf("\n");
            Day++;
        }
        getch();

        // pengulang menu 6 calender
        cout << "\n\n";
        setcolor(14);
        cout << "Apakah Anda Ingin Kembali Ke Menu (y/n) : ";
        cin >> yn1;
        setcolor(15);
        if (yn1 == "y" || yn1 == "Y")
        {
            system("cls");
            menu(); // kembali ke menu
        }
        else
        {
            system("cls");
            goto menu6; // kembali ke menu 6
        }
    }

    /////////////////////////////////////
    /////  Menu 7 Game flappy bird   ////
    /////////////////////////////////////
    else if (pil == "7")
    {
    menu7:
        string op;
        setcursor(0, 0);
        srand((unsigned)time(NULL));

        //	judul program
        system("cls");
        gotoxy(10, 5);
        cout << " -------------------------- ";
        gotoxy(10, 6);
        cout << " |      Flappy Bird       | ";
        gotoxy(10, 7);
        cout << " --------------------------";
        gotoxy(10, 9);
        cout << "1. Start Game";
        gotoxy(10, 10);
        cout << "2. Instructions";
        gotoxy(10, 11);
        cout << "3. Quit";
        gotoxy(10, 13);
        cout << "Masukkan Pilihan Anda [ 1 s.d 3 ] : ";
        cin >> op;

        if (op == "1")
        {
            play();
            goto menu7;
        }
        else if (op == "2")
        {
            instructions();
            goto menu7;
        }
        else if (op == "3")
        {
            system("cls");
            menu();
        }
        else
        {
            goto menu7;
        }
    }

    ////////////////////////////////
    /////     menu 8 keluar    /////
    ////////////////////////////////
    else if (pil == "8")
    {
        cout << "\n\n\n";
        cout << "\n\n\n\n\n\n\n\n";
        setcolor(7);
        cout << "-- Anda Telah Logout -- \n";
        cout << "-- thanks for looking at this simple program :) --\n";
        setcolor(15);
        cout << "\n\n\n\n\n\n\n\n\n\n";
        system("pause");
        system("cls");
        main();
    }
    else
    { // jika inputan menu salah
        system("cls");
        menu(); // kembali ke menu
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////
///// Sistem Login /////
////////////////////////
void login()
{
    string user, u, p;
    char pass[9999];
    string nam, kel, n, k;

    // memasukkan username dan password
    cout << "Username : ";
    cin >> user;
    cout << "Password : ";

    // percabangan apabila saat input password akan berupa bintang (*)
    int i = 0;
    while (i < 9999)
    {
        char ch = getch();
        if (ch == 13)
        {
            pass[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                cout << "\b \b";
                --i;
            }
        }
        else
        {
            pass[i++] = ch;
            cout << "*";
        }
    }
    cout << endl;

    // Memeriksa apakah file sudah ada atau belum
    ifstream input("database_login.txt"); // Membuka file database
    if (!input.good())
    {
        setcolor(4);
        cout << "\n-- Username or Password Invalid --\n";
        setcolor(15);
        cout << "Please check your username and password\n\n\n";
        system("pause");
        system("cls");
        main();
    }

    // output login success
    while (input >> u >> p >> n >> k)
    { // mencari data di database
        if (u == user && p == pass)
        {
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
            menu();
            break;
        }
    }
    input.close(); // menutup file database

    // apabila file ada di database dan saat memasukkan username dan password salah
    if (input.eof())
    {
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
void registr()
{

    // variabel sistem pendaftaran
    string reguser, ru, rp;
    string nama, kl, o, o2;

    // memasukkan username
    while (true)
    {
        cout << "Enter the username : ";
        cin >> reguser;

        // pengecekan apakah data username sudah ada di database atau blm
        ifstream reg("database_login.txt");
        bool flag = false;
        while (reg >> ru >> rp >> nama >> kl)
        {
            if (ru == reguser)
            {
                flag = true;
                break;
            }
        }

        // output apabila username sudah ada di database
        if (flag)
        {
            system("cls");
            setcolor(12);
            cout << "Username sudah terpakai, masukkan username lain" << endl;
            setcolor(15);
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
        else
        {
            break;
        }
    }

    // Memasukkan Password
    char regpass[9999]; // input akan berupa bintang (*)
    cout << "\nEnter the password : ";

    // percabangan apabila saat input password akan berupa bintang (*)
    int i = 0;
    while (i < 9999)
    {
        char ch = getch();

        // if else
        if (ch == 13)
        { // karakter Enter
            regpass[i] = '\0';
            break;
        }
        else if (ch == 8)
        { // karakter Backspace
            if (i > 0)
            {
                cout << "\b \b";
                --i;
            }
        }
        else
        {
            regpass[i++] = ch;
            cout << "*";
        }
    }

    // memasukkan nama dan kelas
    cout << "";
    getline(cin, o);
    cout << "";
    getline(cin, o2);
    cout << "\n\n";

    setcolor(2);
    cout << "-- Data Diri --\t";
    setcolor(15);
    cout << "\t = \t    Gunakan (_) apabila ingin menggunakan spasi\n";
    cout << "Nama : ";
    cin >> nama;
    cout << "Kelas : ";
    cin >> kl;

    // data akan di simpan di database.txt
    ofstream reg("database_login.txt", ios::app);
    reg << reguser << ' ' << regpass << ' ' << nama << ' ' << kl << endl;
    system("cls");
    setcolor(10);
    cout << "\nRegistration Sucessful\n";
    setcolor(15);
    main();
}

//////////////////////////////////
///// lupa password/username /////
//////////////////////////////////
void forgot()
{

    // judul / pembuka forgot
    string ch;
    system("cls");
    setcolor(14);
    cout << "--- Lupa dengan Password atau Username ?? we will help you ---\n\n";
    setcolor(15);
    cout << "1. Cari Password dengan Memasukkan Username" << endl;
    cout << "2. Cari Username dengan Memasukkan Password" << endl;
    cout << "3. Back\n";
    cout << "Masukkan Pilihan Anda [ 1 s.d 3 ] : ";
    cin >> ch;

    // menu 1 cari password
    if (ch == "1")
    {

        // variabel dan input username yang di ingat
        string searchuser, su, sp, n1, k1;
        cout << "\nMasukkan Username yang anda ingat : "; // memasukkan data yang diingat oleh pengguna
        cin >> searchuser;

        // Memeriksa apakah file sudah ada atau belum
        ifstream searchu("database_login.txt"); // Membuka file database
        if (!searchu.good())
        {
            setcolor(4);
            cout << "\nSorry, Your userID is not found in our database";
            setcolor(15);
            cout << "\nPlease kindly contact your system administrator for more details \n";
            cout << "\n\n\n";
            system("pause");
            system("cls");
            forgot(); // kembali ke void forgot();
        }

        // mencari data di database
        while (searchu >> su >> sp >> n1 >> k1)
        {
            if (su == searchuser)
            {

                // output data apabila data ada di database
                setcolor(10);
                cout << "\n\nHoree, your account found in the database";
                setcolor(15);
                cout << "\nYour password is " << sp; // output password apabila ada datanya
                cout << "\n\n\n";
                system("pause");
                system("cls");
                forgot(); // kembali ke void forgot();
                break;
            }
        }
        searchu.close(); // menutup file database.txt

        // output data apabila data yang diinputkan tidak ada di database
        if (searchu.eof())
        {
            setcolor(4);
            cout << "\nSorry, Your userID is not found in our database";
            setcolor(15);
            cout << "\nPlease kindly contact your system administrator for more details \n";
            cout << "\n\n\n";
            system("pause");
            system("cls");
            forgot(); // kembali ke void forgot();
        }
    }

    // menu 2 cari username
    else if (ch == "2")
    {

        // variabel dan input username yang di ingat
        string searchpass, su2, sp2, n2, k2;
        cout << "\nMasukkan Password yang anda ingat : "; // memasukkan data yang diingat oleh pengguna
        cin >> searchpass;

        // Memeriksa apakah file sudah ada atau belum
        ifstream searchp("database_login.txt"); // Membuka file database
        if (!searchp.good())
        {
            setcolor(4);
            cout << "\nSorry, We cannot found your password in our database";
            setcolor(15);
            cout << "\nPlease kindly contact your system administrator for more details \n";
            cout << "\n\n\n";
            system("pause");
            system("cls");
            forgot(); // kembali ke void forgot();
        }

        // mencari data di database
        while (searchp >> su2 >> sp2 >> n2 >> k2)
        {
            if (sp2 == searchpass)
            {

                // output data apabila data ada di database
                setcolor(10);
                cout << "\nsuccess, Your password is found in the database";
                setcolor(15);
                cout << "\nYour Username is : " << su2; // output username apabila ada datanya
                cout << "\n\n\n";
                system("pause");
                system("cls");
                forgot(); // kembali ke void forgot();
                break;
            }
        }
        searchp.close(); // menutup file database.txt

        // output data apabila data yang diinputkan tidak ada di database
        if (searchp.eof())
        {
            setcolor(4);
            cout << "\nSorry, We cannot found your password in our database";
            setcolor(15);
            cout << "\nPlease kindly contact your system administrator for more details \n";
            cout << "\n\n\n";
            system("pause");
            system("cls");
            forgot(); // kembali ke void forgot();
        }
    }

    // menu 3 exit
    else if (ch == "3")
    {
        system("cls");
        main(); // kembali ke main / judul
    }

    // apabila input yang di masukan tidak sesuai
    else
    {
        forgot(); // kembali ke void forgot();
    }
}
