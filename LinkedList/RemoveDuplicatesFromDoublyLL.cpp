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
        unordered_set<int> st;  //using an unordered set to store all the unique values of the linked list nodes
        ListNode* temp = head;   //unordered set uses hashing, hence O(1) time comp for insertion and searching unlike normal set which uses BST, O(logn)

        while(temp != NULL){
            if (st.find(temp->val) != st.end()){   //if value exists already, then just delete that particular node and update pointers accordingly

                ListNode* back = temp->prev;
                back->next = temp->next;

                if(temp->next != NULL){
                    temp->next->prev = back;
                }
                
                ListNode* tempDelNode = temp;
                temp = temp->next;
                delete(tempDelNode);

            }else{    //if value doesn't exist, then insert it into the unordered set and move forward
             st.insert(temp->val);
                temp = temp->next;
            }
        }
        return head;    //return head eventually
    }
};
