#include<iostream>
using namespace std;
struct node{
    int data;
    node* ptr;
};

int main(){
    node* head =NULL;
    node* temp=NULL;
    node* newnode;

    int choice=1;
    while (choice){
        newnode=new node();
        cout << "Enter data: ";
        cin >> newnode->data;
        newnode->ptr=NULL;
        if (head==NULL){
            head=temp=newnode;
        }
        else{
            temp->ptr=newnode;
            temp=newnode;
        }
        cout<< "Do you want to add another one? (1/0)" << endl;
        cin>>choice;
    }
    cout << "linked list" << endl;
    temp =head;
    while (temp!=NULL){
        cout<< temp->data<< endl;
        temp=temp->ptr;
    }
    return 0;
}