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

        while(fastPtr != NULL && fastPtr->next != NULL){  //if fastPtr ever reaches NULL, the list doesn't contain any loop
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr) break;   //if pointers collide, hence, we reset the pointers and update by one now

        }
        if(fastPtr == NULL || fastPtr->next == NULL) return NULL;    

        fastPtr = head;   //reset pointer to head

        while(slowPtr != fastPtr){   //update by one now, until both collide
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;

        }

        return slowPtr;   //return the node on which both the nodes collide
    }
};

