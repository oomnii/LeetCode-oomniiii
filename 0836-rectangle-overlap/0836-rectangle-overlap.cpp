class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // No overlap: rec1 is left of rec2
        if (rec1[2] <= rec2[0]) return false;

        // No overlap: rec2 is left of rec1
        if (rec2[2] <= rec1[0]) return false;

        // No overlap: rec1 is above rec2
        if (rec1[1] >= rec2[3]) return false;

        // No overlap: rec2 is above rec1
        if (rec2[1] >= rec1[3]) return false;

        return true;
    }
};