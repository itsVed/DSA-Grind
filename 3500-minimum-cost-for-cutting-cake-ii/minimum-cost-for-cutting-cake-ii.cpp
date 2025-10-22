class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end(), greater<>());
        sort(v.begin(), v.end(), greater<>());
        int vert = 1, horz = 1;

        int row = h.size(), col = v.size();
        int i=0; 
        int j=0;
        long long cost = 0;

        while(i < row and j < col){
            // horizontal cut
            if(h[i] > v[j]){
                cost += h[i] * vert;
                horz++;
                i++;
            }
            else{ // vertical cut
                cost += v[j] * horz;
                vert++;
                j++;
            }
        }

        while(i < row){
            cost += h[i] * vert;
            i++;
        }

        while(j < col){
            cost += v[j] * horz;
            j++;
        }

        return cost;
    }
};