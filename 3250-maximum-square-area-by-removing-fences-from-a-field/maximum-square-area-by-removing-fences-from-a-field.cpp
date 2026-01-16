class Solution {
public:
    int MOD = 1e9 + 7;

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        
        vector<int> hf(hFences.size() + 2);
        vector<int> vf(vFences.size() + 2);

        hf[0] = 1; hf[hf.size() - 1] = m;
        vf[0] = 1; vf[vf.size() - 1] = n;

        for(int i=0; i < hFences.size(); i++)
            hf[i + 1] = hFences[i];

        for(int i=0; i < vFences.size(); i++)
            vf[i + 1] = vFences[i];

        sort(hf.begin(), hf.end());
        sort(vf.begin(), vf.end());

        set<int> st;

        for(int i=0; i < hf.size(); i++){
            for(int j=i + 1; j < hf.size(); j++){
                st.insert(hf[j] - hf[i]);
            }
        }

        long long maxvalue = -1;

        for(int i=0; i < vf.size(); i++){
            for(int j=i + 1; j < vf.size(); j++){
                if(st.count(vf[j] - vf[i])){
                    maxvalue = max(maxvalue, 1LL * (vf[j] - vf[i]));
                }
            }
        }

        if(maxvalue < 0) return -1;

        return (1LL * maxvalue * maxvalue) % MOD;
    }
};
