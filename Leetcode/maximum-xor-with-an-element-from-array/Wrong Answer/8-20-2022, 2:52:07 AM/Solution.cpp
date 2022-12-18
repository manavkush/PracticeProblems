// https://leetcode.com/problems/maximum-xor-with-an-element-from-array

class Solution {
struct Node {
    Node* links[2] = {};
    
    bool containsBit(int bit) {
        return links[bit]!=NULL;
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};
class Trie {
    public:
    Node * root;
    Trie() {
        root = new Node;
    }
    void insert(int val) {
        Node * node = root;
        for(int i=31;i>=0;i--) {
            int bit = (val>>i)&1;
            if(node->containsBit(bit)==false) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getMax(int val, int high) {
        Node* node = root;
        bool flag = 1;
        int ans = 0;
        for(int i=31;i>=0;i--) {
            int bit = (val>>i)&1;
            int highbit = (high>>i)&1;
            
            if(flag) {  // limitation of maximum
                if(highbit) {   // can take both 1 and 0
                    if(node->containsBit(!bit)) {
                        ans |= (1<<i);
                        if((!bit)==0) {
                            flag = 0;
                        }
                        node = node->get(!bit);
                    } else {
                        if(bit==0) {
                            flag = 0;
                        }
                        node = node->get(bit);
                    }
                } else {        // can only take 0
                    if(node->containsBit(0)) {
                        if(bit==1) {
                            ans |= (1<<i);
                        }
                        node = node->get(0);
                    } else {
                        if(bit==0) {
                            ans |= (1<<i);
                        }
                        node = node->get(1);
                    }
                }
            } else {
                if(node->containsBit(!bit)) {
                    node = node->get(!bit);
                    ans|= (1<<i);
                } else {
                    node = node->get(bit);
                } 
            }
        }
        return ans;
    }
};
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        for(auto &x: nums) {
            // cout<<"x"<<endl;
            trie.insert(x);
        }
        int lowest = *min_element(nums.begin(), nums.end());
        vector<int> ans;
        for(auto &x: queries) {
            if(x[1]<lowest) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(trie.getMax(x[0], x[1]));
        }
        return ans;
    }
};