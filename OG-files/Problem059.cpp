#include<iostream>
#include<vector>
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
    int index=-1;
    node* BuildTree(vector<int> PreArr){
        index++;
        if (PreArr[index]==-1){
            return NULL;
        }
        node* root= new node(PreArr[index]);
        root->right=BuildTree(PreArr);
        root->left=BuildTree(PreArr);
        return root;
    }
};
int main(){
    vector<int> preArr;
    int data=0;
    while(true){
        cout<<"Enter the value: ";
        cin>>data;
        if(data==-10) break;
        preArr.push_back(data);
    }
    node root(preArr[0]);
    node* TreeRoot=root.BuildTree(preArr);
    node* temp=TreeRoot;
    cout<<temp->data<<endl<<temp->right->data<<endl<<temp->left->data;
    // while(temp!=NULL){
    //     cout<<temp->data;
    //     temp=temp->right;
    // }

}
//this is the main program to define a tree from a preorder sequence given with -1 as null node.
