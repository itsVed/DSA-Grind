class Solution {
public:

    bool split(vector<int> &v, int k, int mid){

        int cs = 0;
        int oursplit = 1;

        for(int i=0; i < v.size(); i++){
            if(v[i] > mid) return false;

            if(cs + v[i] > mid){
                oursplit++;
                cs = v[i];
            }
            else{
                cs += v[i];
            }
        }

        return oursplit <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        /*
            i am thinking of a prefix sum get a total out of it and split but how to split this is the main question


        */

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;

        while(low < high){
            int mid = low + (high -  low)/2;

            if(split(nums, k, mid)){
                ans = mid;
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }

};