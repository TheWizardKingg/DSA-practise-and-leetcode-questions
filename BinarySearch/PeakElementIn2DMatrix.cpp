#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    if(m==1 && n==1) return (vector<int>){0,0};      //if only one element, then its already peak, although, the algorithm already handles this case too
    
    for(int i=0; i<m; i++){   //basically apply binary search in all rows

        int start = 0;
        int end = n-1;

        while(start <= end){     
            int mid = start + (end-start) / 2;

            int left = mid-1 >= 0 ? matrix[i][mid-1]: -1;    //calculate all the 4 adjacent neighbors of the current element, if exist, otherwise -1;
            int right = mid+1 < n ? matrix[i][mid+1]: -1;
            int up = i-1 >= 0 ? matrix[i-1][mid]: -1;
            int down = i+1 < m ? matrix[i+1][mid]: -1;

            int e = matrix[i][mid];

            if(e > left && e > right && e > up && e > down){    //if element is greater than all its adjacent neighbors, then its peak, return its indices
                return (vector<int>){i,mid};
            }

            if(left < e && e < right){    //if element lies on increasing slope, then move to the larger neighbor (right)
                start = mid + 1;
            }else if(left > e && e > right){     //if element lies on decreasing slope, then move to the larger neighbor (Left) 
                end = mid - 1;
            }else{     //if element lies in a valley, then move to the larger neighbor (since larger neighbor has better chances of being peak)
                if(left > right){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }
        }
    }
    return (vector<int>){0,0};   //returns 0,0 if no peak found
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