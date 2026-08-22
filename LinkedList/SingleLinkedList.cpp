#include<iostream>
using namespace std;

class Node{
public:

    int data;
    Node* next;

    Node(int val){     //make a class Node with value, and a pointer to next node
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:

    List(){
        head = tail = NULL;   //initialize the pointers with NULL
    }

    void push_front(int val){       //make a node, if its first node then (head=tail=newnode) otherwise update forward mapping, then update previous mapping
        Node* newnode = new Node(val);    //forward mapping first: (newnode->next = head), backward mapping second: (head = newnode)

        if(head == NULL){
            head = tail = newnode;
        }else{
            newnode->next = head;
            head = newnode;
        }
    }

    void pop_front(){     //if list isn't empty, make temp pointer to head, update the head, delete the temp
        if(head != NULL){
            Node* temp = head;
            head = head->next;
            delete(temp);
        }else{
            cout<<"List is Empty"<<endl;
        }
        return;
    }

    void Push_at_position(int val, int position){
        Node* temp = head;
        for(int i=1; i<position-1; i++){    //this stops the temp pointer to 1 node before the actual deletion node 
            temp = temp->next;          //example: we want to delete 5 (position=4) from [4,6,3,5,7,8,9], this loop will update temp and stop temp at 3
        }                              //total 2 iterations for this loop to update temp to 3 (position=3)

        Node* newnode = new Node(val);       //make a new node to insert

        newnode->next = temp->next;     //update forward mapping first (newnode->next = temp->next)
        temp->next = newnode;          //update backward mapping later (temp->next = newnode)
    }

    void Pop_at_position(int position){
        Node* temp = head;           // make two temp pointers (since one is going to be sacrificed for deletion of the node)
        Node* temp2;

        for(int i=1; i<position-1; i++){      //again skip temp to one node before the actual desired node 
            temp = temp->next;
        }
        temp2 = temp->next;        //update forward mapping
        temp->next = temp->next->next;   //update backward mapping
        delete(temp2);
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp->data<<endl;
            temp = temp->next;
        }
    }
};

int main(){
    List l;

    l.push_front(30);
    l.push_front(20);
    l.push_front(10);

    l.print();

    return 0;
}