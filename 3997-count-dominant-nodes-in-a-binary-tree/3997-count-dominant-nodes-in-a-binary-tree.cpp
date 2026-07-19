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
    int count;
    int solve(TreeNode* root){
        if (root == nullptr) {
            return INT_MIN;
        }

        int l = solve(root->left);
        int r = solve(root->right);
        int maxi = max(l,r);
        if(root->val >= maxi) count++;
        return max(root->val,maxi);
    }
    int countDominantNodes(TreeNode* root) {
        count = 0;
        int maxi = solve(root);
        return count;
    }
};