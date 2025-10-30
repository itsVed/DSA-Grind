class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        
        int i = 0;
        int j = 0;

        vector<vector<int>> ans;

        while(i < n and j < m){
            int st = max(firstList[i][0], secondList[j][0]);
            int et = min(firstList[i][1], secondList[j][1]);

            if(st <= et) ans.push_back({st, et});

            if(firstList[i][1] <= secondList[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        
        return ans;
    }
};