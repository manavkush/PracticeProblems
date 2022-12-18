// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

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
    vector<int> res;
    void dfs2(TreeNode* root, int k) {
        if(!root)
            return;
        if(k==0) {
            res.push_back(root->val);
            return;
        }
        dfs2(root->left, k-1);
        dfs2(root->right, k-1);
    }
    int dfs(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return -1;
        if(root==target) {
            dfs2(root->left, k-1);
            dfs2(root->right, k-1);
            return 1;
        }
        int left = dfs(root->left, target, k);
        int right = dfs(root->right, target, k);
        if(left!=-1 and left<=k) {
            if(k==left) {
                res.push_back(root->val);
            } else {
                dfs2(root->right, k-left-1);
            }
        } else if(right!=-1 and right<=k) {
            if(k==right) {
                res.push_back(root->val);
            } else {
                dfs2(root->left, k-right-1);
            }
        } else {
            return -1;
        }
        return max(left, right)+1;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) {
            return vector<int> (1, target->val);
        }
        dfs(root, target, k);
        return res;
    }
};