class Solution:

    def invert(self, s):
        res = ""
        
        for ch in s:
            if ch == '1':
                res += '0'
            else:
                res += '1'

        return res

    def solve(self, idx, n, k, s):
     
        if idx == n - 1:
            return s[k - 1]   

        prev = s 
        inv = self.invert(prev)
        rev = inv[::-1]

        new_s = prev + "1" + rev

        return self.solve(idx + 1, n, k, new_s)

    def findKthBit(self, n: int, k: int) -> str:
        
        return self.solve(0, n, k, "0")