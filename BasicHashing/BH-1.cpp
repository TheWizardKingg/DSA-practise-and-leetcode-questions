#include<iostream>
#include<unordered_map>

using namespace std;
int main(){
    unordered_map<int, int> map;
    int arr[5]={1, 2, 1, 3, 2};
    int query[5]={1, 3, 4, 2, 10};
    int count=0;
    for (int j=0; j<5; j++){
        count=0;
        for(int i=0; i<5; i++){
            if(query[j]==arr[i]) count++;
        }
        map.insert({query[j],count});
    }
    cout<<"Frequencies are: "<<endl;
    for(auto it: map){
        cout<<it.first<<" "<<it.second<<endl;
    } 
    return 0;
    
}

//just include the map, run a for loop, store each element and its occurence in the map
//that's it