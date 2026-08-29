#include<iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL) return NULL;
        else if(head->next == NULL) return NULL;

        ListNode* temp = head;
        ListNode* slowPtr = head->next;
        ListNode* fastPtr = head->next->next;

        while(fastPtr != NULL && fastPtr->next != NULL){
            temp = temp->next;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        temp->next = slowPtr->next;
        delete(slowPtr);

        return head;
    }
};