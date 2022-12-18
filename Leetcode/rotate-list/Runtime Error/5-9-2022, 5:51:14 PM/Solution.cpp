// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0)    return head;
        ListNode* slow, *fast;
        slow = fast = head;
        for(int i=0;i<k;i++) {
            fast = fast->next;
        }
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* ptr = slow->next;
        fast->next = head;
        slow->next = NULL;
        return ptr;
    }
    
};