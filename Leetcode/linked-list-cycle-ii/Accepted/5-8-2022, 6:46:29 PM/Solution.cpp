// https://leetcode.com/problems/linked-list-cycle-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next == head) return head;
        else if(head->next==NULL) return NULL;
        
        ListNode *fast = head, *slow = head;
        bool flag = false;
        do {
           fast = fast->next->next;
           slow = slow->next;
            if(fast == slow) {
                flag = true;
                break;
            }
        } while(fast!=NULL and fast->next!=NULL);
        if(flag) {
            slow = head;
            while(slow!=fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        } else {
            return NULL;
        }
    }
};