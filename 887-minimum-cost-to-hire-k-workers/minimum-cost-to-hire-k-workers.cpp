class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans = DBL_MAX, total = 0;
        int n = quality.size();

        priority_queue<int> pq;
        vector<pair<double, int>> worker;

        for(int i=0; i < n; i++){
            double rate = (double)wage[i] / quality[i];
            worker.push_back({rate, quality[i]});
        }

        sort(worker.begin(), worker.end());

        for(auto [rate, quality] : worker){

            pq.push(quality);
            total += quality;

            if(pq.size() > k){
                total -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                double cost = total * rate;
                ans = min(ans, cost);
            }

        }

        return ans;
    }
};