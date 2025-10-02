class Solution {
public:

    bool isbipartite(int curr, unordered_map<int, vector<int>> &adj, vector<int> &colors, int currcolor){
        colors[curr] = currcolor;

        for(int ngbr : adj[curr]){
            if(colors[ngbr] == currcolor){
                return false;
            }

            if(colors[ngbr] == -1){
                if(isbipartite(ngbr, adj, colors, 1 - currcolor) == false){
                    return false;
                }
            }
        }

        return true;
    }
    
    int maxateachlevel(unordered_map<int, vector<int>> &adj, int node, int n){
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(node);
        visited[node] = true;
        int levels = 1;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();
                q.pop();

                for(int ngbr : adj[curr]){
                    if(visited[ngbr]){
                        continue;
                    }

                    q.push(ngbr);
                    visited[ngbr] = true;
                }

            }

            levels++;
        }

        return levels - 1;
    }

    int maxeachcomp(unordered_map<int, vector<int>> &adj, int node, int n, vector<int> &level, vector<bool> &visited){
        visited[node] = true;
        int maxreach = level[node];

        for(int ngbr: adj[node]){
            if(!visited[ngbr]){
                maxreach = max(maxreach, maxeachcomp(adj, ngbr, n, level, visited));
            }
        }

        return maxreach;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(vector<int> edge : edges){
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n, -1);
        for(int i=0; i < n; i++){

            if(colors[i] == -1){
                if(isbipartite(i, adj, colors, 1) == false){
                    return -1;
                }
            }
        }

        vector<int> levels(n, 0);

        for(int node = 0; node < n; node++){
            levels[node] = maxateachlevel(adj, node, n);
        }

        int ans = 0;
        vector<bool> visited(n, false);

        for(int node=0; node < n; node++){
            if(!visited[node]){
                ans += maxeachcomp(adj, node, n, levels, visited);
            }
        }

        return ans;

    }
};