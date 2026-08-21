/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> result;
    void dfs(Node* root){
        if(root==NULL) return;
        result.push_back(root->val);
        for(auto &child:root->children){
            dfs(child);
        }
    }
    vector<int> preorder(Node* root) {
        if(root==NULL) return {}; 
        dfs(root);
        return result;
    }
};