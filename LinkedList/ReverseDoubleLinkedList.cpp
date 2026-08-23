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

        if(head == NULL)
            return NULL;

        ListNode* A = head;
        ListNode* temp;

        while(true) {

            temp = A->prev;
            A->prev = A->next;
            A->next = temp;

            if(A->prev == NULL)
                break;

            A = A->prev;
        }

        return A;
    }
};

