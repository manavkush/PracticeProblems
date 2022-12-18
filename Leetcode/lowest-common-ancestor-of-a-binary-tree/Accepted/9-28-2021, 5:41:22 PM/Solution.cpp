// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
        map<TreeNode*, TreeNode*> parent;
        void util(TreeNode* root) {
            if(root->left)  {
                parent[root->left] = root;
                util(root->left);
            }
            if(root->right) {
                parent[root->right] = root;
                util(root->right);
            }
            
        }
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            parent[root] = NULL;
            util(root);
            TreeNode *curr = p;
            map<TreeNode*, int> path;
            while(curr!=NULL) {
                path[curr]++;
                curr = parent[curr];
            }
            curr = q;
            while(path.find(curr)==path.end()) {
                curr = parent[curr];
            }
            return curr;
        }
};