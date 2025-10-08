class Solution {
public:

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        vector<int> ans(spells.size());
        sort(potions.begin(), potions.end());

        for(int i=0; i < spells.size(); i++){

            int l = 0, r = n - 1;
            int len = n;

            while(l <= r){
                int mid = l + (r - l)/2;
                long long product = 1LL * potions[mid] * spells[i];

                if(product >= success){
                    len = mid;
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }

            ans[i] = (n - len);

        }

        return ans;
    }
};