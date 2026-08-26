#include<iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;

    ListNode(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while(fastPtr != NULL && fastPtr->next != NULL){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr) break;

        }
        if(fastPtr == NULL || fastPtr->next == NULL) return NULL;

        fastPtr = head;

        while(slowPtr != fastPtr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;

        }

        return slowPtr;
    }
};

