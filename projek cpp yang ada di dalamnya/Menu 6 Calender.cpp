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
// variabel menu 6 (calender) //
///////////////////////////////
int hitung_Year(int thn);
int hitung_Month(int thn,int bln);
int cek_Day(int jmlDay);
int hitung_Day(int bln,int thn);
//variabel perhitungan calender menu 6
int hitung_Year(int thn){
    int jmlDay = 0, year;
    for(year = 1900 ; year < thn ; year++){
            if(year%4 == 0){
              jmlDay += 366;
            }else{
              jmlDay += 365;
            }
    }
    return(jmlDay);
}
//variabel perhitungan calender menu 6
int hitung_Month(int thn,int bln){
    int jmlDay = 0, Month;
    for(Month = 1 ; Month < bln ; Month++)
    {
  if(Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12){
   jmlDay += 31;
  }else if(Month==4||Month==6||Month==9||Month==11){
            jmlDay += 30;
  }else{
            if(thn%4 == 0){
               jmlDay += 29;
   }else
               jmlDay += 28;
            }
  }
    return(jmlDay);
}
//variabel perhitungan calender menu 6
int cek_Day(int jmlDay){
 int Day = jmlDay%7 ;
 return(Day);
}
//variabel perhitungan calender menu 6
int hitung_Day(int Month,int thn)
{
    int jmlDay = 0;
    if(Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12){
               jmlDay += 31;
 }else if(Month == 4 || Month == 6 || Month == 9 || Month == 11){
               jmlDay += 30;
 }else{
  if(thn%4==0)
     jmlDay += 29;
  else
     jmlDay += 28;
    }
    return(jmlDay);
}

////////////////////////////////
/////  menu 6 calender     /////
////////////////////////////////
int main (){
menu6:
int thn,bln,jmlDay,jumlah_Day,Day;
string yn1;

// judul program menu 6
setcolor (14);
cout << "-------- Calender --------\n";
setcolor (15);
    printf("Masukkan Tahun : ");
    scanf("%d",&thn);fflush(stdin);
 do{
  printf("Masukkan Bulan : ");
  scanf("%d",&bln);fflush(stdin);
 }while(bln<1||bln>12);
 
 // output calender
 cout << endl;
 if (bln==1){
  printf("Calender : January %d",thn);
 }else if (bln==2){
  printf("Calender : February %d",thn);
 }else if (bln==3){
  printf("Calender : March %d",thn);
 }else if (bln==4){
  printf("Calender : April %d",thn);
 }else if (bln==5){
  printf("Calender : May %d",thn);
 }else if (bln==6){
  printf("Calender : June %d",thn);
 }else if(bln==7){
  printf("Calender : July %d",thn);
 }else if (bln==8){
  printf("Calender : August %d",thn);
 }else if (bln==9){
  printf("Calender : September %d",thn);
 }else if (bln==10){
  printf("Calender : October %d",thn);
 }else if (bln==11){
  printf("Calender : November %d",thn);
 }else if (bln==12){
  printf("Calender : Desember %d",thn);
 }

    jmlDay = hitung_Year(thn) + hitung_Month(thn, bln);
 Day = cek_Day(jmlDay);
    jumlah_Day = hitung_Day(bln,thn);

	setcolor (10);
    printf("\n=====================================================\n");
	setcolor (11);
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	setcolor (10);
    printf("=====================================================\n");
	setcolor (15);

    for(int i = 0 ; i < Day ; i++){
  printf("\t");
 }
 for(int i = 1 ; i <= jumlah_Day ; i++){
  printf("%d\t", i);
  if(Day %7 == 6)
         printf("\n");
  Day++;
    }
    getch();

// pengulang menu 6 calender
cout << "\n\n";
setcolor (14);
cout << "Apakah Anda Ingin Kembali Ke Menu (y/n) : ";
cin >> yn1;	
setcolor (15);
if (yn1 =="y"||yn1 =="Y"){
				system ("cls");
				goto menu6;		// kembali ke menu
			} else {
				system ("cls");
				goto menu6;	// kembali ke menu 6
			}
}
