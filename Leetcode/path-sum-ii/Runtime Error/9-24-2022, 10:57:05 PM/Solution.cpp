// https://leetcode.com/problems/path-sum-ii

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
    void util(TreeNode* root, int sum, vector<int> &curr, vector<vector<int>> &ans, int target) {
        sum += root->val;
        curr.push_back(root->val);
        
        if( (!root->right) and (!root->left) ) {
            if(target==sum)
                ans.push_back(curr);
        } 
        
        if(root->left) {
            util(root->left, sum, curr, ans, target);
        } 
        if(root->right) {
            util(root->right, sum, curr, ans, target);
        }
        curr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        util(root, 0, curr, ans, targetSum);
        return ans;
    }
};