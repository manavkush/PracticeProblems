// https://leetcode.com/problems/distribute-coins-in-binary-tree

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
        
        pair<int,int> left = util(root->left);
        pair<int,int> right = util(root->right);
        int balance = left.first + right.first+ root->val - 1;
        int moves = abs(left.first) + abs(right.first);
        return {balance, moves};
    }
public:
    int distributeCoins(TreeNode* root) {
        int balance = 0;
        return util(root).second;
    }
};