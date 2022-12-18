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
        ListNode* headPlusk = head;
        for(int i=0;i<k;i++) {
            if(headPlusk==NULL)
                return head;
            headPlusk = headPlusk -> next;
        }
        ListNode*curr = head;
        ListNode*prev = NULL;
        while(curr!=headPlusk) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head->next = reverseKGroup(headPlusk, k);
        return prev;
    }
};