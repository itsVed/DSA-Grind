class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        
        i = 0
        j = len(s) - 1

        while i < len(s) and s[i] != '1':
            i += 1

        while j >= 0 and s[j] != '1':
            j -= 1

        for k in range(i, j + 1):
            if s[k] == '0':
                return False

        return True