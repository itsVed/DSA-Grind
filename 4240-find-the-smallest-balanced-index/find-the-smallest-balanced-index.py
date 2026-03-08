class Solution:
    def smallestBalancedIndex(self, nums: list[int]) -> int:
        n = len(nums) - 1
        tot = sum(nums)
        prod = 1
        curr = tot
        ans = -1
        
        for i in range(n, -1, -1):
            if prod > curr :
                break
            curr -= nums[i]
            if curr == prod:
                ans = i
            prod *= nums[i]

        return ans