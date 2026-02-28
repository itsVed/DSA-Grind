class Solution:
    def concatenatedBinary(self, n: int) -> int:
        
        s = ""
        for num in range(1, n + 1) :
            s += str(bin(num)[2:])

        return int(s, 2) % 1000000007