// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    void util(vector<int> &ans, TreeNode* root) {
        if(!root)
            return;
        util(ans, root->left);
        ans.push_back(root->val);
        util(ans, root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        util(ans, root);
        return ans;
    }
};