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
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(!root){
            return {0,0};
        }
        auto leftTree = solve(root->left);
        auto rightTree = solve(root->right);
        int sum = leftTree.first+rightTree.first+root->val;
        int Tnodes = leftTree.second+rightTree.second+1;
        if(root->val == sum/Tnodes) ans++;
        return {sum,Tnodes};
    }
    int averageOfSubtree(TreeNode* root) {
        auto p = solve(root);
        return ans;
    }
};