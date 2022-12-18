// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return NULL;
        }
        Node* ptr = head;
        while(ptr) {
            Node* temp = ptr->next;
            ptr->next = new Node(ptr->val);
            ptr->next->next = temp;
            ptr = temp;
        }
        ptr = head;
        while(ptr) {
            if(ptr->random!=NULL) {
                Node* copy = ptr->next;
                Node* random_copy = ptr->random->next;
                copy->random = random_copy;
            }
            ptr = ptr->next->next;
        }
        Node* dummy = new Node(0);
        ptr = dummy;
        while(head and head->next) {
            ptr->next = head->next;
            head->next = head->next->next;
            ptr = ptr->next;
            head = head->next;
        }
        return dummy->next;
    }
};