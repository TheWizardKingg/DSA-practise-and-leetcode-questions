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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* oddPtr = head;
        ListNode* evenPtr = head->next;
        ListNode* firstEven = evenPtr;
        ListNode* lastOdd;

        while(true){
            if(oddPtr->next == NULL || evenPtr->next == NULL) break;
            oddPtr->next = oddPtr->next->next;
            oddPtr = oddPtr->next;
            lastOdd = oddPtr;

            evenPtr->next = evenPtr->next->next;
            evenPtr = evenPtr->next;
        }

        lastOdd->next = firstEven;

        return head;
    }
};