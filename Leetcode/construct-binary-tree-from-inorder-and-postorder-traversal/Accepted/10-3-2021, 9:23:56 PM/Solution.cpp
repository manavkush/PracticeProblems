// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    TreeNode* util(vector<int> &postorder, vector<int> &inorder, int x, int ii, int ff) {
        if(ii>ff) {
            return NULL;
        } else {
            TreeNode* left;
            TreeNode* right;
            int pos;
            for(pos=ii; pos<=ff;pos++) {
                if(inorder[pos]==postorder[x]) {
                    break;
                }
            }
            left = util(postorder, inorder, x-(ff-pos)-1, ii, pos-1);
            right = util(postorder, inorder, x-1, pos+1, ff);
            return new TreeNode(postorder[x], left, right);
        }
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* dummy = util(postorder, inorder, postorder.size()-1, 0, inorder.size()-1);
        return dummy;
    }
};