class Solution:
    def mergeAdjacent(self, nums: List[int]) -> List[int]:
        st = []

        for i in nums:
            st.append(i)
            
            while len(st) >= 2 and st[-1] == st[-2]:
                val = st.pop()
                st[-1] += val

        return st
        