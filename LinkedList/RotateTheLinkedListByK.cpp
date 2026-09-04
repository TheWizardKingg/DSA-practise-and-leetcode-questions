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
        if(head == NULL) return NULL;
        ListNode* temp = head;
        ListNode* originalHead = head;
        int size = 0;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        k = k%size;
        if(k == 0) return originalHead;
        temp = head;
        for(int i=1; i<size-k; i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = originalHead;
        return head;
    }
};