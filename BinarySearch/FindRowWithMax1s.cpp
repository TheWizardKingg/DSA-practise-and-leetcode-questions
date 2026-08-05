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

    for(int i=0; i<n; i++){    //linear loop to search over all the rows
        
        int start=0;
        int end=m-1;

        while(start <= end){      //binary search to find the first occurrence of 1 in the row since all rows are increasingly sorted
            int mid = start + (end-start) / 2;

            if(mat[i][mid] == 1){     
                if(mid == 0 || mat[i][mid-1] == 0){    //we are standing on 1 and either its the first element or has 0 before it, means its first occurrence
                    if(maxOnes < m-mid){    //calculate total number of 1s in the row, and check if its more than our previous max so far
                        MaxOneIndex = i;    //if yes then save the index and break out of that row, we are done with that row
                        maxOnes = m-mid;
                    }
                    break;  
                }else{     //if the current one has one more 1 before it, then we shall move to the left side of row to find the first occurrence of 1
                    end = mid-1;
                }
            }
            else{   //if we are currently standing on 0, then it means, all the 1s lie on the right side of the row, hence move to the right
                start = mid+1;
            }
        }
        
    }
    return MaxOneIndex;    //return the index of row with maximum 1s so far, if no rows have any 1s, then return -1

}

int main() {
    vector < vector < int >> mat = {{0, 0, 0, 1},
                                     {0, 1, 1, 1},
                                     {1, 1, 1, 1},
                                     {0, 0, 0, 0}};
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
    return 0;
}
