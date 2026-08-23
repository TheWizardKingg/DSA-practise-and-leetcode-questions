#include<iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node(int val){
        prev = NULL;   //Doubly linked list contains three things, data, previous pointer, next pointer
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    
    void Push_front(int x){     
        Node* newNode = new Node(x);

        if(head == NULL){     //if head is NULL, that means no node in the list, hence newnode is gonna be the first node, then point head to newnode
            head = tail = NULL;
        }else{       //if List contains elements already, then make a newnode, point its next to where head currently is, and then change head to newnode since its the first node of the list now
            newNode->next = head;
            newNode->prev = NULL;
            head = newNode;
        }
    }

    void delete_at_pos(int x, int position){
        Node* temp = head;
        Node* temp2;  //make three temporary pointers (one stays on previous node) (one stays on forward node) (one stays on the deletion node)
        Node* temp3;

        if(head == NULL){    //edge case where list is already empty
            cout<<"Linked list empty"<<endl;
            return;
        }
        for(int i=1; i<position-1; i++){   //if not empty, then update temp pointer until it reaches one element before the actual desired node
            temp = temp->next;
        }  
        temp3 = temp->next;   //temp3 to the deletion node
        temp2 = temp;      //temp2 on the backward node   
        temp = temp->next->next;     //temp on the forward node
        temp->prev = temp2;    //update forward mapping (forward node's prev pointer)
        temp2->next = temp;   //update backward mapping (backward node's next pointer)
        delete(temp3);  //lastly delete the temp3 (deletion node)
        
    }


};