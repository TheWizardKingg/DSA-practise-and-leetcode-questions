#include<iostream>
using namespace std;
class ListNode{    //make the node class
public:      
    int val;
    ListNode* next;

    ListNode(int x){     //make the required constructor
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list
        ListNode* right = slow->next;
        slow->next = nullptr;

        // Sort both halves
        ListNode* left = sortList(head);
        right = sortList(right);

        // Merge sorted halves
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } 
            else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        if (left != nullptr)
            tail->next = left;

        if (right != nullptr)
            tail->next = right;

        return dummy.next;
    }
};