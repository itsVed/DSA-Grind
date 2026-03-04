class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:

        ans = 0
        row = len(mat)
        col = len(mat[0])

        for i in range(row):
            for j in range(col):

                if mat[i][j] == 1:

                    ok = True

                    # Up
                    for u in range(i-1, -1, -1):
                        if mat[u][j] == 1:
                            ok = False
                            break

                    # Down
                    for u in range(i+1, row):
                        if mat[u][j] == 1:
                            ok = False
                            break

                    # Right
                    for r in range(j+1, col):
                        if mat[i][r] == 1:
                            ok = False
                            break

                    # Left
                    for r in range(j-1, -1, -1):
                        if mat[i][r] == 1:
                            ok = False
                            break

                    if ok:
                        ans += 1

        return ans