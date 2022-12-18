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
    int util(TreeNode* root, int pick) {
        if(root==NULL)
            return 0;
        int sum;
        if(pick==1) {
            sum = util(root->left, 0) + util(root->right, 0);
        } else {
            int ans1 = root->val + util(root->left, 1)+util(root->right, 1);
            int ans2 = util(root->left, 0) + util(root->right, 0);
            sum = max(ans1, ans2);
        }
        return sum;
    }
public:
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        return util(root, 0);
    }
};