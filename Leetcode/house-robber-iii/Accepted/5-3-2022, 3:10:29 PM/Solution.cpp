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
    pair<int,int> util(TreeNode* root) {
        if(root==NULL)
            return {0,0};
        pair<int,int> ret,left,right;
        left = util(root->left);
        right = util(root->right);
        ret.first = root->val + left.second + right.second;
        ret.second = max(left.first, left.second) + max(right.first, right.second);
        return ret;
    }
public:
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        pair<int,int> ans = util(root);
        return max(ans.first, ans.second);
    }
};