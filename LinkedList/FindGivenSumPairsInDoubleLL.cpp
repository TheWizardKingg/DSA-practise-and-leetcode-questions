#include<iostream>
#include<vector>
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
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        if(head == NULL) return (vector<vector<int>>){};
        ListNode* i = head;
        ListNode* j = head;

        while(j->next != NULL && j->next->val <= target){
            j = j->next;
        }

        vector<vector<int>> answer;

        while(i != j && j != i->prev){
            
            if(i->val + j->val < target){
                i = i->next;
            }else if(i->val + j->val > target){
                j = j->prev;
            }else{
                answer.push_back((vector<int>){i->val, j->val});

                i = i->next;
                j = j->prev;
            }
        }
        return answer;
    }
};