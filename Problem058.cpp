#include<iostream>
#include<map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head1) {
        map<Node*,Node*> mp;
        Node* temp1=head1;
        Node* head2=NULL;
        Node* temp2=head2;
        for(int i=0;temp1!=NULL;i++){
            Node* newnode=new Node(temp1->val);
            if(head2==NULL){
                head2=newnode;
                temp2=newnode;
            }else{
                temp2->next=newnode;
                temp2=newnode;
            }                                      // bro, can you believe it? 
            mp.insert({temp1,temp2});  
            temp1=temp1->next;                 // i just realized, that i updated first, then inserted
        }                                              //        /(XoX)/
        Node* TEMP1=head1;
        Node* TEMP2=head2;
        while(TEMP1!=NULL){
            if(TEMP1->random==NULL){
                TEMP2->random==TEMP1->random;
                
            }else{
                TEMP2->random=mp[TEMP1->random];
            }
            TEMP1=TEMP1->next;
            TEMP2=TEMP2->next;
        }
        return head2;
            
    }
};
//the idea is to basically make a list copy, and then use a map to store the random connections of the new nodes
//this is not complete yet, and i sleepy, so bye :)
