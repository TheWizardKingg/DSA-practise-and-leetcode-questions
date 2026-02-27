#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
void display(node* end){
    node* Temp=end->next;
    
    
    do{
        cout<<Temp->data;
        Temp=Temp->next;
    }while(Temp!=end->next);
}
void insertatbeg(node* &end, int val){
    node* newnode= (struct node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=end->next;
    end->next=newnode;
}
void insertatend(node*&end, int val){
    node* newnode=(struct node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=end->next;
    end->next=newnode;
    end=newnode;
}
void deleteatbeg(node* &end){
    node* TEMP=end->next;
    end->next=end->next->next;
    free(TEMP);
}
int main(){
    node* end=NULL;
    bool choice=true;
    int val;
    while (choice){
        cout<<"Enter data: ";
        cin>>val;
        node* newnode=(struct node*)malloc(sizeof(node));
        if (val!=-1){
            newnode->data=val;
        }else{
            choice=false;
            break;
        }
        if (end==NULL){
            end=newnode;
            end->next=end;
        }else{
            newnode->next=end->next;
            end->next=newnode;
            end=newnode;
        }
    }
    node* temp=end->next;
    
    do{
        cout<<temp->data;
        temp=temp->next;
    }while(temp!=end->next);
    // int VAL;
    // cout<<"Enter any number to insert at beginning";
    // cin>>VAL;
    // insertatbeg(end, VAL);
    // int a;
    // cout<<"Enter any number to insert at end";
    // cin>>a;
    // insertatend(end, a);
    deleteatbeg(end);
    cout<<endl;
    display(end);
    
    return 0;
}

//This program later on exists in this repo with classes and obj, although structure and classes are same
//but the later programs belong to my original DSA journey series on yt