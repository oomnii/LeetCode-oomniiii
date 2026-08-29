class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        bool Swhite = false;
        bool Twhite = false;
        if(source[0]%2==source[1]%2) Swhite = true;
        if(target[0]%2==target[1]%2) Twhite = true;
        if(Swhite==Twhite){
            if(abs(source[0]-target[0])==abs(source[1]-target[1])) return 1;
            else return 2;
        }
        return -1;
    }
};