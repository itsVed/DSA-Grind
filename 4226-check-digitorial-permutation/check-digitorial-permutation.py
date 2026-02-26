class Solution:
    def isDigitorialPermutation(self, n: int) -> bool:
        
        s = str(n)
        ans = 0

        for ch in s :
            ans += math.factorial(int(ch))

        ans = str(ans)

        s1 = sorted(ans)
        ans = "".join(s1)

        s2 = sorted(s)
        s = "".join(s2)

        return True if ans == s else False