class Solution {
public:

    vector<int> topo(int n, unordered_map<int, vector<int>> &adj, vector<int> &indegree){

        queue<int> q;
        int count = 0;
        vector<int> res;

        for(int i=0; i < n; i++){
            if(indegree[i] == 0){
                res.push_back(i);
                q.push(i);
                count++;
            }
        }

        while(!q.empty()){
            int a = q.front();
            q.pop();

            for(auto ngbr : adj[a]){
                indegree[ngbr]--;

                if(indegree[ngbr] == 0){
                    q.push(ngbr);
                    count++;
                    res.push_back(ngbr);
                }
            }
        }


        if(count == n) return res;

        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 1 and prerequisites.size() == 0) return {0};
        int n = numCourses;

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for(auto vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topo(n, adj, indegree);

    }
};