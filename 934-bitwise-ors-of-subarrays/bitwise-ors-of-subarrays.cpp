class Solution {
public:
    set<pair<int, int>> memo;

    void f(vector<int> &arr, int i, set<int> &st, int currOr){
        if(i >= arr.size()) return;

        currOr |= arr[i];
        st.insert(currOr);

        if (memo.count({i, currOr})) return;
        memo.insert({i, currOr});      

        f(arr, i + 1, st, currOr);
    }

    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> st;
        
        for(int i=0; i < arr.size(); i++){
            f(arr, i, st, 0);
        }

        return st.size();         
    }
};