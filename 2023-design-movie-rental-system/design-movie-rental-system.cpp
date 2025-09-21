class MovieRentingSystem {
public:

    set<vector<int>> rented;
    unordered_map<int, set<vector<int>>> unrented;
    unordered_map<int, unordered_map<int,int>> price;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        
        for(auto i: entries){
            int s = i[0];
            int m = i[1];
            int p = i[2];

            unrented[m].insert({p, s});
            price[m][s] = p;
        }
    }
    
    vector<int> search(int movie) {
        
        if(unrented.find(movie) == unrented.end()){
            return {};
        }

        vector<int> ans;

        for(auto i : unrented[movie]){
            int s = i[1];

            ans.push_back(s);

            if(ans.size() == 5) break;
        }

        return ans;
    }
    
    void rent(int shop, int movie) {
        int p = price[movie][shop];

        unrented[movie].erase(unrented[movie].find({p, shop}));

        rented.insert({p, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int p = price[movie][shop];

        rented.erase({p, shop, movie});

        unrented[movie].insert({p, shop});

    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;

        for(auto i: rented){
            int shop = i[1];
            int movie = i[2];

            ans.push_back({shop, movie});

            if(ans.size() == 5) break;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */