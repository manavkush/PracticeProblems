// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *p = head;
        while(p!=NULL) {
            cnt++;
            p=p->next;
        }
        p =head;
        int req = cnt - n;
        if(req == 0) return head->next;
        cnt = 1;
        while(p->next!=NULL) {
            if(cnt==req) {
                ListNode *temp = p->next;
                p->next = temp->next;
                delete temp;
                return head;
            } else {
                p = p->next;
                cnt++;
            }
        }
        return head;
        
    }
};