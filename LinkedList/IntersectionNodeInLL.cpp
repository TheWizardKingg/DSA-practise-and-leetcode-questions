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
        ListNode* temp1 = headA;    //length of list A is unknown and length of list B is unknown as well as A.length != B.length
        ListNode* temp2 = headB;   //but A+B == B+A, so we make two pointers and traverse them on both lists,
                                   //as soon as they hit NULL in their respective lists, we put them onto the other list, 
        while(temp1 != temp2){        //so they would eventually meet at the intersection point or at NULL if there is no intersection at all.
            if(temp1 == NULL) temp1 = headB;
            else temp1 = temp1->next;

            if(temp2 == NULL) temp2 = headA;
            else temp2 = temp2->next;
        }
        return temp1;
    }
};