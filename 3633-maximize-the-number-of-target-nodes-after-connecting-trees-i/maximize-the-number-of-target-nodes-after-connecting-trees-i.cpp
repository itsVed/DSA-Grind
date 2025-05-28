class Solution {
public:

    int dfs(int curr, vector<vector<int>> &adj, int d, int parent){
        if(d < 0) return 0;

        int count = 1;

        for(auto ngbr : adj[curr]){
            if(ngbr != parent){
                count += dfs(ngbr, adj, d - 1, curr);
            }
        }

        return count;
    }

    vector<int> findCount(vector<vector<int>>& edges, int d){
        int N = edges.size() + 1;

        vector<int> result(N);
        vector<vector<int>> adj(N);

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0; i < N; i++){
            result[i] = dfs(i, adj, d, -1);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

        vector<int> r1 = findCount(edges1, k);
        vector<int> r2 = findCount(edges2, k - 1);

        int target = *max_element(r2.begin(), r2.end());

        for(int i=0;  i < r1.size(); i++){
            r1[i] += target;
        }

        return r1;
    }
};