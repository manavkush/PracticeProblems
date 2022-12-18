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
    unordered_map<long long,int> cache; // stores {sum : freq} from the root to the current node
    void dfs(TreeNode* root, long long curr, int targetSum) {
        if(root==NULL)
            return;
        
        curr+=root->val;
        cache[curr]++;
        
        if(cache.find(curr-targetSum)!=cache.end()) {
            cnt+=cache[curr-targetSum];
        }
        dfs(root->left, curr, targetSum);
        dfs(root->right, curr, targetSum);
        cache[curr]--;
        return;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        cache[0] = 1;
        dfs(root, 0, targetSum);
        if(targetSum==0) return cnt-1;
        return cnt;
    }
};