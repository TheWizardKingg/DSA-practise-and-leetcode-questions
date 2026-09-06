#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int x){
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        Node* newHead = NULL;

        while(temp != NULL){
            mp[temp] = new Node(temp->data);
            if(newHead == NULL) newHead = mp[temp];
            temp = temp->next;
        }

        temp = head;

        while(temp != NULL){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return newHead;

    }
};

