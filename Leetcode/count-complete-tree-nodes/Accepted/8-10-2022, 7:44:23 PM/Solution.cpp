// https://leetcode.com/problems/count-complete-tree-nodes

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
    int calcHeight(TreeNode* root) {
        if(!root) return -1;
        return max(calcHeight(root->left), calcHeight(root->right))+1;
    }
    bool check(TreeNode* root, int l, int r, int x, int height) {
        if(height==0) {
            return root!=NULL;
        }
        int mid = (l+r)/2;
        if(x<=mid)
            return check(root->left, l, mid, x, height-1);
        else
            return check(root->right, mid+1, r, x, height-1);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int height = calcHeight(root);
        if(height==0) 
            return 1; 
        int total = pow(2,height)-1;
        int l = 1;
        int r = pow(2, height)+1;
        int lastRow = pow(2,height);
        
        while(l+1<r) {
            int mid = (r-l)/2 + l;
            if(check(root,1, lastRow, mid, height)) {
            // if(1) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return total+l;
    }
};