// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    int util(TreeNode* root, int high) {
        if(!root)
            return 0;
        if(root->val < high) {
            return 0 + util(root->left, high) + util(root->right, high);
        } else {
            high = max(high, root->val);
            return 1 + util(root->left, high) + util(root->right, high);
        }
    }
public:
    int goodNodes(TreeNode* root) {
        return util(root, INT_MIN);
    }
};