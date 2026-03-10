class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        M = 10**9 + 7

        t = [[[0]*2 for _ in range(one+1)] for _ in range(zero+1)]

        # base cases
        for i in range(1, min(zero, limit) + 1):
            t[i][0][0] = 1

        for j in range(1, min(one, limit) + 1):
            t[0][j][1] = 1

        for i in range(zero + 1):
            for j in range(one + 1):

                if i == 0 or j == 0:
                    continue

                # end with 0
                val0 = (t[i-1][j][0] + t[i-1][j][1]) % M

                if i - 1 >= limit:
                    val0 = (val0 - t[i-1-limit][j][1] + M) % M

                t[i][j][0] = val0

                # end with 1
                val1 = (t[i][j-1][0] + t[i][j-1][1]) % M

                if j - 1 >= limit:
                    val1 = (val1 - t[i][j-1-limit][0] + M) % M

                t[i][j][1] = val1

        return (t[zero][one][0] + t[zero][one][1]) % M