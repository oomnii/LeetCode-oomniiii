class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source==target) return 0;
        bool horizontal = source[0]==target[0];
        bool vertical = source[1]==target[1];
        bool diagonal = abs(source[0]-target[0])== abs(source[1]-target[1]);
        if(horizontal==vertical==diagonal) return 1;
        return 2;
    }
};