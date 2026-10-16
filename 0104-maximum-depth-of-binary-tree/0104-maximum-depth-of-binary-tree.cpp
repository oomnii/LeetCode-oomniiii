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
    int solve(TreeNode* root){
        if(!root->left && !root->right) return 1;
        int l = 0;
        if(root->left) l = solve(root->left);
        int r = 0;
        if(root->right) r = solve(root->right);
        return 1+max(l,r);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return solve(root);
    }
};