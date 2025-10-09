class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int m = mana.size();
        int n = skill.size();

        vector<long long> finish(n, 0);

        for(int j=0; j < m; j++){
            finish[0] += mana[j] * skill[0];

            for(int i=1; i < n; i++){
                finish[i] = max(finish[i], finish[i - 1]) + 1LL * mana[j] * skill[i];
            }

            for(int i=n-1; i > 0; i--){
                finish[i - 1] = finish[i] - 1LL * mana[j] * skill[i];
            }
        }

        return finish[n - 1];
    }
};