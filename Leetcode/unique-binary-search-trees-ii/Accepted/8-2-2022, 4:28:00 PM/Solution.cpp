// https://leetcode.com/problems/unique-binary-search-trees-ii

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
    vector<TreeNode*> util(int l, int r) {
        vector<TreeNode*> vec;
        if(l>r) {
            vec.push_back(NULL);
            return vec;
        }
        for(int i=l;i<=r;i++) {
            
            vector<TreeNode*> left = util(l, i-1);
            vector<TreeNode*> right = util(i+1, r);
            for(auto x: left) {
                for(auto y: right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    vec.push_back(root);
                }
            }
        }
        return vec;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return util(1, n);
    }
};