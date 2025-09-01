class Solution {
public:

    double gain(int a, int b){
        return (double) (a + 1)/(b + 1) - (double)a/b;
    }

    double maxAverageRatio(vector<vector<int>>& c, int e) {
        
        int noofclass = c.size();
        double ans = 0.0;

        priority_queue<pair<double, int>> pq;

        for(int i=0; i < noofclass; i++){
            pq.push({gain(c[i][0], c[i][1]), i});
        }

        while(e--){
            auto [g, idx] = pq.top();
            pq.pop();

            c[idx][0]++;
            c[idx][1]++;

            pq.push({gain(c[idx][0], c[idx][1]), idx});
        }

        for(int i=0; i < noofclass; i++){
            ans += (double)c[i][0]/c[i][1];
        }

        return ans/noofclass;
    }
};