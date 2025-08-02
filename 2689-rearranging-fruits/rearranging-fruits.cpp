class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long ans = 0;
        unordered_map<int,int>  mp;

        for(int val: basket1) mp[val]++;
        for(int val: basket2) mp[val]--;

        vector<int> vec;

        for(auto [fruit, occ] : mp){
            if(occ % 2 == 1) return -1;

            for(int i=0; i < abs(occ)/2; i++){
                vec.push_back(fruit);
            }
        }

        sort(vec.begin(), vec.end());

        int minVal = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));

        for(int i=0; i < vec.size() / 2; i++){
            ans += min(minVal * 2, vec[i]);
        }

        return ans;
    }
};