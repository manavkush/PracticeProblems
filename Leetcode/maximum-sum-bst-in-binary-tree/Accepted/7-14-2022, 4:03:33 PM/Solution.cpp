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
struct node {
    public:
    int low, high, size;
    node(int low, int high, int size) {
        this->size = size;
        this->high = high;
        this->low = low;
    }
};

class Solution {
private:
    int sz = 0;
    node util(TreeNode* root) {
        if(!root)
            return node(INT_MAX, INT_MIN, 0);
        
        node left = util(root->left);
        node right = util(root->right);
        if(root->val > left.high and root->val < right.low) {
            sz = max(sz, left.size+right.size+root->val);
            return node(min(left.low, root->val), max(right.high, root->val), left.size + right.size + root->val);
        }
        return node(INT_MIN, INT_MAX, 0);
    }
public:
    int maxSumBST(TreeNode* root) {
        util(root);
        return sz;
    }
};