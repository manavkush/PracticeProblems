// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another

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
    TreeNode* startNode = NULL;
    void dfs(TreeNode* &root, unordered_map<TreeNode*,TreeNode*> &hash, TreeNode* &parent, int startVal, int endVal) {
        if(!root)
            return;
        hash[root] = parent;
        if(root->val == startVal)
            startNode = root;
        dfs(root->left, hash, root, startVal, endVal);
        dfs(root->right, hash, root, startVal, endVal);
    }
    
    bool dfs2(TreeNode* &root, string &curr, unordered_map<TreeNode*,TreeNode*> &parent, unordered_map<TreeNode*,int> &vis, int endVal) {
        if(root->val==endVal)
            return true;
        if(root->left and vis.find(root->left)==vis.end()) {
            curr+='L';
            vis[root->left] = 1;
            if(dfs2(root->left, curr, parent, vis, endVal))
                return true;
            curr.pop_back();        
        }
        if(root->right and vis.find(root->right)==vis.end()) {
            curr += 'R';
            vis[root->right] = 1;
            if(dfs2(root->right, curr, parent, vis, endVal))
                return true;
            curr.pop_back();
        }
        if(parent[root] and vis.find(parent[root])==vis.end()) {
            curr+='U';
            vis[parent[root]] = 1;
            if(dfs2(parent[root], curr, parent, vis, endVal))
                return true;
            curr.pop_back();
        }
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* par = NULL;
        dfs(root, parent, par, startValue, destValue);
        
        unordered_map<TreeNode*, int> vis;
        vis[startNode] = 1;
        string curr;
        
        dfs2(startNode, curr, parent, vis, destValue);
        return curr;
    }
};