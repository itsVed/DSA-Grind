class Solution:
    def minOperations(self, s: str) -> int:
        
        alt1 = 0
        alt2 = 0
        
        for i in range(len(s)):
            
            if i % 2 == 0:
                if s[i] != '0':
                    alt1 += 1
                if s[i] != '1':
                    alt2 += 1
            else:
                if s[i] != '1':
                    alt1 += 1
                if s[i] != '0':
                    alt2 += 1
        
        return min(alt1, alt2)