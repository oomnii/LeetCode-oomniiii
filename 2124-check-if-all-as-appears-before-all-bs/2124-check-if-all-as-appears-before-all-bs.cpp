class Solution {
public:
    bool checkString(string s) {
        bool foundB = false; 
        for(auto &ch:s){
            if(ch=='b') foundB = true;
            if(ch=='a' && foundB) return false;
        }
        return true;
    }
};