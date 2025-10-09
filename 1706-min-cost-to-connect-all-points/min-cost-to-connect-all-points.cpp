class Solution {
public:

    typedef vector<pair<int,int>> PP;

    int primsalgo(vector<PP> &adj, int V){
        vector<bool> vis(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // {cost, node};
        pq.push({0, 0});
        int totalcost = 0;

        while(!pq.empty()){
            auto[cost, node] = pq.top();
            pq.pop();
            if (vis[node]) continue;

            vis[node] = true;
            totalcost += cost;

            for(auto v: adj[node]){
                int nbcost = v.first;
                int nb = v.second;

                if(!vis[nb])
                    pq.push({nbcost, nb});
            }

        }

        return totalcost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<PP> adj(V);

        for(int i=0; i < V; i++){
            for(int j=i+1; j < V; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int cost = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({cost, j});
                adj[j].push_back({cost, i});
            }
        }

        return primsalgo(adj, V);
    }
};