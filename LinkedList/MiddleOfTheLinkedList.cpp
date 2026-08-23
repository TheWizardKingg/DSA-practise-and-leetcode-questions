#include<iostream>
using namespace std;

class ListNode{
public:
    ListNode* prev;
    int data;
    ListNode* next;

    ListNode(int val){
        prev = NULL;   //Doubly linked list contains three things, data, previous pointer, next pointer
        data = val;
        next = NULL;
    }
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        if(head->next == NULL) return head;
        
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while(true){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            if(fastPtr == NULL || fastPtr->next == NULL) break;
        }

        return slowPtr;
    }
};