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
    void reverseLL(ListNode* start, ListNode* end){
        ListNode* backward = NULL;
        ListNode* main = start;
        ListNode* forward = start->next;

        while(backward != end){
            main->next = backward;

            backward = main;
            main = forward;
            if(forward != NULL) forward = forward->next;
        }

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = head;
        ListNode* temp = head;
        ListNode* nextEnd = head;

        bool firstList = true;

        while(temp != NULL){
            start = temp;
            for(int i=1; i<k && temp != NULL; i++){
                temp = temp->next;
            }
            end = temp;

            if(end == NULL) break;

            if(firstList){
                head = end;
                firstList = false;
            }

            temp = temp->next;
            reverseLL(start, end);

            nextEnd = temp;
            for(int j=1; j<k; j++){
                if(nextEnd == NULL){
                    nextEnd = temp;
                    break;
                }
                nextEnd = nextEnd->next;
            }

            if(nextEnd == NULL) nextEnd = temp;

            start->next = nextEnd;
            
        }
        return head;
    }
};