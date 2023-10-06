#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  // Menginisialisasi fungsi random
  srand(time(0));

  // Menentukan batas atas dan bawah untuk angka yang akan ditebak
  const int MIN = 1;
  const int MAX = 10;

  // Menentukan angka yang akan ditebak
  int angka = MIN + rand() % (MAX - MIN + 1);

  std::cout << "Selamat datang di game tebak angka!" << std::endl;
  std::cout << "Saya telah menyimpan sebuah angka dari " << MIN << " sampai " << MAX << std::endl;
  std::cout << "Silakan tebak angka tersebut." << std::endl;

  // Meminta user untuk menebak angka
  int tebakan;
  std::cout << "Masukkan tebakan Anda: ";
  std::cin >> tebakan;

  // Menampilkan hasil tebakan user
  if (tebakan == angka) {
    std::cout << "Tebakan Anda benar! Angka yang saya simpan adalah " << angka << std::endl;
  } else {
    std::cout << "Maaf, tebakan Anda salah. Angka yang saya simpan adalah " << angka << std::endl;
  }

  return 0;
}

