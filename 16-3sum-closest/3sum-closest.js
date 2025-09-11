/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    nums.sort((a, b) => a - b);
    let ans = 1e9;
    let diff = 1e9;

    let n = nums.length;

    for(let i=0; i < n - 2; i++){

        let j = i + 1, k = n - 1;

        while(j < k){
            let sum = nums[i] + nums[j] + nums[k];

            if(Math.abs(target - sum) < diff){
                ans = sum;
                diff = Math.abs(target - sum);
            }

            if(sum < target){
                j++;
            }
            else if(sum > target){
                k--;
            }
            else{
                return sum;
            }
        }
    }

    return ans;
};