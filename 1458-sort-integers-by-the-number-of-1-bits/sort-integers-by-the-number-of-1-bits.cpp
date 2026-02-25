class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        auto findw = [&](int n){
            int w = 0;

            while(n > 0){
                w++;

                n &= n - 1;
            }

            return w;
        };

        auto compare = [&](int &a, int &b){
            if(findw(a) == findw(b)){
                return a < b;
            }

            return findw(a) < findw(b);
        };

        sort(arr.begin(), arr.end(), compare);

        return arr;
    }
};