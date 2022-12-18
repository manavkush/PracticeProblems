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
        while(ptr1) {
            ptr1= ptr1->next;
            lenA++;
        }
        while(ptr2) {
            ptr2= ptr2->next;
            lenB++;
        }
        int diff = lenA-lenB;
        if(diff>=0) {
            
            while(diff--) {
                headA = headA->next;
            }
        } else {
            diff*=-1;
            while(diff--) {
                headB = headB->next;
            }
        }
        while(headA) {
            if(headA==headB) {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};