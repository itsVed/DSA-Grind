/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean[]}
 */
var subsequenceSumAfterCapping = function(nums, k) {
    nums.sort((a, b) => a - b);
    let n = nums.length;

    let ans = Array(n).fill(false);
    let dp = Array(k + 1).fill(false);
    dp[0] = true;
    
    let i =0;

    for(let x = 1; x <= n; x++){
        while(i < n && nums[i] < x){
            for(let j=k; j >= nums[i]; j--){
                dp[j] = dp[j] | dp[j - nums[i]];
            }
            i++;
        }

        let large = n - i;

        for(let ne=0; ne <= large && k >= ne*x; ne++){
            if(dp[k - x*ne] == true){
                ans[x - 1] = true;
                break;
            }
        }
    }

    return ans;
};