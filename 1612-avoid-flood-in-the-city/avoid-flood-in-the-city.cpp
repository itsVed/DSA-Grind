class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size());
        map<int, int> lastlake;
        set<int> zeroes;

        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                zeroes.insert(i);
            } 
            else if(lastlake.find(rains[i]) != lastlake.end()) {
                
                auto it = zeroes.lower_bound(lastlake[rains[i]]);
                if (it == zeroes.end()) return {};

                ans[*it] = rains[i];
                zeroes.erase(it);
            }

            lastlake[rains[i]] = i; 
            ans[i] = -1;            
        }

        for(auto z : zeroes){ 
            ans[z] = 1;
        }   

        return ans;
    }
};