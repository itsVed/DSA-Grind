class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1) return {0};
        vector<int> ans(n);

        if(n % 2 == 0){
            int i = n / 2;
            int num = 1;
            while(i < n){
                ans[i] = num++;
                i++;
            }

            i = n / 2 - 1;
            int j = n / 2;

            while(i >= 0 and j < n){
                ans[i] = -(ans[j]);
                i--;
                j++;
            }
        }
        else{
            int i = n / 2;
            int num = 1;
            while(i < n){
                ans[i] = num++;
                i++;
            }

            i = n / 2 - 1;
            int j = n / 2;

            while(i > 0 and j < n){
                ans[i] = -(ans[j]);
                i--;
                j++;
            }

            ans[0] = -(ans[n-1] + ans[n-2]);
        }

        return ans;
    }
};