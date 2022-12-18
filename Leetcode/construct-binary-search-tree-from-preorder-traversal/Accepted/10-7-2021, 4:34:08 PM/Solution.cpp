// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    TreeNode* util(vector<int> &preorder, int ii, int ff) {
        if(ii>ff) {
            return NULL;
        }
        TreeNode* ret = new TreeNode(preorder[ii]);
        auto f = lower_bound(preorder.begin()+ii+1, preorder.begin()+ff+1, preorder[ii])-preorder.begin();
        ret->left = util(preorder, ii+1, f-1);
        ret->right = util(preorder, f, ff);
        return ret;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return util(preorder, 0, preorder.size()-1);
    }
};