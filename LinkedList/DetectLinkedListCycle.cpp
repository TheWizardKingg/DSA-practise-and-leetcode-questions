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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;    //base case for lists containing only one or two elements (can't have loops)

        ListNode* slowPtr = head;   //slow pointer
        ListNode* fastPtr = head;   //fast pointer

        while(fastPtr != NULL && fastPtr->next != NULL){    //unless the fastpointer becomes NULL or reaches the end node, run the loop

            slowPtr = slowPtr->next;      //increment slow pointer by one node
            fastPtr = fastPtr->next->next;    //fast pointer moves at twice as fast as slow pointer
            
            if(slowPtr == fastPtr) return true;       //if loop exists then at some point of time, both of the pointers are sure to coincide (aka true)
        }
            

        return false;    //return false if fast pointer has reached the end and still hasn't coincided with the slow pointer yet
    }
};

