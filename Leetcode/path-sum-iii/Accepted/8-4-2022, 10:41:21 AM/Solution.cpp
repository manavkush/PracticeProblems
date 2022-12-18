// https://leetcode.com/problems/path-sum-iii

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
    int cnt = 0;
    vector<long long> dfs(TreeNode* root, long long targetSum) {
        if(root==NULL)
            return vector<long long>();
        
        vector<long long> res;
        if(root->val == targetSum)
            cnt++;
        res.push_back(root->val);
        
        vector<long long> left = dfs(root->left, targetSum);
        vector<long long> right = dfs(root->right, targetSum);
        
        for(int i=0;i<left.size();i++) {
            long long curr = left[i]+root->val;
            if(curr==targetSum)
                cnt++;
            res.push_back(left[i]+root->val);
        }
        for(int i=0;i<right.size();i++) {
            long long curr = right[i]+root->val;
            if(curr==targetSum)
                cnt++;
            res.push_back(right[i]+root->val);
        }
        return res;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return cnt;
    }
};