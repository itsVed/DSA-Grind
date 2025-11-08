class Solution {
public:
    int minimumOneBitOperations(int n) {
        int result = 0;

        vector<int> f(31, 0);
        f[0] = 1;

        for(int i=1; i < 31; i++){
            f[i] = 2 * f[i - 1] + 1;
        }

        int sign = 1;

        for(int i=30; i >= 0; i--){
            int i_th = ((1 << i) & n);

            if(i_th == 0) continue;

            if(sign > 0){
                result += f[i];
            }
            else{
                result -= f[i];
            }

            sign = sign * (-1);
        }

        return result;
    }
};