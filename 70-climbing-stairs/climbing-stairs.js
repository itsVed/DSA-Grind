/**
 * @param {number} n
 * @return {number}
 */
let dp = {};

var climbStairs = function(n) {
    if(n < 0) return 0;
    if(n == 0) return 1;

    if(dp[n] !== undefined){
        return dp[n];
    }

    let take1 = climbStairs(n - 1);
    let take2 = climbStairs(n - 2);

    return dp[n] = take1 + take2;
};