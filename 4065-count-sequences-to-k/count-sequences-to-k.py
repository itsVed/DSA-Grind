class Solution:
    def countSequences(self, nums: List[int], k: int) -> int:
        n = len(nums)

        @lru_cache(None)
        def dfs(i, num, den):
           
            if i == n:
                return 1 if num == k * den else 0

            ans = 0
            x = nums[i]

            new_num = num * x
            new_den = den
            g = gcd(abs(new_num), abs(new_den))
            ans += dfs(i + 1, new_num // g, new_den // g)

            new_num = num
            new_den = den * x
            g = gcd(abs(new_num), abs(new_den))

            ans += dfs(i + 1, new_num // g, new_den // g)

            ans += dfs(i + 1, num, den)

            return ans

        return dfs(0, 1, 1)