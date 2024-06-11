#include <iostream> 
using namespace std; 

class Persegi { 
public: 
    double sisi; 
    Persegi(double s) : sisi(s) {} 
    double luas() { 
        return sisi * sisi; 
    } 
}; 

class Kotak { 
private: 
    double panjang; 
    double lebar; 
    double tinggi; 
public: 
    Kotak(double p, double l, double t) : panjang(p), lebar(l), tinggi(t) {} 
    double volume() { 
        return panjang * lebar * tinggi; 
    } 
}; 

int main() { 
    Persegi persegi(2); 
    cout << "Luas persegi: " << persegi.luas() << endl; 
    Kotak kotak(1, 2, 3); 
    cout << "Volume kotak berbentuk balok: " << kotak.volume() << endl; 
    return 0; 
} 
