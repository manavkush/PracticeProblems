// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next ==NULL) {
            return head;
        }
        ListNode* curr = head;
        int count = 0;
        while(curr!=NULL) {
            count++;
            curr = curr->next;
        }
        int cnt = 0;
        curr = head;
        ListNode* prev = NULL;
        while(cnt<count/2) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            cnt++;
        }
        if(count&1) {
            curr=curr->next;
        }
        while(curr!=NULL) {
            if(curr->val != prev->val)  return false;
            curr = curr->next;
            prev = prev->next;
        }
        return true;
        
    }
};