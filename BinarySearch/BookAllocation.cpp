#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool isValid(int maxPages, int students, vector<int> &nums){
    int actualStudents=1;
    int totalPages=0;

    for(int i=0; i<nums.size(); i++){

        if(totalPages + nums[i] <= maxPages){    //if total pages exceed the current maximum pages, then reset and increase totalStudents needed
            totalPages += nums[i];
        }else{
            actualStudents++;
            totalPages = nums[i];
        }
    }

    return actualStudents <= students;   //eventually, if according to the current maximum students needed exceed the maximum allowed students, return false, otherwise true
}

int findPages(vector<int> &nums, int m)  {
    int maxEle=INT_MIN;
    int sum=0;
    for(int x: nums){       
        sum+=x;            //minimum students can be 1, hence he must read all the books alone
        maxEle=max(maxEle, x);       //maximum students can be nums.size(), since no book can be shared between students, hence each student must read one book 
    }      //and hence one unlucky student will have to read the book with maximum pages 

    int start=maxEle;
    int end=sum;
    int answer=-1;

    while(start <= end){
        int mid = start + (end-start) / 2;

        if(isValid(mid, m, nums)){     //if current value is valid, save it and try finding an even smaller value to minimize the answer
            answer=mid;
            end=mid-1;
        }else{
            start=mid+1;     //if current value is not valid, then try finding a larger value
        }
    }
    return answer;    //return the answer, (-1 if no pages allocation possible)
} 

int main(){
    vector<int> vec;
    int m; 
    cout<<"Enter number of students: ";
    cin>>m;
    int n;
    cout<<"Enter number of books: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the book pages: ";
    int book;
    for(int i=0; i<n; i++){
        cin>>book;
        vec.push_back(book);
    }
    cout<<"Minimum possible maximum pages allocated to a student are: ";
    cout<< findPages(vec, m);
    return 0;
}