// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset< int>>> vec;  // col -> {row, val}
        
        queue<pair<TreeNode*, pair<int,int>>> q;    // row, col, node
        if(root)
            q.push({root, {0,0}});
        while(!q.empty()) {
            pair<TreeNode*, pair<int,int>> top = q.front();
            q.pop();
            
            TreeNode* node = top.first;
            int row = top.second.first, col = top.second.second;
            
            vec[col][row].insert(node->val);
            
            if(node->left) q.push({node->left, {row+1, col-1} });
            if(node->right) q.push({ node->right, {row+1, col+1} });
        }
        
        vector<vector<int>> ans;
        
        for(auto &i: vec) {
            vector<int> temp;
            for(auto &j: i.second) {
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};