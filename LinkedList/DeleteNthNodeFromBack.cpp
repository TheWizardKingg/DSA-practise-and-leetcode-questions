#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* fastPtr = head;

        for(int i=0; i<n; i++){
            fastPtr = fastPtr->next;
        }

        ListNode* slowPtr = head;

        while(true){
            if(fastPtr == NULL){
                head = head->next;
                delete(slowPtr);
                break;
            }else if(fastPtr->next == NULL){
                ListNode* temp = slowPtr->next;
                slowPtr->next = slowPtr->next->next;
                delete(temp);
                break;
            }
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        return head;


    }
};