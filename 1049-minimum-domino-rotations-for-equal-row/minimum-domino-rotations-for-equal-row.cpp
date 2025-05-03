class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n = t.size();
        int cands[2] = {t[0], b[0]};
        
        for (int c = 0; c < 2; ++c) {
            int target = cands[c];
            int rotT = 0, rotB = 0;
            bool flag = true;

            for (int i = 0; i < n; ++i) {
                if (t[i] != target && b[i] != target) {
                    flag = false;
                    break;
                } else if (t[i] != target) {
                    rotT++;
                } else if (b[i] != target) {
                    rotB++;
                }
            }

            if (flag) return min(rotT, rotB);
        }

        return -1;
    }
};