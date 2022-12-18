// https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()) {
            vector<int> temp;
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                Node* front = q.front(); q.pop();
                temp.push_back(front->val);
                for(int i=0;i<front->children.size();i++) {
                    if(front->children[i]) {
                        q.push(front->children[i]);
                    }
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};