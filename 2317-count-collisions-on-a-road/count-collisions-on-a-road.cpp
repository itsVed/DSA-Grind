class Solution {
public:
    int countCollisions(string d) {
        int n = d.size();
        
        int i = 0;
        while (i < n && d[i] == 'L') i++;
        
        int j = n - 1;
        while (j >= 0 && d[j] == 'R') j--;
        
        int ans = 0;
        for (int k = i; k <= j; k++) {
            if (d[k] != 'S')
                ans++;
        }
        
        return ans;
    }
};
