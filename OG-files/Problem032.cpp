#include<iostream>
using namespace std;
struct queue{
    int data;
    queue* next;
};
void enqueue(queue* &front, queue* &rear, int n){
    queue* newnode=(struct queue*)malloc(sizeof(queue));
    newnode->data=n;
    newnode->next=NULL;
    if (front==NULL && rear==NULL){
        front=newnode;
        rear=newnode;
    }else{
        rear->next=newnode;
        rear=newnode;
        newnode->next=NULL;
    }
}
void dequeue(queue* &front, queue* &rear){
    if (front==NULL && rear==NULL){
        cout<<"Underflow"<<endl;
    }else{
        queue* temp=front;
        front=front->next;
        free(temp);
    }
}
void peek(queue* front){
    if (front==NULL){
        cout<<"queue is empty"<<endl;
    }else{
        cout<<front->data<<endl;
    }
}
void display(queue* front){
    while (front!=NULL){
        cout<<front->data<<" ";
        front=front->next;
    }
    cout<<endl;
}
int main(){
    queue* front=NULL;
    queue* rear=NULL;
    int n, choice=1;
    while(choice!=5){
        switch(choice){
            case 1: cout<<"Enter the number to be enqueued: ";
                    cin>>n;
                    enqueue(front,rear,n);
                    break;
            case 2: dequeue(front,rear);
                    break;
            case 3: peek(front);
                    break;
            case 4: display(front);
                    break;
            case 5: break;
            default:cout<<"Invalid choice"<<endl;
                    break;
        }
        cout<<"1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n: ";
        cin>>choice;
    }
    return 0;
    
}

//queue implementation using linked list