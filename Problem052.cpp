#include<iostream>
using namespace std;
struct ListNode{
    int data;
    ListNode* next;
};

void untangleList(ListNode *head){
    ListNode* slow=head;
    ListNode* fast=head;
    bool found=false;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if (fast==slow){
            found=true;
            break;
        }
    }
    if (found!=true){
        return ;
    }
    
    slow=head;
    ListNode* temp;
    while(slow!=fast){
        slow=slow->next;
        temp=fast;
        fast=fast->next;
    }
    temp->next=NULL;
}

int main(){
    return 0;
}