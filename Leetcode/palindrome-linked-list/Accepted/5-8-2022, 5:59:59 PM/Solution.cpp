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
        if(head==NULL || head->next == NULL) {
            return true;
        }
        int cnt = 0;
        ListNode* ptr = head;
        while(ptr) {
            ptr= ptr->next;
            cnt++;
        }
        ListNode* prev = NULL, *nxt = head->next;
        ptr = head;
        for(int i=0;i<cnt/2;i++) {
            ptr->next = prev;
            prev = ptr;
            ptr = nxt;
            nxt = nxt->next;
        }
        if(cnt&1) {
            ptr = ptr->next;
        }
        for(int i=0;i<cnt/2;i++) {
            if(ptr->val!=prev->val) {
                return false;
            } else {
                ptr= ptr->next;
                prev = prev->next;
            }
        }
        return true;
    }
};