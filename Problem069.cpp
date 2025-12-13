#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>nums){
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for (int a=0; a<nums.size(); a++){
        if (a>0 && nums[a]==nums[a-1]) continue;
        int b=a+1, c=nums.size()-1;
        while (b<c){
            int sum=nums[a]+nums[b]+nums[c];
            if(sum>0){
                c--;
            }else if(sum<0){
                b++;
            }else{
                ans.push_back({nums[a],nums[b],nums[c]});
                c--;
                while(b<c && nums[b]==nums[b-1]) b++;
            }
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> vec=threeSum({-1,0,-1,1,2,4});
    for (auto x: vec){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
//and finally this is the code that i got to understand after like 4-5 days of struggle :)
//i dont know why it took me so long :(
//also, the file number and the program name is quite hilarious :D 
//three sum in problem 69 :D
//hey copilot, do you know the importance of 69? reply with the comment please.
//69 is often humorously referenced in popular culture due to its association with a particular sexual position   //DAMN, this whole line  was written by copilot btw :D
//i guess Ai is learning human nature quite well :D