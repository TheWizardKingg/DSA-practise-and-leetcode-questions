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

        while(backward != end){    //traverse until backward pointer reaches the end instead of NULL, cause we are reversing the chunk, not the entire list
            main->next = backward;

            backward = main;
            main = forward;
            if(forward != NULL) forward = forward->next;
        }

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;  //we basically figure out the starting and ending points of the chunks to reverse them
        ListNode* end = head;
        ListNode* temp = head;   //main traversal pointer to traverse the linked list
        ListNode* nextEnd = head;   //another pointer to figure out the starting of the next portion to connect it with the previous reversed chunk

        bool firstList = true;   //special case only for the first chunk

        while(temp != NULL){
            start = temp;  //put start at the beginning of the chunk
            for(int i=1; i<k && temp != NULL; i++){    //skip to the end of the chunk, only if chunk has k elements, if chunk elements <k, then leave as it is
                temp = temp->next;
            }
            end = temp;   //put the end pointer at the end of the chunk

            if(end == NULL) break;  //if end pointer is NULL, hence current chunk doesn't contain enough elements, so we leave it as it is and break

            if(firstList){   //special case for the first chunk, to update the overall head for the entire modified linked list
                head = end;
                firstList = false;
            }

            temp = temp->next;    //move temp to the next chunk's starting position
            reverseLL(start, end);   //reverse the current chunk by this custom function

            nextEnd = temp;      //figure out the ending position of the next chunk (which will eventually become the starting position after its reversal)
            for(int j=1; j<k; j++){
                if(nextEnd == NULL){
                    nextEnd = temp;
                    break;
                }
                nextEnd = nextEnd->next;    
            }

            if(nextEnd == NULL) nextEnd = temp;  //if next chunk doesn't have enough elements, hence incomplete chunk doesn't need reversal, 
                                                // hence we just connect current chunk to the starting position of the next incomplete chunk
            start->next = nextEnd;    
            
        }
        return head;     //return head of the modified linked list after all the reversals
    }
};