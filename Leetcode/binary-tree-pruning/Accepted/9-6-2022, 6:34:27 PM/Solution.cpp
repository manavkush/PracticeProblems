// https://leetcode.com/problems/binary-tree-pruning

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
    bool util(TreeNode* root) {
        if(!root) {
            return false;
        }
        bool left = util(root->left);
        bool right = util(root->right);
        bool present = left | right | (root->val==1);
        if(!left) root->left = NULL;
        if(!right) root->right = NULL;
        if(!present)
            return false;
        return true;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(util(root))
            return root;
        else return NULL;
    }
};