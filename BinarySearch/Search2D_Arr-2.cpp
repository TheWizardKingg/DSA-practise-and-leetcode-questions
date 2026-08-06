#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {      
    int m = matrix.size();           //all rows are sorted in ascending order
    int n = matrix[0].size();           //all columns are sorted in ascending order

    int row = 0;                //start from the top right corner of the matrix
    int col = n-1;

    while(row<m && col>=0){        //check until we reach the bottom left corner of the matrix (hence full matrix checked)
        if(matrix[row][col] == target){      //if target found then early return true
            return true;
        }else if(matrix[row][col] < target){    //if element < target then move downwards since all elements in current row are smaller than target
            row++;
        }else{         //if element > target, then move left since all elements in current column are greater than target
            col--;
        }
    }
    return false;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 16;

    if(searchMatrix(matrix, target)){
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}