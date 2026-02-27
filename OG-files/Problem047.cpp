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
        node* newnode= new node(val);
        if (head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            tail=tail->next;
        }
    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void reverselist(){
        node* current=head;
        node* prev=NULL;
        node* Next=NULL;
        while (current!=NULL){
            Next=current->next;
            current->next=prev;
            prev=current;
            current=Next;
        }
    }
    void displayReversedList(){
        while (tail!=NULL){
            cout<<tail->data<<" ";
            tail=tail->next;
        }
    }
};
int main(){
    linkedlist list;
    int data;
    do{
        cout<<"Enter data, -1 to finish: ";
        cin>>data;
        if (data==-1) break;
        list.insert(data);
    }while(true);
    cout<<"original list: ";
    list.display();
    cout<<"After reversing the list: ";
    list.reverselist();
    list.displayReversedList();
    return 0;
    
}
//https://leetcode.com/problems/reverse-linked-list/
//implemented a linked list with insert and display functions