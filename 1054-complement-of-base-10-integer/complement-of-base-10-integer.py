class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1

        s = ""

        while n > 0:
            if n & 1:
                s += '0'
            else:
                s += '1'
            
            n >>= 1

        s = s[::-1]

        return int(s, 2)