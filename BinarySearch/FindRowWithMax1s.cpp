#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int rowWithMax1s(vector < vector < int >> & mat) {
    int maxOnes=0;
    int MaxOneIndex=-1;
    int n=mat.size();
    int m=mat[0].size();

    for(int i=0; i<n; i++){
        
        int start=0;
        int end=m-1;

        while(start <= end){
            int mid = start + (end-start) / 2;

            if(mat[i][mid] == 1){
                if(mid == 0 || mat[i][mid-1] == 0){
                    if(maxOnes < m-mid){
                        MaxOneIndex = i;
                        maxOnes = m-mid;
                    }
                    break;
                }else{
                    end = mid-1;
                }
            }
            else{
                start = mid+1;
            }
        }
        
    }
    return MaxOneIndex;

}

int main() {
    vector < vector < int >> mat = {{0, 0, 0, 1},
                                     {0, 1, 1, 1},
                                     {1, 1, 1, 1},
                                     {0, 0, 0, 0}};
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
    return 0;
}
