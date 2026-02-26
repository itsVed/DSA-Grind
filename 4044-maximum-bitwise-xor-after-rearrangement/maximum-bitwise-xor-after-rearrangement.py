class Solution:
    def maximumXor(self, s: str, t: str) -> str:

        mp = {'0': 0, '1': 0}

        for ch in t:
            mp[ch] += 1

        ans = ""

        for ch in s:
            if ch == '1':
                if mp['0'] > 0:
                    ans += '1'
                    mp['0'] -= 1
                else:
                    ans += '0'
            else:
                if mp['1'] > 0:
                    ans += '1'
                    mp['1'] -= 1
                else:
                    ans += '0'

        return ans