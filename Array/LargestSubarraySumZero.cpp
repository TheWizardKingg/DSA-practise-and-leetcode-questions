#include <bits/stdc++.h>
using namespace std;

int largestSubarrayWithZeroSum(vector<int>& arr) {
    unordered_map<int, int> firstOccurrence;

    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // Entire array from 0 to i sums to 0
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Prefix sum seen before
        if (firstOccurrence.find(prefixSum) != firstOccurrence.end()) {
            maxLen = max(maxLen, i - firstOccurrence[prefixSum]);
        }
        else {
            firstOccurrence[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    cout << largestSubarrayWithZeroSum(arr);

    return 0;
}