// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next == NULL) {
            return true;
        }
        int cnt = 0;
        ListNode* ptr = head, *slow = head, *fast = head;
        while(fast->next!=NULL and fast->next->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* curr = slow->next;
        ListNode* next = curr->next;
        while(next) {
            curr->next = next->next;
            next->next = slow->next;
            slow->next = next;
            next = curr->next;
        }

        slow = slow->next;
        while(slow) {
            if(slow->val !=  head->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};