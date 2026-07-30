#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
    vector<int> missing;

    int current = 1;

    for (int x : arr) {
        while (current < x) {
            missing.push_back(current);

            if (missing.size() == k)
                return missing[k - 1];

            current++;
        }
        current = x + 1;
    }

    while (missing.size() < k) {
        missing.push_back(current++);
    }

    return missing[k - 1];
}

int main(){
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << findKthPositive(arr, k) << endl;
    return 0;
}