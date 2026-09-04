#include<iostream>
using namespace std;

class ListNode{
public:
    ListNode* prev;
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        prev = NULL;
        next = NULL;
    }
};

class Solution {
public:
    void DelThisNode(ListNode*& head, ListNode*& main){

        ListNode* prev = main->prev;   //we'll need previous and next nodes for pointer deletions
        ListNode* next = main->next;

        if(prev != NULL){    //if main is not the first node, then we can safely update previous node's next pointer to the node after main     
            prev->next = next;
        }else{               //if main is the first node, then we simply need to update the head pointer to the node next to main
            head = next;
        }
        
        if(next != NULL){        //if main is not the last node, then we can safely update next node's previous pointer to the node before main
            next->prev = prev;
        }    

        delete(main);

        main = next;     //update main once
    }
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        ListNode* originalHead = head;  
        ListNode* main = head;

        while(main != NULL){
            if(main->val == target) DelThisNode(head, main);    
            else main = main->next;
        }
        return head;
    }
};