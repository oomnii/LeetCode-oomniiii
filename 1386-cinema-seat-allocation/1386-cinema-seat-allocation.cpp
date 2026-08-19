class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < m; i++) {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];
            mp[row].push_back(seat);
        }

        int remains = (n - mp.size()) * 2;

        for (auto &it : mp) {
            vector<int> &seats = it.second;

            sort(seats.begin(), seats.end());

            bool left = true;    // 2 3 4 5
            bool mid = true;     // 4 5 6 7
            bool right = true;   // 6 7 8 9

            for (int seat : seats) {
                if (seat >= 2 && seat <= 5)
                    left = false;

                if (seat >= 4 && seat <= 7)
                    mid = false;

                if (seat >= 6 && seat <= 9)
                    right = false;
            }

            if (left && right)
                remains += 2;
            else if (left || mid || right)
                remains += 1;
        }

        return remains;
    }
};