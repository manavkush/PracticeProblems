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
        if(head==NULL || head->next==NULL)  return head;
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* curr = head;
        ListNode* ans = dummy;
        ListNode* prev = dummy;
        ListNode* nxt = curr->next;
        int count = 0;
        while(curr!=NULL) {
            curr = curr->next;
            count++;
        }
        curr = head;
        while(count>=k) {
            curr = prev->next;
            nxt = curr->next;            
            for(int i=1;i<k;i++) {
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            
            prev = curr;

            count-=k;
        }
        return dummy->next;
    }
};