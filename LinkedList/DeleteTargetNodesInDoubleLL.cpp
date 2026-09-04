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

        ListNode* prev = main->prev;
        ListNode* next = main->next;

        if(prev != NULL){
            prev->next = next;
        }else{
            head = next;
        }
        
        if(next != NULL){
            next->prev = prev;
        }

        delete(main);

        main = next;
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