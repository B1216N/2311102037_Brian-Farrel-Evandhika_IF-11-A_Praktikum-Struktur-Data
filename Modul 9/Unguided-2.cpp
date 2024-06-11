#include <iostream>  // Library standar yang digunakan untuk input dan output
#include <queue>     // Library standar yang digunakan untuk queue
using namespace std; // Untuk mempersingkat penulisan kode program

struct Pohon // Struct yang berisi data node tree
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root; // Pointer root tree

void init() // Fungsi untuk inisialisasi tree
{
    root = NULL;
}

bool isEmpty() // Fungsi untuk mengecek apakah tree kosong
{
    return root == NULL;
}

void buatNode(char data) // Fungsi untuk membuat node tree
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat sebagai root." << endl;
    }
    else
    {
        cout << "\nTree sudah ada!" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) // Fungsi untuk menambahkan node ke child kiri
{
    if (node->left != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    else
    {
        Pohon *baru = new Pohon();
        baru->data = data;
        baru->left = NULL;
        baru->right = NULL;
        baru->parent = node;
        node->left = baru;
        cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
        return baru;
    }
}

Pohon *insertRight(char data, Pohon *node) // Fungsi untuk menambahkan node ke child kanan
{
    if (node->right != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    else
    {
        Pohon *baru = new Pohon();
        baru->data = data;
        baru->left = NULL;
        baru->right = NULL;
        baru->parent = node;
        node->right = baru;
        cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
        return baru;
    }
}

void update(char data, Pohon *node) // Fungsi untuk mengubah data node
{
    if (!node)
    {
        cout << "\nNode yang ingin diganti tidak ada!!" << endl;
    }
    else
    {
        char temp = node->data;
        node->data = data;
        cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
    }
}

void retrieve(Pohon *node) // Fungsi untuk menampilkan data node
{
    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        cout << "\nData node: " << node->data << endl;
    }
}

void find(Pohon *node) // Fungsi untuk mencari node
{
    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        cout << "\nData Node: " << node->data << endl;
        cout << "Root: " << root->data << endl;
        if (!node->parent)
            cout << "Parent: (tidak punya parent)" << endl;
        else
            cout << "Parent: " << node->parent->data << endl;
        if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
            cout << "Sibling: " << node->parent->left->data << endl;
        else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
            cout << "Sibling: " << node->parent->right->data << endl;
        else
            cout << "Sibling: (tidak punya sibling)" << endl;
        if (!node->left)
            cout << "Child Kiri: (tidak punya Child kiri)" << endl;
        else
            cout << "Child Kiri: " << node->left->data << endl;
        if (!node->right)
            cout << "Child Kanan: (tidak punya Child kanan)" << endl;
        else
            cout << "Child Kanan: " << node->right->data << endl;
    }
}
void preOrder(Pohon *node) // Fungsi untuk melakukan preOrder traversal
{
    if (node != NULL)
    {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(Pohon *node) // Fungsi untuk melakukan inOrder traversal
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
    }
}

void postOrder(Pohon *node) // Fungsi untuk melakukan postOrder traversal
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
    }
}

