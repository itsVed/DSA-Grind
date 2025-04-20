class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        map<int,int> freq;

        for(auto i: answers){
            freq[i]++;
        }
        
        int res = 0;

        for (auto [k, count] : freq){
            res += ((count + k) / (k + 1)) * (k + 1);
        }

        return res;

    }
};