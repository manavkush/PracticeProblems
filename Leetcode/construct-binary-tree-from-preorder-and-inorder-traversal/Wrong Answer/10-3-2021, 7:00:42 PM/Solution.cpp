// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    TreeNode* util(vector<int> &preorder, vector<int> &inorder, int x, int ii, int ff) {
        if(ii>ff) {
            return NULL;
        }
        if(ii==ff) {
            return new TreeNode(inorder[ii]);
        } else {
            TreeNode* left;
            TreeNode* right;
            int i;
            for(i=ii; i<=ff;i++) {
                if(inorder[i]==preorder[x]) {
                    break;
                }
            }
            left = util(preorder, inorder, x+1, ii, i-1);
            right = util(preorder, inorder, i+1, i+1, ff);
            return new TreeNode(preorder[x], left, right);
        }
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* dummy = util(preorder, inorder, 0, 0, inorder.size()-1);
        return dummy;
    }
};