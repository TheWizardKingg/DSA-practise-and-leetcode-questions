#include<iostream>
using namespace std;
struct node{
    int data;
    node* ptr;

};
void insertNode(int val, int pos, int &nodes, node* &head){
    if (pos<0 || pos>nodes+1){
        cout<<"Invalid position"<<endl;
        return;
    }
    nodes++;
    node* TEMP=head;
    for (int i=1; i<pos-1; i++){
        TEMP=TEMP->ptr;
    }
    node* newnode=(struct node*)malloc(sizeof(node));
    if (pos==1){
        newnode->data=val;
        newnode->ptr=head->ptr;
        head=newnode;
    }else if(pos>1 && pos<=nodes){
        newnode->ptr=TEMP->ptr;
        newnode->data=val;
        TEMP->ptr=newnode;
    }else if(pos==nodes+1){
        newnode->data=val;
        newnode->ptr=head;
        TEMP->ptr=newnode;
    }else{
        cout<<"Invalid position"<<endl;
    }
    return;
}


int main(){
    node* head=NULL;
    node* temp=NULL;
    int nodes=0;
    
    int choice=1;
    while (choice==1){
        node* newnode=(struct node*)malloc(sizeof(node));
        cout<<"Enter data: ";
        cin>>newnode->data;
        if (newnode->data==-1){
            choice=0;
            break;
        }
        nodes++;
        if (head==NULL){
            head=newnode;
            temp=newnode;
            newnode->ptr=head;
        }else{
            temp->ptr=newnode;
            newnode->ptr=head;
            temp=temp->ptr;
        }
    }
    node* TEMP=head;
    cout<<"Total nodes are: "<<nodes<<endl;
    cout<<"Linked list: ";
    do{
        cout<<TEMP->data<<" "<<TEMP<<endl;
        TEMP=TEMP->ptr;
    }while(TEMP!=head);
    int val,pos;
    cout<<"Enter a value and position to insert"<<endl;
    cin>>val>>pos;
    insertNode(val, pos, nodes, head);
    cout<<"Linked list: ";
    TEMP=head;
    for (int i=0; i<nodes; i++){
        cout<<TEMP->data<<" ";
        TEMP=TEMP->ptr;
    }
    return 0;
}