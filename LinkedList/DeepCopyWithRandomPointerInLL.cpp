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

        unordered_map<Node*, Node*> mp;   //unordered_map to store mappings (instead of normal map because unordered_map has O(logn) time comp)
        Node* temp = head;
        Node* newHead = NULL;

        while(temp != NULL){   //traversal of the original linked list and creating new nodes and simultaneously mapping original nodes to corresponding new nodes
            mp[temp] = new Node(temp->data);
            if(newHead == NULL) newHead = mp[temp];   //store first node's address as newHead
            temp = temp->next;
        }
 
        temp = head;   //reset temp for another traversal to update new list's connections

        while(temp != NULL){
            mp[temp]->next = mp[temp->next];   //update the new list node's connections using the map
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return newHead;  //return the head of the new linked list

    }
};

