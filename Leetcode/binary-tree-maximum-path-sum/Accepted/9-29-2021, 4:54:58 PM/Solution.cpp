// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int maxim;
    int util(TreeNode* root) {
        if(!root)   return 0;
        int left = util(root->left);
        int right = util(root->right);
        
        if(left<0 and right<0)  {
            maxim = max(maxim, root->val);
            return root->val;
        }
        
        int ret = max(left, right)+root->val;
        maxim = max(maxim, max(ret, left+right+root->val));
        // cout<<maxim<<" "<<left<<" "<<right<<endl;
        return ret;
    }
public:
    int maxPathSum(TreeNode* root) {
        maxim = INT_MIN;
        util(root);
        return maxim;
    }
    
};