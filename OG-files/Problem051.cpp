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
    bool hasCycle(node *head) {
        node* temp1=head;
        node* temp2=head;
        while(temp2!=NULL && temp2->next!=NULL){
            
            temp1=temp1->next;
            temp2=temp2->next->next;
            if (temp1==temp2){
                return true;
            }
        }
        return false;
    }
};
int main(){
    cout<<"This program can't be tested as i am not yet aware of how to create cycles in a linked list"<<endl;
    cout<<"or maybe i just dont want to do so cause i am lazy, either way, who cares -o-";
    return 0;
}
//https://leetcode.com/problems/linked-list-cycle/description/
//this code uses fast and slow pointer approach to detect cycle in a linked list.