void deleteTree(Pohon *node) // Fungsi untuk menghapus tree
{
    if (node != NULL)
    {
        if (node != root)
        {
            if (node->parent->left == node)
                node->parent->left = NULL;
            if (node->parent->right == node)
                node->parent->right = NULL;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        if (node == root)
        {
            delete root;
            root = NULL;
        }
        else
        {
            delete node;
        }
    }
}

void deleteSub(Pohon *node) // Fungsi untuk menghapus subtree
{
    if (!isEmpty())
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

void clear() // Fungsi untuk menghapus tree
{
    if (!isEmpty())
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

int size(Pohon *node = root) // Fungsi untuk menghitung jumlah node tree
{
    if (!node)
    {
        return 0;
    }
    else
    {
        return 1 + size(node->left) + size(node->right);
    }
}

int height(Pohon *node = root) // Fungsi untuk menghitung tinggi tree
{
    if (!node)
    {
        return 0;
    }
    else
    {
        int heightKiri = height(node->left);
        int heightKanan = height(node->right);
        return max(heightKiri, heightKanan) + 1;
    }
}

void characteristic() // Fungsi untuk menampilkan karakteristik tree
{
    cout << "\nSize Tree: " << size() << endl;
    cout << "Height Tree: " << height() << endl;
    if (height() != 0)
    {
        cout << "Average Node of Tree: " << (double)size() / height() << endl;
    }
}
void TampilChild_Descendants(Pohon *node) // Fungsi untuk menampilkan child dan descendant dari node
{
    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        cout << "\nNode: " << node->data << endl;
        if (node->left)
            cout << "Child Kiri: " << node->left->data << endl;
        else
            cout << "Child Kiri: (tidak punya Child kiri)" << endl;

        if (node->right)
            cout << "Child Kanan: " << node->right->data << endl;
        else
            cout << "Child Kanan: (tidak punya Child kanan)" << endl;

        cout << "Descendants:" << endl;
        queue<Pohon *> q;
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
        while (!q.empty())
        {
            Pohon *current = q.front();
            q.pop();
            cout << " " << current->data << ", ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        cout << endl;
    }
}

void brianfarrelevandhika_2311102037() // Fungsi untuk menampilkan menu
{
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Buat Node\n";
        cout << "2. Update Node\n";
        cout << "3. Retrieve Node\n";
        cout << "4. Find Node\n";
        cout << "5. Travers Data\n";
        cout << "6. Hapus Subtree\n";
        cout << "7. Clear Tree\n";
        cout << "8. Karakteristik Tree\n";
        cout << "9. Display Child dan Descendants\n";
        cout << "10. Exit\n";
        cout << "Pilih opsi: ";
        cin >> choice;
        char data, parentData;
        Pohon *parentNode = nullptr;
        switch (choice)
        {
        case 1: // Buat Node
            if (isEmpty())
            {
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
            }
            else // Insert Left atau Insert Right
            {
                cout << "Masukkan data node baru: ";
                cin >> data;
                cout << "Masukkan data parent node: ";
                cin >> parentData;
                cout << "Pilih 1 untuk Insert Left, 2 untuk Insert Right: ";
                char insertChoice;
                cin >> insertChoice;
                parentNode = nullptr;
                queue<Pohon *> q;
                q.push(root);
                while (!q.empty())
                {
                    Pohon *node = q.front();
                    q.pop();
                    if (node->data == parentData)
                    {
                        parentNode = node;
                        break;
                    }
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                if (parentNode)
                {
                    if (insertChoice == '1')
                    {
                        insertLeft(data, parentNode);
                    }
                    else if (insertChoice == '2')
                    {
                        insertRight(data, parentNode);
                    }
                    else
                    {
                        cout << "Opsi tidak valid!" << endl;
                    }
                }
                else
                {
                    cout << "Parent node tidak ditemukan!" << endl;
                }
            }
            break;
        case 2: // Update Node
            if (!isEmpty())
            {
                cout << "Masukkan data node baru: ";
                cin >> data;
                cout << "Masukkan data node yang ingin diupdate: ";
                cin >> parentData;
                parentNode = nullptr;
                // Cari node yang ingin diupdate menggunakan BFS
                queue<Pohon *> q;
                q.push(root);
                while (!q.empty())
                {
                    Pohon *node = q.front();
                    q.pop();
                    if (node->data == parentData)
                    {
                        parentNode = node;
                        break;
                    }
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                if (parentNode)
                {
                    update(data, parentNode);
                }
                else
                {
                    cout << "Node yang ingin diupdate tidak ditemukan!" << endl;
                }
            }
            else
            {
                cout << "Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 3: // Retrieve Node
            if (!isEmpty())
            {
                cout << "Masukkan data node yang ingin diretrieve: ";
                cin >> data;
                parentNode = nullptr;
                // Cari node yang ingin diretrieve menggunakan BFS
                queue<Pohon *> q;
                q.push(root);
                while (!q.empty())
                {
                    Pohon *node = q.front();
                    q.pop();
                    if (node->data == data)
                    {
                        parentNode = node;
                        break;
                    }
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                if (parentNode)
                {
                    retrieve(parentNode);
                }
                else
                {
                    cout << "Node yang ingin diretrieve tidak ditemukan!" << endl;
                }
            }
            else
            {
                cout << "Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 4: // Find Node
            if (!isEmpty())
            {
                cout << "Masukkan data node yang ingin dicari: ";
                cin >> data;
                parentNode = nullptr;
                // Cari node yang ingin dicari menggunakan BFS
                queue<Pohon *> q;
                q.push(root);
                while (!q.empty())
                {
                    Pohon *node = q.front();
                    q.pop();
                    if (node->data == data)
                    {
                        parentNode = node;
                        break;
                    }
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                if (parentNode)
                {
                    find(parentNode);
                }
                else
                {
                    cout << "Node yang ingin dicari tidak ditemukan!" << endl;
                }
            }
            else
            {
                cout << "Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 5: // Travers Data
            if (!isEmpty())
            {
                cout << "\nPreOrder Traversal:" << endl;
                preOrder(root);
                cout << "\n";
                cout << "\nInOrder Traversal:" << endl;
                inOrder(root);
                cout << "\n";
                cout << "\nPostOrder Traversal:" << endl;
                postOrder(root);
                cout << "\n";
            }
            else
            {
                cout << "Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 6: // Hapus Subtree
            if (!isEmpty())
            {
                cout << "Masukkan data node subtree yang ingin dihapus: ";
                cin >> data;
                parentNode = nullptr;
                // Cari node subtree yang ingin dihapus menggunakan BFS
                queue<Pohon *> q;
                q.push(root);
                while (!q.empty())
                {
                    Pohon *node = q.front();
                    q.pop();
                    if (node->data == data)
                    {
                        parentNode = node;
                        break;
                    }
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                if (parentNode)
                {
                    deleteSub(parentNode);
                }
                else
                {
                    cout << "Node subtree yang ingin dihapus tidak ditemukan!" << endl;
                }
            }
            else
            {
                cout << "Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 7: // Clear Tree
            clear();
            break;
        case 8: // Karakteristik Tree
            characteristic();
            break;
        case 9: // Display Child dan Descendants
            if (!isEmpty())
            {
                cout << "Masukkan data node yang ingin ditampilkan child dan descendants: ";
                cin >> data;
                parentNode = nullptr;
                // Cari node yang ingin ditampilkan child dan descendants menggunakan BFS
                queue<Pohon *> q;
                q.push(root);
                while (!q.empty())
                {
                    Pohon *node = q.front();
                    q.pop();
                    if (node->data == data)
                    {
                        parentNode = node;
                        break;
                    }
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                if (parentNode)
                {
                    TampilChild_Descendants(parentNode);
                }
                else
                {
                    cout << "Node yang ingin ditampilkan child dan descendants tidak ditemukan!" << endl;
                }
            }
            else
            {
                cout << "Buat tree terlebih dahulu!" << endl;
            }
            break;
            case 10: // Exit
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        default: // Opsi tidak valid
            cout << "Opsi tidak valid!" << endl;
            break;
        }
    } while (choice != '9');
}

int main() // Fungsi utama program
{
    init();
    brianfarrelevandhika_2311102037();
    return 0;
}

