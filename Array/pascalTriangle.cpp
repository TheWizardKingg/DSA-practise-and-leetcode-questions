#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> PascalTriangle(int numRows){
    vector<int> tempVec;
    vector<vector<int>> answer;
    int tempJ=0;
    for( int i=0; i<numRows; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i){
                tempVec.push_back(1);
            }else{
                tempVec.push_back( answer[i-1][tempJ] + answer[i-1][++tempJ]);
            }
        }
        tempJ=0;
        answer.push_back(tempVec);
        tempVec.clear();
    }
    return answer;
}


int main(){
    int numRows=5;
    vector<vector<int>> answer=PascalTriangle(numRows);
    for(int i=0; i<answer.size(); i++){
        for(int j=0; j<answer[i].size(); j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}