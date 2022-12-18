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
        map<Node*,Node*> hash;
        Node* prev = new Node(head->val);
        hash[head] = prev;
        Node* ret = prev;
        while(head) {
            if(head->random!=NULL) {
                if(hash.count(head->random)) {
                    prev->random = hash[head->random];
                } else {
                    Node* temp = new Node(head->random->val);
                    prev->random = temp;
                    hash[head->random] = temp;
                }
            }
            if(head->next!=NULL) {
                if(hash.count(head->next)) {
                    prev->next = hash[head->next];
                } else {
                    Node* temp = new Node(head->next->val);
                    prev->next = temp;
                    hash[head->next] = temp;
                }
            }
            head = head->next;
            prev = prev->next;
        }
        return ret;
    }
};