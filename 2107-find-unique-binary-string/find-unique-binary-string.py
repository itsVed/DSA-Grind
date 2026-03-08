class Solution:

    def solve(self, s, arr, k) :

        if len(s) == k :
            arr.append(s)
            return

        self.solve(s + '0', arr, k)
        self.solve(s + '1', arr, k)


    def findDifferentBinaryString(self, nums: List[str]) -> str:
        
        arr = []
        k = len(nums[0])
        self.solve("", arr, k)

        for i in range(len(arr)) :

            if arr[i] not in nums :
                return arr[i]