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
        if(head == NULL) return (vector<vector<int>>){};  //if linked list is empty, then return empty vector

        ListNode* i = head;    //using two pointers approach in linked lists
        ListNode* j = head;

        while(j->next != NULL && j->next->val <= target){   //place the end/j pointer at the node having value <= target
            j = j->next;
        }

        vector<vector<int>> answer;

        while(i != j && j != i->prev){     //now check if i+j == target, if yes then save the pair and shrink the pointers
            
            if(i->val + j->val < target){   //if pair sum < target, then push the start pointer forward (as we need to increase the sum)
                i = i->next;
            }else if(i->val + j->val > target){    //if pair sum > target, then push the end pointer backwards (as we need to decrease the sum)
                j = j->prev;
            }else{    //if pair sum == target, save the pair and shrink both pointers
                answer.push_back((vector<int>){i->val, j->val});   

                i = i->next;
                j = j->prev;
            }
        }
        return answer;   //return all the pair's vector as vector of vector
    }
};