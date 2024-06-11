#include <iostream> 
#include <map> 
 
using namespace std; 
 
int main() { 
    // Deklarasi array 
    int array[] = {1, 2, 3, 4, 5}; 
 
    // Deklarasi map 
    map<string, int> ages = {{"Alice", 30}, {"Bob", 25}, 
{"Charlie", 35}}; 
 
    // Menggunakan array 
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) 
{ 
        cout << "Array element " << i << ": " << array[i] << 
endl; 
    } 
 
    // Menggunakan map 
    for (auto const& age : ages) { 
        cout << "Name: " << age.first << ", Age: " << 
age.second << endl; 
    } 
 
    return 0; 
} 