#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
void display(node* end){
    node* Temp=end->next;
    
    
    do{
        cout<<Temp->data<<" ";
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
void deleteatend(node* &end){
    node* TEMP=end->next;
    node* TEMP2;
    for (int i=0; TEMP->next!=end; i++){
        TEMP=TEMP->next;
    }
    TEMP2=TEMP;
    TEMP2=TEMP2->next;
    TEMP->next=end->next;
    end=TEMP;
    free(TEMP2);

}
void deleteatpos(node* &end, int pos){
    node * TEMP=end->next;
    node* TEMP2;
    for (int i=0; i<pos-2; i++){
        TEMP=TEMP->next;
    }
    TEMP2=TEMP;
    TEMP=TEMP->next;
    TEMP2->next=TEMP->next;
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
    int pos;
    cout<<"Enter the position of the node to delete: ";
    cin>>pos;
    deleteatpos(end,pos);
    cout<<"After deletion at position: ";
    display(end);
    
    return 0;
}

// singly circular linked list implementation complete