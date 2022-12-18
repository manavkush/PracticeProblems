// https://leetcode.com/problems/merge-k-sorted-lists

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
private:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode();
        ListNode* ptr = head;
        while(a!=NULL || b!=NULL) {
            if(a==NULL) {
                ptr->next = b;
                b = b->next;
            } else if(b==NULL) {
                ptr->next = a;
                a = a->next;
            } else {
                if(a->val< b->val) {
                    ptr->next = a;
                    a = a->next;
                } else {
                    ptr->next = b;
                    b = b->next;
                }
            }
            ptr = ptr->next;
        }
        return head->next;
    }
    ListNode* mergeUtil(vector<ListNode*> &lists, int idx) {
        int n = lists.size();
        if(idx==n-1) {
            return lists[idx];
        } else {
            ListNode* next = mergeUtil(lists, idx+1);
            return merge(lists[idx], next);
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return NULL;
        }
        return mergeUtil(lists, 0);
    }
};