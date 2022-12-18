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
        
        ListNode* head = new ListNode;
        ListNode* ptr = head;
        ptr->next = NULL;
        
        int next = 0;
        
        while(l1!=NULL and l2!=NULL) {
            ptr->next = new ListNode;
            ptr->next->next = NULL;
            ptr=ptr->next;
            
            ptr->val = l1->val + l2->val + next;
            if(ptr->val > 9) {
                next = ptr->val/10;
                ptr->val %= 10;
            } else {
                next = 0;
            }
            l1= l1->next;
            l2= l2->next;
        }
        if(l1!=NULL) {
            ptr->next = new ListNode;
            ptr = ptr->next;
            ptr->next = NULL;
            
            ptr->val = l1->val+next;
            next = ptr->val/10;
            ptr->val %= 10;
            l1=l1->next;
        }
        if(l2!=NULL) {
            ptr->next = new ListNode;
            ptr = ptr->next;
            ptr->next = NULL;
            
            ptr->val = l2->val+next;
            next = ptr->val/10;
            ptr->val %= 10;
            l2=l2->next;
        }
        return head->next;
    }
};