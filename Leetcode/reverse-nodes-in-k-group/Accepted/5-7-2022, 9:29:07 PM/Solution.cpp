// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) {
            return head;
        }
        int tot = 0;
        ListNode* ptr = head;
        while(ptr) {
            ptr = ptr->next;
            tot++;
        }
        ListNode* ret = new ListNode(0, head);
        ListNode* pre = ret;
        ListNode* curr = head;
        ListNode* nxt = curr->next;
        while(tot>=k) {
            
            curr = pre->next;
            nxt = curr->next;
            for(int i=1;i<k;i++) {
                curr->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = curr->next;
            }
            tot-=k;
            pre = curr;
        }
        
        return ret->next;
    }
};