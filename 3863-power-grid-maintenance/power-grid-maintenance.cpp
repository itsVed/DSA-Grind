class Solution {
public:
    map<int, int> grid;
    map<int, set<int>> mp;
    
    void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis, int comp){
        vis[i] = true;
        mp[comp].insert(i);
        grid[i] = comp;

        for(auto &a : adj[i]){
            if(!vis[a]){
                dfs(a, adj, vis, comp);
            }
        }

        return;
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> ans;
        set<int> st;

        vector<vector<int>> adj(c + 1);

        for(auto conn : connections){
            int u = conn[0];
            int v = conn[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(c + 1, false);

        int comp = 0;

        for(int i=1; i <= c; i++){
            if(!vis[i]){
                dfs(i, adj, vis, comp);
                comp++;
            }
        }

        for(auto &q : queries){
            int node = q[1];
            int type = q[0];
            int comp = grid[node];

            if(type == 2){
                mp[comp].erase(node);
                st.insert(node);
            }
            else{
                if(!st.count(node)) ans.push_back(node);
                else{
                    if(!mp[comp].empty()) ans.push_back(*mp[comp].begin());
                    else ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};