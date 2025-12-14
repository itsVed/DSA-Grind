class Solution {
public:
    int MOD = 1e9 + 7;

    int numberOfWays(string corridor) {

        vector<int> arr;

        for(int i=0; i < corridor.size(); i++){
            if(corridor[i] == 'S'){
                arr.push_back(i);
            }
        }
        int seats = arr.size();

        if(seats == 0 || seats % 2 != 0 || seats == 1) return 0;
        if(seats == 2) return 1;

        int prev = arr[1];
        long long ans = 1;

        for(int i=2; i < arr.size(); i+=2){
            int gap = arr[i] - prev;
            ans = (ans * gap) % MOD;
            prev = arr[i + 1];
        }

        return (int)ans;
    }
};