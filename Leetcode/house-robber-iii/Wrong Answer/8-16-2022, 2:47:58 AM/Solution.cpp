// https://leetcode.com/problems/house-robber-iii

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
        if(!root)
            return {0, 0};
        // if(root->left==NULL and root->right==NULL)
        //     return {root->val, 0};
        pair<int,int> left = util(root->left);
        pair<int,int> right = util(root->right);
        pair<int,int> ret;
        ret.first = root->val+left.second+right.second;
        ret.second = left.first + right.first;
        return ret;
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> ans = util(root);
        return max(ans.first, ans.second);
    }
};