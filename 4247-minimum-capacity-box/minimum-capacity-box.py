class Solution:
    def minimumIndex(self, capacity: list[int], itemSize: int) -> int:

        idx = -1
        diff = float('inf')

        for i in range(len(capacity)):
            if capacity[i] >= itemSize and capacity[i] - itemSize < diff :
                diff = capacity[i] - itemSize
                idx =  i

        
        return idx
        