// https://leetcode.com/problems/house-robber-iii

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
    unordered_map<TreeNode*, int> mp;
public:
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left==NULL and root->right==NULL)
            return root->val;
        if(mp.find(root)!=mp.end())
            return mp[root];
        int left = (root->left == NULL ? 0 : (rob(root->left->left)+rob(root->left->right)));
        int right = (root->right == NULL ? 0 : (rob(root->right->right) + rob(root->right->left)));
        int ans1 = root->val + left + right;
        int ans2 = rob(root->left) + rob(root->right);
        return mp[root] = max(ans1, ans2);
    }
};