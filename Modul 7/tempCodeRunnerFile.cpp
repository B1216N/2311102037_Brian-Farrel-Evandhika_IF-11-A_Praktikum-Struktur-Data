#include <iostream> // Library standar yang digunakan untuk input dan output
#include <string>   // Library standar yang digunakan untuk tipe data string

using namespace std; // Untuk mempersingkat penulisan kode program

struct Node // Membuat struct Node Mahasiswa
{
    string nama;
    long long nim;
    Node *next;
};

class Queue // Membuat class Queue
{
private:
    Node *front;
    Node *back;

public:
    Queue() // Membuat Queue untuk menginisialisasi front dan back
    {
        front = nullptr;
        back = nullptr;
    }

    bool isEmpty() // Membuat fungsi isEmpty untuk mengecek apakah antrian kosong atau tidak
    {
        return front == nullptr;
    }

    void enqueueAntrian(string nama, long long nim) // Membuat fungsi enqueueAntrian untuk menambahkan data ke dalam antrian
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }

    void dequeueAntrian() // Membuat fungsi dequeueAntrian untuk menghapus data dari antrian
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
        }
        else
        {
            cout << "Pengunjung dengan nama " << front->nama << " telah selesai dilayani" << endl;
            Node *temp = front;
            front = front->next;
            delete temp;

            if (front == nullptr)
            {
                back = nullptr;
            }
        }
    }

    int count() // Membuat fungsi count untuk menghitung jumlah data dalam antrian
    {
        int count = 0;
        Node *current = front;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() // Membuat fungsi clear untuk menghapus semua data dalam antrian
    {
        while (!isEmpty())
        {
            dequeueAntrian();
        }
    }

    void view() // Membuat fungsi view untuk menampilkan data dalam antrian
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
            return;
        }
        else
        {
            cout << "Data antrian mahasiswa:" << endl;
            Node *current = front;
            int position = 1;
            while (current != nullptr)
            {
                cout << position << ". " << current->nama << " (" << current->nim << ")" << endl;
                current = current->next;
                position++;
            }
        }
    }
};

int main()
{
    Queue queue;
    int pilihan;
    while (true)
    {
        cout << "========== Menu Antrian Mahasiswa ==========" << endl;
        cout << "1. Tambah antrian" << endl;
        cout << "2. Hapus antrian" << endl;
        cout << "3. Lihat antrian" << endl;
        cout << "4. Hapus semua antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "============================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
        {
            string nama;
            long long nim;
            cout << "Masukkan nama mahasiswa: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM mahasiswa: ";
            cin >> nim;
            queue.enqueueAntrian(nama, nim);
            cout << "Mahasiswa " << nama << " telah ditambahkan ke dalam antrian" << endl;
            break;
        }
        case 2:
        {
            queue.dequeueAntrian();
            break;
        }
        case 3:
        {
            queue.view();
            cout << "Jumlah antrian = " << queue.count() << endl;
            break;
        }
        case 4:
        {
            queue.clear();
            cout << "Semua antrian telah dilayani" << endl;
            break;
        }
        case 5:
        {
            cout << "Terima kasih telah menggunakan program ini" << endl;
            return 0;
        }
        default:
        {
            cout << "Pilihan tidak valid" << endl;
            break;
        }
        }
    }
}