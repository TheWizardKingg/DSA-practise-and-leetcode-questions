#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 2, 1, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxVal = 100;   // set according to constraints
    int hash[101] = {0};  // initialize all to 0

    // Counting frequencies
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    // Printing frequencies
    for (int i = 0; i <= maxVal; i++) {
        if (hash[i] > 0) {
            cout << i << " -> " << hash[i] << endl;
        }
    }

    return 0;
}
