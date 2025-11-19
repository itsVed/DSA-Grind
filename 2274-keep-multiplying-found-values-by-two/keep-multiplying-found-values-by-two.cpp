class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st;

        for(int a : nums){ // inserting the element in our set
            st.insert(a);
        }

        while(st.count(original)){ // searching the original in set 
            original *= 2; // multiply the value by 2
        }

        return original; // return original
    }
};