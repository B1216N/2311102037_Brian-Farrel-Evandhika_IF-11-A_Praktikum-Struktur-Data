#include <iostream> // Library standar yang digunakan untuk input dan output
#include <conio.h> // Library standar yang digunakan untuk _getche()
#include <cstring> // Library standar yang digunakan untuk strlen()
#include <iomanip> // Library standar yang digunakan untuk setw()

using namespace std; // Untuk mempersingkat penulisan kode program

char dataArray[100]; // Data yang akan diurutkan
char cari; // Data yang dicari

void Selection_Sort(char arr[], int n) // Fungsi untuk mengurutkan data menggunakan Selection Sort
{
    int temp, min, i, j;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void BinarySearch(char arr[], int n) // Fungsi untuk mencari data menggunakan Binary Search
{
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = n - 1;
    while (!b_flag && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == cari)
        {
            b_flag = true;
        }
        else if (arr[tengah] < cari)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if (b_flag)
    {
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    }
    else
    {
        cout << "\nData tidak ditemukan" << endl;
    }
}

int main() // Fungsi utama
{
    cout << "========== Searching Huruf ==========" << endl;

    cout << "Masukkan kalimat: ";
    cin.getline(dataArray, 100); // Memasukkan data yang akan diurutkan, getline() digunakan untuk membaca inputan yang mengandung spasi

    int n = strlen(dataArray);

    cout << "Masukkan karakter yang ingin dicari: ";
    cin >> cari;

    cout << "\nData diurutkan: ";
    Selection_Sort(dataArray, n); // Memanggil fungsi Selection_Sort

    for (int x = 0; x < n; x++)
    {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    BinarySearch(dataArray, n);  // Memanggil fungsi BinarySearch

    _getche(); // Menunggu inputan dari user
    return 0;
}