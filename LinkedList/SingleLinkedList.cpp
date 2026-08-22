#include<iostream>
using namespace std;

class Node{
public:

    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:

    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newnode = new Node(val);

        if(head == NULL){
            head = tail = newnode;
        }else{
            newnode->next = head;
            head = newnode;
        }
    }

    void pop_front(){
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
        for(int i=1; i<position-1; i++){
            temp = temp->next;
        }

        Node* newnode = new Node(val);

        newnode->next = temp->next;
        temp->next = newnode;
    }

    void Pop_at_position(int position){
        Node* temp = head;
        Node* temp2;

        for(int i=1; i<position-1; i++){
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp->next->next;
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