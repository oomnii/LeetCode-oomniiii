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
    vector<vector<int>> levelOrder(Node* root) { 
        if(root==NULL) return {};
        vector<vector<int>> result;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            while(sz--){
                Node* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                for(auto &child:curr->children){
                    q.push(child);
                }
            }
            result.push_back(level);
        }
        return result;  
    }
};
