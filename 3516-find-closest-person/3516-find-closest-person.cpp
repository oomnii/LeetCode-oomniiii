class Solution {
public:
    int findClosest(int x, int y, int z) {
        int one = abs(z - x);
        int two = abs(z - y);
        if (one > two) return 2;
        else if (two > one) return 1;
        else return 0;
    }
};