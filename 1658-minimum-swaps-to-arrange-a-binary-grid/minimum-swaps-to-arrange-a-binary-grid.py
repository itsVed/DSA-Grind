class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)

        arr = []

        for row in grid:
            count  = 0
            for el in reversed(row):
                if el == 0 :
                    count += 1
                else :
                    break
            
            arr.append(count)

        swaps = 0

        for i in range(n) :

            need = n - i - 1
            
            j = i

            while j < n and arr[j] < need :
                j += 1

            if j == n :
                return -1

            while j > i :

                arr[j], arr[j - 1] = arr[j - 1], arr[j]
                swaps += 1
                j -= 1

        return swaps


        