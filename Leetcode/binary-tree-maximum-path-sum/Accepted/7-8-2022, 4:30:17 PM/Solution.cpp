// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    pair<int,int> util(TreeNode* root) {
        if(!root) {
            return {-1005, -1005};
        }
        pair<int,int> left = util(root->left);
        pair<int,int> right = util(root->right);
        
        int curr = max({left.first+ root->val, right.first+ root->val, root->val}) ;
        int high = max({left.second, right.second, curr, left.first+right.first+root->val});
        
        return {curr, high};
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        pair<int,int> temp = util(root);
        return temp.second;
    }
};