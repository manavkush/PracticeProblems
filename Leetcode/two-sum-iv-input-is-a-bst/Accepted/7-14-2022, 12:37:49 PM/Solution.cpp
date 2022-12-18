// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool util(TreeNode* root, int k, unordered_map<int,int> &hash) {
        if(!root)
            return 0;
        int req = k - root->val;
        if(hash.find(req)!=hash.end()) 
            return true;
        hash[root->val] = 1;
        
        return util(root->left, k, hash) || util(root->right, k, hash);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> hash;
        return util(root, k, hash);
    }
};