class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int numEquivDominoPairs(vector<vector<int>>& d) {
        unordered_map<pair<int,int>, int, pair_hash> mp;
        int n = d.size();
        int ans = 0;

        for(int i=0; i < n; i++){
            int a = d[i][0];
            int b = d[i][1];


            if(mp.find({a, b}) != mp.end()){
                mp[{a, b}]++;
            }
            else if(mp.find({b, a}) != mp.end()){
                mp[{b, a}]++;
            }
            else{
                mp[{a, b}]++;
            }
        }

        for(auto i: mp){
            ans += (i.second * (i.second - 1))/2;
        }

        return ans;
    }
};