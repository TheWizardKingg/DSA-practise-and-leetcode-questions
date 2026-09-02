#include<iostream>
using namespace std;

class ListNode{
public: 
    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2){
            if(temp1 == NULL) temp1 = headB;
            else temp1 = temp1->next;

            if(temp2 == NULL) temp2 = headA;
            else temp2 = temp2->next;
        }
        return temp1;
    }
};