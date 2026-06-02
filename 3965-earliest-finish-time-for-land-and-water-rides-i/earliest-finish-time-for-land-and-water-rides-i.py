class Solution:

    def cal(self, ls, ld, ws, wd) :
        mini = float('inf')

        for i in range(len(ls)) :
            mini = min(mini, ls[i] + ld[i])

        ans = float('inf')

        for i in range(len(ws)) :
            ans = min(ans, max(mini, ws[i]) + wd[i])

        return ans
    
    def earliestFinishTime(self, ls: List[int], ld: List[int], ws: List[int], wd: List[int]) -> int:

        return min(self.cal(ls, ld, ws, wd), self.cal(ws, wd, ls, ld))

        
        