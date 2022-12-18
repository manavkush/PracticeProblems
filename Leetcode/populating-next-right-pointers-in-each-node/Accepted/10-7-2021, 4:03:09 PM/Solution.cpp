// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node *> q;
        q.push(root);
        int curr = 0;
        int nodes = 1;
        while(!q.empty()) {
            Node *top = q.front();
            q.pop();
            curr++;
            if(top->left)
                q.push(top->left);
            if(top->right)
                q.push(top->right);
            if(curr==nodes) {
                curr = 0;
                nodes = q.size();
            } else {
                top->next = q.front();
            }
        }
        return root;
        
    }
};