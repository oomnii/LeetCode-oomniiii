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
    pair<int,int> solve(TreeNode* root){
        if(!root){
            return {0,0};
        }
        auto leftAns = solve(root->left);
        auto rightAns = solve(root->right); 
        return {root->val+leftAns.second+rightAns.second , max(leftAns.first, leftAns.second)+
                                                            max(rightAns.first, rightAns.second)};
    }
    int rob(TreeNode* root) {
        auto ans = solve(root);
        return max(ans.first,ans.second);
    }
};