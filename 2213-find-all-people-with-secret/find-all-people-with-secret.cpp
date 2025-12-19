class Solution {
public:
    typedef pair<int, int> P;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> secret(n, false);
        secret[0] = true;
        secret[firstPerson] = true;

        map<int, vector<P>> meet;

        for(auto v : meetings){
            int p1 = v[0];
            int p2 = v[1];
            int t = v[2];

            meet[t].push_back({p1, p2});
        }

        for(auto &it : meet){
            int t = it.first;
            vector<P> v = it.second;

            unordered_map<int, vector<int>> adj;
            unordered_set<int> added;
            queue<int> q;

            for(auto [p1, p2] : v){
                adj[p1].push_back(p2);
                adj[p2].push_back(p1);

                if(secret[p1] and added.find(p1) == added.end()){
                    added.insert(p1);
                    q.push(p1);
                }

                if(secret[p2] and added.find(p2) == added.end()){
                    added.insert(p2);
                    q.push(p2);
                }
            }

            while(!q.empty()){
                int p = q.front();
                q.pop();

                for(auto next : adj[p]){
                    if(!secret[next]){
                        secret[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        vector<int> result;

        for(int i=0; i < n; i++){
            if(secret[i]){
                result.push_back(i);
            }
        }

        return result;
    }
};