#include<vector>
#include<iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {      //watch the lecture big bro!!, notes ain't gonna help you here!
    int m=matrix.size();                                    //this is a tough one, its medium but it should be hard level!
    int n=matrix[0].size();
    int srow=0,scol=0,erow=m-1,ecol=n-1;
    vector<int> answer;

    while(srow <= erow && scol <= ecol ){
        for(int j=scol; j<=ecol; j++){
            answer.push_back(matrix[srow][j]);
        }

        for(int i=srow+1; i<=erow; i++){
            answer.push_back(matrix[i][ecol]);
        }

        for(int j=ecol-1; j>=scol; j--){
            if(srow==erow) break;
            answer.push_back(matrix[erow][j]);
        }

        for(int i=erow-1; i>=srow+1; i--){
            if(scol==ecol) break;
            answer.push_back(matrix[i][scol]);
        }

        srow++; scol++; erow--; ecol--;
    }

    return answer;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    vector<int> answer = spiralOrder(matrix);

    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<" ";
    }
}
