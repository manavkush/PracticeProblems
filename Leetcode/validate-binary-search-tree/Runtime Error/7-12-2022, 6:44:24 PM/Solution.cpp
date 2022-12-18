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
private:
    bool util(TreeNode* root, int low, int high) {
        if(!root)
            return true;
        int val = root->val;
        if(low > high || val<low || val>high )
            return false;
        return util(root->left, low, val-1) and util(root->right, val+1, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return util(root, INT_MIN, INT_MAX);
    }
};