#include<iostream>
using namespace std;
class node{
public: 
    int data;
    node* right;
    node* left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
    node* BuildTree(int PreArr[], int size, int index){
        if(PreArr[index]==-1 || index>=size){
            return NULL;
        }
        node* root=new node(PreArr[index]);
        
    }
};

