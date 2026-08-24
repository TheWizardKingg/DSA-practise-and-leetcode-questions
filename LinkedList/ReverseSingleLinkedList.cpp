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
        if(head == NULL) return NULL;    //return NULL if list is empty
                                      //otherwise make three pointers
        ListNode* temp1 = NULL;        //first pointer (before the actual node which matters)
        ListNode* temp2 = head;       //the main pointer (actual node to work with)
        ListNode* temp3 = temp2->next;     //after the main node (to avoid losing the location to next node after connection mapping updation)

        while(true){
            temp2->next = temp1;       //just change the node mapping from next node to the node behind it
            temp1 = temp2;          //increment the previous pointer
            temp2 = temp3;        //increment the main pointer

            if(temp2 == NULL){     //then if the base case isn't here yet,
                head = temp1;
                return head;
            }

            temp3 = temp3->next;   //update the ahead pointer
        }

        return NULL;      //not ever gonna execute though
    }
};