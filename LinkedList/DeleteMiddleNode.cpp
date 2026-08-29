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
        if(head == NULL) return NULL;      //edge case for 0 element in the list
        else if(head->next == NULL) return NULL;       //edge case for 1 element in the list (this one is imp cause otherwise it will throw error for fastPtr declaration)

        ListNode* temp = head;    //this time we want to delete the middle node after finding it, hence we shall maintain a pointer behind the deletion node
        ListNode* slowPtr = head->next;    //slowPtr will be the deletion node 
        ListNode* fastPtr = head->next->next;   //it will update until it reaches the end 

        while(fastPtr != NULL && fastPtr->next != NULL){   //update pointers until fastPtr reaches the end
            temp = temp->next;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        temp->next = slowPtr->next;    //update node mapping
        delete(slowPtr);      //delete the required node

        return head;     //return head;
    }
};