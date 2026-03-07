class Solution:
    def minFlips(self, s: str) -> int:

        n = len(s)
        s = s + s

        alt1 = ""
        alt2 = ""

        for i in range(len(s)):
            alt1 += "1" if i % 2 == 0 else "0"
            alt2 += "0" if i % 2 == 0 else "1"

        i = 0
        flip1 = 0
        flip2 = 0
        res = float('inf')

        for j in range(len(s)):

            if s[j] != alt1[j]:
                flip1 += 1
            if s[j] != alt2[j]:
                flip2 += 1

            if j - i + 1 > n:
                if s[i] != alt1[i]:
                    flip1 -= 1
                if s[i] != alt2[i]:
                    flip2 -= 1
                i += 1

            if j - i + 1 == n:
                res = min(res, flip1, flip2)

        return res