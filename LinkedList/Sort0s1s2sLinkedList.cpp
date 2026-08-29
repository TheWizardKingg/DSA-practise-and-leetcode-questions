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

        ListNode* temp0 = NULL;    //to keep track of the last node containing zero
        ListNode* temp1 = NULL;    //to keep track of the last node containing one
        ListNode* temp2 = NULL;    //to keep track of the last node containing two

        ListNode* dummy = head;    //dummy node for linked list traversal

        ListNode* FirstZero = NULL;   //to keep track of first node containing zero to connect head to this node later
        ListNode* FirstOne = NULL;    //to keep track of first node contining one to connect zero's last node to this node
        ListNode* FirstTwo = NULL;   //to keep track of first node containing two to connect one's last node to this node
 
        while(dummy != NULL) {

            if(dummy->data == 0) {   //if current node is zero, then save it, update temp0

                if(temp0 == NULL) {
                    temp0 = dummy;
                    FirstZero = dummy;
                }
                else {
                    temp0->next = dummy;
                    temp0 = dummy;
                }

            }
            else if(dummy->data == 1) {   //if current node is 1 then save it, update temp1

                if(temp1 == NULL) {
                    temp1 = dummy;
                    FirstOne = dummy;
                }
                else {
                    temp1->next = dummy;
                    temp1 = dummy;
                }

            }
            else {     //if current node is 2, then save it and update temp2

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