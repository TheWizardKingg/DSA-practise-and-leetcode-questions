#include<iostream>
using namespace std;

class ListNode{
public:
    ListNode* prev;
    int data;
    ListNode* next;

    ListNode(int x){
        prev = NULL;
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {

        if(head == NULL)   //avoid the empty linked list edge case
            return NULL;
   
        ListNode* A = head;   //make two pointers, one on original head (final ending node)
        ListNode* temp;      //make another pointer to basically act as the third variable to swap the connections

        while(true) {

            temp = A->prev;   //temporarily store the prev value of current node (current node = A)
            A->prev = A->next;    //update the prev pointer 
            A->next = temp;    //update the next pointer

            if(A->prev == NULL)   //basically if A is on the last node of original list (or first node of the reversed list)
                break;

            A = A->prev;   //otherwise keep updating
        }

        return A;   //return A as the new head of the reversed linked list
    }
};

