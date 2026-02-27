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
    public:
    node* head;
    node* temp;
    linkedlist(){
        head=NULL;
    }
    void insert(int val){
        node* newnode=new node(val);
        if (head==NULL){
            head=temp=newnode;
        }else{
            temp->next=newnode;
            temp=temp->next;
        }
        newnode->data=val;
    }
    void Delete(){
        node* temp=head;
        if (head==NULL){
            return;
        }
        while (temp->next->next!=NULL){
            temp=temp->next;
        }
        delete(temp->next);
        temp->next=NULL;
    }
    void display(){
        node* temp=head;
        while (temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void insertatpos(int a, int val){
        node* temp=head;
        node* temp2=head;
        for (int i=0; i<a-1; i++){
            temp=temp->next;
            temp2=temp2->next;
        }
        temp2=temp->next;
        node* newnode=new node(val);
        newnode->next=temp2;
        temp->next=newnode;
    }
};
int main(){
    linkedlist list;
    int val=0;
    while (val!=-1){
        list.insert(val);
        cout<<"Keep entering the values to insert, -1 to finish: ";
        cin>>val;
    }
    list.display();
    list.Delete();
    cout<<"After deletion"<<endl;
    list.display();
    list.insertatpos(3,10);
    cout<<"After insertion at position 3"<<endl;
    list.display();
    return 0;
}
//This is a program to create a linked list using classes and objects, previous programs used structures and malloc
//This program belongs to my yt DSA series 
//previous questions were from my college POV assignments :P