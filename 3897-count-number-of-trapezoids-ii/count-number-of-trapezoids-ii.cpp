class Solution {
public:

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    string getSlope(vector<int>& p1, vector<int>& p2) {
        int dx = p2[0] - p1[0];
        int dy = p2[1] - p1[1];

        if (dx == 0) return "vertical";
        if (dy == 0) return "horizontal";

        int x = abs(dx);
        int y = abs(dy);
        int g = gcd(x, y);

        string sign = (dx * dy > 0 ? "+" : "-");
        return to_string(x/g) + sign + to_string(y/g);
    }

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<string, vector<array<int,2>>> mid;
        unordered_map<string, unordered_map<int,int>> slope;

        for (int i = 0; i < n; i++) {
            vector<int>& p1 = points[i];

            for (int j = i + 1; j < n; j++) {
                vector<int>& p2 = points[j];

                string midKey = to_string(p1[0] + p2[0]) + "," + to_string(p1[1] + p2[1]);
                mid[midKey].push_back({i, j});

                string slopeKey = getSlope(p1, p2);

                slope.emplace(slopeKey, unordered_map<int,int>());

                auto& mp = slope[slopeKey];

                if (mp.find(i) == mp.end()) {
                    mp[i] = i;
                    mp[j] = i;
                } else {
                    mp[j] = mp[i];
                }
            }
        }

        int ans = 0;

        for (auto& entry : slope) {

            auto& mp = entry.second;
            unordered_map<int,int> counts;

            for (auto& kv : mp) {
                int val = kv.second;
                counts[val]++;
            }

            int prevPairs = 0;

            for (auto& kv : counts) {
                int cnt = kv.second;
                int currPairs = cnt * (cnt - 1) / 2;
                ans += prevPairs * currPairs;
                prevPairs += currPairs;
            }
        }

        for (auto& entry : mid) {
            auto& list = entry.second;

            if (list.size() <= 1) continue;

            unordered_map<string,int> slopeCount;

            for (auto& segment : list) {
                int i = segment[0];
                int j = segment[1];

                vector<int>& p1 = points[i];
                vector<int>& p2 = points[j];

                string key = getSlope(p1, p2);
                slopeCount[key]++;
            }

            int prev = 0;

            for (auto& kv : slopeCount) {
                int cnt = kv.second;
                ans -= prev * cnt;
                prev += cnt;
            }
        }

        return ans;
    }
};
