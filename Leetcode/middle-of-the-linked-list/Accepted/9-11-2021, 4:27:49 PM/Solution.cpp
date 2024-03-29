// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr = head;
        int count = 0;
        while(ptr!=NULL) {
            ptr=ptr->next;
            count++;
        }
        int req = (count+2)/2;
        cout<<count<<" "<<req<<" ";
        count = 1;
        ptr = head;
        while(ptr!=NULL) {
            if(count == req)   { 
                return ptr;
            }
            
            count++;
            ptr = ptr->next;
        }
        
        return ptr;
    }
};