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
    Node* util(Node* node, map<Node*,Node*> &hash) {
        Node* curr = new Node(node->val);
        hash[node] = curr;

        for(auto &x: node->neighbors) {
            Node* ret;
            if(hash.find(x)==hash.end()) {
                ret = util(x, hash);
            } else {
                ret = hash[x];
            }
            curr->neighbors.push_back(ret);
        }
        return curr;
    }
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> hash;
        return util(node, hash);
    }
};