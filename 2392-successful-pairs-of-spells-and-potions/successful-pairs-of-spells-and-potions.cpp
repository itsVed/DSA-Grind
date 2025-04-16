class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end()); // sorting the potions array
        int left, right;

        for(int i=0; i < n; i++){
            left = 0;
            right = m - 1;
            int pair = 0;

            while(left <= right){ // using the binary search so that i can find the index and subtract it from n and i got the no. of pairs
                int mid = (right - left)/2 + left;
                long long mul = (long long) potions[mid] * spells[i]; // calculating the product

                if(mul >= success){ // if i get the true then i search for the left side so i got max ans
                    pair = m - mid;
                    right = mid - 1;
                }
                else{
                    left = mid + 1; // searching the right side
                }
            }   

            ans.push_back(pair); // storig the no. of pairs
        }

        return ans;
    
    }
};