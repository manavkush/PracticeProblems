// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        head->next = NULL;
        ListNode* ptr = head;
        
        while(l1!=NULL and l2!=NULL) {
            ListNode *temp = new ListNode;
            temp->next = NULL;
            if(l1->val<=l2->val) {
                temp->val = l1->val;
                l1=l1->next;
            } else {
                temp->val = l2->val;
                l2=l2->next;
            }
            ptr->next = temp;
            ptr = ptr->next;
        }
        while(l2!=NULL) {
                ptr->next = new ListNode;
                ptr->next->next =  NULL;
                ptr->next->val = l2->val;
                ptr=ptr->next;
                l2=l2->next;
        }
        while(l1!=NULL) {
            ptr->next = new ListNode;
            ptr->next->next = NULL;
            ptr->next->val = l1->val;
            ptr=ptr->next;
            l1=l1->next;
        }
        return head->next;
    }
};