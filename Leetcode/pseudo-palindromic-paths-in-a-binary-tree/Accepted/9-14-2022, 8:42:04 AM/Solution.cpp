// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

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
    int util(TreeNode* root, vector<int> &curr) {
        curr[root->val]++;
        int odds = 0;
        for(int i=1;i<=9;i++) {
            if(curr[i]&1)
                odds++;
        }
        int ans = 0;
        if(root->left==NULL and root->right==NULL) {
            curr[root->val]--;
            if(odds>1) {
                return 0;
            } else {
                return 1;
            }
        }
        if(root->left) ans += util(root->left, curr);
        if(root->right) ans += util(root->right, curr);
        curr[root->val]--;
        return ans;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> curr(10);
        return util(root, curr);
    }
};