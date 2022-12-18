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
    unordered_map<long long,int> cache; // stores {sum : freq} from the root to the current node
    
    int dfs(TreeNode* root, long long curr, int targetSum) {
        if(root==NULL)
            return 0;
        
        curr += root->val;

        int cnt_node = 0;   // ending at curr node
        
        
        // cnt_node = cache[curr-targetSum];
        
        if(cache.find(curr-targetSum) != cache.end()) {
            cnt_node=cache[curr-targetSum];
        }
        cache[curr]++;
        
        int left = dfs(root->left, curr, targetSum);
        int right = dfs(root->right, curr, targetSum);
        
        cache[curr]--;
        return left + right + cnt_node;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        cache[0] = 1;
        return dfs(root, 0, targetSum);
    }
};