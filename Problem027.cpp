#include<iostream>
using namespace std;
struct stack{
    int data;
    stack*next;
};
void display(stack* top){
    stack* temp=top;
    while (temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
    return ;
}
int main(){
    stack* top=NULL;
    int val;
    while (true){
        cout<<"Enter data(-1 to stop): ";
        cin>>val;
        if (val==-1){
            break;
        }else{
            stack* newnode=(struct stack*) malloc(sizeof(stack));
            newnode->data=val;
            newnode->next=top;
            top=newnode;
        }
    }
    int choice;
    cout<<"1. DISPLAY\n2. EXIT\n";
    cin>>choice;
    if (choice==1){
        display(top);

    }else if (choice==2){
        return 0;
    }
    return 0;
}