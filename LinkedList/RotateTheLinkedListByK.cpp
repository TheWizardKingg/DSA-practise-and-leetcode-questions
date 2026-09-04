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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;    //if linked list is empty, no point rotating
        ListNode* temp = head;
        ListNode* originalHead = head;
        int size = 0;    
        while(temp != NULL){      //find the size of the linked list
            size++;
            temp = temp->next;
        }
        k = k%size;    //check how much rotation do we actually need to do (cause here, k is allowed to be greater than the size)
        if(k == 0) return originalHead;   //if actual k after mod comes out to be 0, then no point in rotating the list
        temp = head;
        for(int i=1; i<size-k; i++){     //skip to the node just before the new head after rotation
            temp = temp->next;
        }
        head = temp->next;    //update the pointer mappings
        temp->next = NULL;
        temp = head;
        while(temp->next != NULL){     //skip to the end of the rotated linked list
            temp = temp->next;
        }
        temp->next = originalHead;   //connect it to the original head of the linked list
        return head;     //return head of the rotated linked list
    }
};