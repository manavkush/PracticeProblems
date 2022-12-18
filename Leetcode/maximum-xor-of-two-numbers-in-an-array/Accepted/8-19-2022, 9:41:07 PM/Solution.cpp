// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array

class Solution {

struct Node {
    Node* links[2];
    bool containsBit(int bit) {
        return (links[bit]!=NULL);
    }
    Node* get(int bit) {
        return links[bit];
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int value) {
        Node* node = root;
        for(int i=30;i>=0;i--) {
            int bit = (value>>i) & 1;
            if(node->containsBit(bit)==false) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int val) {
        Node* node = root;
        int curr = 0;

        for(int i=30;i>=0;i--) {
            int bit = (val>>i) & 1;
            if(node->containsBit(!bit)) {
                curr |= (1<<i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }
        return curr;
    }
};

public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie;
        for(auto &x: nums) {
            trie.insert(x);
        }
        int ans = 0;
        for(auto &x: nums) {
            ans = max(ans, trie.getMax(x));
        }
        return ans;
    }
};