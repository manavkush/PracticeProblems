// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ptr = head;
        int cnt = 0;
        while(ptr) {
            ptr = ptr->next;
            cnt++;
        }
        k = k%cnt;
        
        if(k==0)    return head;
        ListNode* slow, *fast;
        slow = fast = head;
        
        for(int i=0;i<k;i++) {
            fast = fast->next;
        }
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ptr = slow->next;
        fast->next = head;
        slow->next = NULL;
        return ptr;
    }
    
};