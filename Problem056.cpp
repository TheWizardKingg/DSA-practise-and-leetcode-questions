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
    void insert(ListNode* &head, int x){
        ListNode* newnode= new ListNode(x);
        ListNode* TEMP=head;
        if (TEMP==NULL){
            TEMP=newnode;
        }else{
            while(TEMP->next!=NULL){
                TEMP=TEMP->next;
            }
            TEMP->next=newnode;
            TEMP=TEMP->next;
        }
        TEMP->val=x;
        TEMP->next=NULL;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3=NULL;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val < temp2->val){
                insert(list3,temp1->val);
                temp1=temp1->next;
            }else if(temp1->val >= temp2->val){
                insert(list3,temp2->val);
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
            insert(list3,temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            insert(list3,temp2->val);
            temp2=temp2->next;
        }
        return list3;
        
    }
};

//This is not complete yet, i will complete it soon