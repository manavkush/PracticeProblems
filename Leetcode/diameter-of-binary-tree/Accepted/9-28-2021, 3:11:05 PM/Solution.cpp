// https://leetcode.com/problems/diameter-of-binary-tree

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
    int diameter = 0;
public:
    int util(TreeNode* root) {
        if(!root)   return -1;
        else {
            int left = util(root->left)+1;
            int right = util(root->right)+1;
            diameter = max(diameter, left+right);
                        
            return max(left, right);
        }
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        
        int res = util(root);
        diameter = max(diameter, res);
        return diameter;
    }
};