#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    int tableSize;
    vector<int> table;

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable(int size) {
        tableSize = size;
        table.resize(tableSize, -1); // -1 means empty
    }

    void insert(int key) {
        int index = hashFunction(key);

        // Linear probing
        while (table[index] != -1) {
            index = (index + 1) % tableSize; // wrap around
        }

        table[index] = key;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << i << " : " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht(7);  // Table size should be > number of elements

    ht.insert(1);
    ht.insert(5);
    ht.insert(6);
    ht.insert(3);
    ht.insert(4);

    ht.display();

    return 0;
}