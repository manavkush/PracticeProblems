// https://leetcode.com/problems/delete-nodes-and-return-forest

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
    void dfs(TreeNode* root, unordered_map<int,int> &hash, vector<TreeNode*> &ans, int prev) {
        if(!root)
            return;
        if(hash.find(root->val)!=hash.end()) {
            // deleted
            dfs(root->left, hash, ans, 0);
            dfs(root->right, hash, ans, 0);
            root->left = NULL;
            root->right=NULL;
        } else {
            if(prev) {
                dfs(root->left, hash, ans, 1);
                dfs(root->right, hash, ans, 1);
            } else {
                dfs(root->left, hash, ans, 1);
                dfs(root->right, hash, ans, 1);
                ans.push_back(root);
            }
            if(root->left and hash.find(root->left->val)!=hash.end()) {
                root->left = NULL;
            } 
            if(root->right and hash.find(root->right->val)!=hash.end()) {
                root->right = NULL;
            }
        }
        
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_map<int,int> hash;
        int n = to_delete.size();
        for(auto &x: to_delete) {
            hash[x]++;
        }
        dfs(root, hash, ans, 0); 
        return ans;
    }
};