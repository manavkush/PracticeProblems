// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        while(ptr1!=ptr2) {
            ptr1= ptr1->next;
            ptr2=ptr2->next;
            
            if(!ptr1) {
                ptr1 = headB;
            }
            if(!ptr2) {
                ptr2 = headA;
            }
        }
        
        return ptr1;
    }
};