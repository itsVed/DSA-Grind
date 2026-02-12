class Solution:
    def longestBalanced(self, s: str) -> int:
        ans = 0
        n = len(s)

        i = 0
        while i < n:
            mp = {}
            j = i

            while j < n:
                mp[s[j]] = mp.get(s[j], 0) + 1

                ok = True
                prev = mp[s[j]]

                for key, val in mp.items():
                    if val != prev:
                        ok = False
                        break

                if ok:
                    ans = max(ans, j - i + 1)

                j += 1

            i += 1

        return ans
