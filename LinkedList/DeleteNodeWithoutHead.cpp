#include<iostream>
using namespace std;

class ListNode{
public:

    int val;
    ListNode* next;

    ListNode(int x, ListNode* nextNode){
        val = x;
        next = nextNode;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        while(temp->next->next != NULL){
            temp->val = temp->next->val;
            temp = temp->next;
        }
        
        temp->val = temp->next->val;
        temp->next = NULL;
    }
};