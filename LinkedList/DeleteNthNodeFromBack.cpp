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
        if(head == NULL || head->next == NULL) return NULL;    //edge case for only none or only one node in the list

        ListNode* fastPtr = head;

        for(int i=0; i<n; i++){     //skip the fastPtr N nodes 
            fastPtr = fastPtr->next;
        }

        ListNode* slowPtr = head;   //now start slowPtr from head

        while(true){     //update both pointers till fastPtr reaches the end, hence slow pointer will be N nodes behind fastPtr (aka Nth node from back)
            if(fastPtr == NULL){    //only occurs in case when n=LinkedListSize
                head = head->next;
                delete(slowPtr);
                break;
            }else if(fastPtr->next == NULL){   //occurs when n<LinkedListSize
                ListNode* temp = slowPtr->next;
                slowPtr->next = slowPtr->next->next;
                delete(temp);
                break;
            }
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        return head;     //return head after deletion


    }
};