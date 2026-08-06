#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    if(m==1 && n==1) return (vector<int>){0,0};
    
    for(int i=0; i<m; i++){
        
        int start = 0;
        int end = n-1;

        while(start <= end){
            int mid = start + (end-start) / 2;

            int left = mid-1 >= 0 ? matrix[i][mid-1]: -1;
            int right = mid+1 < n ? matrix[i][mid+1]: -1;
            int up = i-1 >= 0 ? matrix[i-1][mid]: -1;
            int down = i+1 < m ? matrix[i+1][mid]: -1;

            int e = matrix[i][mid];

            if(e > left && e > right && e > up && e > down){
                return (vector<int>){i,mid};
            }

            if(left < e && e < right){
                start = mid + 1;
            }else if(left > e && e > right){
                end = mid - 1;
            }else{
                if(left > right){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }
        }
    }
    return (vector<int>){0,0};
}

int main(){
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    vector<int> peak = findPeakGrid(matrix);
    cout << "Peak element found at: (" << peak[0] << ", " << peak[1] << ")" << endl;

    return 0;
}