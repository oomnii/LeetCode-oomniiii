class Solution {
public:
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (v[i][i] == 0)
                continue;

            provinces++;

            queue<pair<int, int>> q;
            q.push({i, i});
            v[i][i] = 0;

            while (!q.empty()) {
                int sz = q.size();

                while (sz--) {
                    int row = q.front().first;
                    int currentCity = q.front().second;
                    q.pop();

                    for (int neighbour = 0; neighbour < n; neighbour++) {
                        if (v[currentCity][neighbour] == 1 && v[neighbour][neighbour] == 1) {
                            q.push({currentCity, neighbour});
                            v[neighbour][neighbour] = 0;
                        }
                    }
                }
            }
        }
        return provinces;
    }
};