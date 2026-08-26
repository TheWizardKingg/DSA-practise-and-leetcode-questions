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
    ListNode* Reverse(ListNode* head){
        ListNode* temp1 = NULL;
        ListNode* temp2 = head;
        ListNode* temp3 = head->next;

        while(temp3 != NULL){
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3->next;
        }

        temp2->next = temp1;
        head = temp2;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        else if(head->next == NULL) return true;
    
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        ListNode* head2;

        while(true){
            if(fastPtr == NULL){
                head2 = Reverse(slowPtr);
                break;
            }else if(fastPtr->next == NULL){
                head2 = Reverse(slowPtr->next);
                break;
            }
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        slowPtr = head;

        while(head2 != NULL){
            if(slowPtr->val != head2->val) return false;
            head2 = head2->next;
            slowPtr = slowPtr->next;
        }

        return true;


    }
};