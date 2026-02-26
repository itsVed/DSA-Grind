class Solution:
    def scoreDifference(self, nums: List[int]) -> int:
        firstturn = True
        secondturn = False

        first = 0
        second = 0

        for i in range(len(nums)):
            if nums[i] % 2 != 0:
                firstturn = True if firstturn == False else False
                secondturn = True if secondturn == False else False

            if (i + 1) % 6 == 0 :
                firstturn = True if firstturn == False else False
                secondturn = True if secondturn == False else False
            
            if firstturn :
                first += nums[i]
            else :
                second += nums[i]
            
        return first - second



        