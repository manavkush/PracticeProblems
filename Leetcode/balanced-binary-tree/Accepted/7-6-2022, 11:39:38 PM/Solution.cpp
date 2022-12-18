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
    bool flag = 1;
    int util(TreeNode* root) {
        if(!root)
            return 0;
        int left = util(root->left);
        int right = util(root->right);
        if(abs(left-right)>1) 
            flag = false;
        return max(left, right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        util(root);
        return flag;
    }
};