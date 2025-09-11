/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    let a = [];

    nums.sort((a, b) => a - b);
    let n = nums.length;

    for(let i=0; i < n - 2; i++){
        if(i > 0 && nums[i] === nums[i - 1]) continue;

        let l = i + 1, r = n - 1;

        while(l < r){
            let sum = nums[i] + nums[l] + nums[r];

            if(sum === 0){
                a.push([nums[i], nums[l], nums[r]]);
                l++;
                r--;

                while(l < r && nums[l] == nums[l - 1]){
                    l++;
                }

                while(l < r && nums[r] == nums[r - 1]){
                    r++;
                }


            }
            else if(sum < 0){
                l++;
            }
            else{
                r--;
            }
        }
    }

    return a;
};
