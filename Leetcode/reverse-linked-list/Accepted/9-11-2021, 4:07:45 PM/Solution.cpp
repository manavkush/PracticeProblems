// https://leetcode.com/problems/reverse-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)  return head;
        ListNode *prev = NULL;
        ListNode * ptr = head;
        
        while(ptr!=NULL) {
            ListNode *temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr=temp;            
        }
        return prev;
    }
};