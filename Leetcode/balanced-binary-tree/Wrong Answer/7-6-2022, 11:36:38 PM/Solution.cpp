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
    int util(TreeNode* root, bool &flag) {
        if(!root)
            return 0;
        int left = util(root->left, flag);
        int right = util(root->right, flag);
        if(abs(left-right)>1) 
            flag = false;
        return max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool flag = 1;
        util(root, flag);
        return flag;
    }
};