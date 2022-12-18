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
        int count1, count2;
        count1 = count2 = 0;
        ListNode *ptr = headA;
        while(ptr!=NULL) {
            ptr=ptr->next;
            count1++;
        }
        ptr = headB;
        while(ptr!=NULL) {
            count2++;
            ptr = ptr->next;
        }
        int diff = count1 - count2;
        if(diff>0) {
            while(diff--) {
                headA = headA->next;
            }
        } else {
            while(diff<0) {
                headB = headB->next;
                diff++;
            }
        }
        while(headA!=NULL and headB!=NULL) {
            if(headA==headB) {
                return headA;
            } else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
};