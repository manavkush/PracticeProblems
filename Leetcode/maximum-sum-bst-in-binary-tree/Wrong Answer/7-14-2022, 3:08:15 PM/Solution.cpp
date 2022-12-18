// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree

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
#define pii pair<int,int>
class Solution {
private:
    pair<bool, int> util(TreeNode* root, int &sz, int low, int high) {
        if(!root)
            return {1, 0};
        if(low>high || root->val <low || root->val > high)
            return {0, 0};
        
        pair<bool,int> left = util(root->left, sz, low, root->val-1);
        pair<bool,int> right = util(root->right, sz, root->val+1, high);
        if(left.first and right.first) {
            int sum = left.second + right.second + root->val;
            sz = max(sz, sum);
            return {1, sum};
        } else {
            return {0, 0};
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        int sz = 0;
        util(root, sz, INT_MIN, INT_MAX);
        return sz;
    }
};