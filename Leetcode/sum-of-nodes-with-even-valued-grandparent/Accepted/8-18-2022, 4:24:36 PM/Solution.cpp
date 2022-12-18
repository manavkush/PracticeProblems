// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent

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
    int util(TreeNode* root, int par, int grand) {
        if(!root)
            return 0;
        int sum = 0;
        if(grand)
            sum = root->val;
        sum += util(root->left, ((root->val) & 1)==0, par);
        sum += util(root->right, ((root->val)& 1)==0, par);
        return sum;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return util(root, 0, 0);
    }
};