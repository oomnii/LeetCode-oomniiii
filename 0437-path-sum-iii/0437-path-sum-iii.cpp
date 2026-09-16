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
    unordered_map<long long, int> mp;

    void dfs(TreeNode* root, long long sum, int target) {
        if (!root) return;

        sum += root->val;

        // Previous prefix sum = sum - target
        if (mp.count(sum - target))
            ans += mp[sum - target];

        mp[sum]++;

        dfs(root->left, sum, target);
        dfs(root->right, sum, target);

        // Backtrack
        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;   // path starting from root
        dfs(root, 0, targetSum);
        return ans;
    }
};