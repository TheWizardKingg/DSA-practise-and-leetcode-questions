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
        if(head == NULL || head->next == NULL) return head;   //edge case where list contains zero or only one element 
        ListNode* oddPtr = head;
        ListNode* evenPtr = head->next;
        ListNode* lastOdd = oddPtr;
        ListNode* firstEven = evenPtr;

        while(true){
            if(oddPtr->next == NULL || evenPtr->next == NULL) break;
            oddPtr->next = oddPtr->next->next;   //keep mapping all the odd nodes together
            oddPtr = oddPtr->next;
            lastOdd = oddPtr;    //keep track of the last odd node in order to connect it with the first even node 

            evenPtr->next = evenPtr->next->next;       //keep mapping all the even nodes together
            evenPtr = evenPtr->next;    //update the even pointer as well
        }

        lastOdd->next = firstEven;    // at last, connect the lastOdd mapping to first Even node, hence all the linked list has been separated 

        return head;   //return head finally
    }
};