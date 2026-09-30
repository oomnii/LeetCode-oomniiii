class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int cnt = 0;
        vector<int> depth;
        for(auto &it:seq){
            if(it=='('){
                depth.push_back(cnt%2);
                cnt++;
            }
            else{
                cnt--;
                depth.push_back(cnt%2);
            }
        }
        return depth;
    }
};