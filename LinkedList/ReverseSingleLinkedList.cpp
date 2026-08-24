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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode* temp1 = NULL;
        ListNode* temp2 = head;
        ListNode* temp3 = temp2->next;

        while(true){
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;

            if(temp2 == NULL){
                head = temp1;
                return head;
            }

            temp3 = temp3->next;
        }
    }
};