// https://leetcode.com/problems/validate-binary-search-tree

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
    bool util(TreeNode * root, int min, int max) {
        if(!root)   return true;
        if(root->val>=max)  return false;
        if(root->val<=min)  return false;
        return util(root->left, min, root->val) && util(root->right, root->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return (util(root->left, INT_MIN, root->val) && util(root->right, root->val, INT_MAX));
    }
};