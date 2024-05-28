#include <iostream> // Library standar yang digunakan untuk input dan output
using namespace std; // Untuk mempersingkat penulisan kode program

struct Node // Membuat struct Node
{
    string data;  
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

    void enqueueAntrian(string data) // Membuat fungsi enqueueAntrian untuk menambahkan data ke dalam antrian
    {
        Node *newNode = new Node;
        newNode->data = data;
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
            Node *temp = front;
            front = front->next;
            delete temp;
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
        cout << "Data antrian teller:" << endl;
        Node *current = front;
        int position = 1;
        while (current != nullptr)
        {
            cout << position << ". " << current->data << endl;
            current = current->next;
            position++;
        }
    }
};

int main()
{
    Queue queue;
    queue.enqueueAntrian("Andi");
    queue.enqueueAntrian("Maya");
    queue.view();
    cout << "Jumlah antrian = " << queue.count() << endl;
    queue.dequeueAntrian();
    queue.view();
    cout << "Jumlah antrian = " << queue.count() << endl;
    queue.clear();
    queue.view();
    cout << "Jumlah antrian = " << queue.count() << endl;
    return 0;
}