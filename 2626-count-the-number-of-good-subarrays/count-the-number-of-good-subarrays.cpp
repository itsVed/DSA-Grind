class Solution {
public:
    // I'm thinking of a two pointer
    // ans and count variable
    // whenever count >= k i will increase my ans++
    // just need to think when i have to shrink and expand
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int,int> mp;
        long long count = 0;
        int n = nums.size();
        int i = 0, j = 0;

        while(j < n){
            count += mp[nums[j]];  // maintaining the map for storing the freq of elements
            mp[nums[j]]++;
           
            while(count >= k){ // shrinking
                ans += (n - j); // increasing the answer 

                mp[nums[i]]--; // decreasing the freq in my map
                count -= mp[nums[i]]; // removing the pair from count
                i++;
            }
            
            j++;
        }

        return ans;
    }
};