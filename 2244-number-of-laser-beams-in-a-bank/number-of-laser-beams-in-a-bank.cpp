class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        int count = 0;

        for(auto ch : bank[0]){
            if(ch == '1') count++;
        }

        prev = count;

        for(int i=1; i < bank.size(); i++){
            count = 0;

            for(auto ch : bank[i]){
                if(ch == '1'){
                    ans += prev;
                    count++;
                }
            }

            if(count != 0)
                prev = count;
        }

        return ans;
    }
};