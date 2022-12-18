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
    vector<int> dfs(TreeNode* root, int targetSum) {
        if(root==NULL)
            return vector<int>();
        // if(root->left == NULL and root->right == NULL)
        //     return vector<int> (1, root->val);
        
        vector<int> res;
        if(root->val == targetSum)
            cnt++;
        res.push_back(root->val);
        
        vector<int> left = dfs(root->left, targetSum);
        vector<int> right = dfs(root->right, targetSum);
        
        for(int i=0;i<left.size();i++) {
            int curr = left[i]+root->val;
            if(curr==targetSum)
                cnt++;
            res.push_back(left[i]+root->val);
        }
        for(int i=0;i<right.size();i++) {
            int curr = right[i]+root->val;
            if(curr==targetSum)
                cnt++;
            res.push_back(right[i]+root->val);
        }
        return res;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> sums;
        dfs(root, targetSum);
        return cnt;
    }
};