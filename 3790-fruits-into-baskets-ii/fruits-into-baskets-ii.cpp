class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int count = 0;
        int n = f.size();

        for(int i=0; i < n; i++){
            bool placed = false;
            for(int j=0; j < n; j++){
                if(b[j] >= f[i]){
                    b[j] = 0;
                    placed = true;
                    break;
                }
            }

            if(placed) count++;
        }

        return n - count;
    }
};