// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int maxim;
    int util(TreeNode* root) {
        if(!root)   return 0;
        int left = util(root->left)+root->val;
        int right = util(root->right)+root->val;
        
        maxim = max(maxim, max(left, max(right, left+right-root->val)));
        return max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxim = INT_MIN;
        util(root);
        return maxim;
    }
    
};