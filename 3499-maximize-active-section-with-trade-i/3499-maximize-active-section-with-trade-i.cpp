class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        vector<string> blocks;
        int initialActive = 0;

        int i = 0;
        while (i < n) {
            int j = i;

            while (j < n && s[j] == s[i]) j++;
            char ch = s[i];
            int len = j - i;
            if (ch == '1') {
                initialActive += len;
            }
            blocks.push_back(string(1, ch) + "->" + to_string(len));

            i = j;
        }

        int maxActive = initialActive;
        int blockCount = blocks.size();

        for (i = 1; i < blockCount - 1; i++) {
            if (blocks[i][0] == '0') {
                continue;
            }

            int leftZeros = stoi(blocks[i - 1].substr(3));
            int rightZeros = stoi(blocks[i + 1].substr(3));

            int currentActive = initialActive + leftZeros + rightZeros;

            maxActive = max(maxActive, currentActive);
        }

        return maxActive;
    }
};