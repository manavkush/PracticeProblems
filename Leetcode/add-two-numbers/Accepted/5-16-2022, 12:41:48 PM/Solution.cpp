// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= new ListNode();
        ListNode* ptr = head;
        int prev = 0;
        while(l1 and l2) {
            int sum = prev + l1->val + l2->val;
            ptr->next = new ListNode(sum%10);
            prev = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            ptr = ptr->next;
        }
        while(l1) {
            int sum = prev + l1->val;
            ptr->next = new ListNode(sum%10);
            prev = sum/10;
            l1 = l1->next;
            ptr = ptr->next;
        } 
        while(l2) {
            int sum = prev + l2->val;
            ptr->next = new ListNode(sum%10);
            prev = sum/10;
            l2 = l2->next;
            ptr=ptr->next;
        }
        if(prev) {
            ptr->next = new ListNode(prev);
        }
        return head->next;
    }
};