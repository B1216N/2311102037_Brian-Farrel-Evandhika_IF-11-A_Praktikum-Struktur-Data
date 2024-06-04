#include <iostream> // Library standar yang digunakan untuk input dan output
#include <string>   // Library standar yang digunakan untuk string

using namespace std; // Untuk mempersingkat penulisan kode program

int carivokal(string kata, char huruf) // fungsi untuk mencari jumlah huruf vokal (sequential search)
{
    int jumlah = 0;
    for (int i = 0; i < kata.length(); i++) // Sequential search dilakukan dengan iterasi melalui setiap karakter dalam string
    {
        if (kata[i] == huruf) // Memeriksa apakah karakter pada indeks saat ini sama dengan huruf yang dicari
        {
            jumlah++; // Jika ditemukan huruf yang sesuai, jumlahnya ditambah
        }
    }
    return jumlah; // Mengembalikan jumlah huruf yang ditemukan
}

void hitungvokal(string kata) // fungsi untuk menampilkan jumlah huruf vokal
{
    int jumlah;
    char vokal[10] = {'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O'};
    for (int i = 0; i < 10; i++)
    {
        jumlah = carivokal(kata, vokal[i]);
        cout << "Jumlah huruf " << vokal[i] << " : " << jumlah << endl;
    }
}

int main() // fungsi utama
{
    cout << "========== Menghitung Jumlah Huruf Vokal ==========" << endl;
    string kata;
    cout << "Masukkan kata : ";
    cin >> kata;
    hitungvokal(kata);
    return 0;
}