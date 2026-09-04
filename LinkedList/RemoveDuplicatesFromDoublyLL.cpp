#include<iostream>
#include<unordered_set>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next; 
    ListNode* prev;
     
    ListNode(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
        unordered_set<int> st;
        ListNode* temp = head;

        while(temp != NULL){
            if (st.find(temp->val) != st.end()){

                ListNode* back = temp->prev;
                back->next = temp->next;

                if(temp->next != NULL){
                    temp->next->prev = back;
                }
                
                ListNode* tempDelNode = temp;
                temp = temp->next;
                delete(tempDelNode);

            }else{
             st.insert(temp->val);
                temp = temp->next;
            }
        }
        return head;
    }
};
