#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class linkedlist{
    node* head=NULL;
    node* tail=NULL;
public:
    void insert(int val){
        node* newnode=new node(val);
        if (head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    node* display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        return head;
        
    }
};
int main(){
    linkedlist list;
    int val;
    while(true){
        cout<<"Enter value to insert, -1 to finish: ";
        cin>>val;
        if (val==-1) break;
        list.insert(val);
    }
    cout<<"Linked list: ";
    node* HEAD=list.display();
    node* temp1=HEAD;
    node* temp2=HEAD;
    while (true){
        temp2=temp2->next->next;
        temp1=temp1->next;
        if (temp2==NULL || temp2->next==NULL) break;
    }
    cout<<endl<<"middle node: "<<temp1->data<<" ";
    return 0;
    
}
//https://leetcode.com/problems/linked-list-middle-node/description/
//This code is very easy, run first loop to count number of nodes in a list, then just run the loop n/2 times accordingly to odd or even to return pointer