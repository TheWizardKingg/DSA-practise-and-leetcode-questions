#include<iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node(int val){
        prev = NULL;
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

        if(head == NULL){
            head = tail = NULL;
        }else{
            newNode->next = head;
            newNode->prev = NULL;
            head = newNode;
        }
    }

    void delete_at_pos(int x, int position){
        Node* temp = head;
        Node* temp2;
        Node* temp3;

        if(head == NULL){
            cout<<"Linked list empty"<<endl;
            return;
        }
        for(int i=1; i<position-1; i++){
            temp = temp->next;
        }
        temp3 = temp->next;
        temp2 = temp;
        temp->next = temp->next->next;
        temp->prev = temp2;
        temp2->next = temp;
        delete(temp3);
        
    }


};