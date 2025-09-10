class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        unordered_set<int> sad;

        for(auto f : friendships){
            int u = f[0] - 1;
            int v = f[1] - 1;

            unordered_set<int> lang(languages[u].begin(), languages[u].end());

            bool flag = false;
            for(auto l : languages[v]){
                if(lang.count(l)){
                    flag = true;
                    break;
                }
            }

            if(!flag){
                sad.insert(u);
                sad.insert(v);
            } 
        }
        
        int maxlang = 0;
        vector<int> v(n + 1, 0);

        for(auto a : sad){
            for(auto b : languages[a]){
                v[b] += 1;
                maxlang = max(maxlang, v[b]);
            }
        }

        return sad.size() - maxlang;

    }
};