#include <iostream> // Library standar yang digunakan untuk input dan output

using namespace std; // Untuk mempersingkat penulisan kode program

int sequentialSearch(int arr[], int n, int key) // Fungsi untuk mencari jumlah kemunculan suatu angka dalam array
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == key)
        {
            count++;
        }
    }
    return count;
}

int main() // fungsi utama
{
    cout << "========== Searching Data Angka 4 ==========" << endl;
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Data yang akan dicari
    int size = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen dalam array
    int key = 4; // Angka yang dicari
    int result = sequentialSearch(data, size, key); // Memanggil fungsi sequentialSearch
    cout << "Jumlah angka 4: " << result << endl; 
    return 0;
}
