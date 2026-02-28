class Solution:

    def maxGoodNumber(self, nums: List[int]) -> int:
        
        nums = [bin(nums[i])[2:] for i in range(len(nums))]

        def compare(a, b) :
            if a + b > b + a :
                return -1
            elif b + a > a + b :
                return 0
            else :
                return 1
        

        nums.sort(key=cmp_to_key(compare))

        ans = "".join(nums)

        return int(ans, 2)