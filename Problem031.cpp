#include<iostream>
using namespace std;

#define MAX 100
int Queue[MAX];
int front =-1;
int rear=-1;
void enqueue(int n, int &front, int &rear, int (&Queue)[MAX]){
    if (rear==MAX-1){
        cout<<"Overflow"<<endl;
    }else{
        if (front==-1){
            front++;
        }
        Queue[++rear]=n;
    }
}
void dequeue(int &front, int &rear, int (&Queue)[MAX]){
    if (front==-1 && rear==-1){
        cout<<"underflow"<<endl;
    }else{
        front++;
    }
}
void peek(int &front, int &rear){
    if (front==-1 && rear==-1){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<Queue[front];
    }
}
void display(int front, int rear, int Queue[MAX]){
    while (front<=rear){
        cout<<Queue[front++]<<" ";
    }
}
int main(){
    int n,choice=1;
    
    while(choice!=5){
        
        switch(choice){
            case 1: cout<<"Enter the number to be enqueued: ";
                    cin>>n;
                    enqueue(n,front,rear,Queue);
                    break;
            case 2: dequeue(front,rear,Queue);
                    break;
            case 3: peek(front,rear);
                    break;
            case 4: display(front,rear,Queue);
                    break;
            case 5: break;
            default: cout<<"Invalid choice";
        }
        cout<<"1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n: ";
        cin>>choice;
    }
    return 0;
}