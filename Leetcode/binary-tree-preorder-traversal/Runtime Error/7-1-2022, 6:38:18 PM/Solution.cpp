// https://leetcode.com/problems/binary-tree-preorder-traversal

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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root) {
            ans.push_back(root->val);
            if(root->left) {
                TreeNode* temp = root->left;
                while(temp->right) {
                    temp = temp->right;
                }
                temp -> right = root->right;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
    }
};