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
    TreeNode* util(vector<int>&preorder, int ii, int ff) {
        if(ii>ff)
            return NULL;
        TreeNode* curr = new TreeNode(preorder[ii]);
        int i;
        for(i=ii+1;i<=ff;i++) {
            if(preorder[i]>preorder[ii])
                break;
        }
        curr->left = util(preorder, ii+1, i-1);
        curr->right = util(preorder, i, ff);
        return curr;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return util(preorder, 0, preorder.size()-1);
    }
};