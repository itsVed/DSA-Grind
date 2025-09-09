class Solution {
public:
    int M = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> t(n + 1);
        t[1] = 1;

        int count = 0;

        for(int i=2; i <= n; i++){
            if(i - delay > 0){
                count = (count +  t[i - delay]) % M;
            }

            if(i - forget > 0){
                count  = (count -  t[i - forget] + M) % M;
            }

            t[i] = count;
        }

        int total = 0;

        for(int i = n - forget + 1; i <= n; i++){

            if(i > 0){
                total = (total + t[i]) % M;
            }
        }

        return total;
    }
};