// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int util(TreeNode* root) {
        if(root==NULL) return 0;
        return max(util(root->left), util(root->right))+1;
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        int lev = util(root);
        return 1<<(lev-1);
    }
};