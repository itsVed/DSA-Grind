class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        int i = 0;

        while(n > 0){
            int a = n % 10;
            n /= 10;

            if(a != 0){
                a = a * pow(10, i);
                ans.push_back(a);
            }

            i++;
        }

        sort(ans.begin(), ans.end(), greater<int>());

        return ans;
    }
};