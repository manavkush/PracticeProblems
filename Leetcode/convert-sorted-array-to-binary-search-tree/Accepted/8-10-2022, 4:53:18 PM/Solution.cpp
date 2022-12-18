// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    TreeNode* util(vector<int> &nums, int ii, int ff) {
        if(ii>ff)
            return NULL;
        if(ii==ff) {
            return new TreeNode(nums[ii]);
        }
        int mid = (ii+ff)/2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = util(nums, ii, mid-1);
        curr->right = util(nums, mid+1, ff);
        
        return curr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return util(nums, 0, n-1);
    }
};