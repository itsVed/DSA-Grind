class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        int n = nums.size();

        for(int i=0; i < n; i++){
            int count = 0;
            int sum = 0;

            for(int fact = 1; fact <= sqrt(nums[i]); fact++){
                
                if(nums[i] % fact == 0){
                    int other = nums[i] / fact;

                    if(other == fact){
                        count += 1;
                        sum += fact;
                    }
                    else{
                        count += 2;
                        sum += (fact + other);
                    }
                }

                if(count > 4){
                    break;
                }
            }

            if(count == 4){
                total += sum;
            }
        }

        return total;
    }
};