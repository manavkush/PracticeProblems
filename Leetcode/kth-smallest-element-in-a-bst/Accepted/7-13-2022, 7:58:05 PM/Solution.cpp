// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    void util(TreeNode* root, int k, int &curr, int &val) {
        if(!root)
            return;
        util(root->left, k, curr, val);
        curr++;
        if(curr==k) {
            val = root->val;
            return;
        }
        util(root->right, k, curr, val);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int val, curr = 0;
        util(root, k, curr, val);
        return val;
    }
};