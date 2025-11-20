class Solution {
public:
    // great question
    // always use sorting in any interval based question (Mind it)!

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int result = 0;
        int n = intervals.size();

        auto lambda = [&](auto &v1, auto &v2){ // lambda sort function
            if(v1[1] != v2[1]){ // end points are not same
                return v1[1] < v2[1];
            }
            
            return v1[0] > v2[0]; // end points are same
        };

        sort(intervals.begin(), intervals.end(), lambda); // sorting the intervals array as per end points in ascending order
                                                        // if the end points are same then sort in descending of start point
        int first = -1;
        int second = -1;

        for(auto it : intervals){
            int l = it[0];
            int r = it[1];

            if(l <= first){ // l is smaller or equal then first number then we ignore as both number are already included from
                continue; // that interval i.e first and second number
            }
            else if(l > second){ // if l is greater then second then we have to include both numbers
                result += 2;
                first = r - 1;
                second = r;
            }
            else{ // else we have to only include the rightmost number because it covers the whole range and minimize the array size
                result += 1;
                first = second;
                second = r;
            }
        }

        return result; // returing the result
    }
};