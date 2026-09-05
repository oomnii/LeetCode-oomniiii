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
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }
        queue<TreeNode*> q2;
        unordered_set<TreeNode*> visited;
        int dist = 0;
        q2.push(target);
        visited.insert(target);
        while(!q2.empty()){
            int sz = q2.size();
            if(dist==k) break;
            while(sz--){
                auto node = q2.front();
                q2.pop();
                if(parent[node]!= NULL && !visited.count(parent[node])){
                    q2.push(parent[node]);
                    visited.insert(parent[node]);
                }
                if(node->left && !visited.count(node->left)){
                    q2.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    q2.push(node->right);
                    visited.insert(node->right);
                }
            }
            dist++;
        }
        vector<int> result;
        while(!q2.empty()){
            int value = q2.front()->val;
            result.push_back(value);
            q2.pop();
        }
        return result;   
    }
};