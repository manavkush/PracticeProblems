// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private: 
    map<int, Node*> hash;
public:
    Node* cloneGraph(Node* node) {
        if(!node)   return NULL;
        vector<Node*> temp;
        Node *root = new Node(node->val);
        hash[node->val] = root;
        for(auto x: node->neighbors) {
            if(!hash.count(x->val)) {
                Node *ret = cloneGraph(x);
                hash[x->val] = ret;
                temp.push_back(ret);    
                
            } else {
                temp.push_back(hash[x->val]);
            }
        }
        root->neighbors = temp;
        return root;
    }
};