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
        ListNode* ret = new ListNode(0);
        ListNode* prevLast = ret;
        ListNode* first = head;
        ListNode* last = head;
        
        while(1) {
            bool avlb = true;
            // checking if k nodes are available to reverse
            for(int i=0;i<k-1;i++) {
                if(last==NULL || last->next==NULL) {
                    avlb = false;
                    break;
                }
                last = last->next;
            }
            if(!avlb) {
                prevLast->next = first;
                break;
            } 
            
            prevLast->next = last;
            ListNode* newPrev = first;
            last = last->next;
            
            for(int i=0;i<k;i++) {
                ListNode* temp = first->next;
                first->next = last;
                last = first;
                first = temp;
            }
            prevLast = newPrev;
            first = prevLast->next;
            last = prevLast->next;
        }
        return ret->next;
    }
};