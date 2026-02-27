#include<iostream>
using namespace std;
struct node{
    node* next;
    int data;
    node* prev;
};
void deleteatpos(int nodenumber, int count, node* &head){
    node*TEMP=head;
    if (nodenumber==1){
        head=head->next;
        head->prev=NULL;
        free(TEMP);
    }else if(nodenumber==count){
        for (int i=0; i<nodenumber-1; i++){
            TEMP=TEMP->next;
        }
        TEMP->prev->next=NULL;
        free(TEMP);
    }else if(nodenumber<count && nodenumber>1){
        for (int i=1; i<nodenumber-1; i++){
            TEMP=TEMP->next;
        }
        node*TEMP2=TEMP;
        TEMP2=TEMP->next;
        TEMP->next->next->prev=TEMP;
        TEMP->next=TEMP->next->next;
        free(TEMP2);
    }else{
        cout<<"Invalid nodenumber to delete"<<endl;
    }   
    node* temp=head;
    cout<<"Linked list after deletion: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}
void insertatpos(int pos, int val,int count, node* &head){
    node* TEMP=head;
    if(pos==1){
        node* newnode=(struct node*)malloc(sizeof(node));
        newnode->data=val;
        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;
    }else if(pos>1 && pos<=count){
        for ( int i=1; i<pos-1; i++){
            TEMP=TEMP->next;
        }
        node* newnode=(struct node*)malloc(sizeof(node));
        newnode->data=val;
        newnode->next=TEMP->next;
        TEMP->next=newnode;
        newnode->prev=TEMP;
        newnode->next->prev=newnode;
    }else if(pos==count+1){
        while(TEMP->next!=NULL){
            TEMP=TEMP->next;
        }
        node* newnode=(struct node*) malloc(sizeof(node));
        newnode->data=val;
        newnode->next=NULL;
        newnode->prev=TEMP;
        TEMP->next=newnode;
    }
    else{
        cout<<"Invalid position"<<endl;
    }
    node* temp=head;
    cout<<"Linked list: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    return;
}
int main(){
    int choice=1;
    node* head=NULL;
    node* temp=NULL;
    int count=0;
    while (choice==1){
        node* newnode=(struct node*)malloc(sizeof(node));
        cout<<"Enter data: ";
        cin>>newnode->data;
        if(newnode->data==-1){
            choice==0;
            break;
        }
        newnode->next=NULL;
        if (head==NULL){
            head=newnode;
            newnode->prev=NULL;
            temp=newnode;
        }else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        count++;
        
    
    }
    temp=head;
    cout<<"Linked list: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    int pos,val;
    int nodenumber;
    int choice2;
    cout<<"To insert a node, press 1 \nTo delete a node, press 2"<<endl;
    cin>>choice2;
    if (choice2==1){

        cout<<"\nEnter position and value to insert: ";
        cin>>pos>>val;
        cout<<"total nodes are: "<<count<<endl;
        insertatpos(pos,val,count,head);
    }else if(choice2==2){

        cout<<"total nodes are: "<< count<<endl;
        cout<<"Enter the nodenumber to delete: ";
        cin>>nodenumber;
        deleteatpos(nodenumber,count, head);
    }else{
        cout<<"Invalid";
    }
    return 0;
}
