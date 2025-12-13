class Solution {
public:
    vector<string> validateCoupons(vector<string>& c, vector<string>& b, vector<bool>& a) {
        int n = c.size();
        unordered_set<string> validBL = {"electronics", "grocery", "pharmacy", "restaurant"};

        unordered_map<string,int> order = {
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3}
        };

        vector<pair<string,string>> temp;

        for (int i = 0; i < n; i++) {

            if (!regex_match(c[i], regex("^[A-Za-z0-9_]+$"))) continue;

            if (!validBL.count(b[i])) continue;

            if (!a[i]) continue;

            temp.push_back({c[i], b[i]});
        }

        sort(temp.begin(), temp.end(), [&](auto &A, auto &B){
            int oa = order[A.second];
            int ob = order[B.second];

            if (oa != ob) return oa < ob;      
            return A.first < B.first;         
        });

        vector<string> ans;
        for (auto &p : temp) ans.push_back(p.first);

        return ans;
    }
};
