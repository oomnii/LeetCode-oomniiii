class Solution {
public:
    int minRotations(string s) {
        int rotation = 0;
        int curr = 0;
        for(auto &it:s){
            rotation += min(abs(curr-(it-'0')),10-abs(curr-(it-'0')));
            curr = it-'0';
        }
        return rotation;
    }
};