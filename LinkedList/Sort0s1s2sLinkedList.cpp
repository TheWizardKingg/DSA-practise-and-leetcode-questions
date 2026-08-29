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
    ListNode* sortList(ListNode* &head) {

        ListNode* temp0 = NULL;
        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;

        ListNode* dummy = head;

        ListNode* FirstZero = NULL;
        ListNode* FirstOne = NULL;
        ListNode* FirstTwo = NULL;

        while(dummy != NULL) {

            if(dummy->data == 0) {

                if(temp0 == NULL) {
                    temp0 = dummy;
                    FirstZero = dummy;
                }
                else {
                    temp0->next = dummy;
                    temp0 = dummy;
                }

            }
            else if(dummy->data == 1) {

                if(temp1 == NULL) {
                    temp1 = dummy;
                    FirstOne = dummy;
                }
                else {
                    temp1->next = dummy;
                    temp1 = dummy;
                }

            }
            else {

                if(temp2 == NULL) {
                    temp2 = dummy;
                    FirstTwo = dummy;
                }
                else {
                    temp2->next = dummy;
                    temp2 = dummy;
                }
            }

            dummy = dummy->next;
        }

        // Connect the three lists
        if(temp0 != NULL) {
            head = FirstZero;

            if(temp1 != NULL)
                temp0->next = FirstOne;
            else
                temp0->next = FirstTwo;
        }
        else if(temp1 != NULL) {
            head = FirstOne;
            temp1->next = FirstTwo;
        }
        else {
            head = FirstTwo;
        }

        if(temp1 != NULL && temp2 != NULL)
            temp1->next = FirstTwo;

        return head;
    }
};