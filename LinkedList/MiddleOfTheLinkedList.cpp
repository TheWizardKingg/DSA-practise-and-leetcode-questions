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
        
        ListNode* slowPtr = head;   //slow pointer which increases linearly
        ListNode* fastPtr = head;   //fast pointer which increases with twice the slowPtr's speed by skipping one node 

        while(true){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            if(fastPtr == NULL || fastPtr->next == NULL) break;     //either fastPtr becomes NUll or stands just before null(aka last node), reutrn slowPtr
        }

        return slowPtr;
    }
};