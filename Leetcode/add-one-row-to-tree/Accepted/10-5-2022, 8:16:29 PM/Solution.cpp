// https://leetcode.com/problems/add-one-row-to-tree

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
    TreeNode* util(TreeNode* root, int val, int depth) {
        if(!root)
            return NULL;
        if(depth==2) {
            root->left = new TreeNode(val, root->left, NULL);
            root->right = new TreeNode(val, NULL, root->right);
            return root;
        }
        root->left = util(root->left, val, depth-1);
        root->right = util(root->right, val, depth-1);
        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
            TreeNode* newroot = new TreeNode(val, root, NULL);
            return newroot;
        }
        return util(root, val, depth);
    }
};