// https://leetcode.com/problems/balanced-binary-tree

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
    bool flag = 0;
    int util(TreeNode* root) {
        if(!root)   return 0;
        int left = util(root->left);
        int right = util(root->right);
        if(abs(left-right)<=1) {
            return max(left, right)+1;
        } else {
            return -1;
            flag = 1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)   return 1;
        util(root);
        return !flag;
    }
};