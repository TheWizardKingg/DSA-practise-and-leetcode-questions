#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int st = 0, end = m * n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            int val = matrix[mid / n][mid % n];

            if (val == target)
                return true;

            if (val < target)
                st = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution s;
    bool found = s.searchMatrix(matrix, target);

    if (found)
        cout << "Target found!" << endl;
    else
        cout << "Target NOT found!" << endl;

    return 0;
}

// Problem link: https://leetcode.com/problems/search-a-2d-matrix/
// We treat the 2D matrix as a 1D sorted array and perform binary search on it.
