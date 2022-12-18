// https://leetcode.com/problems/delete-node-in-a-linked-list

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
    void deleteNode(ListNode* node) {
        ListNode *head = node;
        node = node->next;
        head->val = node->val;
        head->next = node->next;
        // while(node->next!=NULL) {
        //     ListNode *temp = node->next;
        //     node->val = temp->val;
        //     if(node->next->next != NULL) {
        //         node = node->next;
        //     } else {
        //         break;
        //     }
        // }
        // ListNode *temp = node->next;
        // delete temp;
        // node->next = NULL;
        // return head;
    }
};