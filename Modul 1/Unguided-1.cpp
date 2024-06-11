#include <iostream> 
 
using namespace std; 
 
int hitungLuas(int panjang, int lebar) { 
  int luas = panjang * lebar; 
  return luas; 
} 
 
int main() { 
  int panjang, lebar; 
 
  cout << "Masukkan panjang persegi panjang: "; 
  cin >> panjang; 
  cout << "Masukkan lebar persegi panjang: "; 
  cin >> lebar; 
 
  int luas = hitungLuas(panjang, lebar); 
 
  cout << "Luas persegi panjang adalah: " << luas << endl; 
 
  return 0; 
} 